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
	// ����
	int random = 0;

	// �_�|���@�Ŏ�������
	// �t�B�[���h�̃}�X�ڐ�
	// 0:�ʘH�@1:��
	int field[MAX_Z][MAX_X];

	// �ʘH (0) �̐���
	// �c�������[�v����
	for (int z = 0; z < MAX_Z; z++)
	{
		// ���������[�v����
		for (int x = 0; x < MAX_X; x++)
		{
			field[z][x] = 0;
		}
	}

	// �㉺�̊O�� (1) �̐���
	// ���������[�v����
	for (int x = 0; x < MAX_X; x++)
	{
		field[0][x] = 1;
		field[MAX_Z - 1][x] = 1;
	}

	// ���E�̊O�� (1) �̐���
	// �c�������[�v����
	for (int z = 0; z < MAX_Z; z++)
	{
		field[z][0] = 1;
		field[z][MAX_X - 1] = 1;
	}

	// �ǂ̍쐬 (1�s��)
	for (int x = 2; x < MAX_X - 1; x += 2)
	{
		// ��������
		random = Common::GetRandom(1, 12);

		field[2][x] = 1;

		if (random <= 3)
		{
			// ��ɕǂ��Ȃ����
			if (field[2 - 1][x] == 0)
			{
				// ��ɖ_��|��
				field[2 - 1][x] = 1;
			}
			else if (field[2 - 1][x] == 1)
			{
				// �ǂ�����Ȃ��蒼��
				x = x - 2;
			}
		}
		else if (random <= 6)
		{
			// ���ɕǂ��Ȃ����
			if (field[2 + 1][x] == 0)
			{
				// ���ɖ_��|��
				field[2 + 1][x] = 1;
			}
			else if (field[2 + 1][x] == 1)
			{
				// �ǂ�����Ȃ��蒼��
				x = x - 2;
			}
		}
		else if (random <= 9)
		{
			// ���ɕǂ��Ȃ����
			if (field[2][x - 1] == 0)
			{
				// ���ɖ_��|��
				field[2][x - 1] = 1;
			}
			else if (field[2][x - 1] == 1)
			{
				// �ǂ�����Ȃ��蒼��
				x = x - 2;
			}
		}
		else
		{
			// �E�ɕǂ��Ȃ����
			if (field[2][x + 1] == 0)
			{
				// �E�ɖ_��|��
				field[2][x + 1] = 1;
			}
			else if (field[2][x + 1] == 1)
			{
				// �ǂ�����Ȃ��蒼��
				x = x - 2;
			}
		}
	}

	// �Q�s�ڈȍ~�̕ǂ̍쐬
	for (int z = 4; z < MAX_Z - 1; z += 2)
	{
		for (int x = 2; x < MAX_X - 1; x += 2)
		{
			// ��������
			random = Common::GetRandom(1, 12);

			field[z][x] = 1;

			if (random <= 4)
			{
				// ���ɕǂ��Ȃ����
				if (field[z + 1][x] == 0)
				{
					// ���ɖ_��|��
					field[z + 1][x] = 1;
				}
				else if (field[z + 1][x] == 1)
				{
					// �ǂ�����Ȃ��蒼��
					x = x - 2;
				}
			}
			else if (random <= 8)
			{
				// ���ɕǂ��Ȃ����
				if (field[z][x - 1] == 0)
				{
					// ���ɖ_��|��
					field[z][x - 1] = 1;
				}
				else if (field[z][x - 1] == 1)
				{
					// �ǂ�����Ȃ��蒼��
					x = x - 2;
				}
			}
			else
			{
				// �E�ɕǂ��Ȃ����
				if (field[z][x + 1] == 0)
				{
					// �E�ɖ_��|��
					field[z][x + 1] = 1;
				}
				else if (field[z][x + 1] == 1)
				{
					// �ǂ�����Ȃ��蒼��
					x = x - 2;
				}
			}
		}
	}

	// �X�^�[�g�n�_�̕ǂ�P������
	field[0][1] = 0;

	// �S�[���n�_�̕ǂ�P������
	field[MAX_Z - 1][MAX_X - 2] = 2;

	// �ǁi�P�j�̂��镔���ɕǂ𐶐�����
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
