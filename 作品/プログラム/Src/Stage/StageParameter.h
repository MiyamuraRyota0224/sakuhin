#pragma once
// ステージに関するパラメーター
#include "../Map/MapParameter.h"


// 種別ID
enum StageID {
	STAGE_ID_TITLE,
	STAGE_ID_STAGE1,
	STAGE_ID_NUM
};

// ステージ１つ分のパラメータ
struct StageParameter {
	int stage_id;								// 種別ID
	int map_id;									// 背景
	int enemy_table_id;							// 敵の配置
	int fog_color_r, fog_color_g, fog_color_b;	// フォグカラー
	float fog_start, fog_end;					// フォグの範囲
};

// 構築用データベース
static const StageParameter STAGE_DATABASE[STAGE_ID_NUM]{
	// stage_id			map_id			enemy_table_id			fog_color	fog_start	fog_end
	{STAGE_ID_TITLE,	MAP_ID_MONO,	-1,						90, 90, 90,	120.0f,		200.0f},
};


