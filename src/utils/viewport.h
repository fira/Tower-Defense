/*
dev: Mickeymouse, Moutarde and Nepta
manager: Word
Copyright © 2011

You should have received a copy of the
GNU General Public License along with this program.
If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef VIEWPORT
#define VIEWPORT

#define VP_UP 0
#define VP_RIGHT 1
#define VP_DOWN 2
#define VP_LEFT 3

#include <SDL/SDL.h>
#include "../map/map.h"

/**
 *	\struct Viewport
 * \brief The displayed screen
 */
typedef struct {
	SDL_Rect screensurface;		//!< Screen surface is where the viewport is displayed
	SDL_Rect mapsurface;		//!< Map surface is the part of the map the viewport displays

	Map* map;					//!< The map displayed by the viewport
	SDL_Surface* screen;		//!< Screen the viewport will be rendered on
	
	int completeredraw;			//!< Indicates the viewport's background should be redrawn completely on next frame
} Viewport;

void drawViewport(Viewport* viewport);
Viewport* createViewport(SDL_Surface* screen, SDL_Rect surface, Map* map);
void moveViewport(Viewport* viewport, short direction);
void blitToViewport(Viewport* viewport, SDL_Surface* src, SDL_Rect* src_rect, SDL_Rect* dest);
void cleanViewport(Viewport *viewport);

#endif
