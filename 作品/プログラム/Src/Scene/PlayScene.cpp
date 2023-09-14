#include "DxLib.h"
#include "PlayScene.h"
#include "../Scene/SceneManager.h"
#include "../Scene/SceneParameter.h"
#include "../Camera/CameraManager.h"
#include "../Camera/CameraParameter.h"
#include "../Player/PlayerManager.h"
#include "../Cristal/CristalManager.h"
#include "../Treasure//TreasureManager.h"
#include "../Stage/StageManager.h"
#include "../Stage/StageParameter.h"
#include "../Maze/MazeManager.h"
#include "../Time/TimeManager.h"
#include "../Collision/CollisionManager.h"
#include "../Sound/SoundManager.h"


#ifdef _DEBUG
#include "../Input/Input.h"
#endif

namespace {
	
}

Play::Play() : Scene()
{
	
}

Play::~Play()
{
}

void Play::Init()
{
	InitCollision();
	InitPlayer();
	InitCristal();
	InitTreasure();
	InitStage();
	InitMaze();
	InitTime();
	InitCamera();
}

void Play::Load()
{
	LoadPlayer();
	LoadCristal();
	LoadTreasure();
	LoadStage();
	LoadMaze();
	LoadSound();
}

void Play::OnLoadEnd()
{
	SoundManager::PlayBGM(SOUND_ID_BGM_PLAY_SCENE);

	StageManager::GetInstance()->OnLoadEnd();
	state_ = SCENE_STATE_FADEIN;

	MazeManager::GetInstance()->OnLoadEnd();
}

void Play::Step()
{
	Scene::Step();

	PlayerManager::GetInstance()->Step();
	CristalManager::GetInstance()->Step();
	TreasureManager::GetInstance()->Step();
	TimeManager::GetInstance()->Step();
	CameraManager::GetInstance()->Step();
	StageManager::GetInstance()->Step();
	CollisionManager::GetInstance()->Step();
	CollisionManager::GetInstance()->CheckCollision();

}

void Play::Update()
{
	PlayerManager::GetInstance()->Update();
	CristalManager::GetInstance()->Update();
	TreasureManager::GetInstance()->Update();
	CameraManager::GetInstance()->Update();
	StageManager::GetInstance()->Update();
	MazeManager::GetInstance()->Update();
	CollisionManager::GetInstance()->Update();
}

void Play::Draw()
{
	StageManager::GetInstance()->Draw();
	MazeManager::GetInstance()->Draw();
	PlayerManager::GetInstance()->Draw();
	CristalManager::GetInstance()->Draw();
	TreasureManager::GetInstance()->Draw();
	TimeManager::GetInstance()->Draw();
	CameraManager::GetInstance()->Draw();
	//CollisionManager::GetInstance()->Draw(); // 当たり判定を可視化したい場合は有効にする
}

void Play::Fin()
{
	// プレイシーンのみで使用するものを削除
	PlayerManager::DeleteInstance();
	CristalManager::DeleteInstance();
	TreasureManager::DeleteInstance();
	MazeManager::DeleteInstance();
	CameraManager::DeleteInstance();
	StageManager::DeleteInstance();
	TimeManager::DeleteInstance();
	CollisionManager::DeleteInstance();
	SoundManager::DeleteSound(SOUND_GROUP_PLAY);
}

void Play::OnFadeinEnd()
{
	
}

void Play::InitPlayer()
{
	PlayerManager::CreateInstance();
	PlayerManager::GetInstance()->CreatePlayer();
	PlayerManager::GetInstance()->Init();
}

void Play::InitCristal()
{
	CristalManager::CreateInstance();
	CristalManager::GetInstance()->CreateCristal();
	CristalManager::GetInstance()->Init();
}

void Play::InitTreasure()
{
	TreasureManager::CreateInstance();
	TreasureManager::GetInstance()->CreateTreasure();
	TreasureManager::GetInstance()->Init();
}

void Play::InitStage()
{
	StageManager::CreateInstance();
	StageManager::GetInstance()->CreateStage(STAGE_ID_STAGE1);
	StageManager::GetInstance()->Init();
}

void Play::InitMaze()
{
	MazeManager::CreateInstance();
	MazeManager::GetInstance()->Init();
}

void Play::InitTime()
{
	TimeManager::CreateInstance();
	TimeManager::GetInstance()->CreateTime();
	TimeManager::GetInstance()->Init();
}

void Play::InitCamera()
{
	CameraManager::CreateInstance();
	CameraManager::GetInstance()->StartCamera(CAMERA_ID_PLAY);
}

void Play::InitEffect()
{
	
}

void Play::InitCollision()
{
	CollisionManager::CreateInstance();
	CollisionManager::GetInstance()->Init();
}

void Play::InitUI()
{
}

void Play::LoadPlayer()
{
	PlayerManager::GetInstance()->Load();
}

void Play::LoadCristal()
{
	CristalManager::GetInstance()->Load();
}

void Play::LoadTreasure()
{
	TreasureManager::GetInstance()->Load();
}

void Play::LoadStage()
{
	StageManager::GetInstance()->Load();
}

void Play::LoadMaze()
{
	MazeManager::GetInstance()->Load();
}

void Play::LoadEffect()
{
	
}

void Play::LoadSound()
{
	SoundManager::Load(SOUND_GROUP_PLAY);
}

void Play::LoadUI()
{
	

}
