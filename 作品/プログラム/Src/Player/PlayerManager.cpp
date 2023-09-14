#include "PlayerManager.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneParameter.h"

PlayerManager* PlayerManager::instance_ = nullptr;

PlayerManager::PlayerManager()
{
	player_ = nullptr;
}

PlayerManager::~PlayerManager()
{
	Fin();
}

void PlayerManager::Init()
{
	if (player_) {
		player_->Init();
	}
}

void PlayerManager::Load()
{
	if (player_) {
		player_->Load();
	}
}

void PlayerManager::Step()
{
	if (player_) {
		player_->Step();
	}
}

void PlayerManager::Update()
{
	if (player_) {
		player_->Update();
	}
}

void PlayerManager::Draw()
{
	if (player_) {
		player_->Draw();
	}
}

void PlayerManager::Delete()
{
	if (player_) {
		delete player_;
		player_ = nullptr;
	}
}

void PlayerManager::Fin()
{
	Delete();
}

