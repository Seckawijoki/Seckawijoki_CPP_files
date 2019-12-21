#include "AREngine.h"
#include "Common.h"
#include "OgreScriptLuaVM.h"
#include "UILib/ui_modelview.h"
#include "UILib/ui_framemgr.h"
#include "OgreCSVParser.h"
#include "OgreAnimationData.h"
#include "OgreSkeletonData.h"
#include "FullyCustomModel.h"
#include "utility/utility.h"
#include "OgreMath.h"
#include "CustomModelData.h"
#include "BlockMaterialMgr.h"
#include "OgreRenderTypes.h"
#include "OgreEntity.h"
#include "defmanager.h"
#include "ClientAccount.h"
#include <algorithm>
using Ogre::CSVParser;
using Ogre::Root;
using Ogre::SequenceDesc;
using Ogre::AnimPlayMode;
using Ogre::SkeletonData;
using Ogre::BoneData;
using Ogre::Entity;
using Ogre::RenderLayer;
using Ogre::CrossProduct;
using Ogre::Sqrt;
using Ogre::ACos;
using Ogre::Abs;
using Ogre::Sin;
using Ogre::Cos;
using Ogre::Rad2Deg;
using std::sort;
//===================================================IBoneNamesArray start===================================================
const char* AvatarBoneNamesArray::ARRAY_BONE_NAMES[] = {
	"2",
	"Bip01",
	"Bip01 Footsteps",
	"109",
	"Bip01 Pelvis",
	"Bip01 Spine",
	"Bip01 Spine1",
	"Bip01 Neck",
	"bip Head",
	"Bip01 HeadNub",
	"Bip01 L Clavicle",
	"Bip01 L UpperArm",
	"Bip01 L Forearm",
	"Bip01 L Hand",
	"Bip01 L Finger0",
	"Bip01 L Finger0Nub",
	"100",
	"Bip01 R Clavicle",
	"Bip01 R UpperArm",
	"Bip01 R Forearm",
	"Bip01 R Hand",
	"Bip01 R Finger0",
	"Bip01 R Finger0Nub",
	"101",
	"107",
	"105",
	"Neck",
	"Head",
	"headBone03",
	"BoneLHair01",
	"BoneLHair02",
	"BoneLHair03",
	"BoneLHair04",
	"BoneRHair01",
	"BoneRHair02",
	"BoneRHair03",
	"BoneRHair04",
	"BoneHair01",
	"BoneHair02",
	"BoneHair03",
	"BoneHair04",
	"BoneLAHair01",
	"BoneLAHair02",
	"BoneLAHair03",
	"BoneLAHair04",
	"BoneRAHair01",
	"BoneRAHair02",
	"BoneRAHair03",
	"BoneRAHair04",
	"BoneRBHair01",
	"BoneRBHair02",
	"BoneRBHair03",
	"BoneRBHair04",
	"BoneLBHair01",
	"BoneLBHair02",
	"BoneLBHair03",
	"BoneLBHair04",
	"BoneCHair01",
	"BoneCHair02",
	"BoneCHair03",
	"BoneDHair01",
	"BoneDHair02",
	"BoneDHair03",
	"BoneDHair04",
	"BoneDHair05",
	"BoneDHair06",
	"Bip01 L Thigh",
	"Bip01 L Calf",
	"Bip01 L Foot",
	"Bip01 L Toe0",
	"Bip01 L Toe0Nub",
	"102",
	"Bip01 R Thigh",
	"Bip01 R Calf",
	"Bip01 R Foot",
	"Bip01 R Toe0",
	"Bip01 R Toe0Nub",
	"103",
	"Bone21",
	"Bone22",
	"Bone23",
	"Bone24",
	"Bone05",
	"Bone06",
	"Bone07",
	"Bone08",
	"Bone01",
	"Bone02",
	"Bone03",
	"Bone04",
	"Bone17",
	"Bone18",
	"Bone19",
	"Bone20",
	"Bone25",
	"Bone26",
	"Bone27",
	"Bone28",
	"Bone29",
	"Bone30",
	"Bone31",
	"Bone32",
	"Bone09",
	"Bone10",
	"Bone11",
	"Bone12",
	"Bone13",
	"Bone14",
	"Bone15",
	"Bone16",
	"Bone33",
	"Bone34",
	"Bone35",
	"Bone36",
	"6",
	"11",
	"4",
	"5",
	"3",
	"9",
	"10",
	"8",
	"14",
	"13",
	"19",
	"18",
	"17",
	"15",
	"22",
	"23",
	"24",
	"20",
	"1",
	"106",
	"1",
};
const char* CustomModelBoneNamesArray::ARRAY_BONE_NAMES[] = {
	"HeadTop",//No need to change
	"Head",
	"Arm_right1",
	"Arm_right2",
	"Arm_right3",//4
	"Arm_left1",
	"Arm_left2",
	"Arm_left3",
	"Leg_right1",
	"Leg_right2",//9
	"Leg_right3",
	"Leg_left1",
	"Leg_left2",
	"Leg_left3",
	"Bip01",//14
	"Body1"
	"Body2"
	"Bip01 R Clavicle",
	"Bip01 L Clavicle",
	"Body3",//19
};
const char* CustomModelBoneNamesArray2::ARRAY_BONE_NAMES[] = {
	"HeadTop",//No need to change
	"head",
	"arm_right1",
	"arm_right2",
	"arm_right3",//4
	"arm_left1",
	"arm_left2",
	"arm_left3",
	"leg_right1",
	"leg_right2",//9
	"leg_right3",
	"leg_left1",
	"leg_left2",
	"leg_left3",
	"Bip01",//14
	"body1"
	"body2"
	"Bip01 R Clavicle",
	"Bip01 L Clavicle",
	"body3",//19
};
const char* AvatarSimpleBoneNamesArray::ARRAY_BONE_NAMES[] = {
	"Neck",//No need to change
	"105",
	"Bip01 R UpperArm",
	"Bip01 R Forearm",
	"Bip01 R Hand",//4
	"Bip01 L UpperArm",
	"Bip01 L Forearm",
	"Bip01 L Hand",
	"Bip01 R Thigh",
	"Bip01 R Calf",//9
	"Bip01 R Foot",
	"Bip01 L Thigh",
	"Bip01 L Calf",
	"Bip01 L Foot",
	"2",//14
	"Bip01 Spine1",
	"Bip01 Spine",
	"Bip01 R Clavicle",
	"Bip01 L Clavicle",
	"Bip01 Pelvis",//19
	"100",
	"Bip01 HeadNub",
	"102",
	"BoneDHair06",
};
const char* TransformerBoneNamesArray::ARRAY_BONE_NAMES[] = {
	//"bip Head",//父节点为Bip01 Neck，点在头顶部
	//"Bip01 Neck",
	//"Neck",
	"headBone03",//父节点为Head
	"Head",//父节点为Neck，点接近颈部，在颈部偏上方
	"Bip01 R UpperArm",
	"Bip01 R Forearm",
	"Bip01 R Hand",//4
	"Bip01 L UpperArm",
	"Bip01 L Forearm",
	"Bip01 L Hand",
	"Bip01 R Thigh",
	"Bip01 R Calf",//9
	"Bip01 R Foot",
	"Bip01 L Thigh",
	"Bip01 L Calf",
	"Bip01 L Foot",
	"Bip01",//14
	"Bip01 Spine1",
	"Bip01 Spine",
	"Bip01 Pelvis",//17
	"Bip01 R Clavicle",//18 //父节点为Bip01 Neck
	"Bip01 L Clavicle",//19 //父节点为Bip01 Neck
	"Bip01 Neck",
	"bip Head",//父节点为Bip01 Neck
};
//===================================================IBoneNamesArray end===================================================
//===================================================AbsTransformer start===================================================

void PrintTranslationTransformer::transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength) {
	if (m_AbsDecorator) {
		m_AbsDecorator->transform(boneRotations, rotationLength, skeletonTranslations, translationLength);
	}
	for (int i = 0; i < translationLength; ++i) {
		LOG_INFO("PrintTranslationTransformer::transform(): skeletonPoint[%d] = %f, %f, %f", i, skeletonTranslations[i].x, skeletonTranslations[i].y, skeletonTranslations[i].z);
	}
}

