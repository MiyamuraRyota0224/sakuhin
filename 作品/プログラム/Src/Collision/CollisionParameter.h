#pragma once
// �R���W�����Ɏg�p����p�����[�^�[

// �R���W�����̌`��
enum CollisionShape {
	COLLISION_SHAPE_SPHERE,	// ���̓����蔻��
	COLLISION_SHAPE_BOX,	// �{�b�N�X�̓����蔻��iAABB�j
	COLLISION_SHAPE_NUM
};

// �R���W�����̃J�e�S���[
enum CollisionCategory {
	COLLISION_CATEGORY_PLAYER,			// �v���C���[
	COLLISION_CATEGORY_WALL,
	COLLISION_CATEGORY_CRISTAL,
	COLLISION_CATEGORY_TREASURE,
	COLLISION_CATEGORY_GIMMIK_FLOOR,
	COLLISION_CATEGORY_NUM
};

// �R���W�����̏��
enum CollisionState {
	COLLISION_STATE_ACTIVE,	// �L��
	COLLISION_STATE_UNUSE,	// ����
	COLLISION_STATE_NONE,	// �g�p�ς�
};
