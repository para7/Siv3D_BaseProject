#pragma once

#include <Siv3D.hpp>
#include <vector>
#include "cursor_uint.hpp"
#include <functional>
#include <tuple>
#include <unordered_map>
#include <map>

// title.cpp�Ŏg���Ă�̂Ŏg�p��͂������
// �F�X����������������I�[�o�[���C�h���Ă�������
class Menu
{
private:
	using Fontinfo = std::tuple<int, String, FontStyle>;

	//���j���[�̊e�v�f
	class menu_elem
	{
	public:
		const int x;
		const int y;
		const String str;
		// �F�̃n�b�V���l
		const size_t hash_color;
		// �t�H���g�f�[�^�̒��o
		const Fontinfo fontinfo; \
			menu_elem(int _x, int _y, const String& _str, const Color& _color, const Font& _font)
			: x(_x)
			, y(_y)
			, str(_str)
			, hash_color(std::hash<Color>()(_color))
			, fontinfo(std::make_tuple(_font.size(), _font.name(), _font.style()))
		{}
		inline Point to_Point() const { return Point{ x,y }; }
	};

private:
	// �v�f�̔z��
	std::vector<menu_elem> m_menu;

	// �`��p�f�[�^�̃n�b�V���c���[
	// �F
	std::unordered_map<size_t, Color> m_colorhash;
	// �t�H���g
	// �L�[�l�̎Z�o��boost�g��Ȃ��Ƃ����̂�map�ɂ��Ă���
	std::map<Fontinfo, Font> m_fonthash;

	// �J�[�\���ʒu
	Cursor_uint m_cursor_int;

	// �J�[�\�����W
	Vec2 m_pos;

	// �J�[�\���ړ����x
	Vec2 m_cursorspd;

	//�J�[�\���ړ��ɕK�v�ȃt���[����
	int m_moveframe;

	// �t���[���J�E���^
	int m_framecnt;

	//���j���[�S�̂̕`��
	virtual void draw_menu() const final;

	// �J�[�\���̕`����W��Ԃ�
	inline int pos_x() const { return static_cast<int>(m_pos.x); }
	inline int pos_y() const { return static_cast<int>(m_pos.y); }
	inline Point pos() const { return Point(m_pos.x, m_pos.y); }

	// �R�}���h���͂��󂯎���ăJ�[�\���𓮂�������
	virtual void update_input(Cursor_uint& cursor_pos);

	// �J�[�\���ړ����x�̃Z�b�g
	void setmovespeed();

	// �J�[�\���ʒu�̍X�V�@
	// �����ς������Ƃ��̓I�[�o�[���C�h��
	// Vec2  : �`�悪�s������W
	// Point : �J�[�\���̈ʒu����v�Z�����{������ׂ����W
	//virtual void update_cursor_drawpos(Vec2&,const Point&);

	// ���j���[���ڂЂƂЂƂ̕`��
	void Menu::draw_menustr(const Point& pos, const Font& font, const Color& color, const String& str) const;

	// �J�[�\���̕`��
	virtual void draw_cursor(const Vec2& pos, const Rect& region) const;

protected:
	//�J�[�\��������Ă���W�ƗL���������Ė߂��֐��@�Ԃ�l�ł��ƃR�s�[�̎��Ԃ�����Ȃ̂ŎQ�Ƃŏ����ς���
	bool onCursor(Rect& getregion);

public:

	// �R���X�g���N�^
	// �X�s�[�h�w�肵�Ȃ���΃J�[�\���̓��[�v����
	Menu();
	inline void set_moveflame(int frame) { m_moveframe = frame; }

	// �f�X�g���N�^(�p���pvirtual)
	virtual ~Menu() {}

	// ���j���[�v�f�̒ǉ�
	virtual void add(int _x, int _y, const String& _str, const Font& _font, const Color& _color) final;

	// �J�[�\�����W���Î~���Ă��邩�ǂ�����Ԃ�
	bool cursor_stoped() const;

	// �J�[�\���̈ʒu��Ԃ�
	// ���W�ł͂Ȃ��̂Œ���
	int position() const;

	// �L�[���͂����&�J�[�\���ʒu�𓮂���
	void update();

	// �`�揈�����ׂĂ��Ăяo��
	void draw() const;
};

/*
std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<menu_elem>>> begin() const
{
return m_menu.begin();
}
std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<menu_elem>>> end() const
{
return m_menu.end();
}
*/