void PrintRotationTransformer::transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength) {
	if (m_AbsDecorator) {
		m_AbsDecorator->transform(boneRotations, rotationLength, skeletonTranslations, translationLength);
	}
	for (int i = 0; i < translationLength; ++i) {
		LOG_INFO("PrintRotationTransformer::transform(): boneRotations[%d] = %f, %f, %f", i, boneRotations[i].x, boneRotations[i].y, boneRotations[i].z);
	}
}

void SimpleFullyCustomModelRelativeBonesRotationTransformer::transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength) {
	if (m_AbsDecorator) {
		m_AbsDecorator->transform(boneRotations, rotationLength, skeletonTranslations, translationLength);
	}
	if (rotationLength < 15 || translationLength < 15){
		return;
	}
	//=====vector to rotate euler angle start=====
	const float additionalRoll = 0;
	//const float defaultPitch = -90;
	Vector3 relativeVector3;
	float yaw, pitch;
	//1->0
	relativeVector3 = skeletonTranslations[1] - skeletonTranslations[0];
	Direction2PitchYaw(&yaw, &pitch, relativeVector3);
	boneRotations[1].setPitchYawRoll(90 - pitch, yaw, additionalRoll);
	//2->3
	relativeVector3 = skeletonTranslations[3] - skeletonTranslations[2];
	Direction2PitchYaw(&yaw, &pitch, relativeVector3);
	boneRotations[2].setPitchYawRoll(90 - pitch, yaw, additionalRoll);
	//3->4
	relativeVector3 = skeletonTranslations[4] - skeletonTranslations[3];
	Direction2PitchYaw(&yaw, &pitch, relativeVector3);
	boneRotations[3].setPitchYawRoll(90 - pitch, yaw, additionalRoll);
	//5->6
	relativeVector3 = skeletonTranslations[6] - skeletonTranslations[5];
	Direction2PitchYaw(&yaw, &pitch, relativeVector3);
	boneRotations[5].setPitchYawRoll(90 - pitch, yaw, additionalRoll);
	//6->7
	relativeVector3 = skeletonTranslations[7] - skeletonTranslations[6];
	Direction2PitchYaw(&yaw, &pitch, relativeVector3);
	boneRotations[6].setPitchYawRoll(90 - pitch, yaw, additionalRoll);
	//8->9
	relativeVector3 = skeletonTranslations[9] - skeletonTranslations[8];
	Direction2PitchYaw(&yaw, &pitch, relativeVector3);
	boneRotations[8].setPitchYawRoll(90 - pitch, yaw, additionalRoll);
	//9->10
	relativeVector3 = skeletonTranslations[10] - skeletonTranslations[9];
	Direction2PitchYaw(&yaw, &pitch, relativeVector3);
	boneRotations[9].setPitchYawRoll(90 - pitch, yaw, additionalRoll);
	//11->12
	relativeVector3 = skeletonTranslations[12] - skeletonTranslations[11];
	Direction2PitchYaw(&yaw, &pitch, relativeVector3);
	boneRotations[11].setPitchYawRoll(90 - pitch, yaw, additionalRoll);
	//12->13
	relativeVector3 = skeletonTranslations[13] - skeletonTranslations[12];
	Direction2PitchYaw(&yaw, &pitch, relativeVector3);
	boneRotations[12].setPitchYawRoll(90 - pitch, yaw, additionalRoll);
	//14->1
	relativeVector3 = skeletonTranslations[1] - skeletonTranslations[14];
	Direction2PitchYaw(&yaw, &pitch, relativeVector3);
	boneRotations[14].setPitchYawRoll(90 - pitch, yaw, 180);
	//=====vector to rotate euler angle end=====
}
void FullyCustomModelAdditionalTranslationTransformer::transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength) {
	if (m_AbsDecorator) {
		m_AbsDecorator->transform(boneRotations, rotationLength, skeletonTranslations, translationLength);
	}
	if (translationLength <= 15) {
		return;
	}
	Vector3 crossProductZAxisVector = skeletonTranslations[1];
	crossProductZAxisVector.x = 0;
	crossProductZAxisVector.y = 0;
	if (crossProductZAxisVector.z < 0) {
		crossProductZAxisVector.z = -crossProductZAxisVector.z;
	}
	else if (crossProductZAxisVector.z == 0) {
		crossProductZAxisVector.z = 1;
	}

	const float chestHeight = FullyCustomModelStandardBoneLengthTranslationTransformer::CHEST_HEIGHT;
	const float stomachHeight = FullyCustomModelStandardBoneLengthTranslationTransformer::STOMACH_HEIGHT;
	const float hipboneHeight = FullyCustomModelStandardBoneLengthTranslationTransformer::HIPBONE_HEIGHT;
	const float shoulderHalfLength = FullyCustomModelStandardBoneLengthTranslationTransformer::SHOULDER_HALF_LENGTH;
	const float UPPER_BODY_HEIGHT = chestHeight + stomachHeight + hipboneHeight / 2.f;
	Vector3 v1_14 = skeletonTranslations[14] - skeletonTranslations[1];
	const float standardRatio = UPPER_BODY_HEIGHT / v1_14.length();
	//Additional skeleton points
	//"Bip01 Spine1",
	skeletonTranslations[15] = v1_14 / UPPER_BODY_HEIGHT * chestHeight + skeletonTranslations[1];
	//"Bip01 Spine",
	skeletonTranslations[16] = v1_14 / UPPER_BODY_HEIGHT * (chestHeight + stomachHeight) + skeletonTranslations[1];
	//"Bip01 R Clavicle",
	//叉乘
	skeletonTranslations[17] = CrossProduct(crossProductZAxisVector, v1_14);
	skeletonTranslations[17] = skeletonTranslations[17] / skeletonTranslations[17].length() * v1_14.length() * shoulderHalfLength / UPPER_BODY_HEIGHT + skeletonTranslations[1];
	//skeletonTranslations[17].y += skeletonTranslations[15].y;
	//"Bip01 L Clavicle",
	//叉乘
	skeletonTranslations[18] = CrossProduct(v1_14, crossProductZAxisVector);
	skeletonTranslations[18] = skeletonTranslations[18] / skeletonTranslations[18].length() * v1_14.length() * shoulderHalfLength / UPPER_BODY_HEIGHT + skeletonTranslations[1];
	//skeletonTranslations[18].y += skeletonTranslations[15].y;
	//"Bip01 Pelvis",
	skeletonTranslations[19] = v1_14 / UPPER_BODY_HEIGHT * (hipboneHeight / 2.F) + skeletonTranslations[14];
	//skeletonTranslations[19] = skeletonTranslations[14];
}
void FullyCustomModelRotationTransformer::transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength) {
	if (m_AbsDecorator) {
		m_AbsDecorator->transform(boneRotations, rotationLength, skeletonTranslations, translationLength);
	}
	if (translationLength < 20) {
		return;
	}
	float roll;
	Vector3 temp;
	Vector3 yUnit = Vector3::UNIT_Y;
	Vector3 negativeYUnit = Vector3::NEGATIVE_UNIT_Y;
	Vector3 xUnit = Vector3::UNIT_X;
	Vector3 negativeXUnit = Vector3::NEGATIVE_UNIT_X;
	Vector3 originalShoulderVector3;
	Vector3 originalHipVector3;
	Vector3 relativeVector3;
	Vector3 v1_14;
	Vector3 lastRelativeVector3;

	relativeVector3 = skeletonTranslations[0] - skeletonTranslations[1];
	roll = getXOYAngleByTheLawOfCosines(yUnit, relativeVector3);
	boneRotations[1].roll = roll;

	relativeVector3 = skeletonTranslations[14] - skeletonTranslations[1];
	v1_14 = relativeVector3;
	roll = getXOYAngleByTheLawOfCosines(negativeYUnit, relativeVector3);
	boneRotations[14].roll = roll;

	lastRelativeVector3 = v1_14;
	relativeVector3 = skeletonTranslations[2] - skeletonTranslations[17];
	roll = getXOYAngleByTheLawOfCosines(lastRelativeVector3, relativeVector3);
	boneRotations[17].roll = roll;

	lastRelativeVector3 = relativeVector3;
	relativeVector3 = skeletonTranslations[3] - skeletonTranslations[2];
	roll = getXOYAngleByTheLawOfCosines(lastRelativeVector3, relativeVector3);
	boneRotations[2].roll = roll;

	lastRelativeVector3 = relativeVector3;
	relativeVector3 = skeletonTranslations[4] - skeletonTranslations[3];
	roll = getXOYAngleByTheLawOfCosines(lastRelativeVector3, relativeVector3);
	boneRotations[3].roll = roll;

	lastRelativeVector3 = v1_14;
	relativeVector3 = skeletonTranslations[5] - skeletonTranslations[18];
	roll = getXOYAngleByTheLawOfCosines(lastRelativeVector3, relativeVector3);
	boneRotations[18].roll = roll;

	lastRelativeVector3 = relativeVector3;
	relativeVector3 = skeletonTranslations[6] - skeletonTranslations[5];
	roll = getXOYAngleByTheLawOfCosines(lastRelativeVector3, relativeVector3);
	boneRotations[5].roll = roll;

	lastRelativeVector3 = relativeVector3;
	relativeVector3 = skeletonTranslations[7] - skeletonTranslations[6];
	roll = getXOYAngleByTheLawOfCosines(lastRelativeVector3, relativeVector3);
	boneRotations[6].roll = roll;

	relativeVector3 = skeletonTranslations[9] - skeletonTranslations[8];
	roll = getXOYAngleByTheLawOfCosines(negativeYUnit, relativeVector3);
	boneRotations[8].roll = roll;

	lastRelativeVector3 = relativeVector3;
	relativeVector3 = skeletonTranslations[10] - skeletonTranslations[9];
	roll = getXOYAngleByTheLawOfCosines(lastRelativeVector3, relativeVector3);
	boneRotations[9].roll = roll;

	relativeVector3 = skeletonTranslations[12] - skeletonTranslations[11];
	roll = getXOYAngleByTheLawOfCosines(negativeYUnit, relativeVector3);
	boneRotations[11].roll = roll;

	lastRelativeVector3 = relativeVector3;
	relativeVector3 = skeletonTranslations[13] - skeletonTranslations[12];
	roll = getXOYAngleByTheLawOfCosines(lastRelativeVector3, relativeVector3);
	boneRotations[12].roll = roll;
}

