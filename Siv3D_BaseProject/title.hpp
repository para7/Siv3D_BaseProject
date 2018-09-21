#pragma once

#include "Para7//Para7Utilities.hpp"

class Title : public MySceneBase
{
private:
	// const付けてコンストラクタで初期化しようとすると、読み込みタイミングが悪かったのかエラー出すことがあったので
	// その場合はconstを外してinit()関数内で代入すればなんとかなる
	// ただし、最適化の関係でconstを付けた方が動作は早いはずだし、初期値設定忘れもなくなるのでできるだけconstつけるようにしたいところ
	const Font titlefont, explfont;
	// メニュー画面の簡単な構築 宣言：menu.hpp
	Menu menus;
public:
	Title();
	void init() override;
	void draw() const override;
	void update() override;
};