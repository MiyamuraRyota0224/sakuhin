#include "MazeManager.h"
#include "MazeParameter.h"
#include "../Common/Common.h"

MazeManager* MazeManager::instance_ = nullptr;

MazeManager::MazeManager()
{
	maze_ = nullptr;
	goal_ = nullptr;
}

MazeManager::~MazeManager()
{
	
}

void MazeManager::Init()
{
	maze_ = new CMaze;
	goal_ = new CGoal;
	Common::InitRandom();
}

void MazeManager::Load()
{
	maze_->Load();
	goal_->Load();
}

void MazeManager::OnLoadEnd()
{
	CreateMaze();
}

void MazeManager::Update()
{
	for(auto wall : walls_)
	wall->Update();

	for(auto goal : goals_)
	goal->Update();
}

void MazeManager::Step()
{

}

void MazeManager::Draw()
{
	for(auto wall : walls_)
	wall->Draw();

	for(auto goal : goals_)
	goal->Draw();
}

void MazeManager::Delete()
{
	maze_->Delete();
	goal_->Delete();
}

void MazeManager::Fin()
{
	maze_->Fin();
	goal_->Fin();
}

void MazeManager::CreateMaze()
{
	// 乱数
	int random = 0;

	// 棒倒し法で自動生成
	// フィールドのマス目数
	// 0:通路　1:壁
	int field[MAX_Z][MAX_X];

	// 通路 (0) の生成
	// 縦幅分ループする
	for (int z = 0; z < MAX_Z; z++)
	{
		// 横幅分ループする
		for (int x = 0; x < MAX_X; x++)
		{
			field[z][x] = 0;
		}
	}

	// 上下の外壁 (1) の生成
	// 横幅分ループする
	for (int x = 0; x < MAX_X; x++)
	{
		field[0][x] = 1;
		field[MAX_Z - 1][x] = 1;
	}

	// 左右の外壁 (1) の生成
	// 縦幅分ループする
	for (int z = 0; z < MAX_Z; z++)
	{
		field[z][0] = 1;
		field[z][MAX_X - 1] = 1;
	}

	// 壁の作成 (1行目)
	for (int x = 2; x < MAX_X - 1; x += 2)
	{
		// 乱数生成
		random = Common::GetRandom(1, 12);

		field[2][x] = 1;

		if (random <= 3)
		{
			// 上に壁がなければ
			if (field[2 - 1][x] == 0)
			{
				// 上に棒を倒す
				field[2 - 1][x] = 1;
			}
			else if (field[2 - 1][x] == 1)
			{
				// 壁があるならやり直し
				x = x - 2;
			}
		}
		else if (random <= 6)
		{
			// 下に壁がなければ
			if (field[2 + 1][x] == 0)
			{
				// 下に棒を倒す
				field[2 + 1][x] = 1;
			}
			else if (field[2 + 1][x] == 1)
			{
				// 壁があるならやり直し
				x = x - 2;
			}
		}
		else if (random <= 9)
		{
			// 左に壁がなければ
			if (field[2][x - 1] == 0)
			{
				// 左に棒を倒す
				field[2][x - 1] = 1;
			}
			else if (field[2][x - 1] == 1)
			{
				// 壁があるならやり直し
				x = x - 2;
			}
		}
		else
		{
			// 右に壁がなければ
			if (field[2][x + 1] == 0)
			{
				// 右に棒を倒す
				field[2][x + 1] = 1;
			}
			else if (field[2][x + 1] == 1)
			{
				// 壁があるならやり直し
				x = x - 2;
			}
		}
	}

	// ２行目以降の壁の作成
	for (int z = 4; z < MAX_Z - 1; z += 2)
	{
		for (int x = 2; x < MAX_X - 1; x += 2)
		{
			// 乱数生成
			random = Common::GetRandom(1, 12);

			field[z][x] = 1;

			if (random <= 4)
			{
				// 下に壁がなければ
				if (field[z + 1][x] == 0)
				{
					// 下に棒を倒す
					field[z + 1][x] = 1;
				}
				else if (field[z + 1][x] == 1)
				{
					// 壁があるならやり直し
					x = x - 2;
				}
			}
			else if (random <= 8)
			{
				// 左に壁がなければ
				if (field[z][x - 1] == 0)
				{
					// 左に棒を倒す
					field[z][x - 1] = 1;
				}
				else if (field[z][x - 1] == 1)
				{
					// 壁があるならやり直し
					x = x - 2;
				}
			}
			else
			{
				// 右に壁がなければ
				if (field[z][x + 1] == 0)
				{
					// 右に棒を倒す
					field[z][x + 1] = 1;
				}
				else if (field[z][x + 1] == 1)
				{
					// 壁があるならやり直し
					x = x - 2;
				}
			}
		}
	}

	// スタート地点の壁を撤去する
	field[0][1] = 0;

	// ゴール地点の壁を撤去する
	field[MAX_Z - 1][MAX_X - 2] = 2;

	// 壁（１）のある部分に壁を生成する
	for (int z = 0; z < MAX_Z; z++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			if (field[z][x] == 1)
			{
				CMaze* wall = maze_->Clone();
				wall->SetPos(VGet(x * SIZE_WIDTH, SIZE_HEIGHT / 2.0f, z * SIZE_DEPS));
				walls_.push_back(wall);
			}

			if (field[z][x] == 2)
			{
				CGoal* goal = goal_->Clone();
				goal->SetPos(VGet(x* SIZE_WIDTH, -SIZE_HEIGHT / 4, z* SIZE_DEPS));
				goals_.push_back(goal);
			}
		}
	}
}
