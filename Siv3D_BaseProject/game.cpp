#include "game.hpp"

void Game::init()
{

}

void Game::update()
{
    //Œˆ’èƒL[‚ğ‰Ÿ‚¹‚Î‚à‚Æ‚Ì‰æ–Ê‚É–ß‚é
    if (command_click(key_1))
    {
        changeScene(L"Title");
    }
}

void Game::draw() const
{

}