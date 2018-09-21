#pragma once

enum Command_list
{
    key_up,
    key_down,
    key_left,
    key_right,
    key_1,
    key_2,
    key_3,
    command_list_num
};

//入力の変更に対応しやすくするための入力処理をまとめたもの
//おした瞬間をとる
bool command_click(Command_list get_key_name);
//おされているかをとる
int command_press(Command_list get_key_name);