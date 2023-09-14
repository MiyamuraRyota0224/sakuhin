#include "Stage.h"
#include "StageParameter.h"


Stage::Stage(int id)
{
	id_ = id;
	sky_hndl_ = -1;
	sky_pos_ = { 0.0f, 0.0f, 0.0f };
	map_ = nullptr;
}

Stage::~Stage()
{
	Fin();
}

void Stage::Init()
{
	StageParameter param = STAGE_DATABASE[id_];
	map_ = new Map(param.map_id);

	// 遠くをぼかすフォグの設定
	/*SetFogEnable(TRUE);
	SetFogColor(param.fog_color_r, param.fog_color_g, param.fog_color_b);
	SetFogStartEnd(param.fog_start, param.fog_end);*/

}

void Stage::Load()
{
	//天球読み込み
	sky_hndl_ = MV1LoadModel("Data/Model/Map/Sky/Sky.x");
	//天球のサイズを大きくする
	MV1SetScale(sky_hndl_, VGet(400.0f, 400.0f, 400.0f));
	if (map_) {
		map_->Load();
	}
}

void Stage::Step()
{
	if (map_) {
		map_->Step();
	}
}

void Stage::Update()
{
	if (map_) {
		map_->Update();
	}
	MV1SetPosition(sky_hndl_, sky_pos_);
}

void Stage::Draw()
{
	if (map_) {
		map_->Draw();
	}
	MV1DrawModel(sky_hndl_);
}

void Stage::Delete()
{
	if (map_) {
		delete map_;
		map_ = nullptr;
	}
}

void Stage::Fin()
{
	Delete();
}
