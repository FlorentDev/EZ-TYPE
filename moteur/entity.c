#ifndef ENTITY_H
	#define ENTITY_H
	#include "entity.h"
#endif

#include <stdio.h>
#include "../GfxLib/GfxLib.h"

void moveUp(Hitbox* hitbox, Position* pos, Speed speed) {
	if(pos->y + hitbox->height < hauteurFenetre()) {
		pos->y += speed.speedY;
		hitbox->pos.y = pos->y;
	}
}

void moveDown(Hitbox* hitbox, Position* pos, Speed speed) {
	if(pos->y > 0) {
		pos->y -= speed.speedY;
		hitbox->pos.y = pos->y;
	}
}

void moveLeft(Hitbox* hitbox, Position* pos, Speed speed) {
	if(pos->x > 0) {
		pos->x -= speed.speedX;
		hitbox->pos.x = pos->x;
	}
}

void moveRight(Hitbox* hitbox, Position* pos, Speed speed) {
	if(pos->x < largeurFenetre()) {
		pos->x += speed.speedX;
		hitbox->pos.x = pos->x;
	}
}

//Return 1 if two hitboxes are colliding, 0 otherwise
int checkCollision(Hitbox hitbox1, Hitbox hitbox2) {
	if (hitbox1.pos.x < hitbox2.pos.x + hitbox2.width
		&& hitbox1.pos.x + hitbox1.width > hitbox2.pos.x
		&& hitbox1.pos.y < hitbox2.pos.y + hitbox2.height
		&& hitbox1.height + hitbox1.pos.y > hitbox2.pos.y) {
			return 1;
	}
	return 0;
}

// Return 1 if the hitbox is in the screen, false otherwise
int isOutOfScreen(Hitbox hitbox) {
	Hitbox widow;
	widow.pos.x = 0;
	widow.pos.y = 0;
	widow.width = largeurFenetre();
	widow.height = hauteurFenetre();	
	return checkCollision(widow, hitbox) == 0;
}
