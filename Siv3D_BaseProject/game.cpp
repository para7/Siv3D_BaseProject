#include "game.hpp"

void Game::init()
{

}

void Game::update()
{
    //����L�[�������΂��Ƃ̉�ʂɖ߂�
    if (command_click(key_1))
    {
        changeScene(L"Title");
    }
}

void Game::draw() const
{

}