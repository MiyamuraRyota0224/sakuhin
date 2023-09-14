#include "Object.h"

CObject::CObject()
{
	handle_ = -1;
	active_ = false;
	pos_ = { 0.0f };
	rot_ = { 0.0f };
	tag_ = 0;
}

CObject::~CObject()
{
}

void CObject::OnCollisionEnter(CObject* another)
{

}