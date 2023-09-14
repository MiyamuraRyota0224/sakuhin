#include "TreasureManager.h"

TreasureManager* TreasureManager::instance_ = nullptr;

TreasureManager::TreasureManager()
{
	treasure_ = nullptr;
}

TreasureManager::~TreasureManager()
{
	Fin();
}

void TreasureManager::Init()
{
	if (treasure_) {
		treasure_->Init();
	}
}

void TreasureManager::Load()
{
	if (treasure_) {
		treasure_->Load();
	}
}

void TreasureManager::Step()
{
	if (treasure_) {
		treasure_->Step();
	}
}

void TreasureManager::Update()
{
	if (treasure_) {
		treasure_->Update();
	}
}

void TreasureManager::Draw()
{
	if (treasure_) {
		treasure_->Draw();
	}
}

void TreasureManager::Delete()
{
	if (treasure_) {
		delete treasure_;
		treasure_ = nullptr;
	}
}

void TreasureManager::Fin()
{
	Delete();
}