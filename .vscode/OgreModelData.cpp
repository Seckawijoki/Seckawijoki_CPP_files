#include "OgreModelData.h"
#include "OgreSkeletonAnimData.h"
#include "OgreMaterialAnimData.h"
#include "OgreMorphAnimData.h"
#include "OgreSkeletonData.h"
#include "OgreMesh.h"
#include "OgreAnimTrackBone.h"
#include <map>

namespace Ogre
{
	IMPLEMENT_RTTI(BSPData, Resource, 100)
	IMPLEMENT_RTTI(ModelData, Resource, 101)

	IMPLEMENT_RTTI(SkinPatch, Resource, 100)
	IMPLEMENT_RTTI(SubMeshData, Resource, 100)
	IMPLEMENT_RTTI(MeshData, Resource, 100)

	BSPData::BSPData(const BSPData &rhs) : m_Vertex(rhs.m_Vertex), m_Index(rhs.m_Index), m_SufaceMtl(rhs.m_SufaceMtl)
	{
	}

	void BSPData::_serialize(Archive &ar, int version)
	{
		ar.serializeRawArray(m_Vertex);
		ar.serializeRawArray(m_Index);
		ar.serializeRawArray(m_SufaceMtl);
	}

	ModelData::ModelData() : m_pSkeleton(NULL), m_pBspData(NULL), m_bAddEndKey(false), m_nEndKeyTime(0), m_iARReadSeqID(0), 
		m_RightHipBone(Vector3::ZERO), m_LeftHipBone(Vector3::ZERO), m_RightShoulder(Vector3::ZERO), m_LeftShoulder(Vector3::ZERO)
	{

	}

	ModelData::~ModelData()
	{
		OGRE_RELEASE(m_pSkeleton);
		OGRE_RELEASE(m_pBspData);
		ReleasePointerArray(m_Meshes);

		for(size_t i=0; i<m_Anims.size(); i++)
		{
			m_Anims[i].anim->release();
			delete[] m_Anims[i].boneids;
		}
	}

	void ModelData::ReleaseSkeleton()
	{
		OGRE_RELEASE(m_pSkeleton);
	}

	const MeshData *ModelData::getMeshByName(const FixedString &name)const 
	{
		for(size_t i=0; i<m_Meshes.size(); i++)
		{
			if(m_Meshes[i]->m_Name == name) return m_Meshes[i];
		}

		return NULL;
	}

	void ModelData::addAnimation(AnimationData *panim)
	{
		for(size_t i=0; i<m_Anims.size(); i++)
		{
			if(m_Anims[i].anim == panim) return;
		}
		if(panim == NULL) return;
		ModelAnimData animdata;
		animdata.nbonetrack = panim->m_BoneTracks.size();
		animdata.boneids = new short[animdata.nbonetrack];
		animdata.anim = panim;
		panim->addRef();

		for(size_t i=0; i<animdata.nbonetrack; i++)
		{
			BoneTrack *pbone = panim->m_BoneTracks[i];
			if(m_pSkeleton != NULL && pbone != NULL){
				animdata.boneids[i] = short(m_pSkeleton->findBoneID(pbone->m_BoneName));
			}
		}

		m_Anims.push_back(animdata);
	}

	void ModelData::getAllSequence(vector<SequenceDesc>&seq_array)
	{
		seq_array.resize(0);
		for(size_t i=0; i<m_Anims.size(); i++)
		{
			AnimationData *panimdata = m_Anims[i].anim;
			seq_array.insert(seq_array.end(), panimdata->m_Sequences.begin(), panimdata->m_Sequences.end());
		}
	}

	BoneTrack* ModelData::getBoneTrack(int seq_id, FixedString boneName)	{
		if (!m_pSkeleton){
			return NULL;
		}
		int boneId = m_pSkeleton->findBoneID(boneName);
		return getBoneTrack(seq_id, boneId);
	}

	BoneTrack* ModelData::getBoneTrack(int seq_id, int boneId)	{
		if (boneId < 0) {
			return NULL;
		}
		for (int i = 0; i < m_Anims.size(); i++) {
			if (!m_Anims[i].anim)
				continue;
			for (int j = 0; j < m_Anims[i].anim->m_Sequences.size(); j++) {
				if (m_Anims[i].anim->getNumBoneTrack() && m_Anims[i].anim->m_Sequences[j].id == seq_id) {
					BoneTrack *pBoneTrack = m_Anims[i].anim->getBoneTrack(boneId);
					return pBoneTrack;
				}
			}
		}
		return NULL;
	}

