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
	/*  アーカイブでまとめたファイルのロード処理例  */
	//titlebgm = Sound(m_data->arc.load(L"Data/Sound/bgm.mp3"));
	
	//　メニュー項目の追加
	//  X座標、Y座標、メニューの文字、フォントデータ、描画色
	// カーソル移動にかかるフレーム数をセット
	menus.set_moveflame(8);

	const Font font{ 20 };
	menus.add(200, 200, L"ゲームスタート",font,Palette::Black);
	menus.add(220, 270, L"あそびかた",font,Palette::Black);
	menus.add(240, 340, L"おしまい",font,Palette::Darkgray);
	// もしハイスコアなどをタイトルメニューに追加したかったら、
	// こんな感じで要素追加してやれば自動的にループするメニュー画面っぽいのが出来上がる
	// 要素を消す関数は今のところ用意する予定はない
}

void Title::update()
{
	//command_click,command_pressはコマンド処理の統一関数
	//詳しい実装や、対応する操作を変えたいときはcommand.hpp
	//これを使う利点はキー操作変えたりときにcommand.cpp内の処理を変えれば全箇所に変更できるのと
	//WASDと十字キーでの移動を両立したりできること

	//カーソルが移動中は決定ボタンが効かないようにするためにstoped()で停止しているかチェック
	if (command_click(key_1) && menus.cursor_stoped())
	{
		if(menus.cursor_stoped())
		//メニュー決定時に効果音を鳴らしたければこのへんで鳴らす
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
			//init()でメニュー要素を追加していたらここを増やす
		}
	}
	//色々更新する　実装はmenu.hpp
	menus.update();
}

void Title::draw() const
{
	//背景を描画
	//背景色そのものを変えちゃうと不意のシーン変更などで背景色が変更され損ねたりするかもしれないので、その場その場で描画している
	//背景色変えたほうが処理が軽いとは思う
	Window::BaseClientRect().draw(Palette::White);

	//メニュー項目の描画
	menus.draw();
	
	//座標バグ修正関数drawCenterの使用例
	drawCenter(titlefont, L"ゲーム", 60, Palette::Black);
    
    const String Creatername{L"Created by : hogehoge"};
	explfont(Creatername).draw(30, Window::BaseHeight() - explfont(Creatername).region().h, Palette::Gray);
}
