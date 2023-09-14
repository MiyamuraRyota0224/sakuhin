#include "CameraManager.h"
#include "CameraParameter.h"
#include "PlayCamera.h"
#include "TitleCamera.h"
#include "ClearCamera.h"
#include "GameoverCamera.h"

CameraManager* CameraManager::instance_ = nullptr;

CameraManager::CameraManager()
	: camera_(nullptr)
{
	Init();
}

CameraManager::~CameraManager()
{
}

void CameraManager::Init()
{
}

void CameraManager::Step()
{
	camera_->Step();
}

void CameraManager::Update()
{
	camera_->Update();
}

void CameraManager::Draw()
{
	camera_->Draw();
}

void CameraManager::Fin()
{
}

// カメラ起動処理（既に起動していたものは停止します）
void CameraManager::StartCamera(int id)
{
	if (camera_) delete camera_;

	switch (id) {
	case CAMERA_ID_TITLE: camera_ = new TitleCamera; break;
	case CAMERA_ID_PLAY: camera_ = new PlayCamera; break;
	case CAMERA_ID_CLEAR: camera_ = new ClearCamera; break;
	case CAMERA_ID_GAMEOVER: camera_ = new GameoverCamera; break;
	}
	camera_->Init();
}