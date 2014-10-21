#ifndef SPRITEENTITY_H
#define SPRITEENTITY_H

#include "Entity.h"

class SpriteEntity : public Entity
{
	public:
		BITMAP *sprite;
		int counter;
		int frame, nextFrame;
		int orientation;
		int frameStart, frameEnd, inverseSpeed;
		int spriteWidth, spriteHeight;
		int offsetX, offsetY;
		
		virtual void Draw(BITMAP *bmp);
		virtual void Update();
		
		void Orientate(float dx, float dy);
		
		SpriteEntity();
};

#endif