
#ifndef __ModelData_H__
#define __ModelData_H__

#include "OgreResource.h"
#include "OgreAnimationData.h"
#include "OgreMesh.h"
#include "OgreQuaternion.h"
using Ogre::BoneTrack;
using std::vector;
namespace Ogre
{
	class _OgreExport BSPData : public Resource
	{
		DECLARE_RTTI(BSPData)
	public:
		enum MTL_TYPE
		{
			MTL_NORMAL = 0,
			MTL_WALK,
			MTL_COLLIDE,
		};
		struct SufaceMtl
		{
			MTL_TYPE type;
		};
	public:
		BSPData()
		{
		}

		BSPData(const BSPData &rhs);

		virtual void _serialize(Archive &ar, int version);

		vector<Vector3> m_Vertex;

		//Index值为每个面4个，前三个是面的三个顶点索引，第四个值为该面的材质索引值，目前未使用
		vector<unsigned short> m_Index;
		vector<SufaceMtl> m_SufaceMtl;
	};

	struct ModelAnchor
	{
		int boneid;
		int anchorid;
	};

	struct ModelAnimData
	{
		AnimationData *anim;
		short *boneids;
		size_t nbonetrack;
	};

	struct SequenceDesc;
	class _OgreExport ModelData : public Resource
	{
		DECLARE_RTTI(ModelData)
	public:
		ModelData();
		~ModelData();

		SkeletonData *getSkeletonData()
		{
			return m_pSkeleton;
		}
		
		//单独释放骨骼数据，针对avatar
		void ReleaseSkeleton();

		size_t getNumMesh()
		{
			return m_Meshes.size();
		}

		const MeshData *getMeshByName(const FixedString &name)const;
		MeshData *getIthMesh(size_t i) 
		{
			assert(i < m_Meshes.size());
			return m_Meshes[i];
		}

		SubMeshData *getSubMesh(size_t imesh, size_t isubmesh)
		{
			assert(isubmesh < getIthMesh(imesh)->m_SubMeshes.size());
			return getIthMesh(imesh)->m_SubMeshes[isubmesh];
		}

		void addMeshData(MeshData *pmesh)
		{
			m_Meshes.push_back(pmesh);
		}

		void addAnimation(AnimationData *panim);

		size_t getNumAnim()
		{
			return m_Anims.size();
		}

		AnimationData *getAnimation(size_t i)
		{
			return m_Anims[i].anim;
		}

		const short *getBoneIDs(size_t i)
		{
			return m_Anims[i].boneids;
		}

		void removeAnimation(size_t i)
		{
			assert(i < m_Anims.size());
			m_Anims.erase(m_Anims.begin() + i);
		}

		void getAllSequence(vector<SequenceDesc>&seq_array);
		void buildAllCunsomData();
		void addCustomSequenceID(int id, AnimPlayMode loopmode);
		void addCustomSequenceIDWithCopiedBones(int id, AnimPlayMode loopmode, int startTime, int endTime);
		void setCustomSequenceEndtime(int id, int endtime);
		void addCustomBone(FixedString name, FixedString father_name, const Vector3 &scale, const Quaternion &rot, const Vector3 &translate);
		void setCustomBone(FixedString name, const Vector3 &scale, const Quaternion &rot, const Vector3 &translate);
		void delCustomBone(FixedString name);
		void changeCustomBoneName(FixedString name, FixedString newname);
		void setCustomKeyFrame(int seq_id, FixedString boneName, const uint tick, Vector3 &translate, Quaternion &rotate, Vector3 &scale);
		void resetAllCustomKeyFrameToZero(int seq_id);
		void resetAllCustomKeyFrameToZero(int seq_id, int boneId);
		bool getCustomKeyFrame(int seq_id, FixedString boneName, const uint tick, Vector3 &translate, Quaternion &rotate, Vector3 &scale, bool loop);
		bool getCustomKeyFrameEx(int seq_id, FixedString boneName, const uint tick, Vector3 &translate, Quaternion &rotate, Vector3 &scale, bool loop);
		void insertCustomKeyFrame(int seq_id, FixedString boneName, const uint tick, Vector3 &translate, Quaternion &rotate, Vector3 &scale);
		void setCustomKeyFrames(int seq_id, FixedString boneName, size_t nkey, const uint *tick,Vector3 *translate, Quaternion *rotate, Vector3 *scale);
		void delCustomKeyFrame(int seq_id, FixedString boneName, const uint tick);
		void delRotationKeyFrame(int seq_id, FixedString boneName);
		void getBoneRelationship();
		bool isForeFathers(vector<FixedString> &boneName, BoneData *bonedata_s, BoneData *bonedata_f);
		static float getAngle(const Vector3& v1, const Vector3& v2);
		/*
		 * 把ar截获的数据(绝对值) 转化成 所有骨骼对应的数据(已经转化为相对值)
		 * ar截获的数据(绝对值) 入口参数要带骨骼名数组 和 数据数组
		 * 如果有一个骨骼链 从根骨骼到最末端骨骼都没有一个ar传入的骨骼名。 那么将不会返回这几个骨骼相关数据。
		 */
		void getCustomKeyFrameByArData(
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
		);

		SequenceDesc findSequenceDesc(int seq_id);
	private:
		BoneTrack* getBoneTrack(int seq_id, FixedString boneName);
		BoneTrack* getBoneTrack(int seq_id, int boneId);
		virtual void _serialize(Archive &ar, int version);

	public:
		vector<MeshData *>m_Meshes;
		SkeletonData *m_pSkeleton;
		vector<ModelAnimData>m_Anims;
		BSPData *m_pBspData;
		BoxBound m_Bounding;
		vector<ModelAnchor>m_Anchors; 
		std::map<int, std::list<int>> m_BoneRelationshipMap;
		Vector3 m_RightHipBone;
		Vector3 m_LeftHipBone;
		Vector3 m_RightShoulder;
		Vector3 m_LeftShoulder;
		int m_iARReadSeqID;
		int  m_nEndKeyTime;
		bool m_bAddEndKey;
	};
}

#endif