	void ModelData::_serialize(Archive &ar, int version)
	{
		ar << m_Meshes;
		ar << m_pSkeleton;

		if(version==100 && ar.isLoading())
		{
			vector<SkeletonAnimData *>anims;
			ar << anims;

			for(size_t i=0; i<anims.size(); i++)
			{
				AnimationData *panimdata = new AnimationData;
				SkeletonAnimData *psrc = anims[i];

				panimdata->m_BoneTracks = psrc->m_TrackArray;
				panimdata->m_Sequences = psrc->m_Sequences;
				panimdata->m_TriggerArray = psrc->m_TriggerArray;

				psrc->m_TrackArray.clear();
				addAnimation(panimdata);
				panimdata->release();
			}
		}
		else if(ar.isLoading())
		{
			vector<AnimationData *>anims;
			ar << anims;

			for(size_t i=0; i<anims.size(); i++)
			{
				addAnimation(anims[i]);
				anims[i]->release();
			}
		}
		else
		{
			vector<AnimationData *>anims;
			for(size_t i=0; i<m_Anims.size(); i++)
			{
				if(m_Anims[i].anim){
					anims.push_back(m_Anims[i].anim);
				}
			}
			ar << anims;
		}

		ar << m_pBspData;
		ar << m_Bounding;
		ar.serializeRawArray(m_Anchors);
	}

	void ModelData::buildAllCunsomData()
	{
		vector<AnimationData *> anims;
		for(size_t i=0; i<m_Anims.size(); i++)
		{
			if(m_Anims[i].anim) 
			{
				if (m_pSkeleton)
				m_Anims[i].anim->reCreateByBoneChange(m_pSkeleton->getBoneNameTab());
				anims.push_back(m_Anims[i].anim);
			}
		}
		for(size_t i=0; i<m_Anims.size(); i++)
		{
			m_Anims[i].anim->release();
			delete[] m_Anims[i].boneids;
		}
		m_Anims.clear();

		for(size_t i=0; i<anims.size(); i++)
		{
			addAnimation(anims[i]);
		}
	}

	void ModelData::addCustomSequenceID(int id, AnimPlayMode loopmode)
	{
		for (int i = 0; i<m_Anims.size(); i++)
		{
			if (!m_Anims[i].anim)
				continue;
			for (int j = 0; j<m_Anims[i].anim->m_Sequences.size(); j++)
			{
				if (m_Anims[i].anim->m_Sequences[j].id == id)
				{
					return;
				}
			}
		}
		Ogre::AnimationData* anim = new Ogre::AnimationData();
		Ogre::SequenceDesc desc;
		desc.id = id;
		desc.time_start = 0;
		desc.time_end = 0;
		desc.loopmode = loopmode;
		anim->m_Sequences.push_back(desc);
		addAnimation(anim);
	}

	void ModelData::addCustomSequenceIDWithCopiedBones(int id, AnimPlayMode loopmode, int startTime, int endTime)
	{
		for (int i = 0; i < m_Anims.size(); i++)
		{
			if (!m_Anims[i].anim)
				continue;
			for (int j = 0; j < m_Anims[i].anim->m_Sequences.size(); j++)
			{
				if (m_Anims[i].anim->m_Sequences[j].id == id)
				{
					return;
				}
			}
		}
		Ogre::AnimationData* anim = new Ogre::AnimationData();
		Ogre::SequenceDesc desc;
		desc.id = id;
		desc.time_start = startTime;
		desc.time_end = endTime;
		desc.loopmode = loopmode;
		anim->m_Sequences.push_back(desc);

		Vector3 defaultTranslation(0.f);
		Quaternion defaultRotation(0, 0, 0, 0);
		Vector3 defaultScale(1.f);
		for (int i = 0; i < m_Anims.size(); i++)
		{
			if (!m_Anims[i].anim)
				continue;
			int length = 0;
			if (length = m_pSkeleton->getNumBone()){
				for (int j = 0; j < length; ++j) 
				{
					BoneTrack *ptrack = new BoneTrack();
					ptrack->setBoneInfo(m_pSkeleton->getIthBone(j)->m_Name, j);
					anim->addBoneTrack(ptrack);
				}
				break;
			}
		}
		addAnimation(anim);
	}

