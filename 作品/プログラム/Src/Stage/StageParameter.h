#pragma once
// �X�e�[�W�Ɋւ���p�����[�^�[
#include "../Map/MapParameter.h"


// ���ID
enum StageID {
	STAGE_ID_TITLE,
	STAGE_ID_STAGE1,
	STAGE_ID_NUM
};

// �X�e�[�W�P���̃p�����[�^
struct StageParameter {
	int stage_id;								// ���ID
	int map_id;									// �w�i
	int enemy_table_id;							// �G�̔z�u
	int fog_color_r, fog_color_g, fog_color_b;	// �t�H�O�J���[
	float fog_start, fog_end;					// �t�H�O�͈̔�
};

// �\�z�p�f�[�^�x�[�X
static const StageParameter STAGE_DATABASE[STAGE_ID_NUM]{
	// stage_id			map_id			enemy_table_id			fog_color	fog_start	fog_end
	{STAGE_ID_TITLE,	MAP_ID_MONO,	-1,						90, 90, 90,	120.0f,		200.0f},
};


