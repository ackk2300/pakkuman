#include "PlayScene.h"
#include "Stage.h"



PlayScene::PlayScene(GameObject* parent)
	:GameObject (parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
}

void PlayScene::Update()
{
	Instantiate<Stage>(this);
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
