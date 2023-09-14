#pragma once

#include <DxLib.h>

class Map {
public:
	Map(int id);
	~Map();

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	int GetColHandle() { return handle_; }

private:
	int id_;
	int handle_;
};
