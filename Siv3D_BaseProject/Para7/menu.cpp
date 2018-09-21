#include "menu.hpp"
#include "command.hpp"

// public関数
// コンストラクタ
Menu::Menu()
	: m_framecnt(0)
	, m_moveframe(0)
{}

// デストラクタは継承用のvirtualで中身がないのでヘッダにある

//private

// メニュー全体の描画
void Menu::draw_menu() const
{
	for (const auto &it : m_menu)
	{
		draw_menustr(it.to_Point(), m_fonthash.at(it.fontinfo), m_colorhash.at(it.hash_color), it.str);
	}
}

// コマンド入力を受け取ってカーソルを動かす処理
void Menu::update_input(Cursor_uint& cursor_pos)
{
	if (m_cursor_int.max() != 0 && m_framecnt < -3)
	{
		// 上入力
		if (command_press(key_up) && cursor_stoped())
		{
			--m_cursor_int;
			//カーソルの移動量をセッティング
			setmovespeed();
		}
		// 下入力
		if (command_press(key_down) && cursor_stoped())
		{
			++m_cursor_int;
			//カーソルの移動量をセッティング
			setmovespeed();
		}
	}
}

// カーソル移動速度のセット
void Menu::setmovespeed()
{
	m_cursorspd = m_pos - Vec2(m_menu[m_cursor_int.value()].to_Point());
	m_cursorspd /= static_cast<double>(m_moveframe);
	m_framecnt = m_moveframe;
}

// カーソル位置の更新
// 挙動変えたいときはオーバーライドで
// drawpos = 描画座標　これを変える
// destpos = カーソル位置から算出される、本来描画されるべき座標
/*
void Menu::update_cursor_drawpos(Vec2& drawpos, const Point& destpos)
{
drawpos += destpos
}
*/

// メニュー項目ひとつひとつの描画
void Menu::draw_menustr(const Point& pos, const Font& font, const Color& color, const String& str) const
{
	font(str).draw(pos, color);
}

// カーソルの描画
void Menu::draw_cursor(const Vec2& pos, const Rect& region) const
{
	Circle(pos.x - 20, pos.y + region.h / 2, 13).draw(Palette::Orange);//カーソル
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

// 要素の追加
void Menu::add(int _x, int _y, const String& _str, const Font& _font, const Color& _color)
{
	const auto adddata = menu_elem(_x, _y, _str, _color, _font);
	m_menu.push_back(adddata);
	//m_menuでハッシュにしたデータからフォントと色データをデータツリーに格納
	if (m_colorhash.count(adddata.hash_color) == 0)
	{
		m_colorhash[adddata.hash_color] = _color;
	}
	if (m_fonthash.count(adddata.fontinfo) == 0)
	{
		m_fonthash[adddata.fontinfo] = _font;
	}
	//要素数をカウント
	m_cursor_int.max_reset(m_cursor_int.max() + 1);

	//最初の増加ならカーソル位置を初期化
	if (m_cursor_int.max() == 1)
	{
		m_pos = m_menu[0].to_Point();
	}
}

// カーソルが停止しているかどうかを返す
bool Menu::cursor_stoped() const
{
	return m_framecnt <= 0;
}

// カーソルの位置を返す
// 座標ではないので注意
int Menu::position() const
{
	return m_cursor_int.value();
}

// キー入力を取る&カーソル位置を動かす
void Menu::update()
{
	//コマンド入力を受けとってカーソルを動かす処理
	update_input(m_cursor_int);

	//カーソル位置を動かす
	if (0 < m_framecnt)
	{
		m_pos -= m_cursorspd;
	}
	--m_framecnt;
	//update_cursor_drawpos( m_pos, m_menu[m_cursor_int.value()].to_Point());
}

// 描画処理をすべて呼び出す
void Menu::draw() const
{
	auto rect = m_fonthash.at(m_menu[m_cursor_int.value()].fontinfo)(m_menu[m_cursor_int.value()].str).region();
	rect.setPos(m_menu[m_cursor_int.value()].to_Point());
	draw_cursor(m_pos, rect);

	// 内部でさらにdraw_menustrを呼び出している
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
