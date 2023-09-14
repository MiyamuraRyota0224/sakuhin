#include "PlayCamera.h"
#include "../Player/PlayerManager.h"
#include "../Stage/StageManager.h"
#include "../Common/MyMath.h"
#include "../Common/Common.h"
#include <algorithm>

using namespace std;

namespace {
	constexpr float CAMERA_HEIGHT = 1.5f;
	constexpr float CAMERA_DIR = 10.0f;
	constexpr float CAMERA_OFFSET_LOOK_Y = 10.0f;
	constexpr float CAMERA_OFFSET_POS = -30.0f;
}

PlayCamera::PlayCamera() : CameraBase()
{
}

PlayCamera::~PlayCamera()
{
	Fin();
}

void PlayCamera::Init()
{
	SetCameraNearFar(0.1f, 700.0f);
}

void PlayCamera::Step()
{

	// プレイヤー情報取得
	CPlayer* player = PlayerManager::GetInstance()->GetPlayer();
	VECTOR player_pos = player->GetPos();
	rot_ = player->GetRot();
	pos_ = player_pos;
	// 視点をプレイヤーの上へ
	pos_.y = pos_.y + CAMERA_HEIGHT;
	// 注視点をプレイヤーの前へ
	dir_.x = sinf(rot_.y);
	dir_.z = cosf(rot_.y);
	VECTOR dir = MyMath::VecScale(dir_, CAMERA_DIR);
	look_ = MyMath::VecAdd(player_pos, dir);
	look_.y = CAMERA_HEIGHT;

}

void PlayCamera::Draw()
{
}

void PlayCamera::Fin()
{
}