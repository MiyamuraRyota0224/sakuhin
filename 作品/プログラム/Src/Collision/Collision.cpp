#include "Collision.h"
#include "../Common/MyMath.h"

Collision::Collision()
{
	shape_ = 0;
	state_ = 0;
	owner_ = nullptr;
	pos_ = { 0.0f };
}

Collision::~Collision()
{
	Fin();
}

void Collision::Init()
{
}

void Collision::Step()
{
	if (owner_) {
		pos_ = owner_->GetPos();
	}
}

void Collision::Update()
{
}

void Collision::Draw()
{
}

void Collision::Fin()
{
}

bool Collision::IsHitTriangleXY(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	// �O�p�`�̕ӂɉ������x�N�g��
	VECTOR vecAB = MyMath::VecCreate(vertexA, vertexB); vecAB.z = 0.0f;
	VECTOR vecBC = MyMath::VecCreate(vertexB, vertexC); vecBC.z = 0.0f;
	VECTOR vecCA = MyMath::VecCreate(vertexC, vertexA); vecCA.z = 0.0f;

	// �e���_����Ώۂ܂ł̃x�N�g��
	VECTOR vecAP = MyMath::VecCreate(vertexA, point); vecAP.z = 0.0f;
	VECTOR vecBP = MyMath::VecCreate(vertexB, point); vecBP.z = 0.0f;
	VECTOR vecCP = MyMath::VecCreate(vertexC, point); vecCP.z = 0.0f;

	// �Ή�����x�N�g���ǂ����ĊO�ς��v�Z����
	VECTOR vecABAP = MyMath::VecCross(vecAB, vecAP);
	VECTOR vecBCBP = MyMath::VecCross(vecBC, vecBP);
	VECTOR vecCACP = MyMath::VecCross(vecCA, vecCP);

	// �e�O�ς�Z������0�ȉ��ł���Γ������Ă���
	if (vecABAP.z >= 0 && vecBCBP.z >= 0 && vecCACP.z >= 0) {
		return true;
	}

	if (vecABAP.z <= 0 && vecBCBP.z <= 0 && vecCACP.z <= 0) {
		return true;
	}

	return false;
}

bool Collision::IsHitTriangleXZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	// �O�p�`�̕ӂɉ������x�N�g��
	VECTOR vecAB = MyMath::VecCreate(vertexA, vertexB); vecAB.y = 0.0f;
	VECTOR vecBC = MyMath::VecCreate(vertexB, vertexC); vecBC.y = 0.0f;
	VECTOR vecCA = MyMath::VecCreate(vertexC, vertexA); vecCA.y = 0.0f;

	// �e���_����Ώۂ܂ł̃x�N�g��
	VECTOR vecAP = MyMath::VecCreate(vertexA, point); vecAP.y = 0.0f;
	VECTOR vecBP = MyMath::VecCreate(vertexB, point); vecBP.y = 0.0f;
	VECTOR vecCP = MyMath::VecCreate(vertexC, point); vecCP.y = 0.0f;

	// �Ή�����x�N�g���ǂ����ĊO�ς��v�Z����
	VECTOR vecABAP = MyMath::VecCross(vecAB, vecAP);
	VECTOR vecBCBP = MyMath::VecCross(vecBC, vecBP);
	VECTOR vecCACP = MyMath::VecCross(vecCA, vecCP);

	// �e�O�ς�Y������0�ȉ��ł���Γ������Ă���
	if (vecABAP.y >= 0 && vecBCBP.y >= 0 && vecCACP.y >= 0) {
		return true;
	}

	if (vecABAP.y <= 0 && vecBCBP.y <= 0 && vecCACP.y <= 0) {
		return true;
	}


	return false;
}

bool Collision::IsHitTriangleYZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	// �O�p�`�̕ӂɉ������x�N�g��
	VECTOR vecAB = MyMath::VecCreate(vertexA, vertexB); vecAB.x = 0.0f;
	VECTOR vecBC = MyMath::VecCreate(vertexB, vertexC); vecBC.x = 0.0f;
	VECTOR vecCA = MyMath::VecCreate(vertexC, vertexA); vecCA.x = 0.0f;

	// �e���_����Ώۂ܂ł̃x�N�g��
	VECTOR vecAP = MyMath::VecCreate(vertexA, point); vecAP.x = 0.0f;
	VECTOR vecBP = MyMath::VecCreate(vertexB, point); vecBP.x = 0.0f;
	VECTOR vecCP = MyMath::VecCreate(vertexC, point); vecCP.x = 0.0f;

	// �Ή�����x�N�g���ǂ����ĊO�ς��v�Z����
	VECTOR vecABAP = MyMath::VecCross(vecAB, vecAP);
	VECTOR vecBCBP = MyMath::VecCross(vecBC, vecBP);
	VECTOR vecCACP = MyMath::VecCross(vecCA, vecCP);

	// �e�O�ς�X������0�ȉ��ł���Γ������Ă���
	if (vecABAP.x >= 0 && vecBCBP.x >= 0 && vecCACP.x >= 0) {
		return true;
	}

	if (vecABAP.x <= 0 && vecBCBP.x <= 0 && vecCACP.x <= 0) {
		return true;
	}

	return false;
}