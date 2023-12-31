#pragma once

#include "../Object/Object.h"
#include "../Collision/SphereCollision.h"

class CTreasure : public CObject {
public:
	CTreasure();
	~CTreasure();

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	virtual void OnCollisionEnter(CObject* another) override;

	void Reset();
	void SetIsHeld(bool isHeld);

private:

	VECTOR restart_pos_;

	// 半径
	float rad_;

	// 持たれているか
	bool isHeld_;

	// ギミックに乗っているか
	bool isOnGimmik_;

	// 当たり判定
	SphereCollision* collision_;
};