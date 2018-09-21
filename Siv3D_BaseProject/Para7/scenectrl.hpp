#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "common.hpp"

using Myapp = SceneManager < String, Common >;

//�V�[���}�l�[�W���[���g���Ƃ��́A����MySceneBase���p�������
//ScalableWindow()���g�p�����ۂɈÓ]�����܂����삵�Ȃ��s�������ł���
//�܂��́AMyapp::Scene���p�����A�ʂ�drawFadeIn(double)��drawFadeOut(double)�����ꂼ��I�[�o�[���C�h���Ă�����
//Siv3D�̊J���҂��񂢂킭�AOpenSiv3D�ł͉��P����\��炵���̂ŁA����̏��Ɋ��҂��悤�I
class MySceneBase : public SceneManager < String, Common >::Scene
{
public:
	virtual void main() {};
	virtual void draw() const {};
	virtual void init() {};

	// ScalableWindow�ŋK��ȉ��̉�ʃT�C�Y�ɂ���ƈÓ]�͈͂��o�O��̂�
	// �����h�����߃t�F�[�h�C��/�A�E�g���I�[�o�[���C�h
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