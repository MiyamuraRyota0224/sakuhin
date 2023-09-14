#include "ClearCamera.h"
#include "../Player/PlayerManager.h"
#include "../Common/MyMath.h"

namespace {
	constexpr float CAMERA_NEAR_CLIP = 0.1f;				// �j�A�N���b�v
	constexpr float CAMERA_FAR_CLIP = 450.0f;				// �t�@�[�N���b�v
	constexpr VECTOR CAMERA_POS = { 5.0f, 10.0f, 20.0f };	// �Œ���W
	constexpr VECTOR CAMERA_LOOK = { 0.0f, 10.0f, 50.0f };	// �Œ蒍���_
}

ClearCamera::ClearCamera() : CameraBase()
{
}

ClearCamera::~ClearCamera()
{
	Fin();
}

void ClearCamera::Init()
{
	pos_ = CAMERA_POS;
	look_ = CAMERA_LOOK;
	SetCameraNearFar(CAMERA_NEAR_CLIP, CAMERA_FAR_CLIP);
}

void ClearCamera::Step()
{
}

void ClearCamera::Draw()
{
}

void ClearCamera::Fin()
{
}