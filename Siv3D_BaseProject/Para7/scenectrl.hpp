#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "common.hpp"

using Myapp = SceneManager < String, Common >;

//シーンマネージャーを使うときは、このMySceneBaseを継承すると
//ScalableWindow()を使用した際に暗転がうまく動作しない不具合を回避できる
//または、Myapp::Sceneを継承し、個別にdrawFadeIn(double)とdrawFadeOut(double)をそれぞれオーバーライドしてもいい
//Siv3Dの開発者さんいわく、OpenSiv3Dでは改善する予定らしいので、今後の情報に期待しよう！
class MySceneBase : public SceneManager < String, Common >::Scene
{
public:
	virtual void main() {};
	virtual void draw() const {};
	virtual void init() {};

	// ScalableWindowで規定以下の画面サイズにすると暗転範囲がバグるので
	// それを防ぐためフェードイン/アウトをオーバーライド
	void drawFadeIn(double t) const override
	{
		draw();
		s3d::Transformer2D tr(Graphics2D::GetTransform().inverse());
		s3d::Window::ClientRect().draw(ColorF(0.0).setAlpha(1.0 - t));
	}
	void drawFadeOut(double t) const override
	{
		draw();
		s3d::Transformer2D tr(Graphics2D::GetTransform().inverse());
		s3d::Window::ClientRect().draw(ColorF(0.0).setAlpha(t));
	}
};