void FullyCustomModelLengthToAxisTranslationTransformer::transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength) {
	if (m_AbsDecorator) {
		m_AbsDecorator->transform(boneRotations, rotationLength, skeletonTranslations, translationLength);
	}
	if (translationLength < 20) {
		return;
	}
	skeletonTranslations[1].y = Distance(skeletonTranslations[1], skeletonTranslations[15]);
	skeletonTranslations[4].y = -Distance(skeletonTranslations[4], skeletonTranslations[3]);
	skeletonTranslations[3].y = -Distance(skeletonTranslations[3], skeletonTranslations[2]);
	skeletonTranslations[2].y = -Distance(skeletonTranslations[2], skeletonTranslations[17]);
	skeletonTranslations[17].y = skeletonTranslations[1].y;
	skeletonTranslations[7].y = -Distance(skeletonTranslations[7], skeletonTranslations[6]);
	skeletonTranslations[6].y = -Distance(skeletonTranslations[6], skeletonTranslations[5]);
	skeletonTranslations[5].y = -Distance(skeletonTranslations[5], skeletonTranslations[18]);
	skeletonTranslations[18].y = skeletonTranslations[1].y;
	skeletonTranslations[10].y = -Distance(skeletonTranslations[10], skeletonTranslations[9]);
	skeletonTranslations[9].y = -Distance(skeletonTranslations[9], skeletonTranslations[8]);
	skeletonTranslations[8].x = -Distance(skeletonTranslations[8], skeletonTranslations[19]);
	skeletonTranslations[8].y = 0;
	skeletonTranslations[13].y = -Distance(skeletonTranslations[13], skeletonTranslations[12]);
	skeletonTranslations[12].y = -Distance(skeletonTranslations[12], skeletonTranslations[11]);
	skeletonTranslations[11].x = Distance(skeletonTranslations[11], skeletonTranslations[19]);
	skeletonTranslations[11].y = 0;
	skeletonTranslations[15].y = Distance(skeletonTranslations[15], skeletonTranslations[16]);
	skeletonTranslations[16].y = Distance(skeletonTranslations[16], skeletonTranslations[19]);
	skeletonTranslations[19].y = -Distance(skeletonTranslations[19], skeletonTranslations[14]);
	for (int i = 0; i < translationLength; ++i){
		if (i == 8 || i == 11){
			continue;
		}
		skeletonTranslations[i].x = 0;
	}
}

