#include "TitleScene.h"
#include "SceneParameter.h"
#include "../Stage/StageManager.h"
#include "../Stage/StageParameter.h"
#include "../Camera/CameraManager.h"
#include "../Camera/CameraParameter.h"
#include "../Input/Input.h"
#include "../Scene/SceneManager.h"
#include "../Common/Fade.h"
#include "../UI/GameUIManager.h"
#include "../UI/GameUIParameter.h"
#include "../UI/GameUIAnimation.h"
#include "../Sound/SoundManager.h"

namespace {
	constexpr int FADEIN_TIME = 120;
	constexpr int FADEOUT_TIME = 120;
	constexpr float LOGO_POS_X = 190.0f;
	constexpr float LOGO_POS_Y = 60.0f;
	constexpr float LOGO_FLOATING_SPEED = 0.03f;
	constexpr float LOGO_FLOATING_SIZE = 10.0f;
	constexpr float PRESS_ENTER_KEY_POS_X = 380.0f;
	constexpr float PRESS_ENTER_KEY_POS_Y = 420.0f;
	constexpr float PRESS_ENTER_KEY_BLINK_SPEED = 0.02f;
}

Title::Title() : Scene()
{
	ui_logo_ = nullptr;
	ui_press_ = nullptr;
	handle_ = -1;
}

Title::~Title()
{
}

void Title::Init()
{
	
}

void Title::Load()
{
	handle_ = LoadGraph("Data/UI/Title/title.png");
}

void Title::OnLoadEnd()
{
	
}

void Title::Step()
{
	Scene::Step();

	// フェードインが終わってから入力を受け付ける
	if (CInput::IsPush(KEY_ENTER)) {
		// SE再生
		//SoundManager::PlaySE(SOUND_ID_SE_DECISION);
		// シーン遷移
		SceneManager::GetInstance()->ChangeScene(SCENE_ID_PLAY);
	}
}

void Title::Update()
{
	
}

void Title::Draw()
{
	DrawGraph(0, 0, handle_, true);
}

void Title::Fin()
{
	
}
