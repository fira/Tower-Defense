#include "message.h"

/**
 * \fn SDL_Surface* printIntTTF(int number, Case cell)
 * \brief print useful information in the map
 *
 * \param number the integer to print
 * \param cell the cell where information is printed
 * \return the Surface which must be freeed
 */
 
SDL_Surface* printIntTTF(int number, Case cell, TTF_Font *font){
	SDL_Color blackColor={0,0,0};
	char text[3];
	SDL_Rect position;
	position.x = cell.x;
	position.y = cell.y;
	snprintf(text,3,"%.2d",number);
	SDL_Surface *renderText = TTF_RenderUTF8_Solid(font, text, blackColor);
	blitToViewport(_viewport, renderText, NULL, &position);
  return renderText;
}

/**
 * \fn SDL_Surface* printHudTTF(int message, TTF_Font *font)
 * \brief print a message in the down right corner of the viewport
 *
 * \param message the message to printHudTTF
 * \return the Surface which must be freeed
 */
 
SDL_Surface* printHudTTF(int message, TTF_Font *font){
	SDL_Color blueColor={50,50,255};
	char text[3];
	SDL_Rect position;
	Case cell = *getCase(21,18);
	position.x = cell.x;
	position.y = cell.y;
	snprintf(text,3,"%.2d",message);	

	SDL_Surface *renderText = TTF_RenderUTF8_Solid(font, text, blueColor);
	SDL_BlitSurface(renderText, NULL, _viewport->screen, &position);
  return renderText;
}

/**
 * \fn SDL_Surface* printLifeTTF(int life, Enemy *enemy TTF_Font *miniFont)
 * \brief print some info about an Enemy
 *
 * \param life an info to display behind the enemy
 * \param enemy the enemy info must follow
 */
 
SDL_Surface* printLifeTTF(int life, Enemy *enemy, TTF_Font *miniFont){
	SDL_Color lifeColor={200,30,20};
	char text[3];
	SDL_Rect animOffset = enemy->animPosition;
	animOffset.x += animOffset.w;
	animOffset.y += animOffset.h;
	snprintf(text,3,"%.2d",life);

	SDL_Surface *renderText = TTF_RenderUTF8_Solid(miniFont, text, lifeColor);
	blitToViewport(_viewport, renderText, NULL, &animOffset);
  return renderText;
}
