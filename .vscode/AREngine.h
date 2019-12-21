#ifndef __AR_ENGINE__H__
#define __AR_ENGINE__H__
#include "OgrePlatform.h"
#include "OgreSingleton.h"
#include "OgreModel.h"
#include "OgreModelData.h"
#include "OgreFixedString.h"
#include "OgreVector3.h"
#include "OgreQuaternion.h"
#include "OgreAnimTrackBone.h"
#include "actors/ActorBody.h"
#include "UILib/ui_layoutframe.h"
#include "DecoratorPattern.h"
using Ogre::Vector3;
using Ogre::Quaternion;
using Ogre::Model;
using Ogre::BoneTrack;
using Ogre::ModelData;
using Ogre::Matrix4;
using Ogre::FixedString;
using Ogre::Singleton;
using std::vector;
using std::string;
//===================================================IBoneNamesArray start===================================================
#define DECLARE_AND_IMPLEMENT_GET_BONE_NAMES(classname) \
public:\
	const char* get(int index) {\
		return ARRAY_BONE_NAMES[index];\
	}\
	int length() {\
		return sizeof(ARRAY_BONE_NAMES) / sizeof(FixedString);\
	}

class IBoneNamesArray{
public:
	virtual const char* get(int index) = 0;
	virtual int length() = 0;
};
class TransformerBoneNamesArray : public IBoneNamesArray {
	DECLARE_AND_IMPLEMENT_GET_BONE_NAMES(TransformerBoneNamesArray)
private:
	static const char* ARRAY_BONE_NAMES[22];
};
class AvatarSimpleBoneNamesArray : public IBoneNamesArray {
	DECLARE_AND_IMPLEMENT_GET_BONE_NAMES(AvatarSimpleBoneNamesArray)
private:
	static const char* ARRAY_BONE_NAMES[24];
};
class AvatarBoneNamesArray : public IBoneNamesArray {
public:
	const char* get(int index) {
		return ARRAY_BONE_NAMES[index];
	}
	int length() {
		return sizeof(ARRAY_BONE_NAMES) / sizeof(const char*);
	}
private:
	static const char* ARRAY_BONE_NAMES[135];
};
class CustomModelBoneNamesArray : public IBoneNamesArray {
	DECLARE_AND_IMPLEMENT_GET_BONE_NAMES(CustomModelBoneNamesArray)
private:
	static const char* ARRAY_BONE_NAMES[24];
};
class CustomModelBoneNamesArray2 : public IBoneNamesArray {
	DECLARE_AND_IMPLEMENT_GET_BONE_NAMES(CustomModelBoneNamesArray2)
private:
	static const char* ARRAY_BONE_NAMES[24];
};
//===================================================IBoneNamesArray end===================================================

/**
*	装饰者接口
*	含正规注释的为正式使用逻辑，其余为探索过程中的逻辑，功能完成后删。
*/
//===================================================AbsTransformer start===================================================
#define DECLARE_AND_IMPLEMENT_TRANSFORMER(classname) DECLARE_AND_IMPLEMENT_DECORATOR(AbsTransformer, classname)

class AbsAREngine;
class AbsTransformer{
	DECLARE_AND_IMPLEMENT_ABSTRACT_DECORATOR(AbsTransformer)
public:
    virtual void transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength) = 0;
};

/*
*	打印偏移
*/
class PrintTranslationTransformer : public AbsTransformer {
	DECLARE_AND_IMPLEMENT_TRANSFORMER(PrintTranslationTransformer)
public:
	void transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength);
};

/*
*	打印旋转
*/
class PrintRotationTransformer : public AbsTransformer {
	DECLARE_AND_IMPLEMENT_TRANSFORMER(PrintRotationTransformer)
public:
	void transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength);
};

/*
*	相邻骨骼节点之间，计算出从原本的父节点到子节点在场景根部坐标系的欧拉角
*/
class SimpleFullyCustomModelRelativeBonesRotationTransformer : public AbsTransformer {
	DECLARE_AND_IMPLEMENT_TRANSFORMER(SimpleFullyCustomModelRelativeBonesRotationTransformer)
public:
	void transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength);
};

