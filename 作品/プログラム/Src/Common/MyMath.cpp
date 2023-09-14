#include "MyMath.h"
#include <math.h>

// ���W�A���p����Sin�g���擾
float MyMath::GetSin(float rad)
{
	return sinf(rad);
}

// ���W�A���p����min�`max�͈̔͂�Sin�g���擾
float MyMath::GetSin(float min, float max, float rad)
{
	float mult = (max - min) / 2.0f;
	return (sinf(rad) + 1.0f) * mult + min;
}

// posA����posB�̋������擾
float MyMath::GetDistance(VECTOR posA, VECTOR posB)
{
	float x = posB.x - posA.x;
	float y = posB.y - posA.y;
	float z = posB.z - posA.z;

	return sqrtf(x * x + y * y + z * z);
}

// �x�N�g������
VECTOR MyMath::VecCreate(VECTOR vPosA, VECTOR vPosB)
{
	VECTOR result;
	result.x = vPosB.x - vPosA.x;
	result.y = vPosB.y - vPosA.y;
	result.z = vPosB.z - vPosA.z;
	return result;
}

// �x�N�g���̒����擾
float MyMath::VecLong(VECTOR PosA, VECTOR PosB)
{
	float result;
	result = sqrtf((PosA.x - PosB.x) * (PosA.x - PosB.x) + (PosA.y - PosB.y) * (PosA.y - PosB.y) + (PosA.z - PosB.z) * (PosA.z - PosB.z));
	return result;
}

// �x�N�g���̉��Z
VECTOR MyMath::VecAdd(VECTOR vecA, VECTOR vecB)
{
	VECTOR result;
	result.x = vecA.x + vecB.x;
	result.y = vecA.y + vecB.y;
	result.z = vecA.z + vecB.z;

	return result;
}

// �x�N�g���̌��Z
VECTOR MyMath::VecSubtract(VECTOR vecA, VECTOR vecB)
{
	VECTOR result;
	result.x = vecA.x - vecB.x;
	result.y = vecA.y - vecB.y;
	result.z = vecA.z - vecB.z;

	return result;

}

// �x�N�g���̃X�J���[�{
VECTOR MyMath::VecScale(VECTOR vec, float scale)
{
	VECTOR result;
	result.x = vec.x * scale;
	result.y = vec.y * scale;
	result.z = vec.z * scale;

	return result;
}

// �x�N�g���̓���
float MyMath::VecDot(VECTOR vecA, VECTOR vecB)
{
	float result;
	result = vecA.x * vecB.x + vecA.y * vecB.y + vecA.z * vecB.z;
	return result;
}

// �x�N�g���̊O��
VECTOR MyMath::VecCross(VECTOR vecA, VECTOR vecB)
{
	VECTOR result;
	result.x = vecA.y * vecB.z - vecA.z * vecB.y;
	result.y = vecA.z * vecB.x - vecA.x * vecB.z;
	result.z = vecA.x * vecB.y - vecA.y * vecB.x;
	return result;
}

// �x�N�g���̐��K��
VECTOR MyMath::VecNormalize(VECTOR vec)
{
	float size;
	VECTOR result;
	size = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	size = sqrtf(size);
	result.x = vec.x / size;
	result.y = vec.y / size;
	result.z = vec.z / size;

	return result;
}

//�x�N�g������]������
VECTOR MyMath::VecRotation(VECTOR vec, VECTOR rotation)
{
	VECTOR result = { 0 };
	MATRIX dir = GetldentityMatrix();
	MATRIX rotation_mat = GetRotationMatrix(rotation);

	dir = MatMult(dir, rotation_mat);
	result = MatTransform(rotation_mat, vec);

	return result;
}

//���ɐ����ȃx�N�g�����擾
VECTOR MyMath::GetNormVecX(VECTOR vec)
{
	VECTOR w = VecRotation(vec, VGet(0.5f * DX_PI_F, 0.0f, 0.0f));
	return VecCross(vec, w);
}

//�c�ɐ����ȃx�N�g�����擾
VECTOR MyMath::GetNormVecY(VECTOR vec)
{
	VECTOR w = VecRotation(vec, VGet(0.0f, 0.5f * DX_PI_F, 0.0f));
	return VecCross(vec, w);
}

// ��]�l����E������\���x�N�g���擾
VECTOR MyMath::GetAxisX(VECTOR rotation)
{
	return VecRotation(VGet(1.0f, 0.0f, 0.0f), rotation);
}

// ��]�l����������\���x�N�g���擾
VECTOR MyMath::GetAxisY(VECTOR rotation)
{
	return VecRotation(VGet(0.0f, 1.0f, 0.0f), rotation);
}

// ��]�l���牜������\���x�N�g���擾
VECTOR MyMath::GetAxisZ(VECTOR rotation)
{
	return VecRotation(VGet(0.0f, 0.0f, 1.0f), rotation);
}