	void ModelData::setCustomSequenceEndtime(int id, int endtime)
	{
		for (int i = 0; i<m_Anims.size(); i++)
		{
			if (!m_Anims[i].anim)
				continue;
			for (int j = 0; j<m_Anims[i].anim->m_Sequences.size(); j++)
			{
				if (m_Anims[i].anim->m_Sequences[j].id == id)
				{
					m_Anims[i].anim->m_Sequences[j].time_end = endtime;
				}
			}
		}
	}

	void ModelData::addCustomBone(FixedString name, FixedString father_name, const Vector3 &scale, const Quaternion &rot, const Vector3 &translate)
	{
		if (!m_pSkeleton)
		{
			m_pSkeleton = new SkeletonData();
		}
		if (m_pSkeleton)
		{
			if (m_pSkeleton->addBone(name, father_name, scale, rot, translate))
			{
				for (int i = 0; i<m_Anims.size(); i++)
				{
					if (!m_Anims[i].anim)
						continue;
					for (int j = 0; j<m_Anims[i].anim->m_Sequences.size(); j++)
					{
						if (m_Anims[i].anim->m_Sequences[j].id >= 0)
						{
							BoneTrack *ptrack = new BoneTrack();
							ptrack->setBoneInfo(name, m_pSkeleton->findBoneID(name));
							m_Anims[i].anim->addBoneTrack(ptrack);
						}
					}
				}
				buildAllCunsomData();
			}
		}
	}

	void ModelData::setCustomBone(FixedString name, const Vector3 &scale, const Quaternion &rot, const Vector3 &translate)
	{
		if (!m_pSkeleton)
		{
			m_pSkeleton = new SkeletonData();
		}
		if (m_pSkeleton)
		{
			m_pSkeleton->setBone(name, scale, rot, translate);
		}
	}

	void ModelData::setCustomKeyFrame(int seq_id, FixedString boneName, const uint tick, Vector3 &translate, Quaternion &rotate, Vector3 &scale)
	{
		if (!m_pSkeleton)
		{
			return;
		}
		int boneid = m_pSkeleton->findBoneID(boneName);
		if (boneid < 0)
		{
			return;
		}
		for (int i = 0; i<m_Anims.size(); i++)
		{
			if (!m_Anims[i].anim)
				continue;
			for (int j = 0; j<m_Anims[i].anim->m_Sequences.size(); j++)
			{
				if (m_Anims[i].anim->getNumBoneTrack() && m_Anims[i].anim->m_Sequences[j].id == seq_id)
				{
					BoneTrack *ptrack = m_Anims[i].anim->getBoneTrack(boneid);
					if (ptrack)
					{
						ptrack->setKeyFrame(seq_id, translate, rotate, scale, tick);
						if (m_bAddEndKey)
						{
							m_bAddEndKey = false;
							if (tick != m_nEndKeyTime)
							{
								ptrack->delKeyFrame(seq_id, m_nEndKeyTime);
							}
						}
					}
				}
			}
		}
	}

	void ModelData::resetAllCustomKeyFrameToZero(int seq_id){
		if (!m_pSkeleton){
			return;
		}
		const int boneCount = m_pSkeleton->getNumBone();
		for (int boneId = 0; boneId < boneCount; ++boneId){
			resetAllCustomKeyFrameToZero(seq_id, boneId);
		}
	}

	void ModelData::resetAllCustomKeyFrameToZero(int seq_id, int boneId){
		BoneTrack* boneTrack = getBoneTrack(seq_id, boneId);
		if (!boneTrack){
			return;
		}
		boneTrack->clearTranslationKeyFrame();
		boneTrack->clearRotationKeyFrame();
		Vector3 defaultTranslation(0.f);
		Quaternion defaultRotation(0, 0, 0, 0);
		Vector3 defaultScale(1.f);
		boneTrack->insertKeyFrame(seq_id, defaultTranslation, defaultRotation, defaultScale, 0);
	}

	bool ModelData::getCustomKeyFrame(int seq_id, FixedString boneName, const uint tick, Vector3 &translate, Quaternion &rotate, Vector3 &scale, bool loop)
	{
		if (!m_pSkeleton)
		{
			return false;
		}
		int boneid = m_pSkeleton->findBoneID(boneName);
		if (boneid < 0)
		{
			return false;
		}
		for (int i = 0; i<m_Anims.size(); i++)
		{
			if (!m_Anims[i].anim)
				continue;
			for (int j = 0; j<m_Anims[i].anim->m_Sequences.size(); j++)
			{
				if (m_Anims[i].anim->getNumBoneTrack() && m_Anims[i].anim->m_Sequences[j].id == seq_id)
				{
					int boneindex = -1;
					for (int c = 0; c<m_Anims[i].nbonetrack; c++)
					{
						if (m_Anims[i].boneids[c] == boneid)
						{
							boneindex = c;
							break;
						}
					}
					if (boneindex < 0)
						continue;
					BoneTrack *ptrack = m_Anims[i].anim->getBoneTrack(boneindex);
					if (ptrack)
					{
						int seq_index = m_Anims[i].anim->getSequenceIndex(seq_id);
						return ptrack->getValue(seq_index, tick, translate, rotate, scale, loop);
					}
				}
			}
		}
		return false;
	}

