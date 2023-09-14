#include "GameUIManager.h"
#include "GameUIParameter.h"
#include "GameUIAnimation.h"

GameUIManager *GameUIManager::instance_ = nullptr;

GameUIManager::GameUIManager()
{
}

GameUIManager::~GameUIManager()
{
	Fin();
}

// UI����
GameUI* GameUIManager::CreateUI(int type)
{
	GameUI* ui = nullptr;
	switch (type) {
		case UI_TYPE_SPRITE: ui = new GameUISprite; break;
	}

	ui_vec_.push_back(ui);
	return ui;
}

GameUI* GameUIManager::CreateUI(int type, float pos_x, float pos_y, const char *file_path)
{
	GameUI *ui = CreateUI(type);
	ui->Init(pos_x, pos_y);
	ui->Load(file_path);

	return ui;
}

void GameUIManager::Step()
{
	for (auto itr : ui_vec_ ) {
		itr->Step();
	}
}

void GameUIManager::Draw()
{
	for (auto itr : ui_vec_) {
		itr->Draw();
	}
}

void GameUIManager::Fin()
{
	DeleteAll();
}

// vector����UI�����ׂč폜
void GameUIManager::DeleteAll()
{
	// �܂�UI���폜���Ă���
	for (auto itr = ui_vec_.begin(); itr != ui_vec_.end(); itr++) {
		GameUI *ui = (*itr);
		delete ui;
	}
	// �z����폜����
	ui_vec_.clear();
	ui_vec_.shrink_to_fit();

	// UI�A�j���[�V�������폜
	GameUIAnimationManager::DeleteAnimation();
}

