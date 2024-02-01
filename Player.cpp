#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Stage.h"

namespace {
	const float PLAYER_MOVE_SPEED{ 1.0f };
}

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1), speed_(PLAYER_MOVE_SPEED),pStage_(nullptr)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	pStage_ = (Stage *)FindObject("Stage");

	//map[13][1]が、(map[y][x]の場合)初期位置
}

void Player::Update()
{
	//int moveDir = Dir::NONE;
	XMVECTOR vFront = { 0,0,1,0 };
	XMVECTOR move{ 0,0,0,0 };

	if (Input::IsKeyDown(DIK_UP))
	{
		//this->transform_.position_.z += 0.1;
		move = XMVECTOR{ 0,0,1,0 };
	}
	if (Input::IsKeyDown(DIK_LEFT))
	{
		move = XMVECTOR{ -1,0,0,0 };
	}
	if (Input::IsKeyDown(DIK_DOWN))
	{
		move = XMVECTOR{ 0,0,-1,0 };
	}
	if (Input::IsKeyDown(DIK_RIGHT))
	{
		move = XMVECTOR{ 1,0,0,0 };
	}

	XMVECTOR posTmp = XMLoadFloat3(&(transform_.position_));
	XMVECTOR posTmp = XMVectorZero(); //ゼロベクトルで初期化
	posTmp = pos + speed_ * move;
	//posTmp.x,posTmp,z => int tx,ty :配列のインデックス
	//仮にmapの配列をmap{}{}とする
	//移動先がフロア(STAGE_OBJ => 0)だったら動く

	//if(map[ty][tx] == STAGE_OBJ)::FLOOR{
	//}

	//pos = pos + speed_ * move;
	//Debug::Log("X,Z)=");
	//Debug::Log(XMVectorGetX(pos));
	//Debug::Log(",");
	//Debug::Log(XMVectorGetZ(pos), true);
	int tx, ty;
	tx = (int)(XMVectorGetX(pos) + 0.5);
	ty = -pStage_->GetStageWidth() - (int)(XMVectorGetZ(posTmp) + 0.5);
	if (!(pStage_->IsWall(tx, ty))) {
		pos = posTmp;
	}
	Debug::Log("iX,iZ)=");
	Debug::Log(tx);
	Debug::Log(",");
	Debug::Log(ty);
	Debug::Log(" : ");
	Debug::Log(pStage_->IsWall(tx, ty), true);

	if (!XMVector3Equal(move, XMVectorZero())) {
		XMStoreFloat3(&(transform_.position_), pos);

		XMVECTOR vdot = XMVector3Dot(vFront, move);
		assert(XMVectorGetX(vdot) <= 1 && XMVectorGetX(vdot) >= -1);
		float angle = acos(XMVectorGetX(vdot));

		XMVECTOR vCross = XMVector3Cross(vFront, move);
		if (XMVectorGetY(vCross) < 0) {
			{
				angle *= -1;
			}

			transform_.rotate_.y = XMConvertToDegrees(angle);
		}
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}