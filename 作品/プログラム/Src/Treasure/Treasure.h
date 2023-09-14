#pragma once

#include "../Object/Object.h"
#include "../Collision/SphereCollision.h"

class CTreasure : public CObject {
public:
	CTreasure();
	~CTreasure();

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	virtual void OnCollisionEnter(CObject* another) override;

	void Reset();
	void SetIsHeld(bool isHeld);

private:

	VECTOR restart_pos_;

	// ”¼Œa
	float rad_;

	// ‚½‚ê‚Ä‚¢‚é‚©
	bool isHeld_;

	// ƒMƒ~ƒbƒN‚Éæ‚Á‚Ä‚¢‚é‚©
	bool isOnGimmik_;

	// “–‚½‚è”»’è
	SphereCollision* collision_;
};