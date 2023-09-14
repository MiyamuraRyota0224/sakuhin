#pragma once
// ƒJƒƒ‰ŠÇ—ƒNƒ‰ƒX
#include "CameraBase.h"

class CameraManager {
public:
	CameraManager();
	~CameraManager();

public:
	static void CreateInstance() { if (!instance_) instance_ = new CameraManager; }
	static CameraManager* GetInstance() { return instance_; }
	static void DeleteInstance() { if (instance_) delete instance_; instance_ = nullptr; }

public:
	void Init();
	void Step();
	void Update();
	void Draw();
	void Fin();

	void StartCamera(int id);

private:
	static CameraManager* instance_;
	CameraBase* camera_;
};
