#pragma once

#include "../Object/Object.h"
#include "PlayerParameter.h"
#include "../Collision/BoxCollision.h"
#include "../Collision/SphereCollision.h"


class CPlayer : public CObject {
public:
	CPlayer();
	~CPlayer();

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	void Reset();

	virtual void OnCollisionEnter(CObject* another) override;

private:
	void Move();
	void Action();

private:
	// ���
	enum PLAYER_STATE {
		STATE_DEFAULT,	// �����~�܂�
		STATE_WALK,		// ����
		STATE_CARRY,	// �����^��
		STATE_TOUTCH,	// �G���
	};

	// �e��Ԃ̏���
	void Defaultexec();
	void Walkexec();
	void Carryexec();
	void Toutchexec();
	
private:
	// �ړ���
	VECTOR move_;

	VECTOR dir_;

	VECTOR old_pos_;

	VECTOR restart_pos_;

	// ������������
	bool hasObject_;
	// ���������^�ׂ邩
	bool canCarry_;
	// �G����邩
	bool canToutch_;
	// �G�ꂽ��
	bool isTouch_;


	bool isOnGimmik_;
	// ���
	PLAYER_STATE state_;
	// �����蔻��
	BoxCollision* collision_box;
	SphereCollision* collision_sphere;
};