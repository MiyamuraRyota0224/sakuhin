#include "Time.h"
#include "../Common/Common.h"
#include "../Scene/SceneManager.h"
#include "../Scene/SceneParameter.h"
#include "../Player/PlayerManager.h"
#include "../Treasure/TreasureManager.h"
#include "DxLib.h"

namespace {
	// 制限時間
	constexpr float TIME_RIMIT = 180.0f;

	// 描画座標
	constexpr int POS_X = 1100;
	constexpr int POS_Y = 20;
}

CTime::CTime()
{
	timer_ = 0.0f;
	isReset_ = false;
}

CTime::~CTime()
{

}

void CTime::Init()
{
	timer_ = TIME_RIMIT;
}

void CTime::Load()
{

}

void CTime::Step()
{
	timer_ -= 1 / GetFPS();
	if (timer_ < 0)
	{
		SceneManager::GetInstance()->ChangeScene(SCENE_ID_GAMEOVER);
	}
}

void CTime::Update()
{

}

void CTime::Draw()
{
	SetFontSize(36);
	DrawFormatString(POS_X, POS_Y, GetColor(255, 255, 255), "%.2f", timer_);
	// 60秒以下になったら表示を赤くする
	if(timer_ <= 60.0f)
		DrawFormatString(POS_X, POS_Y, GetColor(255, 0, 0), "%.2f", timer_);
	SetFontSize(16);
}

void CTime::Delete()
{

}

void CTime::Fin()
{

}

void CTime::Reset()
{
	// 制限時間を元に戻す
	timer_ = TIME_RIMIT;

	// プレイヤーリセット

	// トレジャーリセット

}