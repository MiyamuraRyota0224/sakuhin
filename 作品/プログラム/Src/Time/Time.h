#pragma once

class CTime
{
public:
	CTime();
	~CTime();

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Draw();
	void Delete();
	void Fin();

	void Reset();

private:
	float timer_;

	bool isReset_;
};