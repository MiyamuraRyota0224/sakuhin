
//SceneManager.cpp
//�V�[���Ǘ�
//�e�V�[���ւ̃A�N�Z�X�͕K��SceneManager���o�R

#include "SceneManager.h"
#include "SceneParameter.h"
#include "PlayScene.h"
#include "TitleScene.h"
#include "GameoverScene.h"
#include "ClearScene.h"
#ifdef _DEBUG
#include "../Input/Input.h"
#endif


SceneManager *SceneManager::instance_ = nullptr;

SceneManager::SceneManager()
: scene_(nullptr)
, current_scene_state_(SCENE_STATE_INIT)
{
	scene_ = nullptr;
	current_scene_state_ = SCENE_STATE_INIT;
	next_scene_id_ = SCENE_ID_NUM;
	current_scene_id_ = SCENE_ID_NUM;
}

SceneManager::~SceneManager()
{
}

//������
void SceneManager::Init()
{
	//�����̓V�[���Ǘ��̏������ł����āA
	//�e�V�[���̏������ł͂Ȃ�
}

//���[�v
void SceneManager::Loop()
{
	void (SceneManager:: * scene_func[])() = {
		&SceneManager::SceneInit,
		& SceneManager::SceneLoad,
		& SceneManager::SceneLoadEnd,
		& SceneManager::SceneLoop,
		& SceneManager::SceneFin,
	};

	(this->*scene_func[current_scene_state_])();
}

// �V�[�����[�v���̊e�֐�
void SceneManager::SceneInit()
{
	scene_->Init();
	current_scene_state_ = SCENE_STATE_LOAD;
}

void SceneManager::SceneLoad()
{
	scene_->Load();
	current_scene_state_ = SCENE_STATE_LOAD_END;
}

void SceneManager::SceneLoadEnd()
{
	scene_->OnLoadEnd();
	current_scene_state_ = SCENE_STATE_LOOP;
}

void SceneManager::SceneLoop()
{
#ifdef _DEBUG
	// �f�o�b�O�̑�����@�\
	int loop = 1;
	if (CInput::IsCont(KEY_Z)) {
		loop = 10;
	}
	for (int i = 0; i < loop; i++) {
		scene_->Step();
		scene_->Update();
	}
	scene_->Draw();	//�`��̓X�e�b�v�̌�ɌĂ�
#else
	scene_->Step();
	scene_->Update();
	scene_->Draw();	//�`��̓X�e�b�v�̌�ɌĂ�
#endif
}

void SceneManager::SceneFin()
{
	scene_->Fin();
	ChangeNextScene();
}

//�㏈��
void SceneManager::Fin()
{
	if (scene_) {
		delete scene_;
	}
}

//�P�ԍŏ��̃V�[�����J�n����
void SceneManager::StartFirstScene(int sceneID)
{
	//���ɉ����V�[���������Ă�̂ł���Α��I��
	if (scene_) return;

	//�V�[���𐶐����ď���������J�n����
	CreateScene(sceneID);
	current_scene_id_ = sceneID;
	current_scene_state_ = SCENE_STATE_INIT;
}

//�����̃V�[���ɕύX����
void SceneManager::ChangeScene(int sceneID)
{
	//���ɑJ�ڂ���V�[�����o���Ă����A�I��������
	next_scene_id_ = sceneID;
	current_scene_state_ = SCENE_STATE_FIN;
}

//�V�[���𐶐�����
void SceneManager::CreateScene(int sceneID)
{
	//�V�[���𐶐�
	switch (sceneID) {
		case SCENE_ID_TITLE: scene_ = new Title; break;
		case SCENE_ID_PLAY: scene_ = new Play; break;
		case SCENE_ID_CLEAR: scene_ = new Clear; break;
		case SCENE_ID_GAMEOVER: scene_ = new Gameover; break;
	}
}

//���̃V�[���ɑJ�ڂ���
void SceneManager::ChangeNextScene()
{
	//�I�������V�[�����폜
	delete scene_;
	//���̃V�[���𐶐�
	CreateScene(next_scene_id_);
	//���݂̃V�[��ID�ݒ�
	current_scene_id_ = next_scene_id_;
	//��Ԃ��������ɖ߂�
	current_scene_state_ = SCENE_STATE_INIT;
}