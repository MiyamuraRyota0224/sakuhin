#pragma once
#include "../Object/Object.h"
#include "../Collision/BoxCollision.h"

class CGoal : public CObject {
public:
	CGoal();
	~CGoal();

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	CGoal* Clone();

private:
	BoxCollision* collision_;
	
};