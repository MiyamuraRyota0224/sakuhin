
#include "ClearScene.h"
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
	constexpr float LOGO_POS_X = 150.0f;
	constexpr float LOGO_POS_Y = 120.0f;
	constexpr float LOGO_FLOATING_SPEED = 0.03f;
	constexpr float LOGO_FLOATING_SIZE = 10.0f;
	constexpr float PRESS_ENTER_KEY_POS_X = 240.0f;
	constexpr float PRESS_ENTER_KEY_POS_Y = 420.0f;
	constexpr float PRESS_ENTER_KEY_BLINK_SPEED = 0.02f;
}

Clear::Clear() : Scene()
{
	ui_logo_ = nullptr;
	ui_press_ = nullptr;
}

Clear::~Clear()
{

}

void Clear::Init()
{
	
}

void Clear::Load()
{
	handle_ = LoadGraph("Data/UI/Clear/clear.png");
}

void Clear::OnLoadEnd()
{
	
}

void Clear::Step()
{
	//エンターキーを押したら
	if (CInput::IsCont(KEY_ENTER))
	{
		//タイトルシーンへ
		SceneManager::GetInstance()->ChangeScene(SCENE_ID_TITLE);
	}
}

void Clear::Update()
{
	
}

void Clear::Draw()
{
	DrawGraph(0, 0, handle_, true);
}

void Clear::Fin()
{
	
}