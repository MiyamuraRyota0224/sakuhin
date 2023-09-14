#pragma once

#include "DxLib.h"
#include "ObjectParameter.h"

class CObject {
public:
	CObject();
	~CObject();

public:
	virtual void OnCollisionEnter(CObject* another);

public:
	// ========取得、設定関連=========

	// 生存フラグ
	void SetActive(bool active) { active_ = active; }
	bool IsActive() const { return active_; }

	// 座標
	void SetPos(VECTOR pos) { pos_ = pos; }
	VECTOR GetPos() const { return pos_; }

	// 角度
	void SetRot(VECTOR rot) { rot_ = rot; }
	VECTOR GetRot() const { return rot_; }

	// タグ
	void SetTag(int tag) { tag_ |= (1 << tag); }
	int GetTag() const { return tag_; }

	// ===============================

	bool ObjectHasTag(int tag) const { return (tag_ & (1 << tag)); }

protected:
	// ハンドル
	int handle_;
	// 生存フラグ
	bool active_;
	// 座標
	VECTOR pos_;
	// 角度
	VECTOR rot_;
	// タグ
	int tag_;
};