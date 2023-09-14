#pragma once
// 背景となるステージ用クラス
#include "../Map/Map.h"

class Stage {
public:
	Stage(int id);
	~Stage();

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	void SetSkyPos(VECTOR pos) { sky_pos_ = pos; }

private:
	int id_;
	int sky_hndl_;
	VECTOR sky_pos_;
	Map* map_;
};
