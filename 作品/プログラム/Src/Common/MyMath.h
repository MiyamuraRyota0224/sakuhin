#pragma once

#include "DxLib.h"


// Quaternion�\����
struct Quaternion {
	float w;
	float x;
	float y;
	float z;
};

//�x�N�g����s��̌v�Z�������܂Ƃ߂��N���X
class MyMath
{
public:
	static float GetSin(float rad);
	static float GetSin(float min, float max, float rad);
	static float GetDistance(VECTOR posA, VECTOR posB);
	static VECTOR VecCreate(VECTOR PosA, VECTOR PosB);//�x�N�g���쐬
	static float VecLong(VECTOR PosA, VECTOR PosB);//�x�N�g���̒���
	static VECTOR VecAdd(VECTOR vecA, VECTOR vecB);//�x�N�g���̑����Z
	static VECTOR VecSubtract(VECTOR vecA, VECTOR vecB);//�x�N�g���̈����Z
	static VECTOR VecScale(VECTOR vec, float scale);//�x�N�g���̃X�J���[�{
	static float VecDot(VECTOR vecA, VECTOR vecB);//�x�N�g���̓���
	static VECTOR VecCross(VECTOR vecA, VECTOR vecB);//�x�N�g���̊O��
	static VECTOR VecNormalize(VECTOR vec);//�x�N�g���̐��K��
	static VECTOR VecRotation(VECTOR vec, VECTOR rotation);//�x�N�g������]������
	static VECTOR GetNormVecX(VECTOR vec);//���ɐ����ȃx�N�g�����擾
	static VECTOR GetNormVecY(VECTOR vec);//�c�ɐ����ȃx�N�g�����擾
	static VECTOR GetAxisX(VECTOR rotation);//��]�ɑΉ�����X���x�N�g���擾
	static VECTOR GetAxisY(VECTOR rotation);//��]�ɑΉ�����Y���x�N�g���擾
	static VECTOR GetAxisZ(VECTOR rotation);//��]�ɑΉ�����Z���x�N�g���擾
	static VECTOR GetVecRotationXY(VECTOR vec);// �x�N�g���̊p�x�擾
	static MATRIX GetldentityMatrix();//�P�ʍs��̎擾
	static MATRIX GetTranslateMatrix(float x, float y, float z);//�ړ��s��̎擾
	static MATRIX GetTranslateMatrix(VECTOR trans);//�ړ��s��̎擾
	static MATRIX GetScaleMatrix(float x, float y, float z);//�g�k�s��̎擾
	static MATRIX GetPitchMatrix(float rot);//X����]�s��̎擾
	static MATRIX GetYawMatrix(float rot);//Y����]�s��̎擾
	static MATRIX GetRollMatrix(float rot);//Z����]�s��̎擾
	static MATRIX GetRotationMatrix(VECTOR rotation);//��]�s����擾
	static MATRIX MatAdd(MATRIX matA, MATRIX matB);//�s��̑����Z
	static MATRIX MatMult(MATRIX matA, MATRIX matB);//�s��̊|���Z
	static MATRIX MatScale(MATRIX mat, float scale);//�s��̃X�J���[�{
	static VECTOR MatTransform(MATRIX mat, VECTOR vec);//�x�N�g���~�s��
	static MATRIX MatTranspose(MATRIX mat);//�s��̓]�u
	static VECTOR GetVec(MATRIX mat);//�s�񂩂�x�N�g�����擾
	static void GetAxisRotationQuaternion(VECTOR axis, float angle, Quaternion& out_quaA, Quaternion& out_quaB);// ����]�p�N�I�[�^�j�I���擾
	static VECTOR PointRotationQuaternion(VECTOR pos, VECTOR axis, float angle);// �_�̎���]
	static Quaternion QuaternionMult(Quaternion quaA, Quaternion quaB); // �N�I�[�^�j�I���~�N�I�[�^�j�I��
	static VECTOR GetPolygonNormalVec(VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);//�|���S���̖@���x�N�g��
	static float GetTriangleHeightXY(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float GetTriangleHeightXZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float GetTriangleHeightYZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float Abs(float val);
};
