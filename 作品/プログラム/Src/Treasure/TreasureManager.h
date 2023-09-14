#pragma once

#include "Treasure.h"

class TreasureManager {
public:
	TreasureManager();
	~TreasureManager();

public:
	static void CreateInstance() { if (!instance_) instance_ = new TreasureManager; }
	static TreasureManager* GetInstance() { return instance_; }
	static void DeleteInstance() { if (instance_) delete instance_; instance_ = nullptr; }

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	CTreasure* CreateTreasure() { if (!treasure_)treasure_ = new CTreasure; return treasure_; }
	CTreasure* GetTreasure() const { return treasure_; }
	void DeleteTreasure() { if (treasure_)delete treasure_; }

private:
	static TreasureManager* instance_;

	CTreasure* treasure_;

};