/*
*	自定义模型额外添加胸部(15)、肚子(16)、胯骨(19)、左右肩膀(18,17)5个点
*/
class FullyCustomModelAdditionalTranslationTransformer : public AbsTransformer {
	DECLARE_AND_IMPLEMENT_TRANSFORMER(FullyCustomModelAdditionalTranslationTransformer)
public:
	void transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength);
};

/*
*	指定计算子骨骼从父骨骼中偏移的角度，适用于Avatar 20个坐标点的模型。
*	索引值的旋转应当为当前骨骼指向下一个子骨骼的角度。
*/
class FullyCustomModelRotationTransformer : public AbsTransformer {
	DECLARE_AND_IMPLEMENT_TRANSFORMER(FullyCustomModelRotationTransformer)
public:
	void transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength);
};


/*
*	搭配上述FullyCustomModelRotationTransformer旋转转换器，先旋转，后此位移转换。
*	索引值的位移为该骨骼偏移到父骨骼的距离，距离为代码内置值，参考AvatarStandardBoneLengthTranslationTransformer。
*	只将骨骼的固定尺寸的负数值设置为大部分点的y值，x值设为0；
*	8和9的则设到x值中，y值为0；
*/
class FullyCustomModelLengthToAxisTranslationTransformer : public AbsTransformer {
	DECLARE_AND_IMPLEMENT_TRANSFORMER(FullyCustomModelLengthToAxisTranslationTransformer)
public:
	void transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength);
};

/*
*	每个绝对坐标值，按指定的比例，偏移到对应的位置
*	相对坐标偏移前调用
*/
class FullyCustomModelStandardBoneLengthTranslationTransformer : public AbsTransformer {
	DECLARE_AND_IMPLEMENT_TRANSFORMER(FullyCustomModelStandardBoneLengthTranslationTransformer)
public:
	void transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength);
private:
	static const float HEAD_HEIGHT;
	static const float SHOULDER_HALF_LENGTH;
	static const float ARM_LENGTH;
	static const float WRIST_LENGTH;
	static const float HAND_LENGTH;
	static const float CHEST_HEIGHT;
	static const float STOMACH_HEIGHT;
	static const float HIPBONE_HALF_LENGTH;
	static const float HIPBONE_HEIGHT;
	static const float THIGH_LENGTH;
	static const float LEG_LENGTH;
	static const float FOOT_LENGTH;
	friend class FullyCustomModelAdditionalTranslationTransformer;
	friend class AvatarHierarchicAdjacentBonesTranslationTransformer;
};

/*
*	每个绝对坐标值，按指定的比例，偏移到对应的位置。
*	比例值在tranform函数中
*	相对坐标偏移前调用
*/
class SimpleFullyCustomModelStandardBoneLengthTranslationTransformer : public AbsTransformer {
	DECLARE_AND_IMPLEMENT_TRANSFORMER(SimpleFullyCustomModelStandardBoneLengthTranslationTransformer)
public:
	void transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength);
};


