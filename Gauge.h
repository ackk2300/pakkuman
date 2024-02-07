#pragma once
#include "Engine/GameObject.h"

class Gauge :
    public GameObject
{
    int hGaugeBar_; //�Q�[�W�̉摜�n���h��
    int hGaugeFrame_;//�t���[���̉摜�n���h��

    int gaugeMaxVal_;//�Q�[�W�̍ő�l
    int gaugeCrrVal_;//�J�����g�̒l�i�����̒l�j curre t value
public:
    Gauge( GameObject* parent);

    //������
    void Initialize()override;

    //�X�V
    void Update()override;

    //�`��
    void Draw()override;

    //�J��
    void Release() override;

    void SetGaugeVal(int _crr, int _max)
    {
        gaugeMaxVal_ = _max;
        gaugeCrrVal_ = _crr;
    }
};

