#ifndef ITEM_H
#define ITEM_H

#include <allegro.h>

#include <string>

class Item
{
	public:
		bool equippable;
		int amount;
		BITMAP *icon;
		std::string name;
		
		virtual void OnUse()
		{
		}
		
		virtual void SetAmount(int a)
		{
			amount = a;
		}
};

#endif