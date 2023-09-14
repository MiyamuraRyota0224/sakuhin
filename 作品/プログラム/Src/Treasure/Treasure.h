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

	// ���a
	float rad_;

	// ������Ă��邩
	bool isHeld_;

	// �M�~�b�N�ɏ���Ă��邩
	bool isOnGimmik_;

	// �����蔻��
	SphereCollision* collision_;
};