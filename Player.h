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
	int hpMax_; //最大HP
	int hpCrr_; //HP
	Text* pText;
public:
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
};

