#ifndef TYPETO
#define TYPETO

#include <stdio.h>

#include <SDL/SDL.h>

#include "typeBul.h"

typedef struct {
	int iniDamages;
	int iniRange;
	int iniAttSpeed;
	int price;
	int isSplash;
	int isSlower;
	int canAttackFlying;
	int canPoison;
	TypeBul typeBul;
	SDL_Surface* image;
} TypeTo;

TypeTo* createTypeTo(SDL_Surface* image, int iniDamages, int iniRange, int iniAttSpeed, int price, int isSplash, int isSlower, int canAttackFlying, int canPoison, TypeBul typeBul);

#endif