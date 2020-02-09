#include "class.player.hpp"
float Player::balance ()
{
     // cout << name << " Money: " << balance << endl;
     return money;
};

void Player::deposit (float num)
{
     money += num;
}

Player::Player()
{
     money = 0;
     //name = "Player";
}

