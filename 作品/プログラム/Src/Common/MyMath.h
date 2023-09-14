#pragma once

#include "DxLib.h"


// Quaternion構造体
struct Quaternion {
	float w;
	float x;
	float y;
	float z;
};

//ベクトルや行列の計算処理をまとめたクラス
class MyMath
{
public:
	static float GetSin(float rad);
	static float GetSin(float min, float max, float rad);
	static float GetDistance(VECTOR posA, VECTOR posB);
	static VECTOR VecCreate(VECTOR PosA, VECTOR PosB);//ベクトル作成
	static float VecLong(VECTOR PosA, VECTOR PosB);//ベクトルの長さ
	static VECTOR VecAdd(VECTOR vecA, VECTOR vecB);//ベクトルの足し算
	static VECTOR VecSubtract(VECTOR vecA, VECTOR vecB);//ベクトルの引き算
	static VECTOR VecScale(VECTOR vec, float scale);//ベクトルのスカラー倍
	static float VecDot(VECTOR vecA, VECTOR vecB);//ベクトルの内積
	static VECTOR VecCross(VECTOR vecA, VECTOR vecB);//ベクトルの外積
	static VECTOR VecNormalize(VECTOR vec);//ベクトルの正規化
	static VECTOR VecRotation(VECTOR vec, VECTOR rotation);//ベクトルを回転させる
	static VECTOR GetNormVecX(VECTOR vec);//横に垂直なベクトルを取得
	static VECTOR GetNormVecY(VECTOR vec);//縦に垂直なベクトルを取得
	static VECTOR GetAxisX(VECTOR rotation);//回転に対応したX軸ベクトル取得
	static VECTOR GetAxisY(VECTOR rotation);//回転に対応したY軸ベクトル取得
	static VECTOR GetAxisZ(VECTOR rotation);//回転に対応したZ軸ベクトル取得
	static VECTOR GetVecRotationXY(VECTOR vec);// ベクトルの角度取得
	static MATRIX GetldentityMatrix();//単位行列の取得
	static MATRIX GetTranslateMatrix(float x, float y, float z);//移動行列の取得
	static MATRIX GetTranslateMatrix(VECTOR trans);//移動行列の取得
	static MATRIX GetScaleMatrix(float x, float y, float z);//拡縮行列の取得
	static MATRIX GetPitchMatrix(float rot);//X軸回転行列の取得
	static MATRIX GetYawMatrix(float rot);//Y軸回転行列の取得
	static MATRIX GetRollMatrix(float rot);//Z軸回転行列の取得
	static MATRIX GetRotationMatrix(VECTOR rotation);//回転行列を取得
	static MATRIX MatAdd(MATRIX matA, MATRIX matB);//行列の足し算
	static MATRIX MatMult(MATRIX matA, MATRIX matB);//行列の掛け算
	static MATRIX MatScale(MATRIX mat, float scale);//行列のスカラー倍
	static VECTOR MatTransform(MATRIX mat, VECTOR vec);//ベクトル×行列
	static MATRIX MatTranspose(MATRIX mat);//行列の転置
	static VECTOR GetVec(MATRIX mat);//行列からベクトルを取得
	static void GetAxisRotationQuaternion(VECTOR axis, float angle, Quaternion& out_quaA, Quaternion& out_quaB);// 軸回転用クオータニオン取得
	static VECTOR PointRotationQuaternion(VECTOR pos, VECTOR axis, float angle);// 点の軸回転
	static Quaternion QuaternionMult(Quaternion quaA, Quaternion quaB); // クオータニオン×クオータニオン
	static VECTOR GetPolygonNormalVec(VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);//ポリゴンの法線ベクトル
	static float GetTriangleHeightXY(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float GetTriangleHeightXZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float GetTriangleHeightYZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float Abs(float val);
};