const float FullyCustomModelStandardBoneLengthTranslationTransformer::HEAD_HEIGHT = 65.f;
const float FullyCustomModelStandardBoneLengthTranslationTransformer::SHOULDER_HALF_LENGTH = 55.f;
const float FullyCustomModelStandardBoneLengthTranslationTransformer::ARM_LENGTH = 55.f;
const float FullyCustomModelStandardBoneLengthTranslationTransformer::WRIST_LENGTH = 55.f;
const float FullyCustomModelStandardBoneLengthTranslationTransformer::HAND_LENGTH = 0;
const float FullyCustomModelStandardBoneLengthTranslationTransformer::CHEST_HEIGHT = 45.f;
const float FullyCustomModelStandardBoneLengthTranslationTransformer::STOMACH_HEIGHT = 30.f;
const float FullyCustomModelStandardBoneLengthTranslationTransformer::HIPBONE_HALF_LENGTH = 25.f;
const float FullyCustomModelStandardBoneLengthTranslationTransformer::HIPBONE_HEIGHT = 30.f;
const float FullyCustomModelStandardBoneLengthTranslationTransformer::THIGH_LENGTH = 50.f;
const float FullyCustomModelStandardBoneLengthTranslationTransformer::LEG_LENGTH = 50.f;
const float FullyCustomModelStandardBoneLengthTranslationTransformer::FOOT_LENGTH = 0;
void FullyCustomModelStandardBoneLengthTranslationTransformer::transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength) {
	if (m_AbsDecorator) {
		m_AbsDecorator->transform(boneRotations, rotationLength, skeletonTranslations, translationLength);
	}
	if (translationLength < 20) {
		return;
	}
	Vector3 deltaVector3(0, 0, 0);
	Vector3 newScaledPoint(0, 0, 0);
	const float UPPER_BODY_HEIGHT = CHEST_HEIGHT + STOMACH_HEIGHT + HIPBONE_HEIGHT / 2.f;
	const float upperBodyHeight = Distance(skeletonTranslations[1], skeletonTranslations[14]);
	float lengthFactor = UPPER_BODY_HEIGHT / upperBodyHeight;
	for (int i = 0; i < translationLength; ++i) {
		skeletonTranslations[i].x *= lengthFactor;
		skeletonTranslations[i].y *= lengthFactor;
	}
	//0
	const float headHeight = Distance(skeletonTranslations[0], skeletonTranslations[1]);
	const float headScale = HEAD_HEIGHT / headHeight;
	skeletonTranslations[0] = (skeletonTranslations[0] - skeletonTranslations[1]) * headScale + skeletonTranslations[1];
	//2, 3, 4
	const float rightShoulderWidth = Distance(skeletonTranslations[2], skeletonTranslations[1]);
	const float rightShoulderScale = SHOULDER_HALF_LENGTH / rightShoulderWidth;
	newScaledPoint = (skeletonTranslations[2] - skeletonTranslations[1]) * rightShoulderScale + skeletonTranslations[17];
	deltaVector3 = newScaledPoint - skeletonTranslations[2];
	skeletonTranslations[3] += deltaVector3;
	skeletonTranslations[4] += deltaVector3;
	skeletonTranslations[2] = newScaledPoint;
	//3, 4
	const float rightArmLength = Distance(skeletonTranslations[2], skeletonTranslations[3]);
	const float rightArmScale = ARM_LENGTH / rightArmLength;
	newScaledPoint = (skeletonTranslations[3] - skeletonTranslations[2]) * rightArmScale + skeletonTranslations[2];
	deltaVector3 = newScaledPoint - skeletonTranslations[3];
	skeletonTranslations[4] += deltaVector3;
	skeletonTranslations[3] = newScaledPoint;
	//4
	const float rightWristLength = Distance(skeletonTranslations[3], skeletonTranslations[4]);
	const float rightWristScale = WRIST_LENGTH / rightWristLength;
	newScaledPoint = (skeletonTranslations[4] - skeletonTranslations[3]) * rightWristScale + skeletonTranslations[3];
	deltaVector3 = newScaledPoint - skeletonTranslations[4];
	skeletonTranslations[4] = newScaledPoint;
	//5, 6, 7
	const float leftShoulderWidth = Distance(skeletonTranslations[1], skeletonTranslations[5]);
	const float leftShoulderScale = SHOULDER_HALF_LENGTH / leftShoulderWidth;
	newScaledPoint = (skeletonTranslations[5] - skeletonTranslations[1]) * leftShoulderScale + skeletonTranslations[18];
	deltaVector3 = newScaledPoint - skeletonTranslations[5];
	skeletonTranslations[6] += deltaVector3;
	skeletonTranslations[7] += deltaVector3;
	skeletonTranslations[5] = newScaledPoint;
	//6, 7
	const float leftArmLength = Distance(skeletonTranslations[5], skeletonTranslations[6]);
	const float leftArmScale = ARM_LENGTH / leftArmLength;
	newScaledPoint = (skeletonTranslations[6] - skeletonTranslations[5]) * leftArmScale + skeletonTranslations[5];
	deltaVector3 = newScaledPoint - skeletonTranslations[6];
	skeletonTranslations[7] += deltaVector3;
	skeletonTranslations[6] = newScaledPoint;
	//7
	const float leftWristLength = Distance(skeletonTranslations[6], skeletonTranslations[7]);
	const float leftWristScale = WRIST_LENGTH / leftWristLength;
	newScaledPoint = (skeletonTranslations[7] - skeletonTranslations[6]) * leftWristScale + skeletonTranslations[6];
	deltaVector3 = newScaledPoint - skeletonTranslations[7];
	skeletonTranslations[7] = newScaledPoint;
	//8, 9, 10
	const float rightHipLength = Distance(skeletonTranslations[19], skeletonTranslations[8]);
	const float rightHipScale = HIPBONE_HALF_LENGTH / rightHipLength;
	newScaledPoint = (skeletonTranslations[8] - skeletonTranslations[19]) * rightHipScale + skeletonTranslations[19];
	deltaVector3 = newScaledPoint - skeletonTranslations[8];
	skeletonTranslations[9] += deltaVector3;
	skeletonTranslations[10] += deltaVector3;
	skeletonTranslations[8] = newScaledPoint;
	//9, 10
	const float rightThighLength = Distance(skeletonTranslations[8], skeletonTranslations[9]);
	const float rightThighScale = THIGH_LENGTH / rightThighLength;
	newScaledPoint = (skeletonTranslations[9] - skeletonTranslations[8]) * rightThighScale + skeletonTranslations[8];
	deltaVector3 = newScaledPoint - skeletonTranslations[9];
	skeletonTranslations[10] += deltaVector3;
	skeletonTranslations[9] = newScaledPoint;
	//10
	const float rightLegLength = Distance(skeletonTranslations[9], skeletonTranslations[10]);
	const float rightLegScale = LEG_LENGTH / rightLegLength;
	newScaledPoint = (skeletonTranslations[10] - skeletonTranslations[9]) * rightLegScale + skeletonTranslations[9];
	deltaVector3 = newScaledPoint - skeletonTranslations[9];
	skeletonTranslations[10] = newScaledPoint;
	//11, 12, 13
	const float leftHipLength = Distance(skeletonTranslations[19], skeletonTranslations[11]);
	const float leftHipScale = HIPBONE_HALF_LENGTH / leftHipLength;
	newScaledPoint = (skeletonTranslations[11] - skeletonTranslations[19]) * leftHipScale + skeletonTranslations[19];
	deltaVector3 = newScaledPoint - skeletonTranslations[11];
	skeletonTranslations[12] += deltaVector3;
	skeletonTranslations[13] += deltaVector3;
	skeletonTranslations[11] = newScaledPoint;
	//12, 13
	const float leftThighLength = Distance(skeletonTranslations[11], skeletonTranslations[12]);
	const float leftThighScale = THIGH_LENGTH / leftThighLength;
	newScaledPoint = (skeletonTranslations[12] - skeletonTranslations[11]) * leftThighScale + skeletonTranslations[11];
	deltaVector3 = newScaledPoint - skeletonTranslations[12];
	skeletonTranslations[13] += deltaVector3;
	skeletonTranslations[12] = newScaledPoint;
	//13
	const float leftLegLength = Distance(skeletonTranslations[12], skeletonTranslations[13]);
	const float leftLegScale = LEG_LENGTH / leftLegLength;
	newScaledPoint = (skeletonTranslations[13] - skeletonTranslations[12]) * leftLegScale + skeletonTranslations[12];
	deltaVector3 = newScaledPoint - skeletonTranslations[13];
	skeletonTranslations[13] = newScaledPoint;
}

