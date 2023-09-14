#pragma once

#include "Cristal.h"

class CristalManager {
public:
	CristalManager();
	~CristalManager();

public:
	static void CreateInstance() { if (!instance_) instance_ = new CristalManager; }
	static CristalManager* GetInstance() { return instance_; }
	static void DeleteInstance() { if (instance_) delete instance_; instance_ = nullptr; }

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	CCristal* CreateCristal() { if (!cristal_)cristal_ = new CCristal; return cristal_; }
	CCristal* GetCristal() const { return cristal_; }
	void DeleteCristal() { if (cristal_)delete cristal_; }

private:
	static CristalManager* instance_;

	CCristal* cristal_;

};
