#include "menu.hpp"
#include "command.hpp"

// public�֐�
// �R���X�g���N�^
Menu::Menu()
	: m_framecnt(0)
	, m_moveframe(0)
{}

// �f�X�g���N�^�͌p���p��virtual�Œ��g���Ȃ��̂Ńw�b�_�ɂ���

//private

// ���j���[�S�̂̕`��
void Menu::draw_menu() const
{
	for (const auto &it : m_menu)
	{
		draw_menustr(it.to_Point(), m_fonthash.at(it.fontinfo), m_colorhash.at(it.hash_color), it.str);
	}
}

// �R�}���h���͂��󂯎���ăJ�[�\���𓮂�������
void Menu::update_input(Cursor_uint& cursor_pos)
{
	if (m_cursor_int.max() != 0 && m_framecnt < -3)
	{
		// �����
		if (command_press(key_up) && cursor_stoped())
		{
			--m_cursor_int;
			//�J�[�\���̈ړ��ʂ��Z�b�e�B���O
			setmovespeed();
		}
		// ������
		if (command_press(key_down) && cursor_stoped())
		{
			++m_cursor_int;
			//�J�[�\���̈ړ��ʂ��Z�b�e�B���O
			setmovespeed();
		}
	}
}

// �J�[�\���ړ����x�̃Z�b�g
void Menu::setmovespeed()
{
	m_cursorspd = m_pos - Vec2(m_menu[m_cursor_int.value()].to_Point());
	m_cursorspd /= static_cast<double>(m_moveframe);
	m_framecnt = m_moveframe;
}

// �J�[�\���ʒu�̍X�V
// �����ς������Ƃ��̓I�[�o�[���C�h��
// drawpos = �`����W�@�����ς���
// destpos = �J�[�\���ʒu����Z�o�����A�{���`�悳���ׂ����W
/*
void Menu::update_cursor_drawpos(Vec2& drawpos, const Point& destpos)
{
drawpos += destpos
}
*/

// ���j���[���ڂЂƂЂƂ̕`��
void Menu::draw_menustr(const Point& pos, const Font& font, const Color& color, const String& str) const
{
	font(str).draw(pos, color);
}

// �J�[�\���̕`��
void Menu::draw_cursor(const Vec2& pos, const Rect& region) const
{
	Circle(pos.x - 20, pos.y + region.h / 2, 13).draw(Palette::Orange);//�J�[�\��
}

// protected

bool Menu::onCursor(Rect& getregion)
{
	bool ret = false;
	for (const auto &it : m_menu)
	{
		if (m_fonthash[it.fontinfo].region(it.str, it.to_Point()).mouseOver)
		{
			getregion = m_fonthash[it.fontinfo].region(it.str, it.to_Point());
			ret = true;
		}
	}
	if (!ret)
	{
		getregion = Rect{ 5000,5000,0,0 };
	}
	return ret;
}

// public

// �v�f�̒ǉ�
void Menu::add(int _x, int _y, const String& _str, const Font& _font, const Color& _color)
{
	const auto adddata = menu_elem(_x, _y, _str, _color, _font);
	m_menu.push_back(adddata);
	//m_menu�Ńn�b�V���ɂ����f�[�^����t�H���g�ƐF�f�[�^���f�[�^�c���[�Ɋi�[
	if (m_colorhash.count(adddata.hash_color) == 0)
	{
		m_colorhash[adddata.hash_color] = _color;
	}
	if (m_fonthash.count(adddata.fontinfo) == 0)
	{
		m_fonthash[adddata.fontinfo] = _font;
	}
	//�v�f�����J�E���g
	m_cursor_int.max_reset(m_cursor_int.max() + 1);

	//�ŏ��̑����Ȃ�J�[�\���ʒu��������
	if (m_cursor_int.max() == 1)
	{
		m_pos = m_menu[0].to_Point();
	}
}

// �J�[�\������~���Ă��邩�ǂ�����Ԃ�
bool Menu::cursor_stoped() const
{
	return m_framecnt <= 0;
}

// �J�[�\���̈ʒu��Ԃ�
// ���W�ł͂Ȃ��̂Œ���
int Menu::position() const
{
	return m_cursor_int.value();
}

// �L�[���͂����&�J�[�\���ʒu�𓮂���
void Menu::update()
{
	//�R�}���h���͂��󂯂Ƃ��ăJ�[�\���𓮂�������
	update_input(m_cursor_int);

	//�J�[�\���ʒu�𓮂���
	if (0 < m_framecnt)
	{
		m_pos -= m_cursorspd;
	}
	--m_framecnt;
	//update_cursor_drawpos( m_pos, m_menu[m_cursor_int.value()].to_Point());
}

// �`�揈�������ׂČĂяo��
void Menu::draw() const
{
	auto rect = m_fonthash.at(m_menu[m_cursor_int.value()].fontinfo)(m_menu[m_cursor_int.value()].str).region();
	rect.setPos(m_menu[m_cursor_int.value()].to_Point());
	draw_cursor(m_pos, rect);

	// �����ł����draw_menustr���Ăяo���Ă���
	draw_menu();
}
/*------------*/


/*
int Menu::add(const int _x, const int _y, const String _str)
{
m_list.push_back(menu_elem(_x,_y,_str));
return m_list.size()-1;
}

menu_elem & Menu::operator[] (unsigned n)
{
return m_list[n];
}

size_t Menu::size()
{
return m_list.size();
}
*/
