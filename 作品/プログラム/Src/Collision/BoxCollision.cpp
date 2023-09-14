#include "BoxCollision.h"
#include "CollisionParameter.h"

BoxCollision::BoxCollision() : Collision()
{
	shape_ = COLLISION_SHAPE_BOX;
	size_ = { 0.0f };
}

BoxCollision::~BoxCollision()
{
	Fin();
}

void BoxCollision::Init()
{
}

void BoxCollision::Update()
{
}

void BoxCollision::Draw()
{
#ifdef	_DEBUG
	// �����蔻��̉���
	VECTOR posA = VGet(pos_.x - size_.x / 2.0f, pos_.y - size_.y / 2.0f, pos_.z - size_.z / 2.0f);
	VECTOR posB = VGet(pos_.x + size_.x / 2.0f, pos_.y + size_.y / 2.0f, pos_.z + size_.z / 2.0f);

	DrawCube3D(posA, posB, GetColor(0, 255, 0), GetColor(0, 255, 0), FALSE);
#endif
}

void BoxCollision::Fin()
{
}

Collision* BoxCollision::Clone()
{
	Collision* clone = new BoxCollision;
	*clone = *this;
	return clone;
}

bool BoxCollision::CheckCollision(Collision* another)
{
	// ����A�{�b�N�X���m�̓����蔻�肵���Ƃ�Ȃ�
	if (another->GetShape() != COLLISION_SHAPE_BOX) {
		return false;
	}

	BoxCollision* another_box = static_cast<BoxCollision*>(another);
	VECTOR another_size = another_box->GetSize();

	float w1_half = (size_.x / 2);		//�Ώ�A�̉����̔����i���S����[�܂ł̒����j
	float h1_half = (size_.y / 2);		//�Ώ�A�̍����̔����i���S����[�܂ł̒����j
	float d1_half = (size_.z / 2);		//�Ώ�A�̉��s���̔����i���S����[�܂ł̒����j

	float x1min = pos_.x - w1_half;	//�Ώ�A�̍ŏ�X
	float x1max = pos_.x + w1_half;	//�Ώ�A�̍ő�X
	float y1min = pos_.y - h1_half;	//�Ώ�A�̍ŏ�Y
	float y1max = pos_.y + h1_half;	//�Ώ�A�̍ő�Y
	float z1min = pos_.z - d1_half;	//�Ώ�A�̍ŏ�Z
	float z1max = pos_.z + d1_half;	//�Ώ�A�̍ő�Z

	float w2_half = (another_size.x / 2);		//�Ώ�B�̉����̔����i���S����[�܂ł̒����j
	float h2_half = (another_size.y / 2);		//�Ώ�B�̍����̔����i���S����[�܂ł̒����j
	float d2_half = (another_size.z / 2);		//�Ώ�B�̉��s���̔����i���S����[�܂ł̒����j

	float x2min = another_box->pos_.x - w2_half;		//�Ώ�B�̍ŏ�X
	float x2max = another_box->pos_.x + w2_half;		//�Ώ�B�̍ő�X
	float y2min = another_box->pos_.y - h2_half;		//�Ώ�B�̍ŏ�Y
	float y2max = another_box->pos_.y + h2_half;		//�Ώ�B�̍ő�Y
	float z2min = another_box->pos_.z - d2_half;		//�Ώ�B�̍ŏ�Z
	float z2max = another_box->pos_.z + d2_half;		//�Ώ�B�̍ő�Z

	if (x1min < x2max && x1max > x2min && 
		y1min < y2max && y1max > y2min && 
		z1min < z2max && z1max > z2min)
		return true;

	return false;
}
