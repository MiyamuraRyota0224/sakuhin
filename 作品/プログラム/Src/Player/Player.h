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
	// ó‘Ô
	enum PLAYER_STATE {
		STATE_DEFAULT,	// —§‚¿~‚Ü‚é
		STATE_WALK,		// •à‚­
		STATE_CARRY,	// ‚¿‰^‚Ô
		STATE_TOUTCH,	// G‚ê‚é
	};

	// Šeó‘Ô‚Ìˆ—
	void Defaultexec();
	void Walkexec();
	void Carryexec();
	void Toutchexec();
	
private:
	// ˆÚ“®—Ê
	VECTOR move_;

	VECTOR dir_;

	VECTOR old_pos_;

	VECTOR restart_pos_;

	// •¨‚ğ‚Á‚½‚©
	bool hasObject_;
	// •¨‚ğ‚¿‰^‚×‚é‚©
	bool canCarry_;
	// G‚ê‚ç‚ê‚é‚©
	bool canToutch_;
	// G‚ê‚½‚©
	bool isTouch_;


	bool isOnGimmik_;
	// ó‘Ô
	PLAYER_STATE state_;
	// “–‚½‚è”»’è
	BoxCollision* collision_box;
	SphereCollision* collision_sphere;
};