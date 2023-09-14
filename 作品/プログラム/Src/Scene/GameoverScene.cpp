
#include "GameoverScene.h"
#include "SceneParameter.h"
#include "../Input/Input.h"
#include "../Stage/StageManager.h"
#include "../Stage/StageParameter.h"
#include "../Camera/CameraManager.h"
#include "../Camera/CameraParameter.h"
#include "../Scene/SceneManager.h"
#include "../Common/Fade.h"
#include "../UI/GameUIManager.h"
#include "../UI/GameUIParameter.h"
#include "../UI/GameUIAnimation.h"

namespace {
	constexpr int FADEIN_TIME = 120;
	constexpr int FADEOUT_TIME = 120;
	constexpr float LOGO_POS_X = 190.0f;
	constexpr float LOGO_POS_Y = 120.0f;
	constexpr float LOGO_FLOATING_SPEED = 0.03f;
	constexpr float LOGO_FLOATING_SIZE = 10.0f;
	constexpr float PRESS_ENTER_KEY_POS_X = 240.0f;
	constexpr float PRESS_ENTER_KEY_POS_Y = 420.0f;
	constexpr float PRESS_ENTER_KEY_BLINK_SPEED = 0.02f;
}

Gameover::Gameover() : Scene()
{
	ui_logo_ = nullptr;
	ui_press_ = nullptr;
}

Gameover::~Gameover()
{

}

void Gameover::Init()
{
	
}

void Gameover::Load()
{
	handle_ = LoadGraph("Data/UI/Gameover/gameover.png");
}

void Gameover::OnLoadEnd()
{
	
}

void Gameover::Step()
{
	//エンターキーを押したら
	if (CInput::IsPush(KEY_ENTER))
	{
		//タイトルシーンへ
		SceneManager::GetInstance()->ChangeScene(SCENE_ID_TITLE);
	}
}

void Gameover::Update()
{
	
}

void Gameover::Draw()
{
	DrawGraph(0, 0, handle_, true);
}

void Gameover::Fin()
{
	
}