//�t�@�C�������S�~�Ȃ̂͂킩���Ă��邯�ǈ��ՂɕύX�ł��Ȃ��c
#pragma once

#include <Siv3D.hpp>

bool myUpdate();

void setTime();
int32 getms();

//ScalableWindow�g������DrawCenter��������Ɠ��삵�Ȃ��Ȃ����̂ő�p
void drawCenter(const Font &, const String, int, const Color& = { 255,255,255 });

//void drawCenter(const Font &, const String&, int, const Color& = { 255,255,255 });
//void drawCenter(const Font &, const wchar_t*, int, const Color& = { 255,255,255 });
//wchar_t�Ɠ���ƂȂ񂩎��ʂ��ۂ�
