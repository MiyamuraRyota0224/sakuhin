
//SceneManager.cpp
//シーン管理
//各シーンへのアクセスは必ずSceneManagerを経由

#include "SceneManager.h"
#include "SceneParameter.h"
#include "PlayScene.h"
#include "TitleScene.h"
#include "GameoverScene.h"
#include "ClearScene.h"
#ifdef _DEBUG
#include "../Input/Input.h"
#endif


SceneManager *SceneManager::instance_ = nullptr;

SceneManager::SceneManager()
: scene_(nullptr)
, current_scene_state_(SCENE_STATE_INIT)
{
	scene_ = nullptr;
	current_scene_state_ = SCENE_STATE_INIT;
	next_scene_id_ = SCENE_ID_NUM;
	current_scene_id_ = SCENE_ID_NUM;
}

SceneManager::~SceneManager()
{
}

//初期化
void SceneManager::Init()
{
	//ここはシーン管理の初期化であって、
	//各シーンの初期化ではない
}

//ループ
void SceneManager::Loop()
{
	void (SceneManager:: * scene_func[])() = {
		&SceneManager::SceneInit,
		& SceneManager::SceneLoad,
		& SceneManager::SceneLoadEnd,
		& SceneManager::SceneLoop,
		& SceneManager::SceneFin,
	};

	(this->*scene_func[current_scene_state_])();
}

// シーンループ中の各関数
void SceneManager::SceneInit()
{
	scene_->Init();
	current_scene_state_ = SCENE_STATE_LOAD;
}

void SceneManager::SceneLoad()
{
	scene_->Load();
	current_scene_state_ = SCENE_STATE_LOAD_END;
}

void SceneManager::SceneLoadEnd()
{
	scene_->OnLoadEnd();
	current_scene_state_ = SCENE_STATE_LOOP;
}

void SceneManager::SceneLoop()
{
#ifdef _DEBUG
	// デバッグの早送り機能
	int loop = 1;
	if (CInput::IsCont(KEY_Z)) {
		loop = 10;
	}
	for (int i = 0; i < loop; i++) {
		scene_->Step();
		scene_->Update();
	}
	scene_->Draw();	//描画はステップの後に呼ぶ
#else
	scene_->Step();
	scene_->Update();
	scene_->Draw();	//描画はステップの後に呼ぶ
#endif
}

void SceneManager::SceneFin()
{
	scene_->Fin();
	ChangeNextScene();
}

//後処理
void SceneManager::Fin()
{
	if (scene_) {
		delete scene_;
	}
}

//１番最初のシーンを開始する
void SceneManager::StartFirstScene(int sceneID)
{
	//既に何かシーンが動いてるのであれば即終了
	if (scene_) return;

	//シーンを生成して初期化から開始する
	CreateScene(sceneID);
	current_scene_id_ = sceneID;
	current_scene_state_ = SCENE_STATE_INIT;
}

//引数のシーンに変更する
void SceneManager::ChangeScene(int sceneID)
{
	//次に遷移するシーンを覚えておき、終了処理へ
	next_scene_id_ = sceneID;
	current_scene_state_ = SCENE_STATE_FIN;
}

//シーンを生成する
void SceneManager::CreateScene(int sceneID)
{
	//シーンを生成
	switch (sceneID) {
		case SCENE_ID_TITLE: scene_ = new Title; break;
		case SCENE_ID_PLAY: scene_ = new Play; break;
		case SCENE_ID_CLEAR: scene_ = new Clear; break;
		case SCENE_ID_GAMEOVER: scene_ = new Gameover; break;
	}
}

//次のシーンに遷移する
void SceneManager::ChangeNextScene()
{
	//終了したシーンを削除
	delete scene_;
	//次のシーンを生成
	CreateScene(next_scene_id_);
	//現在のシーンID設定
	current_scene_id_ = next_scene_id_;
	//状態を初期化に戻す
	current_scene_state_ = SCENE_STATE_INIT;
}