// �x�N�g���̊p�x�擾
VECTOR MyMath::GetVecRotationXY(VECTOR vec)
{
	VECTOR result = { 0.0f };
	result.x = -atan2f(vec.y, vec.z);
	result.y = atan2f(-vec.x, -vec.z);

	return result;
}

// �P�ʍs��擾
MATRIX MyMath::GetldentityMatrix()
{
	MATRIX result = { 0 };
	for(int i = 0; i < 4; i++)	{
		for(int j = 0; j < 4; j++){
			if(i == j){
				result.m[i][j] = 1;
			}
			else{
				result.m[i][j] = 0;
			}
		}
	}

	return result;
}

//���s�ړ��s��̎擾
MATRIX MyMath::GetTranslateMatrix(float x, float y, float z)
{
	MATRIX result = GetldentityMatrix();
	result.m[0][3] = x;
	result.m[1][3] = y;
	result.m[2][3] = z;

	return result;
}

//���s�ړ��s��̎擾
MATRIX MyMath::GetTranslateMatrix(VECTOR trans)
{
	MATRIX result = GetldentityMatrix();
	result.m[0][3] = trans.x;
	result.m[1][3] = trans.y;
	result.m[2][3] = trans.z;

	return result;
}


//�g�k�s��̎擾
MATRIX MyMath::GetScaleMatrix(float x, float y, float z)
{
	MATRIX result = GetldentityMatrix();
	result.m[0][0] = x;
	result.m[1][1] = y;
	result.m[2][2] = z;

	return result;
}

//X����]�s��̎擾
MATRIX MyMath::GetPitchMatrix(float rot)
{
	MATRIX result = GetldentityMatrix();
	result.m[1][1] = cosf(rot);
	result.m[1][2] = -sinf(rot);
	result.m[2][1] = sinf(rot);
	result.m[2][2] = cosf(rot);

	return result;
}

//Y����]�s��̎擾
MATRIX MyMath::GetYawMatrix(float rot)
{
	MATRIX result = GetldentityMatrix();
	result.m[0][0] = cosf(rot);
	result.m[0][2] = sinf(rot);
	result.m[2][0] = -sinf(rot);
	result.m[2][2] = cosf(rot);

	return result;
}

//Z����]�s��̎擾
MATRIX MyMath::GetRollMatrix(float rot)
{
	MATRIX result = GetldentityMatrix();
	result.m[0][0] = cosf(rot);
	result.m[0][1] = -sinf(rot);
	result.m[1][0] = sinf(rot);
	result.m[1][1] = cosf(rot);

	return result;
}

// ��]�s��擾
MATRIX MyMath::GetRotationMatrix(VECTOR rotation)
{
	// �e���̉�]�s����擾
	MATRIX result = GetldentityMatrix();
	MATRIX pitch = GetPitchMatrix(rotation.x);
	MATRIX yaw = GetYawMatrix(rotation.y);
	MATRIX roll = GetRollMatrix(rotation.z);

	// �s�������
	result = MatMult(result, roll);
	result = MatMult(result, yaw);
	result = MatMult(result, pitch);

	return result;
}

// �s��̉��Z
MATRIX MyMath::MatAdd(MATRIX matA, MATRIX matB)
{
	MATRIX result = { 0 };
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			result.m[i][j] = matA.m[i][j] + matB.m[i][j];
		}
	}

	return result;
}

// �s�񓯎m�̊|���Z
MATRIX MyMath::MatMult(MATRIX matA, MATRIX matB)
{
	MATRIX result = { 0 };
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				result.m[i][j] += (matA.m[i][k] * matB.m[k][j]);
			}
		}
	}

	return result;
}

// �s��̃X�J���[�{
MATRIX MyMath::MatScale(MATRIX mat, float scale)
{
	MATRIX result = { 0 };
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			result.m[i][j] = mat.m[i][j] * scale;
		}
	}

	return result;
}

// �s����g�p�������W�ϊ�
VECTOR MyMath::MatTransform(MATRIX mat, VECTOR vec)
{
	float work[4] = { 0 };
	float result_buf[4] = { 0 };
	VECTOR result_vec = { 0 };
	work[0] = vec.x;
	work[1] = vec.y;
	work[2] = vec.z;
	work[3] = 1;
	for(int i = 0; i < 4; i++){
		for(int k = 0; k < 4; k++){
			result_buf[i] += (mat.m[i][k] * work[k]);
		}
	}

	result_vec.x = result_buf[0];
	result_vec.y = result_buf[1];
	result_vec.z = result_buf[2];

	return result_vec;
}

// �s��̓]�u
MATRIX MyMath::MatTranspose(MATRIX mat)
{
	MATRIX result = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[j][i] = mat.m[i][j];
		}
	}

	return result;
}

VECTOR MyMath::GetVec(MATRIX mat)
{
	float result_buf[4] = { 0 };
	VECTOR result_vec = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result_buf[i] = mat.m[i][j];
		}
	}

	result_vec.x = result_buf[0];
	result_vec.y = result_buf[1];
	result_vec.z = result_buf[2];

	return result_vec;
}

