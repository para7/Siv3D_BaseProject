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

//���͂̕ύX�ɑΉ����₷�����邽�߂̓��͏������܂Ƃ߂�����
//�������u�Ԃ��Ƃ�
bool command_click(Command_list get_key_name);
//������Ă��邩���Ƃ�
int command_press(Command_list get_key_name);