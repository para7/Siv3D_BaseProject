#include "Para7/scenectrl.hpp"
#include "title.hpp"
#include "Para7/usefuls.hpp"
#include "Para7/command.hpp"

Title::Title()
	: titlefont(40, Typeface::Bold)
	, explfont(15, Typeface::Medium)
//	, menus(Font{20},Palette::Black,10)
{}

void Title::init()
{
	/*  �A�[�J�C�u�ł܂Ƃ߂��t�@�C���̃��[�h������  */
	//titlebgm = Sound(m_data->arc.load(L"Data/Sound/bgm.mp3"));
	
	//�@���j���[���ڂ̒ǉ�
	//  X���W�AY���W�A���j���[�̕����A�t�H���g�f�[�^�A�`��F
	// �J�[�\���ړ��ɂ�����t���[�������Z�b�g
	menus.set_moveflame(8);

	const Font font{ 20 };
	menus.add(200, 200, L"�Q�[���X�^�[�g",font,Palette::Black);
	menus.add(220, 270, L"�����т���",font,Palette::Black);
	menus.add(240, 340, L"�����܂�",font,Palette::Darkgray);
	// �����n�C�X�R�A�Ȃǂ��^�C�g�����j���[�ɒǉ�������������A
	// ����Ȋ����ŗv�f�ǉ����Ă��Ύ����I�Ƀ��[�v���郁�j���[��ʂ��ۂ��̂��o���オ��
	// �v�f�������֐��͍��̂Ƃ���p�ӂ���\��͂Ȃ�
}

void Title::update()
{
	//command_click,command_press�̓R�}���h�����̓���֐�
	//�ڂ���������A�Ή����鑀���ς������Ƃ���command.hpp
	//������g�����_�̓L�[����ς�����Ƃ���command.cpp���̏�����ς���ΑS�ӏ��ɕύX�ł���̂�
	//WASD�Ə\���L�[�ł̈ړ��𗼗�������ł��邱��

	//�J�[�\�����ړ����͌���{�^���������Ȃ��悤�ɂ��邽�߂�stoped()�Œ�~���Ă��邩�`�F�b�N
	if (command_click(key_1) && menus.cursor_stoped())
	{
		if(menus.cursor_stoped())
		//���j���[���莞�Ɍ��ʉ���炵������΂��̂ւ�Ŗ炷
		switch (menus.position())
		{
		case 0:
			changeScene(L"Game");
			break;
		case 1:
			changeScene(L"Explain");
			break;
		case 2:
			System::Exit();
			break;
			//init()�Ń��j���[�v�f��ǉ����Ă����炱���𑝂₷
		}
	}
	//�F�X�X�V����@������menu.hpp
	menus.update();
}

void Title::draw() const
{
	//�w�i��`��
	//�w�i�F���̂��̂�ς����Ⴄ�ƕs�ӂ̃V�[���ύX�ȂǂŔw�i�F���ύX���ꑹ�˂��肷�邩������Ȃ��̂ŁA���̏ꂻ�̏�ŕ`�悵�Ă���
	//�w�i�F�ς����ق����������y���Ƃ͎v��
	Window::BaseClientRect().draw(Palette::White);

	//���j���[���ڂ̕`��
	menus.draw();
	
	//���W�o�O�C���֐�drawCenter�̎g�p��
	drawCenter(titlefont, L"�Q�[��", 60, Palette::Black);
    
    const String Creatername{L"Created by : hogehoge"};
	explfont(Creatername).draw(30, Window::BaseHeight() - explfont(Creatername).region().h, Palette::Gray);
}