	void ModelData::insertCustomKeyFrame(int seq_id, FixedString boneName, const uint tick, Vector3 &translate, Quaternion &rotate, Vector3 &scale)	{
		BoneTrack* boneTrack = getBoneTrack(seq_id, boneName);
		if (!boneTrack) {
			return;
		}
		boneTrack->insertKeyFrame(seq_id, translate, rotate, scale, tick);
		if (!m_bAddEndKey){
			return;
		}
		m_bAddEndKey = false;
		if (tick == m_nEndKeyTime) {
			return;
		}
		boneTrack->delKeyFrame(seq_id, m_nEndKeyTime);
	}

	void ModelData::setCustomKeyFrames(int seq_id, FixedString boneName, size_t nkey, const uint *tick, Vector3 *translate, Quaternion *rotate, Vector3 *scale)
	{
		if (!m_pSkeleton)
		{
			return;
		}
		int boneid = m_pSkeleton->findBoneID(boneName);
		if (boneid < 0)
		{
			return;
		}
		for (int i = 0; i<m_Anims.size(); i++)
		{
			if (!m_Anims[i].anim)
				continue;
			for (int j = 0; j<m_Anims[i].anim->m_Sequences.size(); j++)
			{
				if (m_Anims[i].anim->getNumBoneTrack() && m_Anims[i].anim->m_Sequences[j].id == seq_id)
				{
					BoneTrack *ptrack = m_Anims[i].anim->getBoneTrack(boneid);
					if (ptrack)
					{
						ptrack->setKeyFrames(0, nkey, tick, translate, rotate, scale);
						if (nkey && m_Anims[i].anim->m_Sequences[j].time_end > tick[nkey-1])
						{
							ptrack->insertKeyFrame(0, translate[nkey-1], rotate[nkey-1], scale[nkey-1], m_Anims[i].anim->m_Sequences[j].time_end);
							m_bAddEndKey = true;
							m_nEndKeyTime = m_Anims[i].anim->m_Sequences[j].time_end;
						}
					}
					//m_Anims[i].anim->m_Sequences[j].time_end = tick[nkey - 1];
					break;
				}
			}
		}
	}

	void ModelData::delCustomKeyFrame(int seq_id, FixedString boneName, const uint tick){
		BoneTrack* boneTrack = getBoneTrack(seq_id, boneName);
		if (!boneTrack) {
			return;
		}
		boneTrack->delKeyFrame(0, tick);
		if (!m_bAddEndKey){
			return;
		}
		m_bAddEndKey = false;
		if (tick == m_nEndKeyTime){
			return;
		}
		boneTrack->delKeyFrame(seq_id, m_nEndKeyTime);
	}

	void ModelData::delRotationKeyFrame(int seq_id, FixedString boneName)
	{
		if (!m_pSkeleton)
		{
			return;
		}
		int boneid = m_pSkeleton->findBoneID(boneName);
		if (boneid < 0)
		{
			return;
		}
		for (int i = 0; i<m_Anims.size(); i++)
		{
			if (!m_Anims[i].anim)
				continue;
			for (int j = 0; j<m_Anims[i].anim->m_Sequences.size(); j++)
			{
				if (m_Anims[i].anim->getNumBoneTrack() && m_Anims[i].anim->m_Sequences[j].id == seq_id)
				{
					BoneTrack *ptrack = m_Anims[i].anim->getBoneTrack(boneid);
					if (ptrack)
					{
						ptrack->clearRotationKeyFrame();
					}
					break;
				}
			}
		}
	}
	
	void ModelData::delCustomBone(FixedString name)
	{
		if (m_pSkeleton)
		{
			m_pSkeleton->delBone(name);
			buildAllCunsomData();
		}
	}
	
