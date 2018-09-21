//ファイル名がゴミなのはわかっているけど安易に変更できない…
#pragma once

#include <Siv3D.hpp>

bool myUpdate();

void setTime();
int32 getms();

//ScalableWindow使ったらDrawCenterがきちんと動作しなくなったので代用
void drawCenter(const Font &, const String, int, const Color& = { 255,255,255 });

//void drawCenter(const Font &, const String&, int, const Color& = { 255,255,255 });
//void drawCenter(const Font &, const wchar_t*, int, const Color& = { 255,255,255 });
//wchar_tと二つ作るとなんか死ぬっぽい