void SimpleFullyCustomModelStandardBoneLengthTranslationTransformer::transform(Vector3* boneRotations, const int& rotationLength, Vector3* skeletonTranslations, const int& translationLength) {
	if (m_AbsDecorator) {
		m_AbsDecorator->transform(boneRotations, rotationLength, skeletonTranslations, translationLength);
	}
	if (translationLength < 15) {
		return;
	}
	//=====Method.3 : standard distance reference start=====
	Vector3 deltaVector3(0, 0, 0);
	Vector3 newScaledPoint(0, 0, 0);
	const float UPPER_BODY_HEIGHT = Distance(skeletonTranslations[1], skeletonTranslations[14]);
	//0
	const float neckLength = Distance(skeletonTranslations[0], skeletonTranslations[1]);
	const float neckScale = UPPER_BODY_HEIGHT * 31 / 20 / neckLength;
	skeletonTranslations[0] = (skeletonTranslations[0] - skeletonTranslations[1]) * neckScale + skeletonTranslations[1];
	//2, 3, 4
	const float rightShoulderWidth = Distance(skeletonTranslations[1], skeletonTranslations[2]);
	const float rightShoulderScale = UPPER_BODY_HEIGHT * 6 / 20 / rightShoulderWidth;
	newScaledPoint = (skeletonTranslations[2] - skeletonTranslations[1]) * rightShoulderScale + skeletonTranslations[1];
	deltaVector3 = newScaledPoint - skeletonTranslations[2];
	skeletonTranslations[3] += deltaVector3;
	skeletonTranslations[4] += deltaVector3;
	skeletonTranslations[2] = newScaledPoint;
	//3, 4
	const float rightArmLength = Distance(skeletonTranslations[2], skeletonTranslations[3]);
	const float rightArmScale = UPPER_BODY_HEIGHT * 11 / 20 / rightArmLength;
	newScaledPoint = (skeletonTranslations[3] - skeletonTranslations[2]) * rightArmScale + skeletonTranslations[2];
	deltaVector3 = newScaledPoint - skeletonTranslations[3];
	skeletonTranslations[4] += deltaVector3;
	skeletonTranslations[3] = newScaledPoint;
	//4
	const float rightWristLength = Distance(skeletonTranslations[3], skeletonTranslations[4]);
	const float rightWristScale = UPPER_BODY_HEIGHT * 10 / 20 / rightWristLength;
	newScaledPoint = (skeletonTranslations[4] - skeletonTranslations[3]) * rightWristScale + skeletonTranslations[3];
	deltaVector3 = newScaledPoint - skeletonTranslations[4];
	skeletonTranslations[4] = newScaledPoint;
	//5, 6, 7
	const float leftShoulderWidth = Distance(skeletonTranslations[1], skeletonTranslations[5]);
	const float leftShoulderScale = UPPER_BODY_HEIGHT * 6 / 20 / leftShoulderWidth;
	newScaledPoint = (skeletonTranslations[5] - skeletonTranslations[1]) * leftShoulderScale + skeletonTranslations[1];
	deltaVector3 = newScaledPoint - skeletonTranslations[5];
	skeletonTranslations[6] += deltaVector3;
	skeletonTranslations[7] += deltaVector3;
	skeletonTranslations[5] = newScaledPoint;
	//6, 7
	const float leftArmLength = Distance(skeletonTranslations[5], skeletonTranslations[6]);
	const float leftArmScale = UPPER_BODY_HEIGHT * 11 / 20 / leftArmLength;
	newScaledPoint = (skeletonTranslations[6] - skeletonTranslations[5]) * leftArmScale + skeletonTranslations[5];
	deltaVector3 = newScaledPoint - skeletonTranslations[6];
	skeletonTranslations[7] += deltaVector3;
	skeletonTranslations[6] = newScaledPoint;
	//7
	const float leftWristLength = Distance(skeletonTranslations[6], skeletonTranslations[7]);
	const float leftWristScale = UPPER_BODY_HEIGHT * 10 / 20 / leftWristLength;
	newScaledPoint = (skeletonTranslations[7] - skeletonTranslations[6]) * leftWristScale + skeletonTranslations[6];
	deltaVector3 = newScaledPoint - skeletonTranslations[7];
	skeletonTranslations[7] = newScaledPoint;
	//8, 9, 10
	const float rightHipLength = Distance(skeletonTranslations[14], skeletonTranslations[8]);
	const float rightHipScale = UPPER_BODY_HEIGHT * 5 / 20 / rightHipLength;
	newScaledPoint = (skeletonTranslations[8] - skeletonTranslations[14]) * rightHipScale + skeletonTranslations[14];
	deltaVector3 = newScaledPoint - skeletonTranslations[8];
	skeletonTranslations[9] += deltaVector3;
	skeletonTranslations[10] += deltaVector3;
	skeletonTranslations[8] = newScaledPoint;
	//9, 10
	const float rightThighLength = Distance(skeletonTranslations[8], skeletonTranslations[9]);
	const float rightThighScale = UPPER_BODY_HEIGHT * 10 / 20 / rightThighLength;
	newScaledPoint = (skeletonTranslations[9] - skeletonTranslations[8]) * rightThighScale + skeletonTranslations[8];
	deltaVector3 = newScaledPoint - skeletonTranslations[9];
	skeletonTranslations[10] += deltaVector3;
	skeletonTranslations[9] = newScaledPoint;
	//10
	const float rightLegLength = Distance(skeletonTranslations[9], skeletonTranslations[10]);
	const float rightLegScale = UPPER_BODY_HEIGHT * 10 / 20 / rightLegLength;
	newScaledPoint = (skeletonTranslations[10] - skeletonTranslations[9]) * rightLegScale + skeletonTranslations[9];
	deltaVector3 = newScaledPoint - skeletonTranslations[9];
	skeletonTranslations[10] = newScaledPoint;
	//11, 12, 13
	const float leftHipLength = Distance(skeletonTranslations[14], skeletonTranslations[11]);
	const float leftHipScale = UPPER_BODY_HEIGHT * 5 / 20 / leftHipLength;
	newScaledPoint = (skeletonTranslations[11] - skeletonTranslations[14]) * leftHipScale + skeletonTranslations[14];
	deltaVector3 = newScaledPoint - skeletonTranslations[11];
	skeletonTranslations[12] += deltaVector3;
	skeletonTranslations[13] += deltaVector3;
	skeletonTranslations[11] = newScaledPoint;
	//12, 13
	const float leftThighLength = Distance(skeletonTranslations[11], skeletonTranslations[12]);
	const float leftThighScale = UPPER_BODY_HEIGHT * 10 / 20 / leftThighLength;
	newScaledPoint = (skeletonTranslations[12] - skeletonTranslations[11]) * leftThighScale + skeletonTranslations[11];
	deltaVector3 = newScaledPoint - skeletonTranslations[12];
	skeletonTranslations[13] += deltaVector3;
	skeletonTranslations[12] = newScaledPoint;
	//13
	const float leftLegLength = Distance(skeletonTranslations[12], skeletonTranslations[13]);
	const float leftLegScale = UPPER_BODY_HEIGHT * 10 / 20 / leftLegLength;
	newScaledPoint = (skeletonTranslations[13] - skeletonTranslations[12]) * leftLegScale + skeletonTranslations[12];
	deltaVector3 = newScaledPoint - skeletonTranslations[13];
	skeletonTranslations[13] = newScaledPoint;
	//=====Method.3 : standard distance reference end=====

	const float standardSpineLength = 40.f;
	const float lengthFactor = standardSpineLength / UPPER_BODY_HEIGHT;
	for (int i = 0; i < translationLength; ++i){
		skeletonTranslations[i].x *= lengthFactor;
		skeletonTranslations[i].y *= lengthFactor;
		skeletonTranslations[i].z += 1.5f;
		skeletonTranslations[i].z /= 2;
	}
}
//===================================================AbsTransformer end===================================================
//===================================================AbsAREngine start===================================================
const int AbsAREngine::PLAY_SEQUENCE_ID_ONE = 500101;
//const int AbsAREngine::PLAY_SEQUENCE_ID_THE_OTHER = 500102;
int AbsAREngine::s_KeyFrameTickInterval = 33;
int AbsAREngine::s_KeyFrameTickRange = 957;
AbsAREngine::AbsAREngine(){
    m_pTransformer = NULL;
	m_pBoneNamesArray = NULL;
	m_uiARCustomModelView = NULL;
	m_pAvatarActorBody = NULL;
	m_pFullyCustomModelActorBody = NULL;
	m_pRoleSkinActorBody = NULL;
	m_pActorBody = NULL;
	m_fsARModelViewUIName = "";
	m_fZFactor = 1.f;
	m_iCurStartRow = 0;
	m_iConfidenceLevel = 0;
	//m_iWrittenSequenceId = PLAY_SEQUENCE_ID_ONE;
	m_iCurrentTick = 0;
	m_iStartTick = -1;
	m_bAllConfidence = true;
	m_bIsReading2DPoints = false;
	m_bHasReadHipBone = true;
	m_bHasPlayedAnimation = false;
	m_bChangeSequenceIdMode = true;
	IBoneNamesArray* iBoneNamesArray = new TransformerBoneNamesArray();
	Quaternion defaultRotation(0, 0, 0, 1);
	Vector3 defaultScale(1.f, 1.f, 1.f);
	const int length = iBoneNamesArray->length();
	for (int i = 0; i < length; ++i) {
		FixedString fs = iBoneNamesArray->get(i);
		m_vBoneNamesInput.push_back(fs);
		m_vRotationInput.push_back(defaultRotation);
		m_vScaleInput.push_back(defaultScale);
	}
}

AbsAREngine::~AbsAREngine(){
	#if OGRE_PLATFORM != OGRE_PLATFORM_APPLE
	OGRE_DELETE(m_pTransformer);
	OGRE_DELETE(m_pBoneNamesArray);
	OGRE_DELETE(m_pAvatarActorBody);
	OGRE_DELETE(m_pFullyCustomModelActorBody);
	OGRE_DELETE(m_pRoleSkinActorBody);
	m_fsARModelViewUIName = "";
	m_uiARCustomModelView = NULL;
	m_pAvatarActorBody = NULL;
	m_pFullyCustomModelActorBody = NULL;
	m_pActorBody = NULL;
	m_vTranslationInput.clear();
	m_vRotationInput.clear();
	m_vScaleInput.clear();
	#endif//OGRE_PLATFORM != OGRE_PLATFORM_APPLE
}

void AbsAREngine::bindModelView(const char* uiName){
	if (!uiName) {
		m_uiARCustomModelView = NULL;
		m_fsARModelViewUIName = "";
		return;
	}
	m_fsARModelViewUIName = uiName;
	LayoutFrame* ui = g_pFrameMgr->FindLayoutFrame(uiName);
	m_uiARCustomModelView = dynamic_cast<ModelView*>(ui);
	if (!m_uiARCustomModelView) {
		m_fsARModelViewUIName = "";
		return;
	}
	ActorBody* actorBody = m_uiARCustomModelView->getActorbody();
}

