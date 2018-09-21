#include "usefuls.hpp"

void drawCenter(const Font &font, const String str, int y, const Color &color)
{
	font(str).drawAt(Window::BaseCenter().x, y, color);
}

static int timer = 0;
static int beforetime = 0;
static Stopwatch watch;
bool start = true;

void setTime()
{
	if (start)
	{
		watch.start();
		start = false;
	}
	timer = watch.ms() - beforetime;

	beforetime = watch.ms();
}

int32 getms()
{
	return timer;
}


bool myUpdate()
{
	setTime();
	
	return System::Update();
}



/*
void drawCenter(const Font &font, const wchar_t *str, int y, const Color &color)
{
	font(str).drawAt(Window::BaseCenter().x, y, color);
}

void drawCenter(const Font &font, const String& str, int y, const Color &color)
{
    font(str).drawAt(Window::BaseCenter().x, y, color);
}
*/