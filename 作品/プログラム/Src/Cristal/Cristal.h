#pragma once

#include "../Object/Object.h"
#include "../Collision/SphereCollision.h"

class CCristal : public CObject {
public:
	CCristal();
	~CCristal();

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	virtual void OnCollisionEnter(CObject* another) override;

	void SetIsCheck(bool isCheck) { isCheck_ = isCheck; }

private:
	void Reset();

private:
	// 触れられたか
	bool isCheck_;

	// 当たり判定
	SphereCollision* collision_;
};