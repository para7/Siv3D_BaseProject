#include <Siv3D.hpp>
#include "command.hpp"

int timer = 0;
int keyinputer[command_list_num] = {};

//コマンド入力処理
//Xboxコントローラに対応させた
void command_update()
{
	auto Xcontroler = XInput(0);
	double stickborder = 0.6;
    if (   Input::KeyUp.pressed 
		|| Input::KeyW.pressed 
		|| Xcontroler.buttonUp.pressed
		|| Xcontroler.leftThumbY > stickborder)
    {
        keyinputer[key_up]++;
    }
    else
    {
        keyinputer[key_up] = 0;
    }

    if (Input::KeyDown.pressed 
		|| Input::KeyS.pressed
		|| Xcontroler.buttonDown.pressed
		|| Xcontroler.leftThumbY < -stickborder)
    {
        keyinputer[key_down]++;
    }
    else
    {
        keyinputer[key_down] = 0;
    }

    if (Input::KeyLeft.pressed 
		|| Input::KeyA.pressed
		|| Xcontroler.buttonLeft.pressed
		|| Xcontroler.leftThumbX < -stickborder)
    {
        keyinputer[key_left]++;
    }
    else
    {
        keyinputer[key_left] = 0;
    }

    if (Input::KeyRight.pressed 
		|| Input::KeyD.pressed
		|| Xcontroler.buttonRight.pressed
		|| Xcontroler.leftThumbX > stickborder)
    {
        keyinputer[key_right]++;
    }
    else
    {
        keyinputer[key_right] = 0;
    }
    
    if (Input::KeyZ.pressed 
		|| Input::KeyJ.pressed 
		|| Input::KeySpace.pressed 
		|| Input::KeyEnter.pressed
		|| Xcontroler.buttonA.pressed)
    {
        keyinputer[key_1]++;
    }
    else
    {
        keyinputer[key_1] = 0;
    }
    
    if (Input::KeyX.pressed 
		|| Input::KeyK.pressed
		|| Xcontroler.buttonB.pressed)
    {
        keyinputer[key_2]++;
    }
    else
    {
        keyinputer[key_2] = 0;
    }
	if (Input::KeyC.pressed || Input::KeyL.pressed)
	{
		keyinputer[key_3]++;
	}
	else
	{
		keyinputer[key_3] = 0;
	}

    timer = System::FrameCount();
}

bool command_click(Command_list get_key_name)
{
    if (command_list_num == get_key_name)
    {
        return false;
    }
	//フレームが変わってたら入力処理を取る
    if (timer != System::FrameCount())
    {
        command_update();
    }
    return keyinputer[get_key_name] == 1 ? true : false;
}
int command_press(Command_list get_key_name)
{
    if (command_list_num == get_key_name)
    {
        return 0;
    }
    if (timer != System::FrameCount())
    {
        command_update();
    }
    return keyinputer[get_key_name];
}