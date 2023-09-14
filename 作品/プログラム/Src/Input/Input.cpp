#include "DxLib.h"
#include "Input.h"

int CInput::m_pre_key_state = 0;
int CInput::m_current_key_state = 0;


//入力制御初期化
void CInput::InitInput()
{
	m_pre_key_state = 0;
	m_current_key_state = 0;
}

//入力制御ステップ
void CInput::StepInput()
{
	//前回のキー状態を保存
	m_pre_key_state = m_current_key_state;

	//今回のキー状態を判定前にfalseに
	m_current_key_state = 0;

	//必要なキーは以下に判定を書く

	if (CheckHitKey(KEY_INPUT_Z) == 1)
		m_current_key_state |= KEY_Z;

	if (CheckHitKey(KEY_INPUT_X) == 1)
		m_current_key_state |= KEY_X;

	if (CheckHitKey(KEY_INPUT_UP) == 1)
		m_current_key_state |= KEY_UP;

	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
		m_current_key_state |= KEY_DOWN;

	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		m_current_key_state |= KEY_LEFT;

	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		m_current_key_state |= KEY_RIGHT;

	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		m_current_key_state |= KEY_SPACE;

	if (CheckHitKey(KEY_INPUT_C) == 1)
		m_current_key_state |= KEY_C;

	if (CheckHitKey(KEY_INPUT_W) == 1)
		m_current_key_state |= KEY_W;

	if (CheckHitKey(KEY_INPUT_A) == 1)
		m_current_key_state |= KEY_A;

	if (CheckHitKey(KEY_INPUT_S) == 1)
		m_current_key_state |= KEY_S;

	if (CheckHitKey(KEY_INPUT_D) == 1)
		m_current_key_state |= KEY_D;

	if (CheckHitKey(KEY_INPUT_Q) == 1)
		m_current_key_state |= KEY_Q;

	if (CheckHitKey(KEY_INPUT_E) == 1)
		m_current_key_state |= KEY_E;

	if (CheckHitKey(KEY_INPUT_F) == 1)
		m_current_key_state |= KEY_F;

	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		m_current_key_state |= KEY_ENTER;

	if (CheckHitKey(KEY_INPUT_LSHIFT) == 1)
		m_current_key_state |= KEY_LSHIFT;
}

//今押された
bool CInput::IsPush(int key_bit)
{
	if((m_current_key_state & key_bit) && (m_pre_key_state & key_bit) == 0)
		return true;

	return false;
}

//押されている
bool CInput::IsCont(int key_bit)
{
	if(m_current_key_state & key_bit)
		return true;

	return false;
}

