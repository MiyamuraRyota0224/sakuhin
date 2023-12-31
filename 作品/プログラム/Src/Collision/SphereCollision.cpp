#include "SphereCollision.h"
#include "CollisionParameter.h"
#include "../Common/MyMath.h"

SphereCollision::SphereCollision() : Collision()
{
	shape_ = COLLISION_SHAPE_SPHERE;
	radius_ = 0.0f;
}

SphereCollision::~SphereCollision()
{
	Fin();
}

void SphereCollision::Init()
{
}

void SphereCollision::Update()
{
}

void SphereCollision::Draw()
{
#ifdef _DEBUG
	// 当たり判定可視化
	DrawSphere3D(pos_, radius_, 16, GetColor(0, 255, 0), GetColor(0, 255, 0), FALSE);
#endif
}

void SphereCollision::Fin()
{
}

Collision* SphereCollision::Clone()
{
	Collision* clone = new SphereCollision;
	*clone = *this;
	return clone;
}

bool SphereCollision::CheckCollision(Collision* another)
{
	// 現状、球同士の当たり判定しかとらない
	if (another->GetShape() != COLLISION_SHAPE_SPHERE) {
		return false;
	}

	SphereCollision* another_collision = static_cast<SphereCollision*>(another);
	VECTOR another_pos = another->GetPos();
	float another_radius = another_collision->GetRadius();

	if ((pos_.x - another_pos.x) * (pos_.x - another_pos.x) +
		(pos_.y - another_pos.y) * (pos_.y - another_pos.y) +
		(pos_.z - another_pos.z) * (pos_.z - another_pos.z) <=
		(radius_ + another_radius) * (radius_ + another_radius)) {
		return true;
	}

	return false;
}
