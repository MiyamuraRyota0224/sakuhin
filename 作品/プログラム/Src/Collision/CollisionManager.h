#pragma once
// コリジョン管理クラス
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
	void DeleteEndCollision();	// 使用済みコリジョンの削除

public:
	void CheckCollision();	// 当たり判定チェック

private:
	void CheckPlayerAndWall();			// プレイヤーと壁の当たり判定
	void CheckPlayerAndTreasure();		// プレイヤーと宝箱の当たり判定
	void CheckTreasureAndGimmikFloor();	// プレイヤーとギミック床の当たり判定

private:
	static CollisionManager* instance_;							// インスタンス
	std::list<Collision*>collisions_[COLLISION_CATEGORY_NUM];	// 管理リスト
	float optimize_interval_;									// リスト最適化時間間隔
	float optimize_timer_;										// リスト最適化タイマー
};
