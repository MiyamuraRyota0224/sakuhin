#pragma once

#include "Player.h"

class PlayerManager {
public:
	PlayerManager();
	~PlayerManager();

public:
	static void CreateInstance() { if (!instance_) instance_ = new PlayerManager; }
	static PlayerManager* GetInstance() { return instance_; }
	static void DeleteInstance() { if (instance_) delete instance_; instance_ = nullptr; }

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	CPlayer* CreatePlayer() { if (!player_)player_ = new CPlayer; return player_; }
	CPlayer* GetPlayer() const { return player_; }
	void DeletePlayer() { if (player_)delete player_; }

private:
	static PlayerManager* instance_;

	CPlayer* player_;

};
