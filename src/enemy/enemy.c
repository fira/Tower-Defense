#include <stdbool.h>

#include "enemy.h"

Enemy* createEnemy(int x, int y, TypeEn* type) {
	Enemy* enemy = (Enemy*)malloc( sizeof(Enemy) );

	enemy->x = x;
	enemy->y = y;
	enemy->life = type->maxLife;
	enemy->speed = type->normalSpeed;
	enemy->type = type;
	enemy->isPoisoned = false;

	return enemy;
}