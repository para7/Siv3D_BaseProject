#include "game.hpp"

void Game::init()
{

}

void Game::update()
{
    //決定キーを押せばもとの画面に戻る
    if (command_click(key_1))
    {
        changeScene(L"Title");
    }
}

void Game::draw() const
{

}