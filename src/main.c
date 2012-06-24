/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL.h>

#include "engine.h"

int main(int argc, char* argv[]) {
	/* Weird seeding technique made-in-nepta */
	int *seed = malloc(sizeof(int*));
	seed = seed;
	srand((long)*seed);
	free(seed);

	/* Get the relative path from executable to resources */
	int respath_length = strrchr(argv[0], '/') + 1 - argv[0];
	char *respath = calloc(respath_length + 10, 1);
	strncpy(respath, argv[0], respath_length);
	strncpy(respath+respath_length, "resources/", 10);
	
	SDL_Init(SDL_INIT_VIDEO);
	// FIXME Deficient by design? (cf. event/event.c)
	// Several instances of the Engine could not run because they all share the same event queue...
	SDL_SetEventFilter(eventFilter);
	/* Init the main display screen for our app */
	SDL_Surface *screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_ASYNCBLIT | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Tower Defense", NULL);
	
	/* Instantiate the game engine */
	Engine *game = createEngine(screen, respath);
}

