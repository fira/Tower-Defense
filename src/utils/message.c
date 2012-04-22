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
	blitToViewport(_viewport,renderText,NULL,&position);
  return renderText;
}
