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

//“ü—Í‚Ì•ÏX‚É‘Î‰‚µ‚â‚·‚­‚·‚é‚½‚ß‚Ì“ü—Íˆ—‚ğ‚Ü‚Æ‚ß‚½‚à‚Ì
//‚¨‚µ‚½uŠÔ‚ğ‚Æ‚é
bool command_click(Command_list get_key_name);
//‚¨‚³‚ê‚Ä‚¢‚é‚©‚ğ‚Æ‚é
int command_press(Command_list get_key_name);