//===================================================AbsTransformer end===================================================
//===================================================AbsAREngine start===================================================
class AbsAREngine//tolua_exports
	:public Singleton<AbsAREngine>
{//tolua_exports
public:
    AbsAREngine();
    ~AbsAREngine();
	void onGetSkeletonConfidence(int length, float *confidence);
	void onGetSkeletonPointIsExist(int length, int *isExist);
	void onGetSkeletonPoint(float *coordinates, int coordinateLength);
	void onGetSkeletonPointAndConfidence(float *coordinates, int coordinateLength, float *confidence, int confidenceLength);
	//tolua_begin
	void bindModelView(const char* uiName);
	void readDemoPoints(const char* szPath);
	ActorBody* newAvatarActorBody(const char*);
	ActorBody* getAvatarActorBody(const char*);
	ActorBody* newRoleSkinActorBody(const int);
	ActorBody* getRoleSkinActorBody(const int);
	void setConfidenceLevel(int iConfidenceLevel);
	int getConfidenceLevel();
	void setAllConfidence(bool bAllConfidence);
	bool areAllConfidence();
	void setZFactor(float factor);
	float getZFactor();
	void setRead2DPoints(bool);
	void readHipBone();
	void clearHipBone();
	void setChangeSequenceIdMode(bool);
	//tolua_end
	void update(float);
	void onPostCreateActorBody(ActorBody* actorBody, const int interval, const int range);
	void onOrientationChange(const int);
private:
	//旧的测试接口
	void printBoneNames();
	ActorBody* newFullyCustomModelActorBody(const char*, const char*);
	ActorBody* getFullyCustomModelActorBody(const char*, const char*);
	bool unwrap();
	void unwrapAll();
	void setTransformer(AbsTransformer* absTransformer);
	void wrapTransformer(int index);
	//接口
	void bindHightlights(ActorBody*);
	virtual void setSkeletonPoint(float *coordinates, int coordinateLength) = 0;
	virtual void setSkeletonPointAndConfidence(float *coordinates, int coordinateLength, float *confidence, int confidenceLength) = 0;
	virtual void setSkeletonPointWithAllConfidence(float *coordinates, int coordinateLength, float *confidence, int confidenceLength) = 0;
	virtual void setSkeletonPointWithEachConfidence(float *coordinates, int coordinateLength, float *confidence, int confidenceLength) = 0;
protected:
	ModelView* m_uiARCustomModelView;
	ActorBody* m_pAvatarActorBody;
	ActorBody* m_pFullyCustomModelActorBody;
	ActorBody* m_pRoleSkinActorBody;
	ActorBody* m_pActorBody;

	vector<FixedString> m_vBoneNamesInput;
	vector<Vector3> m_vTranslationInput;
	vector<Quaternion> m_vRotationInput;
	vector<Vector3> m_vScaleInput;
	vector<float> m_vConfidenceInput;

	vector<FixedString> m_vBoneNamesOutput;
	vector<Vector3> m_vTranslationOutput;
	vector<Quaternion> m_vRotationOutput;
	vector<Vector3> m_vScaleOutput;
	vector<float> m_vConfidenceOutput;

	IBoneNamesArray* m_pBoneNamesArray;
	IBoneNamesArray* m_pInputBoneNamesArray;
	AbsTransformer* m_pTransformer;

	FixedString m_fsARModelViewUIName;
	float m_fZFactor;
	int m_iCurStartRow;
	int m_iConfidenceLevel;
	//int m_iWrittenSequenceId;
	int m_iCurrentTick;
	int m_iStartTick;
	bool m_bAllConfidence;
	bool m_bIsReading2DPoints;
	bool m_bHasReadHipBone;
	bool m_bHasPlayedAnimation;
	bool m_bChangeSequenceIdMode;
	static int s_KeyFrameTickInterval;
	static int s_KeyFrameTickRange;
	static const int PLAY_SEQUENCE_ID_ONE;
	//static const int PLAY_SEQUENCE_ID_THE_OTHER;

};//tolua_exports
//===================================================AbsAREngine end===================================================

//===================================================HuaweiAREngine start===================================================
class HuaweiAREngine : public AbsAREngine {//tolua_exports
public:
    HuaweiAREngine();
    ~HuaweiAREngine();
private:
	void setSkeletonPoint(float *coordinates, int coordinateLength) override;
	void setSkeletonPointAndConfidence(float *coordinates, int coordinateLength, float *confidence, int confidenceLength) override;
	void setSkeletonPointWithAllConfidence(float *coordinates, int coordinateLength, float *confidence, int confidenceLength) override;
	void setSkeletonPointWithEachConfidence(float *coordinates, int coordinateLength, float *confidence, int confidenceLength) override;
};//tolua_exports
//===================================================HuaweiAREngine end===================================================
#endif//__AR_ENGINE__H__