void AbsAREngine::update(float dtime) {
	if (m_uiARCustomModelView && m_uiARCustomModelView->IsShown() && m_pActorBody) {
		m_pActorBody->update(dtime);
		Entity* entity = m_pActorBody->getEntity();
		if (entity) {
			int tick = m_iCurrentTick - s_KeyFrameTickInterval * 2;
			if (tick < 0 && m_bHasPlayedAnimation) {
				tick += s_KeyFrameTickRange;
				entity->resetUpdate(true, tick);
			}
		}
	}
}

void AbsAREngine::setTransformer(AbsTransformer* absTransformer){
    if (m_pTransformer){
        delete m_pTransformer;
    }
    m_pTransformer = absTransformer;
}

void AbsAREngine::onOrientationChange(const int orientation){
	if (!m_uiARCustomModelView){
		return;
	}
	const int differenceRange = 10;
	int zAngle;
	if (orientation > 90 - differenceRange && orientation <= 90 + differenceRange){
		zAngle = 180;
	} else if (orientation > 270 - differenceRange && orientation <= 270 + differenceRange) {
		zAngle = 0;
	} else if (orientation > 180 - differenceRange && orientation <= 180 + differenceRange) {
		zAngle = -90;
	} else if (orientation > 0 - differenceRange && orientation <= 0 + differenceRange) {
		zAngle = 90;
	}
	//m_uiARCustomModelView->setModelZAngle(zAngle);
}

void AbsAREngine::onPostCreateActorBody(ActorBody* actorBody, const int interval, const int range){
	if (!actorBody){
		return;
	}
	Model* model = actorBody->getModel();
	if (!model) {
		return;
	}
	ModelData* modelData = model->getModelData();
	if (!modelData) {
		return;
	}
	if (!m_pBoneNamesArray) {
		return;
	}

	modelData->addCustomSequenceIDWithCopiedBones(PLAY_SEQUENCE_ID_ONE, AnimPlayMode::ANIM_MODE_LOOP, 0, range);
	//modelData->addCustomSequenceIDWithCopiedBones(PLAY_SEQUENCE_ID_THE_OTHER, AnimPlayMode::ANIM_MODE_LOOP, 0, range);
}

void AbsAREngine::bindHightlights(ActorBody* actorBody){
	Entity* entity = m_pActorBody->getEntity();
	if (!entity) {
		return;
	}
	const char* ARRAY_BONE_NAMES[] = {
		//"Bip01 R Clavicle",
		//"Bip01 R UpperArm",
		//"Bip01 R Forearm",
		//"Bip01 R Hand",
		//"Bip01 L Clavicle",
		//"Bip01 L UpperArm",
		//"Bip01 L Forearm",
		//"Bip01 L Hand",
		//"Head",//14
		//"Neck",//14
		//"Bip01 Spine1",
		//"Bip01 Spine",
		//"Bip01",//17
		//"Bip01 Pelvis",//18
		"headBone03",//父节点为Head
		//"bip Head",//父节点为Bip01 Neck
		"Bip01 Neck",
		"Neck",
		//"headBone03",//父节点为Head
		"Head",//父节点为Neck
	};
	for (int i = 0; i < sizeof(ARRAY_BONE_NAMES) / sizeof(const char*); ++i) {
		auto effectModel = g_BlockMtlMgr.getModel("entity/custommodel/point.omod");
		if (!effectModel) {
			continue;
		}
		effectModel->setLayer(RenderLayer::RL_SCENE_FRONT);
		Ogre::ColourValue color(0, 1.0f, 1.0f);
		effectModel->setOverlayColor(&color);
		entity->bindCunstomObject(ARRAY_BONE_NAMES[i], effectModel);
	}
}

ActorBody* AbsAREngine::getRoleSkinActorBody(const int modelID) {
	if (modelID <= 0){
		return m_pActorBody = m_pRoleSkinActorBody;
	}
	if (m_pBoneNamesArray) {
		delete m_pBoneNamesArray;
	}
	m_pBoneNamesArray = new TransformerBoneNamesArray();
	ActorBody* actorBody = newRoleSkinActorBody(modelID);
	OGRE_DELETE(m_pRoleSkinActorBody);
	m_pActorBody = m_pRoleSkinActorBody = actorBody;
	onPostCreateActorBody(actorBody, 33, 33);
	bindHightlights(actorBody);
	if (!actorBody) {
		return actorBody;
	}
	Model* model = actorBody->getModel();
	if (!model) {
		return actorBody;
	}
	ModelData* modelData = model->getModelData();
	if (!modelData) {
		return actorBody;
	}
	modelData->getBoneRelationship();
	modelData->m_iARReadSeqID = 100100;
	return actorBody;
}

ActorBody* AbsAREngine::newRoleSkinActorBody(const int modelID) {
	const RoleSkinDef *skinDef = g_DefMgr.getRoleSkinDef(modelID);
	if (skinDef == NULL) {
		return m_pRoleSkinActorBody;
	}
	ActorBody *actorBody = new ActorBody(NULL);
	int modelIndex = skinDef->Model;
	char path[256];
	sprintf(path, "entity/%d/body.omod", modelIndex);
	const ROLEINFO &roleinfo = g_AccountMgr->m_AccInfo->RoleInfo;
	int rolemodel = roleinfo.Model;
	if (rolemodel == 0) rolemodel = 1;
	int geniuslv = g_AccountMgr->m_AccountData->getGenuisLv(rolemodel);
	if (geniuslv < 0) geniuslv = 0;
	int playerindex = ComposePlayerIndex(rolemodel, geniuslv, modelID);
	actorBody->initPlayer(playerindex, 0, "", 1);
	Model* model = g_BlockMtlMgr.getModel(path);
	actorBody->loadModel(model);
	actorBody->setIsInUI(true);
	return actorBody;
}

ActorBody* AbsAREngine::getAvatarActorBody(const char* szBodyPath){
	if (m_pBoneNamesArray){
		delete m_pBoneNamesArray;
	}
	m_pBoneNamesArray = new TransformerBoneNamesArray();
	if (m_pAvatarActorBody) {
		return m_pActorBody = m_pAvatarActorBody;
	}
	ActorBody* actorBody = newAvatarActorBody(szBodyPath);
	m_pActorBody = m_pAvatarActorBody = actorBody;
	onPostCreateActorBody(actorBody, 33, 33);
	//bindHightlights(actorBody);
	if (!actorBody) {
		return actorBody;
	}
	Model* model = actorBody->getModel();
	if (!model) {
		return actorBody;
	}
	ModelData* modelData = model->getModelData();
	if (!modelData) {
		return actorBody;
	}
	modelData->getBoneRelationship();
	modelData->m_iARReadSeqID = 0;
	return actorBody;
}

ActorBody* AbsAREngine::newAvatarActorBody(const char* szBodyPath){
	ActorBody *actorBody = new ActorBody(NULL);
	char path[256];
	const int avatarModel = 99;

	actorBody->setBodyType(3);
	actorBody->initMonster(szBodyPath, 1.0f);
	//actorBody->initPlayer(0, 0, szBodyPath, 1);
	actorBody->setIsInUI(true);
	actorBody->setAvtBodyID(avatarModel);

	actorBody->addAvatarPartModel(2, 1);
	actorBody->addAvatarPartModel(3, 4);
	actorBody->addAvatarPartModel(4, 6);
	return actorBody;
}

ActorBody* AbsAREngine::getFullyCustomModelActorBody(const char* szCustomModelAnimPath, const char* szCustomModelAnimFilename) {
	if (m_pBoneNamesArray) {
		delete m_pBoneNamesArray;
	}
	m_pBoneNamesArray = new AvatarSimpleBoneNamesArray();
	if (m_pFullyCustomModelActorBody) {
		return m_pActorBody = m_pFullyCustomModelActorBody;
	}
	ActorBody* actorBody = newFullyCustomModelActorBody(szCustomModelAnimPath, szCustomModelAnimFilename);
	m_pActorBody = m_pFullyCustomModelActorBody = actorBody;
	onPostCreateActorBody(actorBody, 33, 330);
	return actorBody;
}

