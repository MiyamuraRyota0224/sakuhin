#include "StageManager.h"
#include "../Map/MapManager.h"

StageManager* StageManager::instance_ = nullptr;

StageManager::StageManager()
{
	stage_ = nullptr;
	now_stage_id_ = -1;
	MapManager::CreateInstance();
}

StageManager::~StageManager()
{
	Fin();
}

void StageManager::Init()
{
	if (stage_) {
		stage_->Init();
	}
}

void StageManager::Load()
{
	if (stage_) {
		stage_->Load();
	}
}

void StageManager::OnLoadEnd()
{

}

void StageManager::Step()
{
	if (stage_) {
		stage_->Step();
	}
}

void StageManager::Update()
{
	if (stage_) {
		stage_->Update();
	}
}

void StageManager::Draw()
{
	if (stage_) {
		stage_->Draw();
	}
}

void StageManager::Delete()
{
	if (stage_) {
		stage_->Delete();
		delete stage_;
		stage_ = nullptr;
	}

	// ƒ}ƒbƒv‚â‹ó‚àíœ
	MapManager::DeleteInstance();
}

void StageManager::Fin()
{
	Delete();
}
