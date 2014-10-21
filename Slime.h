#ifndef SLIME_H
#define SLIME_H

#include "HitHurtEnemy.h"

class Slime : public HitHurtEnemy
{
	public:
		static BITMAP *_sprite;
		
		void SetParameter(std::string p, std::string v);
		void Die();
		void Update();
		
		Slime(int fh = 1);
		
		static Entity *Create();
	private:
		bool walking;
		int walkTime;
		int walkCounter;
		int agitation;
		float walkSpeed;
		float pathIntegral;
		int futureGenerations;
		int direction;
};

#endif