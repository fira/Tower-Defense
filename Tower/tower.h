	#include <stdio.h>
	#include "typeTo.h"

typedef struct {
	int x;
	int y;
	TypeTo type;
	int kills;
	int level;
	int damages;
	int range;
	int attSpeed;
	int sellPrice;
} Tower;

Tower *createTower(int x, int y, TypeTo type);
int get_price(int iniPrice);