ActorBody* AbsAREngine::newFullyCustomModelActorBody(const char* szCustomModelAnimPath, const char* szCustomModelAnimFilename) {
	FullyCustomModel* fullyCustomModel = new FullyCustomModel();
	bool result = fullyCustomModel->load(szCustomModelAnimPath, szCustomModelAnimFilename, -999);
	if (!result) {
		return NULL;
	}
	ActorBody* actorBody = new ActorBody(NULL);
	actorBody->initFullyCustomActor(MAP_MODEL_CLASS, fullyCustomModel, "", true);
	return actorBody;
}

void AbsAREngine::readDemoPoints(const char* szPath) {
	if (!szPath){
		return;
	}
	CSVParser parser;
	bool loaded = parser.Load(szPath);
	if (!loaded){
		return;
	}
	parser.SetTitleLine(0);
	int column = parser.GetNumCols();
	column = column > 45 ? 45 : column;
	int row = parser.GetNumLines();
	const int curRow = m_iCurStartRow + 1;
	m_iCurStartRow = curRow;
	float *fs = new float[column];
	for (int j = 0; j < column; ++j) {
		fs[j] = parser[curRow% row][j].Float();
	}
	onGetSkeletonPoint(fs, column);
	delete fs;
}
void AbsAREngine::unwrapAll() {
	for (; unwrap(););
}
bool AbsAREngine::unwrap() {
	if (!m_pTransformer) {
		return false;
	}
	AbsTransformer* outerDecortor = m_pTransformer;
	m_pTransformer = m_pTransformer->unwrap();
	delete outerDecortor;
	return true;
}
void AbsAREngine::wrapTransformer(int index) {
	switch (index) {
	case 1: {
		unwrap();
		break;
	}
	case 5: {
		m_pTransformer = new FullyCustomModelStandardBoneLengthTranslationTransformer(m_pTransformer);
		break;
	}
	case 6: {
		m_pTransformer = new PrintTranslationTransformer(m_pTransformer);
		break;
	}
	case 7: {
		m_pTransformer = new PrintRotationTransformer(m_pTransformer);
		break;
	}
	case 9: {
		m_pTransformer = new FullyCustomModelRotationTransformer(m_pTransformer);
		break;
	}
	case 10: {
		m_pTransformer = new FullyCustomModelLengthToAxisTranslationTransformer(m_pTransformer);
		break;
	}
	default:
		break;
	}
	if (index == 11){
		OGRE_DELETE(m_pBoneNamesArray);
		m_pBoneNamesArray = new AvatarBoneNamesArray();
	} else {
		OGRE_DELETE(m_pBoneNamesArray);
		m_pBoneNamesArray = new TransformerBoneNamesArray();
	}
}
void AbsAREngine::setConfidenceLevel(int iConfidenceLevel){
	m_iConfidenceLevel = iConfidenceLevel;
}
int AbsAREngine::getConfidenceLevel(){
	return m_iConfidenceLevel;
}
void AbsAREngine::setAllConfidence(bool bAllConfidence){
	m_bAllConfidence = bAllConfidence;
}
bool AbsAREngine::areAllConfidence(){
	return m_bAllConfidence;
}

void AbsAREngine::onGetSkeletonConfidence(int length, float *confidence) {
}

void AbsAREngine::onGetSkeletonPointIsExist(int length, int *isExist) {
}

void AbsAREngine::onGetSkeletonPoint(float *coordinates, int coordinateLength) {
	if (coordinateLength < 45){
		return;
	}
	setSkeletonPoint(coordinates, coordinateLength);
}

void AbsAREngine::onGetSkeletonPointAndConfidence(float *coordinates, int coordinateLength, float *confidence, int confidenceLength) {
	if (coordinateLength < 45) {
		return;
	}
	if (confidence == NULL || confidenceLength <= 0) {
		onGetSkeletonPoint(coordinates, coordinateLength);
		return;
	}
	setSkeletonPointAndConfidence(coordinates, coordinateLength, confidence, confidenceLength);
}

void AbsAREngine::printBoneNames(){
	if (!m_pActorBody) {
		return;
	}
	Model* model = m_pActorBody->getModel();
	if (!model) {
		return;
	}
	ModelData* modelData = model->getModelData();
	if (!modelData) {
		return;
	}
	SkeletonData* skeletonData = modelData->getSkeletonData();
	if (!skeletonData){
		return;
	}
	BoneData* boneData = NULL;
	BoneData* parentBoneData = NULL;
	int boneId;
	boneId = skeletonData->findBoneID("Bip01");
	if (boneId < 0){
		return;
	}
	const int boneCount = skeletonData->getNumBone();
	LOG_INFO("boneCount(): boneCount = %d", boneCount);
	for (int i = 0; i < boneCount; ++i){
		boneData = skeletonData->getIthBone(i);
		if (!boneData){
			continue;
		}
		LOG_INFO("\"%s\",", boneData->m_Name.c_str());
	}
}

void AbsAREngine::setZFactor(float factor){
	m_fZFactor = factor;
}

float AbsAREngine::getZFactor(){
	return m_fZFactor;
}

void AbsAREngine::setRead2DPoints(bool bRead2DPoints){
	m_bIsReading2DPoints = bRead2DPoints;
}

void AbsAREngine::readHipBone() {
	m_bHasReadHipBone = false;
}

void AbsAREngine::clearHipBone() {
	if (!m_pActorBody) {
		return;
	}
	Model* model = m_pActorBody->getModel();
	if (!model) {
		return;
	}
	ModelData* modelData = model->getModelData();
	if (!modelData) {
		return;
	}
	modelData->m_RightHipBone = Vector3::ZERO;
	modelData->m_LeftHipBone = Vector3::ZERO;
	modelData->m_RightShoulder = Vector3::ZERO;
	modelData->m_LeftShoulder = Vector3::ZERO;
}

void AbsAREngine::setChangeSequenceIdMode(bool yes){
	m_bChangeSequenceIdMode = yes;
}
//===================================================AbsAREngine end===================================================


//===================================================HuaweiAREngine start===================================================
HuaweiAREngine::HuaweiAREngine() : AbsAREngine(){
}

HuaweiAREngine::~HuaweiAREngine(){
}

void HuaweiAREngine::setSkeletonPointAndConfidence(float *coordinates, int coordinateLength, float *confidence, int confidenceLength) {
	if (m_bAllConfidence){
		setSkeletonPointWithAllConfidence(coordinates, coordinateLength, confidence, confidenceLength);
	} else {
		setSkeletonPointWithEachConfidence(coordinates, coordinateLength, confidence, confidenceLength);
	}
}

void HuaweiAREngine::setSkeletonPointWithAllConfidence(float *coordinates, int coordinateLength, float *confidence, int confidenceLength) {
	const float fConfidenceLevel = m_iConfidenceLevel;
	for (int i = 0; i < confidenceLength; ++i) {
		if (confidence[i] * 100.f < fConfidenceLevel) {
			return;
		}
	}
	onGetSkeletonPoint(coordinates, coordinateLength);
}

