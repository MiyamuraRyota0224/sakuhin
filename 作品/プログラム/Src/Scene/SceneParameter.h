#pragma once

//�V�[�����
enum SCENE_STATE {
	SCENE_STATE_INIT,		//������
	SCENE_STATE_LOAD,		//���[�h
	SCENE_STATE_LOAD_END,	//���[�h�I��
	SCENE_STATE_LOOP,		//���[�v
	SCENE_STATE_FIN,		//�㏈��
};
//�V�[��ID
enum SCENE_ID
{
	SCENE_ID_TITLE,		//�^�C�g���V�[��
	SCENE_ID_PLAY,		//�v���C�V�[��
	SCENE_ID_CLEAR,		//�N���A�V�[��
	SCENE_ID_GAMEOVER,	//�Q�[���I�[�o�[�V�[��
	SCENE_ID_NUM,
};

