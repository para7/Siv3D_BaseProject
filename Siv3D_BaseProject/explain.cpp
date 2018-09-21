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
	//決定キーを押せばもとの画面に戻る
	if (command_click(key_1))
	{
		changeScene(L"Title");
	}
}
void Explain::draw() const
{
	Window::BaseClientRect().draw(Palette::White);
	
	font(L"適当に作るだけならここに操作説明を書くといい感じ\n\n操作方法\n移動　カーソルキー　または　asdwキー\nkey_1(決定)　Zキー　Jキー　スペースキー\n\nデフォルトのコードでは以下のボタンにも対応しています\nkey_2   Xキー Kキー\nkey_3   C Lキー").draw(20, 20,Palette::Black);
	
	drawCenter(font,L"決定キーを押すと戻ります",440,Palette::Black);
}

Explain::Explain()
	: font(15)
{}