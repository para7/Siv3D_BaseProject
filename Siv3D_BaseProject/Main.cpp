#include "Para7/Para7Utilities.hpp"
#include "game.hpp"
#include "title.hpp"
#include "explain.hpp"
#include "asset.hpp"

using namespace Para7;

void Main()
{
	//　起動時に表示されるアイコンを変える　http://siv3d.hateblo.jp/entry/adventcalendar2013/19

	/*
	アーカイブについて補足
	Dataのフォルダに必要な画像とか全部ぶち込んでから、ArchiveMaker.exeを起動するとData.s3aが更新される
	exe埋め込みするためにResource.rc に Data.s3a FILE "1001" と書いているので、L"/1001"がアーカイブデータへのパスになる
	common.hppでシーン管理のコモンデータとしてFileArchiveを持たせているので、シーンクラス内からなら
	m_data->arc.load(L"Data/ファイルのパス");
	のような形でデータを読み込めるようになっている
	使用例はtitle.cppのinit()にある
	*/

	//  ログ.htmlに出力される数を最小にする
	Logger::SetOutputLevel(OutputLevel::Less);

	//　ウィンドウタイトル
	Window::SetTitle(L"GameTitle");

	Window::Resize(Size(960, 720));

	//  背景色
	//  Graphics::SetBackground(Palette::Black);

	//  ScalableWindowのセット
	//  640*480の画面に描画する処理はそのままに、ウィンドウサイズを可変にできる
	ScalableWindow::Setup(640, 480);

	//アセット管理に登録するファイルの読み込みを一括して行う自作関数 アセット管理については https://github.com/Siv3D/Reference-JP/wiki/%E3%82%A2%E3%82%BB%E3%83%83%E3%83%88%E7%AE%A1%E7%90%86
	asset_registers();

	//アプリ内でカーソルを表示したい場合はDefaultとかを指定
	Cursor::SetStyle(CursorStyle::Default);

	//  シーン管理　宣言はscenectrl.hppを参照　
	Myapp mainscene;
    //  タイトル class Titleの宣言 : title.hpp
    mainscene.add<Title>(L"Title");
    //  ゲーム game.hpp
    mainscene.add<Game>(L"Game");
    //  操作説明画面 explain.hpp
    mainscene.add<Explain>(L"Explain");

	//MasterVoice::SetVolume(0.02);

	/*  別のシーンを追加する場合は、includeしてこのあたりでaddする  */

	//	Graphics2D::SetSamplerState(SamplerState::ClampLinear);
	//	Graphics2D::SetSamplerState(SamplerState::WrapPoint);

	Graphics::SetBackground(Palette::White);

	Common common;

	while (myUpdate())
	{
		{
			//Alt+Enterを押すことで、いつでも全画面とウィンドウを切り替えることができる
			if (Input::KeyAlt.pressed && Input::KeyEnter.clicked)
			{
				if (Window::IsFullSceen())//フルスクリーンなら
				{
					Window::SetFullscreen(false, { 640,480 });//ウィンドウに
					ScalableWindow::Setup(640, 480);
				}
				else//ウィンドウなら
				{
					Window::SetFullscreen(true, { 640 , 480 });//フルスクリーンに
				}
			}
			//  ScalableWindowのセット　
			const auto transformer = ScalableWindow::CreateTransformer();

			//  シーンごとの処理へ
			mainscene.updateAndDraw();
		}
		//  ScalableWindowで画面に隙間ができたところを黒で埋めるようにする
		ScalableWindow::DrawBlackBars(Palette::Black);
	}
}
