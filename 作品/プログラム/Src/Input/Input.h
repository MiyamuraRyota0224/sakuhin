
#pragma once

#include "DxLib.h"

//����p�r�b�g
#define KEY_Z		(1 << 0)	// Z�L�[
#define KEY_X		(1 << 1)	// X�L�[
#define KEY_ENTER	(1 << 2)	// ENTER�L�[
#define KEY_UP		(1 << 3)	// ��
#define KEY_DOWN	(1 << 4)	// ��
#define KEY_LEFT	(1 << 5)	// ��
#define KEY_RIGHT	(1 << 6)	// ��
#define KEY_SPACE	(1 << 7)	// SPACE
#define KEY_C		(1 << 8)	// C
#define KEY_W		(1 << 9)	// W
#define KEY_A		(1 << 10)	// A
#define KEY_S		(1 << 11)	// S
#define KEY_D		(1 << 12)	// D
#define KEY_Q		(1 << 13)	// Q
#define KEY_E		(1 << 14)	// E
#define KEY_F		(1 << 15)	// F
#define KEY_LSHIFT	(1 << 16)	// LSHIFT


class CInput {
public:
	//���͐��䏉����
	static void InitInput();

	//���͐���X�e�b�v
	//StepInput�͑���Step��葁���Ă�
	static void StepInput();

	//�������ꂽ
	static bool IsPush(int key_bit);

	//������Ă���
	static bool IsCont(int key_bit);

	//�}�E�X���W�̎擾
	static void GetMouse() { GetMousePoint(&mouse_x, &mouse_y); }
	static int GetMouseX() { return mouse_x; }
	static int GetMouseY() { return mouse_y; }

	//�}�E�X���W�̐ݒ�
	static void SetMouse() { SetMousePoint(mouse_x, mouse_y); }

private:

	static int m_pre_key_state;		//�O��̃L�[���
	static int m_current_key_state;	//����̃L�[���

private:
	static int mouse_x;
	static int mouse_y;

};
