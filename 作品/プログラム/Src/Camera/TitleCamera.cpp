#include "TitleCamera.h"
#include "../Player/PlayerManager.h"
#include "../Common/MyMath.h"

namespace {
	constexpr float CAMERA_NEAR_CLIP = 0.1f;				// ニアクリップ
	constexpr float CAMERA_FAR_CLIP = 450.0f;				// ファークリップ
	constexpr VECTOR CAMERA_POS = { 5.0f, 10.0f, 20.0f };	// 固定座標
	constexpr VECTOR CAMERA_LOOK = { 0.0f, 10.0f, 50.0f };	// 固定注視点
}

TitleCamera::TitleCamera() : CameraBase()
{
}

TitleCamera::~TitleCamera()
{
	Fin();
}

void TitleCamera::Init()
{
	pos_ = CAMERA_POS;
	look_ = CAMERA_LOOK;
	SetCameraNearFar(CAMERA_NEAR_CLIP, CAMERA_FAR_CLIP);
}

void TitleCamera::Step()
{
}

void TitleCamera::Draw()
{
}

void TitleCamera::Fin()
{
}