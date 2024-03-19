#include "TitleScene.h"
#include "TitleImage.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"


//�R���X�g���N�^
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

//������
void TitleScene::Initialize()
{
	Instantiate<TitleImage>(this);
}

//�X�V
void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

//�`��
void TitleScene::Draw()
{
}

//�J��
void TitleScene::Release()
{
}