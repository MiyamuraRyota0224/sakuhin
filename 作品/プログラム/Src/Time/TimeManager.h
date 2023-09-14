#pragma once

#include "Time.h"

class TimeManager {
public:
	TimeManager();
	~TimeManager();

public:
	static void CreateInstance() { if (!instance_) instance_ = new TimeManager; }
	static TimeManager* GetInstance() { return instance_; }
	static void DeleteInstance() { if (instance_) delete instance_; instance_ = nullptr; }

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	void Reset();

	CTime* CreateTime() { if (!time_)time_ = new CTime; return time_; }
	CTime* GetTime() const { return time_; }
	void DeleteTime() { if (time_)delete time_; }

private:
	static TimeManager* instance_;

	CTime* time_;

};
