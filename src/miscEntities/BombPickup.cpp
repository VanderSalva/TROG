#include "BombPickup.h"
#include "Game.h"

BITMAP *BombPickup::_sprite = 0;

BombPickup::BombPickup()
{
	if(_sprite == 0) _sprite = (BITMAP *) game.GetData("spr_bombPickup"); // load_bitmap("bombPickup.bmp", 0);
	sprite = _sprite;
	width = 15;
	height = 15;
	offsetY = 3;
	spriteWidth = 15;
	spriteHeight = 18;
	item = "Bomb";
	amount = 3;
}