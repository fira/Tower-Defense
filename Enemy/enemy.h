#ifndef ENNEMY_H
#define ENNEMY_H

#include <stdio.h>

#include "typeEn.h"

typedef struct {
	int x;
	int y;
	int life;
	int speed;
	int isPoisoned;
	TypeEn* type;
} Enemy;

Enemy* createEnemy(int x, int y, TypeEn* type);

#endif
