#include "explain.hpp"
#include "Para7//Para7Utilities.hpp"
//#include "Para7/command.hpp"
//#include "Para7/usefuls.hpp"

/*
void Explain::init()
{}
*/

void Explain::update()
{
	//����L�[�������΂��Ƃ̉�ʂɖ߂�
	if (command_click(key_1))
	{
		changeScene(L"Title");
	}
}
void Explain::draw() const
{
	Window::BaseClientRect().draw(Palette::White);
	
	font(L"�K���ɍ�邾���Ȃ炱���ɑ�������������Ƃ�������\n\n������@\n�ړ��@�J�[�\���L�[�@�܂��́@asdw�L�[\nkey_1(����)�@Z�L�[�@J�L�[�@�X�y�[�X�L�[\n\n�f�t�H���g�̃R�[�h�ł͈ȉ��̃{�^���ɂ��Ή����Ă��܂�\nkey_2   X�L�[ K�L�[\nkey_3   C L�L�[").draw(20, 20,Palette::Black);
	
	drawCenter(font,L"����L�[�������Ɩ߂�܂�",440,Palette::Black);
}

Explain::Explain()
	: font(15)
{}