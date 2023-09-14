#pragma once
// ”wŒi‚Æ‚È‚éƒXƒe[ƒWŠÇ—
#include "Stage.h"

class StageManager {
public:
	StageManager();
	~StageManager();

public:
	static void CreateInstance() { if (!instance_) instance_ = new StageManager; }
	static StageManager* GetInstance() { return instance_; }
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

	Stage* CreateStage(int id) { stage_ = new Stage(id); now_stage_id_ = id; return stage_; }
	Stage* GetStage() const { return stage_; }

	int GetNowStageID() const { return now_stage_id_; }
private:
	static StageManager* instance_;

	Stage* stage_;
	int now_stage_id_;
};
