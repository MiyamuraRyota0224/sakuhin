#include "CristalManager.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneParameter.h"

CristalManager* CristalManager::instance_ = nullptr;

CristalManager::CristalManager()
{
	cristal_ = nullptr;
}

CristalManager::~CristalManager()
{
	Fin();
}

void CristalManager::Init()
{
	if (cristal_) {
		cristal_->Init();
	}
}

void CristalManager::Load()
{
	if (cristal_) {
		cristal_->Load();
	}
}

void CristalManager::Step()
{
	if (cristal_) {
		cristal_->Step();
	}
}

void CristalManager::Update()
{
	if (cristal_) {
		cristal_->Update();
	}
}

void CristalManager::Draw()
{
	if (cristal_) {
		cristal_->Draw();
	}
}

void CristalManager::Delete()
{
	if (cristal_) {
		delete cristal_;
		cristal_ = nullptr;
	}
}

void CristalManager::Fin()
{
	Delete();
}

