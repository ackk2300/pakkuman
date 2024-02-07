#include "PlayScene.h"
#include "Stage.h"
#include "Player.h"
#include "Gauge.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject (parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	Instantiate<Gauge>(this);
}

void PlayScene::Update()
{
	//Instantiate<Stage>(this);
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
