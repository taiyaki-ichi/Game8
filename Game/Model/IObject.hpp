#pragma once

namespace g8
{
	class IStageObject
	{
	public:

		//�ŏ��̃t���[���̊J�n�O�Ɉ�x�����Ă΂��
		//����Ȃ�����
		virtual void Start() {};

		//�����蔻��̑O�ɌĂ΂��
		virtual void Update1() {};
		//�����蔻��̌�ɌĂ΂��
		virtual void Update2() {};
	};
}