// ����]�p�N�I�[�^�j�I���擾
// ���͈���
// axis:��]��
// angle�F�p�x
// �����o��
// out_quaA:����]�p�N�I�[�^�j�I��A
// out_quaB:����]�p�N�I�[�^�j�I��B
void MyMath::GetAxisRotationQuaternion(VECTOR axis, float angle, Quaternion& out_quaA, Quaternion& out_quaB)
{
	// �N�I�[�^�j�I��A�v�Z
	out_quaA.w = cosf(angle) / 2.0f;
	out_quaA.x = axis.x * sinf(angle) / 2.0f;
	out_quaA.y = axis.y * sinf(angle) / 2.0f;
	out_quaA.z = axis.z * sinf(angle) / 2.0f;

	// �N�I�[�^�j�I��B�v�Z
	out_quaB.w = cosf(angle) / 2.0f;
	out_quaB.x = -axis.x * sinf(angle) / 2.0f;
	out_quaB.y = -axis.y * sinf(angle) / 2.0f;
	out_quaB.z = -axis.z * sinf(angle) / 2.0f;
}

// �_�̎���]
// pos:����]������_�̍��W
// axis�F����\���x�N�g��
// angle:��]�p�x
VECTOR MyMath::PointRotationQuaternion(VECTOR pos, VECTOR axis, float angle)
{
	Quaternion P = { 0.0f, pos.x, pos.y, pos.z };
	Quaternion Q, R, result;
	GetAxisRotationQuaternion(axis, angle, Q, R);
	result = QuaternionMult(R, P);
	result = QuaternionMult(result, Q);

	return VGet(result.x, result.y, result.z);
}


// �N�I�[�^�j�I���~�N�I�[�^�j�I��
Quaternion MyMath::QuaternionMult(Quaternion quaA, Quaternion quaB)
{
	Quaternion result = { 0.0f };
	VECTOR vecA = { quaA.x, quaA.y, quaA.z };
	VECTOR vecB = { quaB.x, quaB.y, quaB.z };
	float w = 0.0f;
	VECTOR ima = { 0.0f };

	// �������v�Z
	w = quaA.w * quaB.w - VecDot(vecA, vecB);

	// �������v�Z
	ima = VecScale(vecB, quaA.w);
	ima = VecAdd(ima, VecScale(vecA, quaB.w));
	ima = VecAdd(ima, VecCross(vecA, vecB));

	// ���ʕԋp
	result = { w, ima.x, ima.y, ima.z };
	return result;
}

VECTOR MyMath::GetPolygonNormalVec(VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	VECTOR vecAB = VecCreate(vertexA, vertexB);
	VECTOR vecAC = VecCreate(vertexA, vertexC);
	VECTOR vecABAC = VecCross(vecAB, vecAC);
	return VecNormalize(vecABAC);
}

float MyMath::GetTriangleHeightXY(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	// �ӂɉ������x�N�g��AB��AC���v�Z
	VECTOR vecAB = VecCreate(vertexA, vertexB);
	VECTOR vecAC = VecCreate(vertexA, vertexC);
	// �ʖ@�����v�Z
	VECTOR vecNorm = VecCross(vecAB, vecAC);
	vecNorm = VecNormalize(vecNorm);
	// ���ʂ̕��������獂���iY���W���v�Z�j
	float z = (-vecNorm.x * (point.x - vertexA.x) - vecNorm.y * (point.y - vertexA.y) + vecNorm.z * vertexA.z) / vecNorm.z;

	return z;
}

float MyMath::GetTriangleHeightXZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	// �ӂɉ������x�N�g��AB��AC���v�Z
	VECTOR vecAB = VecCreate(vertexA, vertexB);
	VECTOR vecAC = VecCreate(vertexA, vertexC);
	// �ʖ@�����v�Z
	VECTOR vecNorm = VecCross(vecAB, vecAC);
	vecNorm = VecNormalize(vecNorm);
	// ���ʂ̕��������獂���iY���W���v�Z�j
	float y = (-vecNorm.x * (point.x - vertexA.x) - vecNorm.z * (point.z - vertexA.z) + vecNorm.y * vertexA.y) / vecNorm.y;

	return y;
}

float MyMath::GetTriangleHeightYZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	// �ӂɉ������x�N�g��AB��AC���v�Z
	VECTOR vecAB = VecCreate(vertexA, vertexB);
	VECTOR vecAC = VecCreate(vertexA, vertexC);
	// �ʖ@�����v�Z
	VECTOR vecNorm = VecCross(vecAB, vecAC);
	vecNorm = VecNormalize(vecNorm);
	// ���ʂ̕��������獂���iY���W���v�Z�j
	float x = (-vecNorm.y * (point.y - vertexA.y) - vecNorm.z * (point.z - vertexA.z) + vecNorm.x * vertexA.x) / vecNorm.x;

	return x;
}


float MyMath::Abs(float val)
{
	if (val < 0.0f) {
		return -val;
	}
	return val;
}