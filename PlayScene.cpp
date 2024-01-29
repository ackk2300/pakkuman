#include "PlayScene.h"
#include "Stage.h"
#include "Player.h"


PlayScene::PlayScene(GameObject* parent)
	:GameObject (parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
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
