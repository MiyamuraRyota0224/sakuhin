#pragma once
// ボックスの当たり判定（AABB）
#include "DxLib.h"
#include "Collision.h"

class BoxCollision : public Collision{
public:
	BoxCollision();
	virtual ~BoxCollision();

public:
	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Fin();
	virtual Collision* Clone() override;

	virtual bool CheckCollision(Collision* another) override;

public:
	VECTOR GetSize() const { return size_; }

	void SetSize(VECTOR size) { size_ = size; }
	void SetSize(float width, float height, float depth) { size_ = VGet(width, height, depth); }

private:
	VECTOR size_;
};
