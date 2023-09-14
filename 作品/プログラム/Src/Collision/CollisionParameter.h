#pragma once
// コリジョンに使用するパラメーター

// コリジョンの形状
enum CollisionShape {
	COLLISION_SHAPE_SPHERE,	// 球の当たり判定
	COLLISION_SHAPE_BOX,	// ボックスの当たり判定（AABB）
	COLLISION_SHAPE_NUM
};

// コリジョンのカテゴリー
enum CollisionCategory {
	COLLISION_CATEGORY_PLAYER,			// プレイヤー
	COLLISION_CATEGORY_WALL,
	COLLISION_CATEGORY_CRISTAL,
	COLLISION_CATEGORY_TREASURE,
	COLLISION_CATEGORY_GIMMIK_FLOOR,
	COLLISION_CATEGORY_NUM
};

// コリジョンの状態
enum CollisionState {
	COLLISION_STATE_ACTIVE,	// 有効
	COLLISION_STATE_UNUSE,	// 無効
	COLLISION_STATE_NONE,	// 使用済み
};
