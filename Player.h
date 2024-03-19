#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Stage;

class Player :
    public GameObject

{
	int hModel_;
	float speed_;
	Stage* pStage_;
	int hpMax_; //�ő�HP
	int hpCrr_; //HP
	Text* pText;
public:
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
};