void HuaweiAREngine::setSkeletonPointWithEachConfidence(float *coordinates, int coordinateLength, float *confidence, int confidenceLength) {
	bool withEachConfidence = m_iConfidenceLevel > 0 && confidence != NULL && confidenceLength > 0;
	if (!m_pActorBody) {
		return;
	}
	Model* model = m_pActorBody->getModel();
	if (!model) {
		return;
	}
	ModelData* modelData = model->getModelData();
	if (!modelData) {
		return;
	}
	if (!m_pBoneNamesArray) {
		return;
	}
	int boneNameLength = m_pBoneNamesArray->length();
	if (boneNameLength < 15){
		return;
	}
	Vector3* skeletonTranslations = new Vector3[boneNameLength];
	Vector3* boneRotations = new Vector3[boneNameLength];
	Vector3 boneZoom(1.f);
	m_vTranslationInput.clear();
	m_vConfidenceInput.clear();
	m_vBoneNamesOutput.clear();
	m_vTranslationOutput.clear();
	m_vRotationOutput.clear();
	m_vScaleOutput.clear();
	m_vConfidenceOutput.clear();
	const float fZFactor = m_fZFactor <= 0.00001f ? 1.f : m_fZFactor;
	for (int i = 0, j = 0; i < coordinateLength && j < boneNameLength; i += 3, ++j) {
		skeletonTranslations[j].x = coordinates[i];
		skeletonTranslations[j].y = coordinates[i + 1];
		skeletonTranslations[j].z = m_bIsReading2DPoints ? 0 : -coordinates[i + 2];
		//skeletonTranslations[j].z *= fZFactor;
		m_vTranslationInput.push_back(skeletonTranslations[j]);
	}
	for (int j = coordinateLength / 3; j < boneNameLength; ++j) {
		skeletonTranslations[j].x = 0;
		skeletonTranslations[j].y = 0;
		skeletonTranslations[j].z = 0;
	}
	for (int i = 0; i < boneNameLength; ++i) {
		boneRotations[i].setPitchYawRoll(0, 0, 0);
	}
	if (withEachConfidence) {
		for (int i = 0; i < confidenceLength; ++i) {
			m_vConfidenceInput.push_back(confidence[i]);
		}
	}
	else {
		for (int i = 0; i < boneNameLength; ++i) {
			m_vConfidenceInput.push_back(1.f);
		}
	}

	Vector3 v14_1 = skeletonTranslations[1] - skeletonTranslations[14];
	//"Bip01 Spine1",
	skeletonTranslations[15] = v14_1 / 4.f * 3.f + skeletonTranslations[14];
	m_vConfidenceInput.push_back(withEachConfidence ? (confidence[14] + confidence[1]) / 2.f : 1.f);
	//"Bip01 Spine",
	skeletonTranslations[16] = v14_1 / 4.f + skeletonTranslations[14];
	m_vConfidenceInput.push_back(withEachConfidence ? (confidence[14] + confidence[1]) / 2.f : 1.f);
	//"Bip01 Pelvis",
	skeletonTranslations[17] = skeletonTranslations[14];
	//skeletonTranslations[17] = v14_1 / 67.f * (-10.f) + skeletonTranslations[14];
	m_vConfidenceInput.push_back(withEachConfidence ? confidence[14] : 1.f);
	//"Bip01 R Clavicle",
	skeletonTranslations[18] = (skeletonTranslations[2] - skeletonTranslations[1]) / 2.f + skeletonTranslations[1];
	m_vConfidenceInput.push_back(withEachConfidence ? confidence[2] : 1.f);
	//skeletonTranslations[18].y = skeletonTranslations[2].y - (skeletonTranslations[2].y + skeletonTranslations[5].y) / 4.f;
	//"Bip01 L Clavicle",
	skeletonTranslations[19] = (skeletonTranslations[5] - skeletonTranslations[1]) / 2.f + skeletonTranslations[1];
	m_vConfidenceInput.push_back(withEachConfidence ? confidence[5] : 1.f);
	//skeletonTranslations[19].y = skeletonTranslations[5].y + (skeletonTranslations[2].y + skeletonTranslations[5].y) / 4.f;
	//"Bip01 Neck",
	skeletonTranslations[20] = skeletonTranslations[1];
	m_vConfidenceInput.push_back(withEachConfidence ? confidence[1] : 1.f);
	//"Bip01 Neck",
	skeletonTranslations[21] = skeletonTranslations[0];
	m_vConfidenceInput.push_back(withEachConfidence ? confidence[0] : 1.f);

	m_vTranslationInput.push_back(skeletonTranslations[15]);
	m_vTranslationInput.push_back(skeletonTranslations[16]);
	m_vTranslationInput.push_back(skeletonTranslations[17]);
	m_vTranslationInput.push_back(skeletonTranslations[18]);
	m_vTranslationInput.push_back(skeletonTranslations[19]);
	m_vTranslationInput.push_back(skeletonTranslations[20]);
	m_vTranslationInput.push_back(skeletonTranslations[21]);

	if (!m_bHasReadHipBone){
		m_bHasReadHipBone = true;
		modelData->m_RightHipBone = skeletonTranslations[8] - skeletonTranslations[14];
		modelData->m_LeftHipBone = skeletonTranslations[11] - skeletonTranslations[14];
		modelData->m_RightShoulder = skeletonTranslations[2] - skeletonTranslations[1];
		modelData->m_LeftShoulder = skeletonTranslations[5] - skeletonTranslations[1];
		Normalize(modelData->m_RightHipBone);
		Normalize(modelData->m_LeftHipBone);
		Normalize(modelData->m_RightShoulder);
		Normalize(modelData->m_LeftShoulder);
	}

	modelData->getCustomKeyFrameByArData(
		m_vBoneNamesInput,
		m_vTranslationInput,
		m_vRotationInput,
		m_vScaleInput,
		m_vConfidenceInput,

		m_vBoneNamesOutput,
		m_vTranslationOutput,
		m_vRotationOutput,
		m_vScaleOutput,
		m_vConfidenceOutput
	);

	if (m_pTransformer) {
		m_pTransformer->transform(boneRotations, boneNameLength, skeletonTranslations, boneNameLength);
	}

	const int writtenSequenceId = PLAY_SEQUENCE_ID_ONE;
	int startTick = m_iStartTick;
	if (startTick < 0) {
		SequenceDesc sequenceDesc = modelData->findSequenceDesc(writtenSequenceId);
		if (&sequenceDesc) {
			m_iStartTick = startTick = sequenceDesc.time_start;
		}
	}
	const double dbConfidenceLevel = m_iConfidenceLevel;
	if (!m_pTransformer) {
		boneNameLength = m_vBoneNamesOutput.size();
	}
	int tick;
	Vector3 translate;
	Quaternion rotate;
	Vector3 scale;
	FixedString boneName;

	for (int i = 0; i < boneNameLength; ++i) {
		if (withEachConfidence) {
			if (i < confidenceLength && confidence[i] * 100.0 < dbConfidenceLevel) {
				continue;
			}
			/*if (i < m_vConfidenceOutput.size() && m_vConfidenceOutput[i] * 100.0 < dbConfidenceLevel) {
			continue;
			}*/
		}
		tick = startTick + m_iCurrentTick;
		if (m_pTransformer) {
			boneName = m_pBoneNamesArray->get(i);
			translate = skeletonTranslations[i];
			rotate = Quaternion::Euler(boneRotations[i]);
			scale = boneZoom;
		}
		else {
			boneName = m_vBoneNamesOutput[i];
			translate = m_vTranslationOutput[i];
			rotate = m_vRotationOutput[i];
			scale = m_vScaleOutput[i];
		}
		modelData->insertCustomKeyFrame(
			writtenSequenceId,
			boneName,
			tick,
			translate,
			rotate,
			scale
		);
	}
	m_iCurrentTick += s_KeyFrameTickInterval;
	if (!m_bHasPlayedAnimation && m_iCurrentTick >= 100) {
		m_bHasPlayedAnimation = true;
		m_pActorBody->playAnimBySeqId(writtenSequenceId);
	}
	for (int i = 0; i < boneNameLength; ++i) {
		if (withEachConfidence) {
			if (i < confidenceLength && confidence[i] * 100.0 < dbConfidenceLevel) {
				continue;
			}
		}
		tick = startTick + m_iCurrentTick;
		if (m_pTransformer) {
			boneName = m_pBoneNamesArray->get(i);
			translate = skeletonTranslations[i];
			rotate = Quaternion::Euler(boneRotations[i]);
			scale = boneZoom;
		}
		else {
			boneName = m_vBoneNamesOutput[i];
			translate = m_vTranslationOutput[i];
			rotate = m_vRotationOutput[i];
			scale = m_vScaleOutput[i];
		}
		modelData->insertCustomKeyFrame(
			writtenSequenceId,
			boneName,
			tick,
			translate,
			rotate,
			scale
		);
	}
	if (m_iCurrentTick >= s_KeyFrameTickRange) {
		m_iCurrentTick = 0;
	}
	m_pActorBody->playAnimBySeqId(writtenSequenceId);
}
void HuaweiAREngine::setSkeletonPoint(float *coordinates, int coordinateLength) {
	setSkeletonPointWithEachConfidence(coordinates, coordinateLength, NULL, 0);
}
//===================================================HuaweiAREngine end===================================================