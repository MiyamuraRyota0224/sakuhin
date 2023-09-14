#include "TimeManager.h"

TimeManager* TimeManager::instance_ = nullptr;

TimeManager::TimeManager()
{
	time_ = nullptr;
}

TimeManager::~TimeManager()
{
	Fin();
}

void TimeManager::Init()
{
	if (time_) {
		time_->Init();
	}
}

void TimeManager::Load()
{
	if (time_) {
		time_->Load();
	}
}

void TimeManager::Step()
{
	if (time_) {
		time_->Step();
	}
}

void TimeManager::Update()
{
	if (time_) {
		time_->Update();
	}
}

void TimeManager::Draw()
{
	if (time_) {
		time_->Draw();
	}
}

void TimeManager::Delete()
{
	if (time_) {
		delete time_;
		time_ = nullptr;
	}
}

void TimeManager::Fin()
{
	Delete();
}

void TimeManager::Reset()
{
	time_->Reset();
}