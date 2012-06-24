/*
dev: Mickeymouse, Moutarde and Nepta
manager: Word
Copyright © 2011
You should have received a copy of the
GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.
*/

#include "viewport.h"

/**
 * \fn Viewport* createViewport(SDL_Rect suface, Map* map)
 * \brief Creates a viewport.
 *
 * \param suface The surface where to draw the viewport
 * \param map The map element that will be displayed by the viewport
 * \return The array on the viewport, in order to use it.
 */
Viewport* createViewport(SDL_Surface* screen, SDL_Rect surface, Map* map) {
	// Allocates space 
	Viewport* viewport = (Viewport*)malloc( sizeof(Viewport) );
	
	// Initializes the displayed map surface to 0,0 and with specified size
	// FIXME This might later need to be passed as parameters
	viewport->mapsurface.x = 0;
	viewport->mapsurface.y = 0;
	viewport->mapsurface.w = surface.w;
	viewport->mapsurface.h = surface.h;

	// Initialize the viewport's screen position to given surface
	// FIXME Doesnt actually work (the offset is not taking into consideration yet, it'll always be drawn in 0,0)
	viewport->screensurface = surface;

	// Map and screen the viewport is directly tied to
	viewport->map = map;
	viewport->screen = screen;

	viewport->completeredraw = 1;
	
	return viewport;
}

/**
 * \fn void redrawViewport(Viewport* viewport)
 * \brief Draws the map to the screen.
 *
 * \param viewport Viewport to draw on the screen
 */
void redrawViewport(Viewport* viewport) {
	// FIXME Need a system to manage SetClipRect
	// Right now, this prevents updating the menu !
	SDL_SetClipRect(viewport->screen, &viewport->screensurface);

	SDL_BlitSurface(viewport->map->bg, &(viewport->mapsurface), viewport->screen, NULL);
}


/**
 * \fn void updateViewport(Viewport* viewport)
 * \brief Reverts viewport contents to a blank one
 * \brief This is done by re-blitting map portions onto previously blitted items,
 * \brief and is SIGNIFICANTLY faster than redrawing the whole map
 *
 * \param viewport The viewport to clear
 */
void updateViewport(Viewport *viewport) {
	SDL_Rect target;
		
	/* If something like scrolling happened to the background, we have to re-draw
	the viewport contents completely instead of updating it */	
	if(viewport->completeredraw) {
		redrawViewport(viewport);
		viewport->completeredraw = 0;	
	} else {
		// FIXME CRITICAL To be implemented
	}
}

/**
 * \brief Blit the specified image to destination, on the viewport
 *
 * \param viewport The viewport element to draw on
 * \param src_sprite Surface to draw
 * \param relsrc Rectangle of the source sprite to draw
 * \param reldest Map relative rectangle where to draw the sprite (will be modified)
 */
 void blitToViewport(Viewport *viewport, SDL_Surface* src_sprite, SDL_Rect* relsrc, SDL_Rect* reldest) {
	// Shift the destination from map relative coordinates to screen displayed ones	
	reldest->x -= viewport->mapsurface.x;
	reldest->y -= viewport->mapsurface.y;
	
	// Blit the image onto specified position
	SDL_BlitSurface(src_sprite, relsrc, viewport->screen, reldest);
}


/**
 * \brief Moves the viewports viewing coordinates
 *
 * \param viewport The viewport to move
 * \param direction Which direction to move (ENUM element)
 */
void moveViewport(Viewport* viewport, short direction) {
	// FIXME Offsets and stuff should be parameters / contants
	// Idea: why not simply pass the X/Y offset to the function ?
	// The game will also need a viewport panning function
	switch(direction) {
		case VP_UP:
			viewport->mapsurface.y -= 5;
			if (viewport->mapsurface.y < 0) {
				viewport->mapsurface.y = 0;
			}
			viewport->completeredraw = 1;
		break;

		case VP_DOWN:
			viewport->mapsurface.y += 5;
			if (viewport->mapsurface.y > viewport->map->h - viewport->mapsurface.h) {
				viewport->mapsurface.y = viewport->map->h - viewport->mapsurface.h;
			}
			viewport->completeredraw = 1;
		break;

		case VP_LEFT:
			viewport->mapsurface.x -= 5;
			if (viewport->mapsurface.x < 0) {
				viewport->mapsurface.x = 0;
			}
			viewport->completeredraw = 1;
		break;

		case VP_RIGHT:
			viewport->mapsurface.x += 5;
			if (viewport->mapsurface.x > viewport->map->w - viewport->mapsurface.w) {
				viewport->mapsurface.x = viewport->map->w - viewport->mapsurface.w;
			}
			viewport->completeredraw = 1;
		break;
	}
}


