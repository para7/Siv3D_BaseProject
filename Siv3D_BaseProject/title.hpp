#pragma once

#include "Para7//Para7Utilities.hpp"

class Title : public MySceneBase
{
private:
	// const�t���ăR���X�g���N�^�ŏ��������悤�Ƃ���ƁA�ǂݍ��݃^�C�~���O�����������̂��G���[�o�����Ƃ��������̂�
	// ���̏ꍇ��const���O����init()�֐����ő������΂Ȃ�Ƃ��Ȃ�
	// �������A�œK���̊֌W��const��t������������͑����͂������A�����l�ݒ�Y����Ȃ��Ȃ�̂łł��邾��const����悤�ɂ������Ƃ���
	const Font titlefont, explfont;
	// ���j���[��ʂ̊ȒP�ȍ\�z �錾�Fmenu.hpp
	Menu menus;
public:
	Title();
	void init() override;
	void draw() const override;
	void update() override;
};