	void ModelData::changeCustomBoneName(FixedString name, FixedString newname)
	{
		if (m_pSkeleton)
		{
			int oldbonid = m_pSkeleton->findBoneID(name);
			m_pSkeleton->changeBoneName(name, newname);
			for (int i = 0; i<m_Anims.size(); i++)
			{
				if (!m_Anims[i].anim)
					continue;
				for (int j = 0; j<m_Anims[i].anim->m_Sequences.size(); j++)
				{
					if (m_Anims[i].anim->getNumBoneTrack())
					{
						BoneTrack *ptrack = m_Anims[i].anim->getBoneTrack(oldbonid);
						if (ptrack)
						{
							ptrack->m_BoneName = newname;
						}
					}
				}
			}
			buildAllCunsomData();
		}
	}

	SequenceDesc ModelData::findSequenceDesc(int seq_id)
	{
		for (int i = 0; i < m_Anims.size(); ++i){
			vector<SequenceDesc> seqs = m_Anims[i].anim->m_Sequences;
			int size = seqs.size();
			for (int j = 0; j < size; ++j){
				if (seqs[j].id == seq_id){
					return seqs[j];
				}
			}
		}
		return SequenceDesc();
	}

	inline int getInBoneNameIndex(vector<FixedString> &boneName, FixedString &name_)
	{
		for (int i = 0; i<boneName.size(); i++)
		{
			if (strcmp(name_.c_str(), boneName[i].c_str()) == 0)
			{
				return i;
			}
		}
		return -1;
	}

	void Direction2PitchYaw(float *yaw, float *pitch, const Ogre::Vector3 &dir)
	{
		if(yaw)
		{
			*yaw = ATan2(-dir.x, -dir.z);
		}

		if(pitch)
		{
			float r = Sqrt(dir.x*dir.x + dir.z*dir.z);
			*pitch = -ATan2(dir.y, r);
		}
	}

	void ModelData::getBoneRelationship()
	{
		if (!m_pSkeleton)
		{
			return;
		}
		m_BoneRelationshipMap.clear();
		const int bonenum = m_pSkeleton->getNumBone();
		for (int m = 0; m < bonenum; m++)
		{
			BoneData *parentBone = m_pSkeleton->getIthBone(m);
			//LOG_INFO("getBoneRelationship(): parentBone->m_Name = %s", parentBone->m_Name.c_str());
			for (int n = bonenum - 1; n >= 0; --n)
			{
				BoneData *childBone = m_pSkeleton->getIthBone(n);
				if (parentBone->m_ID == childBone->m_FatherID)
				{
					m_BoneRelationshipMap[parentBone->m_ID].push_back(childBone->m_ID);
					//LOG_INFO("childBone->m_Name = %s", childBone->m_Name.c_str());
				}
			}
		}
	}

	bool ModelData::getCustomKeyFrameEx(int seq_id, FixedString boneName, const uint tick, Vector3 &translate, Quaternion &rotate, Vector3 &scale, bool loop)
	{
		//Vector3 translate;
		//Quaternion rotate;
		//Vector3 scale;
		int boneid =  m_pSkeleton->findBoneID(boneName);
		BoneData *bonedata = m_pSkeleton->getIthBone(boneid);
		if (getCustomKeyFrame(seq_id, bonedata->m_Name, 100, translate, rotate, scale, true) == false)
		{
			translate = bonedata->m_OriginTM.getTranslate(); 
			Matrix4 matScale;
			bonedata->m_OriginTM.getScale(matScale);
			scale.x = matScale._11;
			scale.y = matScale._22;
			scale.z = matScale._33;

			Matrix4 tm = bonedata->m_OriginTM;
			rotate.setMatrix(tm);
		}
		return true;
	}

	bool ModelData::isForeFathers(vector<FixedString> &boneName, BoneData *bonedata_s, BoneData *bonedata_f)
	{
		int forefatherid = bonedata_f->m_ID;
		int sonnext_father = bonedata_s->m_FatherID;
		while (sonnext_father >= 0)
		{
			if (sonnext_father == forefatherid)
			{
				return true;
			}

			for (int i = 0; i<boneName.size(); i++)
			{
				if (strcmp(boneName[i].c_str(), m_pSkeleton->getIthBone(sonnext_father)->m_Name.c_str()) == 0)
				{
					return false;
				}
			}
			sonnext_father = m_pSkeleton->getIthBone(sonnext_father)->m_FatherID;
		}
		return false;
	}

