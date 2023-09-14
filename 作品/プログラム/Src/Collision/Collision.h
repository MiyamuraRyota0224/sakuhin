#pragma once
// コリジョン基底クラス
#include "CollisionParameter.h"
#include "../Object/Object.h"

class Collision {
public:
	Collision();
	~Collision();

public:
	virtual void Init();
	virtual void Step();
	virtual void Update();
	virtual void Draw();
	virtual void Fin();
	virtual Collision* Clone() = 0;

	virtual bool CheckCollision(Collision* another) = 0;

public:
	void SetOwner(CObject* owner) { owner_ = owner; }
	void SetState(int state) { state_ = state; }
	void SetShape(int shape) { shape_ = shape; }
	void SetRadius(float radius) { radius_ = radius; }

	CObject* GetOwner() const { return owner_; }
	int GetState() const { return state_; }
	int GetShape() const { return shape_; }
	VECTOR GetPos() const { return pos_; }
	float GetRadius() const { return radius_; }
	bool IsActive() const { return state_ != COLLISION_STATE_NONE; }
	bool IsCheck() const { return state_ == COLLISION_STATE_ACTIVE; }

	static bool IsHitTriangleXY(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static bool IsHitTriangleXZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static bool IsHitTriangleYZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);

protected:
	int shape_;
	float radius_;
	int state_;
	CObject* owner_;
	VECTOR pos_;
};
