#pragma once

#include "GameUISprite.h"
#include <vector>

//UIä«óùópÉNÉâÉX
class GameUIManager {
public:
	GameUIManager();
	~GameUIManager();

public:
	static void CreateInstance() { if (!instance_) instance_ = new GameUIManager; }
	static GameUIManager* GetInstance() { return instance_; }
	static void DeleteInstance() { if (instance_) delete instance_; instance_ = nullptr; }

public:
	GameUI* CreateUI(int type);
	GameUI* CreateUI(int type, float pos_x, float pos_y, const char *file_path);

	void Step();
	void Draw();
	void Fin();
	void DeleteAll();

private:
	static GameUIManager *instance_;
	std::vector<GameUI*> ui_vec_;
};

