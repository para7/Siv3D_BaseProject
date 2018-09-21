#pragma once

#include <Siv3D.hpp>
#include <vector>
#include "cursor_uint.hpp"
#include <functional>
#include <tuple>
#include <unordered_map>
#include <map>

// title.cppで使ってるので使用例はそちらを
// 色々調整したかったらオーバーライドしてください
class Menu
{
private:
	using Fontinfo = std::tuple<int, String, FontStyle>;

	//メニューの各要素
	class menu_elem
	{
	public:
		const int x;
		const int y;
		const String str;
		// 色のハッシュ値
		const size_t hash_color;
		// フォントデータの抽出
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
	// 要素の配列
	std::vector<menu_elem> m_menu;

	// 描画用データのハッシュツリー
	// 色
	std::unordered_map<size_t, Color> m_colorhash;
	// フォント
	// キー値の算出がboost使わないときついのでmapにしてある
	std::map<Fontinfo, Font> m_fonthash;

	// カーソル位置
	Cursor_uint m_cursor_int;

	// カーソル座標
	Vec2 m_pos;

	// カーソル移動速度
	Vec2 m_cursorspd;

	//カーソル移動に必要なフレーム数
	int m_moveframe;

	// フレームカウンタ
	int m_framecnt;

	//メニュー全体の描画
	virtual void draw_menu() const final;

	// カーソルの描画座標を返す
	inline int pos_x() const { return static_cast<int>(m_pos.x); }
	inline int pos_y() const { return static_cast<int>(m_pos.y); }
	inline Point pos() const { return Point(m_pos.x, m_pos.y); }

	// コマンド入力を受け取ってカーソルを動かす処理
	virtual void update_input(Cursor_uint& cursor_pos);

	// カーソル移動速度のセット
	void setmovespeed();

	// カーソル位置の更新　
	// 挙動変えたいときはオーバーライドで
	// Vec2  : 描画が行われる座標
	// Point : カーソルの位置から計算される本来あるべき座標
	//virtual void update_cursor_drawpos(Vec2&,const Point&);

	// メニュー項目ひとつひとつの描画
	void Menu::draw_menustr(const Point& pos, const Font& font, const Color& color, const String& str) const;

	// カーソルの描画
	virtual void draw_cursor(const Vec2& pos, const Rect& region) const;

protected:
	//カーソルが乗ってる座標と有無を代入して戻す関数　返り値でやるとコピーの時間があれなので参照で書き変える
	bool onCursor(Rect& getregion);

public:

	// コンストラクタ
	// スピード指定しなければカーソルはワープする
	Menu();
	inline void set_moveflame(int frame) { m_moveframe = frame; }

	// デストラクタ(継承用virtual)
	virtual ~Menu() {}

	// メニュー要素の追加
	virtual void add(int _x, int _y, const String& _str, const Font& _font, const Color& _color) final;

	// カーソル座標が静止しているかどうかを返す
	bool cursor_stoped() const;

	// カーソルの位置を返す
	// 座標ではないので注意
	int position() const;

	// キー入力を取る&カーソル位置を動かす
	void update();

	// 描画処理すべてを呼び出す
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
