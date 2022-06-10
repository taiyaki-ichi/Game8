#pragma once
#include"Rect.hpp"
#include<array>

namespace g8
{
	//��ӂ̒�����2�̐����`�̓_�𔽎��v���̏��ɓ��ꍞ��
	void InitNormalizeRect(std::array<Vector2D, 4>&) noexcept;

	//Rect���炻�̎l�p�`���\������l�_���v�Z
	void ToVector2DArray(Rect const&, std::array<Vector2D, 4>&) noexcept;

	//p1, p2 ����Ȃ���� q1, q2 ����Ȃ�����������Ă��邩�ǂ���
	bool CrossDetection(Vector2D const& p1, Vector2D const& p2, Vector2D const& q1, Vector2D const& q2) noexcept;

	//�Е��̎l�p�`�����S�ɑ����̓����ɂ��邩�ǂ����̔���
	bool IsContain(std::array<Vector2D, 4> const&, std::array<Vector2D, 4> const&) noexcept;

	//Rect���m���������Ă��邩�ǂ���
	bool IsHit(Rect const&, Rect const&) noexcept;
}