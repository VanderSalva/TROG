#include <cstdlib>

#include "Game.h"

#include "Poof.h"
#include "BombPickup.h"
#include "Heart.h"

#include "Enemy.h"

bool Enemy::Is(std::string what)
{
	if(what == "ENEMY") return true;
	if(what == "SOLID") return true;
	return false;
}

void Enemy::Update()
{
	if(health <= 0)
	{
		Drop();
		alive = false;
	}
}

void Enemy::Die()
{
	Drop();
	alive = false;
	Entity *poof = new Poof(x + width / 2, y + height / 2);
	game.entitiesManager.Add(poof);
}

void Enemy::OnHit(int damage)
{
	health -= damage;
	if(health <= 0) Die();
}

void Enemy::OnHit(int hx, int hy, int hw, int hh, int damage)
{
	OnHit(damage);
	if(!alive) return;
	if(x - hx > 0)
	{
		if(y - hy > 0)
		{
			if(hx + hw - x < hy + hh - y) MoveSolid(hitJump, 0);
			else MoveSolid(0, hitJump);
		}
		else
		{
			if(hx + hw - x < y + height - hy) MoveSolid(hitJump, 0);
			else MoveSolid(0, -hitJump);
		}
	}
	else
	{
		if(y - hy > 0)
		{
			if(x + width - hx < hy + hh - y) MoveSolid(-hitJump, 0);
			else MoveSolid(0, hitJump);
		}
		else
		{
			if(x + width - hx < y + height - hy) MoveSolid(-hitJump, 0);
			else MoveSolid(0, -hitJump);
		}
	}
}

std::vector<Enemy::CreateDropFunction> Enemy::PossibleDrops()
{
	std::vector<CreateDropFunction> drops;
	drops.push_back(Heart::Create);
	if(game.inventoryManager.Find("Bomb") != 0) drops.push_back(BombPickup::Create);
	return drops;
}

void Enemy::Drop()
{
	std::vector<CreateDropFunction> drops = PossibleDrops();
	if(rand() % (noDropChance + 1) == 0)
	{
		Entity *drop = drops[rand() % drops.size()]();
		drop->x = x;
		drop->y = y;
		game.entitiesManager.Add(drop);
	}
}

Enemy::Enemy()
{
	hitJump = 60;
	noDropChance = 5;
}