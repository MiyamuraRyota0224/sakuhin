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
	// ========�擾�A�ݒ�֘A=========

	// �����t���O
	void SetActive(bool active) { active_ = active; }
	bool IsActive() const { return active_; }

	// ���W
	void SetPos(VECTOR pos) { pos_ = pos; }
	VECTOR GetPos() const { return pos_; }

	// �p�x
	void SetRot(VECTOR rot) { rot_ = rot; }
	VECTOR GetRot() const { return rot_; }

	// �^�O
	void SetTag(int tag) { tag_ |= (1 << tag); }
	int GetTag() const { return tag_; }

	// ===============================

	bool ObjectHasTag(int tag) const { return (tag_ & (1 << tag)); }

protected:
	// �n���h��
	int handle_;
	// �����t���O
	bool active_;
	// ���W
	VECTOR pos_;
	// �p�x
	VECTOR rot_;
	// �^�O
	int tag_;
};