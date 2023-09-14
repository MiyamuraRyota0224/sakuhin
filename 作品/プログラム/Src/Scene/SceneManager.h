#pragma once

//SceneManager.h
//�V�[���Ǘ�
//�e�V�[���ւ̃A�N�Z�X�͕K��SceneManager���o�R

#include "Scene.h"

class SceneManager
{
public:
	static void CreateInstance() { if (!instance_) instance_ = new SceneManager; }
	static SceneManager* GetInstance() { return instance_; }
	static void DeleteInstance() { if (instance_) delete instance_; instance_ = nullptr; }

public:

	SceneManager();
	~SceneManager();

	//������
	void Init();

	//���[�v
	void Loop();

	//�㏈��
	void Fin();

	//�P�ԍŏ��̃V�[�����J�n����
	void StartFirstScene(int sceneID);

	//�����̃V�[���ɕύX����
	void ChangeScene(int sceneID);

	// ���݂̃V�[�����擾����
	Scene* GetNowScene() const { return scene_; }

private:
	//�V�[���𐶐�����
	void CreateScene(int sceneID);

	//���̉�ʂɑJ�ڂ�����
	void ChangeNextScene();

	// �V�[�����[�v���̊e�֐�
	void SceneInit();
	void SceneLoad();
	void SceneLoadEnd();
	void SceneLoop();
	void SceneFin();

private:
	//�C���X�^���X
	static SceneManager *instance_;

	//���݂̃V�[��ID
	int current_scene_id_;
	int next_scene_id_;
	int current_scene_state_;

	//���|�C���^�P�ŊǗ�����
	Scene *scene_;
};
