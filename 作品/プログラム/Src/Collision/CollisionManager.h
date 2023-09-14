#pragma once
// �R���W�����Ǘ��N���X
#include "Collision.h"
#include "CollisionParameter.h"
#include <list>

class CollisionManager {
public:
	CollisionManager();
	~CollisionManager();

public:
	static void CreateInstance() { if (!instance_) instance_ = new CollisionManager; }
	static CollisionManager* GetInstance() { return instance_; }
	static void DeleteInstance() { if (instance_) delete instance_; instance_ = nullptr; }

public:
	void Init();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

public:
	Collision* CreateCollision(int shape, int category);
	void DeleteEndCollision();	// �g�p�ς݃R���W�����̍폜

public:
	void CheckCollision();	// �����蔻��`�F�b�N

private:
	void CheckPlayerAndWall();			// �v���C���[�ƕǂ̓����蔻��
	void CheckPlayerAndTreasure();		// �v���C���[�ƕ󔠂̓����蔻��
	void CheckTreasureAndGimmikFloor();	// �v���C���[�ƃM�~�b�N���̓����蔻��

private:
	static CollisionManager* instance_;							// �C���X�^���X
	std::list<Collision*>collisions_[COLLISION_CATEGORY_NUM];	// �Ǘ����X�g
	float optimize_interval_;									// ���X�g�œK�����ԊԊu
	float optimize_timer_;										// ���X�g�œK���^�C�}�[
};