	float ModelData::getAngle(const Vector3& v1, const Vector3& v2){
		if (isZeroVector(v1) || isZeroVector(v2)){
			return 0;
		}
		Vector3 cp = CrossProduct(v1, v2);
		float angle = ACos(DotProduct(v1, v2) / (v1.length() * v2.length()));
		if (cp.z < 0) {
			angle = 360 - angle;
		}
		return angle;
	}

	void  ModelData::getCustomKeyFrameByArData(
		vector<FixedString> &boneName,
		vector<Vector3> &translate,
		vector<Quaternion> &rotate,
		vector<Vector3> &scale,
		vector<float> &confidence,
		vector<FixedString> &boneName_ret,
		vector<Vector3> &translate_ret,
		vector<Quaternion> &rotate_ret,
		vector<Vector3> &scale_ret,
		vector<float> &confidence_ret
	){
		const int readSeqID = m_iARReadSeqID;
		int bonenum = m_pSkeleton->getNumBone();
		struct key_pos
		{
			Vector3 translate;
			Quaternion rotate;
			Vector3 scale;
			float confidence;

			Vector3 translate_;
			Quaternion rotate_;
			Vector3 scale_;
			float confidence_;
			int boneid;
		};
		std::map<std::string, key_pos> bone_key; 
		for (int i = 0; i<boneName.size(); i++)
		{
			key_pos pos;
			pos.rotate = rotate[i];
			pos.translate = translate[i];
			pos.scale = scale[i];
			pos.confidence = confidence[i];
			pos.rotate_ = rotate[i];
			pos.translate_ = translate[i];
			pos.scale_ = scale[i];
			pos.confidence_ = confidence[i];
			pos.boneid = -1;
			bone_key[boneName[i].c_str()] = pos;
		}

		for (int i = 0; i<bonenum; i++)
		{
			BoneData *bonedata = m_pSkeleton->getIthBone(i);
			if (bonedata)
			{
				Vector3 translate;
				Quaternion rotate;
				Vector3 scale;
				if (getCustomKeyFrame(readSeqID, bonedata->m_Name, 100, translate, rotate, scale, true))
				{
					scale.setElement(1, 1, 1);
					bonedata->m_OriginTM.makeSRTMatrix(scale, rotate, translate);
				}
			}
		}
		std::map<int, std::list<int>> boneid_id_sons_ext(m_BoneRelationshipMap);
		std::map<int, int> father_use;
		std::map<std::string, int> bone_son_must_check;
		//bone_son_must_check["Bip01 R Clavicle"] = 1;
		//bone_son_must_check["Bip01 Spine"] = 1;

		//收集华为对应avartar的A-B连接的点
		for (int i = 0; i<boneName.size(); i++)
		{
			std::map<int, std::list<int>> boneid_id_sons;
			for (int m = 0;	m<bonenum; m++)
			{
				//父节点
				BoneData *bonedata = m_pSkeleton->getIthBone(m);
				//找到内存中父节点的数据
				if (strcmp(bonedata->m_Name.c_str(), boneName[i].c_str()) == 0)
				{
					for (int n = 0;	n<bonenum; n++)
					{
						//子节点
						BoneData *bonedata_ = m_pSkeleton->getIthBone(n);
						//子节点在参数中的索引
						int index = getInBoneNameIndex(boneName, bonedata_->m_Name);
						if (bonedata_->m_FatherID == bonedata->m_ID && index>=0) //收集到一个
						{
							//Vector3 translate = translate_ret[index] - translate_ret[i];
							//Matrix4 tm = bonedata_->m_OriginTM;
							//子节点的key_pos
							key_pos &pos = bone_key[bonedata_->m_Name.c_str()];
							//子节点减去当前使用i遍历的父节点，即由父节点指向子节点的向量
							pos.translate_ = translate[index] - translate[i];
							//保存子节点ID
							pos.boneid = bonedata_->m_ID;

							if (father_use.find(bonedata_->m_FatherID) == father_use.end())
							{
								father_use[bonedata_->m_FatherID] = 1;
							}
							else
							{
								father_use[bonedata_->m_FatherID]++;
								//father_use[bonedata_->m_FatherID] = 1;
							}
						}
					}
				}
			}
		}

		Vector3 v14_8 = translate[8] - translate[14];
		Vector3 v14_11 = translate[11] - translate[14];
		Vector3 v1_2 = translate[2] - translate[1];
		Vector3 v1_5 = translate[5] - translate[1];
		Normalize(v14_8);
		Normalize(v14_11);
		Normalize(v1_2);
		Normalize(v1_5);
		float bodyAngle = 0.f;
		float armsAngle = 0.f;
		//正面
		if (translate[8].x < translate[14].x && translate[11].x > translate[14].x) {
			//LOG_INFO("front");
			//rotate_ret[bip01Index].rotate(yAxis, 0);
			//bodyAngle = 0.f;
		}
		//背面
		else if (translate[8].x > translate[14].x && translate[11].x < translate[14].x) {
			//LOG_INFO("back");
			//bodyAngle = -180.f;
		}
		//向左侧面
		else if (translate[8].x < translate[14].x && translate[11].x < translate[14].x) {
			//LOG_INFO("left");
			//bodyAngle = -90.f;
		}
		//向右侧面
		else if (translate[8].x > translate[14].x && translate[11].x > translate[14].x) {
			//LOG_INFO("right");
			//bodyAngle = 90.f;
		}
		bodyAngle = (getAngle(m_RightHipBone, v14_8) + getAngle(m_LeftHipBone, v14_11)) / 2.f;
		armsAngle = (getAngle(m_RightShoulder, v1_2) + getAngle(m_LeftShoulder, v1_5)) / 2.f;
		LOG_INFO("a = %f", bodyAngle);
		LOG_INFO("b = %f", bodyAngle);
		if (bodyAngle >= 0.00001f) {
			Vector3 t;
			Vector3 s;
			Quaternion r;
			int boneId = m_pSkeleton->findBoneID("场景根");
			BoneData* boneData = m_pSkeleton->getIthBone(boneId);
			getCustomKeyFrameEx(readSeqID, boneData->m_Name, 100, t, r, s, true);
			Quaternion q = Quaternion::Euler(0, bodyAngle, 0);
			r = q;
			boneData->m_OriginTM.makeSRTMatrix(s, r, t);
		}
		if (armsAngle >= 0.00001f) {
			Vector3 t;
			Vector3 s;
			Quaternion r;
			int boneId = m_pSkeleton->findBoneID("Bip01 Neck");
			BoneData* boneData = m_pSkeleton->getIthBone(boneId);
			getCustomKeyFrameEx(readSeqID, boneData->m_Name, 100, t, r, s, true);
			Quaternion q = Quaternion::Euler(0, armsAngle, 0);
			r = q;
			//boneData->m_OriginTM.makeSRTMatrix(s, r, t);
		}

		//引入boneid_id_sons_ext是为了保证先算父节点
		for (int i = 0; i<bonenum; i++)
		{
			BoneData *bonedata = m_pSkeleton->getIthBone(i);
			//从根节点开始遍历
			if (bonedata && bonedata->m_FatherID < 0)
			{
				//boneid_id_sons_ext
				int boneid_id_f = bonedata->m_ID;
				while (boneid_id_f >= 0)
				{
					BoneData *bonedata = m_pSkeleton->getIthBone(boneid_id_f);
					Vector3 translate; //B
					Quaternion rotate;
					Vector3 scale;
					float confidence = 1.f;
					getCustomKeyFrameEx(readSeqID, bonedata->m_Name, 100, translate, rotate, scale, true);
					//参数中含有该骨骼的AR数据
					do
					{
						if (bone_key.find(bonedata->m_Name.c_str())!= bone_key.end() && bone_key[bonedata->m_Name.c_str()].boneid >= 0 && 
							(
								true 
								//||
								//false
								//strcmp(bonedata->m_Name.c_str(), "Bip01 R Hand") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 L Hand") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 R Forearm") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 L Forearm") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 R UpperArm") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 L UpperArm") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 R Clavicle") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 L Clavicle") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 R Foot") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 L Foot") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 R Calf") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 L Calf") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 R Thigh") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 L Thigh") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Head") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Neck") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 Spine1") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 Spine") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01") == 0
								//|| strcmp(bonedata->m_Name.c_str(), "Bip01 Pelvis") == 0
								)
								&& ((father_use[bonedata->m_FatherID] == 1) || (bone_son_must_check.find(bonedata->m_Name.c_str()) != bone_son_must_check.end()))
							)
						{
							Vector3 translate2 = translate;
							key_pos pos = bone_key[bonedata->m_Name.c_str()];
							confidence = pos.confidence;
							Normalize(pos.translate_);
							float length = translate2.length();
							if (length < 0.00001f)
							{
								break;
							}
							pos.translate_ *= translate2.length();
							// LOG_INFO("getCustomKeyFrameByArData(): pos.translate_ = (%f, %f, %f)", pos.translate_.x, pos.translate_.y, pos.translate_.z);
							//translate = pos.translate_;
							//遍历的骨骼的基向量组矩阵
							Matrix4 tm_ = bonedata->m_OriginTM;
							int fatherId = bonedata->m_FatherID;  //bonedata->m_FatherID就是A	   bonedata就是B
							if (fatherId >= 0)
							{
								BoneData * bonefather = m_pSkeleton->getIthBone(fatherId);
								//省略左乘的矩阵：正交基组
								Matrix4 tm__ = bonefather->m_OriginTM;
								fatherId = bonefather->m_FatherID;
								while (fatherId >= 0)
								{
									bonefather = m_pSkeleton->getIthBone(fatherId);
									tm__ *= bonefather->m_OriginTM;
									fatherId = bonefather->m_FatherID;
								}
								//tm_ *= tm__;
								//至此，tm__	为世界坐标
								Matrix4 tm_t;
								//tm__.getTranslate()为该骨骼的偏移在世界坐标系下的偏移值，加上AR的偏移，取得新的世界坐标值
								tm_t.makeSRTMatrix(scale, rotate, tm__.getTranslate() + pos.translate_); 
								//反乘进去，得到在父节点坐标系下的偏移值
								tm_t *= tm__.inverse();
								Vector3 translate_ = tm_t.getTranslate();  // B-   translate变量是B
								//LOG_INFO("getCustomKeyFrameByArData(): bonedata->m_Name.c_str() = %s", bonedata->m_Name.c_str());
								//LOG_INFO("getCustomKeyFrameByArData(): B  = (%f, %f, %f)", translate.x, translate.y, translate.z);
								//LOG_INFO("getCustomKeyFrameByArData(): B' = (%f, %f, %f)", translate_.x, translate_.y, translate_.z);

								Vector3 translate_0 = translate + (translate_ - translate) / 2.0;
								Normalize(translate_0);
								Quaternion rotate_temp;
								rotate_temp.setAxisAngle(translate_0, 180);
								Quaternion rotate_temp1;
								Vector3 translate_1 = translate;
								Normalize(translate_1);
								rotate_temp1.setAxisAngle(translate_1, -180);
								BoneData *bonedata_f = m_pSkeleton->getIthBone(bonedata->m_FatherID);
								Vector3 translate__;
								Quaternion rotate__;
								Vector3 scale__;
								getCustomKeyFrameEx(readSeqID, bonedata_f->m_Name, 100, translate__, rotate__, scale__, true);
								//Quaternion rotate_temp = Quaternion::XYZAngleToQuat(pitch, yaw, 0);
								rotate_temp *= rotate__;
								rotate_temp1 *= rotate_temp;
								//算出A的旋转并且赋值给  bonedata_f->m_OriginTM BoneData *bonedata_f = m_pSkeleton->getIthBone(bonedata->m_FatherID); 
								bonedata_f->m_OriginTM.makeSRTMatrix(scale__, rotate_temp1, translate__); 
								for (int n = 0; n < rotate_ret.size(); n++)
								{
									if (strcmp(boneName_ret[n].c_str(), bonedata_f->m_Name.c_str()) == 0)
									{
										rotate_ret[n] = rotate_temp1;//重新赋值A的旋转
										break;
									}
								}
							}//if (fatherId >= 0)
						}//if (bone_key.find(bonedata->m_Name.c_str())!= bone_key.end() && bone_key[bonedata->m_Name.c_str()].boneid >= 0 && (father_use[bonedata->m_FatherID] == 1))
					}//do_while
					while(0);
					boneName_ret.push_back(bonedata->m_Name);
					translate_ret.push_back(translate);
					rotate_ret.push_back(rotate);
					scale_ret.push_back(scale);
					confidence_ret.push_back(confidence);

					//boneid_id_f = bonedata->m_ID;
					//深度遍历
					while (boneid_id_f >= 0)
					{
						if (boneid_id_sons_ext[boneid_id_f].size())
						{
							int id_ = boneid_id_f;
							boneid_id_f = boneid_id_sons_ext[id_].front();
							boneid_id_sons_ext[id_].pop_front();
							break;
						}
						else //已无子节点，返回上层，遍历邻居结点
						{
							BoneData *bonedata_f = m_pSkeleton->getIthBone(boneid_id_f);
							boneid_id_f = bonedata_f->m_FatherID;
						}
					}
				}//boneid_id_f >= 0
			}//if (bonedata && bonedata->m_FatherID < 0)
		}//for (int i = 0; i<bonenum; i++)
	}//function
}//Ogre