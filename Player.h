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
	int hpMax_; //Å‘åHP
	int hpCrr_; //HP
	Text* pText;
public:
	Player(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
};

