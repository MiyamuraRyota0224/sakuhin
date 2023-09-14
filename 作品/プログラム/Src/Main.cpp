#include "DxLib.h"
#include "Common/Common.h"
#include "Scene/SceneManager.h"
#include "Scene/SceneParameter.h"
#include "Input/Input.h"



//FPS�v���p
int g_nFrameCnt = 0;		//FPS�J�E���g
float g_fFramerate = 0.0f;	//�t���[�����[�g
int g_nLastTime = 0;		//�ȑO�v����������

void DrawFramerate();		//FPS�\��

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	//�E�B���h�E�T�C�Y��ύX
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	// �K�v�ȃ}�l�[�W���[�N���X�𐶐��A������
	// �V�[���}�l�[�W���[
	SceneManager::CreateInstance();
	SceneManager* scene_manager = SceneManager::GetInstance();
	scene_manager->StartFirstScene(SCENE_ID_TITLE);

	
	

	Common::Init();

	int nCurrentTime = 0;			//���݂̌o�ߎ���
	int nOldTime = GetNowCount();	//�ȑO�̌o�ߎ���

	// �y�o�b�t�@��L���ɂ���
	// SetUseZBuffer3D(TRUE);

	// �y�o�b�t�@�ւ̏������݂�L���ɂ���
	// SetWriteZBuffer3D(TRUE);

	

	
	while (ProcessMessage() != -1) {
		//�V�X�e���ɏ�����Ԃ�
		Sleep(1);

		//���̌o�ߎ��Ԃ��擾
		nCurrentTime = GetNowCount();

		//�ȑO�̎��Ԃ���1/60�b�o�߂��Ă����珈�������s
		if (nCurrentTime - nOldTime >= FRAME_RATE)
		{
			//���Ԃ̍X�V
			nOldTime = nCurrentTime;

			// ����ʂ�����/////////////////////////////////////////////
			ClearDrawScreen();

			// ���͍X�V
			CInput::StepInput();
			// �Q�[���֘A���ʍ��ڍX�V
			Common::Step();
			// �V�[���̍X�V
			scene_manager->Loop();
	

#ifdef _DEBUG
			//�t���[�����[�g�̕`��
			DrawFramerate();
#endif
			ScreenFlip();

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
				break;
			}
		}
	}

	// �㏈��
	SceneManager::DeleteInstance();
	

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

//FPS�\��
void DrawFramerate()
{
	//�t���[�������J�E���g
	g_nFrameCnt++;

	//���݂̎���
	int nCurrentTime = GetNowCount();

	//�O��̎��Ԃ���̌o�ߎ���
	float fLapsedTime = (float)(nCurrentTime - g_nLastTime);

	//�O��̎��Ԃ���P�b�ȏ�o�߂��Ă�����t���[�����[�g���X�V
	if (fLapsedTime >= 1000)
	{
		//�t���[�����[�g�v�Z
		float fFrameCnt = (float)(g_nFrameCnt * 1000);	//�t���[���񐔂��~���b�ɍ��킹��
		g_fFramerate = fFrameCnt / fLapsedTime;			//�t���[�����[�g�����߂�

		g_nFrameCnt = 0;				//�t���[���J�E���g���N���A
		g_nLastTime = nCurrentTime;		//���Ԃ��X�V
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(255, 255, 255);

	//�t���[�����[�g�̕\��
	DrawFormatString(WINDOW_WIDTH - 95, WINDOW_HEIGHT - 20, GetColor(255, 0, 0), "FPS[%.2f]", g_fFramerate);
}
