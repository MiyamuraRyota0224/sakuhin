
//SceneBase.cpp
//シーン用基底クラス

#include "Scene.h"
#include "SceneParameter.h"
#include "SceneManager.h"
#include "../Common/Fade.h"
#include "../Sound/SoundManager.h"

Scene::Scene()
{
	state_ = SCENE_STATE_NONE;
	next_scene_ = -1;
}

Scene::~Scene()
{
}

void Scene::Step()
{
	if (state_ == SCENE_STATE_FADEIN && Fade::IsFadeEnd()) {
		SceneManager::GetInstance()->GetNowScene()->OnFadeinEnd();
	}
	if (state_ == SCENE_STATE_FADEOUT && Fade::IsFadeEnd()) {
		SceneManager::GetInstance()->ChangeScene(next_scene_);
	}
}

void Scene::ChangeScene(int next_scene, int fade_time)
{
	if (Fade::IsFadeEnd()) {
		Fade::FadeOut(fade_time);
		next_scene_ = next_scene;
		state_ = SCENE_STATE_FADEOUT;
	}
}

void Scene::OnFadeinEnd()
{
	state_ = SCENE_STATE_NONE;
}
