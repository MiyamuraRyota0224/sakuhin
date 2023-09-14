#pragma once

//SceneManager.h
//シーン管理
//各シーンへのアクセスは必ずSceneManagerを経由

#include "Scene.h"

class SceneManager
{
public:
	static void CreateInstance() { if (!instance_) instance_ = new SceneManager; }
	static SceneManager* GetInstance() { return instance_; }
	static void DeleteInstance() { if (instance_) delete instance_; instance_ = nullptr; }

public:

	SceneManager();
	~SceneManager();

	//初期化
	void Init();

	//ループ
	void Loop();

	//後処理
	void Fin();

	//１番最初のシーンを開始する
	void StartFirstScene(int sceneID);

	//引数のシーンに変更する
	void ChangeScene(int sceneID);

	// 現在のシーンを取得する
	Scene* GetNowScene() const { return scene_; }

private:
	//シーンを生成する
	void CreateScene(int sceneID);

	//次の画面に遷移させる
	void ChangeNextScene();

	// シーンループ中の各関数
	void SceneInit();
	void SceneLoad();
	void SceneLoadEnd();
	void SceneLoop();
	void SceneFin();

private:
	//インスタンス
	static SceneManager *instance_;

	//現在のシーンID
	int current_scene_id_;
	int next_scene_id_;
	int current_scene_state_;

	//基底ポインタ１つで管理する
	Scene *scene_;
};
