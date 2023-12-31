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
	// 状態
	enum PLAYER_STATE {
		STATE_DEFAULT,	// 立ち止まる
		STATE_WALK,		// 歩く
		STATE_CARRY,	// 持ち運ぶ
		STATE_TOUTCH,	// 触れる
	};

	// 各状態の処理
	void Defaultexec();
	void Walkexec();
	void Carryexec();
	void Toutchexec();
	
private:
	// 移動量
	VECTOR move_;

	VECTOR dir_;

	VECTOR old_pos_;

	VECTOR restart_pos_;

	// 物を持ったか
	bool hasObject_;
	// 物を持ち運べるか
	bool canCarry_;
	// 触れられるか
	bool canToutch_;
	// 触れたか
	bool isTouch_;


	bool isOnGimmik_;
	// 状態
	PLAYER_STATE state_;
	// 当たり判定
	BoxCollision* collision_box;
	SphereCollision* collision_sphere;
};