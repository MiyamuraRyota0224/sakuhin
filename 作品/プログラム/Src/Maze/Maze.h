#pragma once

#include "../Object/Object.h"
#include "../Collision/BoxCollision.h"
#include <vector>
#include <list>

class CMaze : public CObject{
public:
	CMaze();
	~CMaze();

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	CMaze* Clone();

private:
	BoxCollision* collision_;
};