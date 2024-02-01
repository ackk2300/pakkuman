#pragma once
#include "Engine/GameObject.h"

class Stage;

class Player :
    public GameObject

{
	int hModel_;
	float speed_;
	Stage* pStage_;
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
};

