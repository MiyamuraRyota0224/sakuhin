#pragma once

#include "Map.h"

class MapManager {
public:
	MapManager();
	~MapManager();

public:
	static void CreateInstance() { if (!instance_) instance_ = new MapManager; }
	static MapManager* GetInstance() { return instance_; }
	static void DeleteInstance() { if (instance_) delete instance_; instance_ = nullptr; }

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	Map* CreateMap(int id);
	Map* GetMap() const { if(map_) return map_; }
	void DeleteMap();

private:
	static MapManager* instance_;
	Map* map_;
};
