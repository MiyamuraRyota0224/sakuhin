#include "MapManager.h"

MapManager* MapManager::instance_ = nullptr;

MapManager::MapManager()
{
	map_ = nullptr;
}

MapManager::~MapManager()
{
	Fin();
}

void MapManager::Init()
{
	if (map_) {
		map_->Init();
	}
}

void MapManager::Load()
{
	if (map_) {
		map_->Load();
	}
}

void MapManager::Step()
{
	if (map_) {
		map_->Step();
	}
}

void MapManager::Update()
{
	if (map_) {
		map_->Update();
	}
}

void MapManager::Draw()
{
	if (map_) {
		map_->Draw();
	}
}

void MapManager::Delete()
{
	DeleteMap();
}

void MapManager::Fin()
{
	Delete();
}

Map* MapManager::CreateMap(int id)
{
	if (map_) {
		DeleteMap();
	}

	map_ = new Map(id);

	return map_;
}

void MapManager::DeleteMap()
{
	if (map_) {
		map_->Delete();
		delete map_;
		map_ = nullptr;
	}
}
