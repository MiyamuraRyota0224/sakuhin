#pragma once

#include "Maze.h"
#include "Goal.h"

class MazeManager {
public:
	MazeManager();
	~MazeManager();

public:
	static void CreateInstance() { if (!instance_) instance_ = new MazeManager; }
	static MazeManager* GetInstance() { return instance_; }
	static void DeleteInstance() { if (instance_) delete instance_; instance_ = nullptr; }

public:
	void Init();
	void Load();
	void OnLoadEnd();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	void CreateMaze();


private:
	static MazeManager* instance_;

	std::vector<CMaze*> walls_;
	std::vector<CGoal*> goals_;
	CMaze* maze_;
	CGoal* goal_;
};