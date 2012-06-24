/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */
 
#ifndef __ENGINE_H__
#define __ENGINE_H__
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <SDL/SDL.h>

/* Chances are we'll need everything anyway... */
#include "map/map.h"
#include "enemy/enemy.h"
#include "tower/tower.h"
#include "utils/viewport.h"
#include "event/event.h"
#include "list/EnemyList.h"
#include "list/TowerList.h"
#include "list/MovementList.h"
#include "utils/menu.h"
#include "utils/button.h"
#include "enemy/action.h"
#include "tower/bullet.h"
#include "utils/message.h"

typedef struct {
	/* General */
	SDL_Surface *screen;			//!< Software screen on which to render
	char* respath;					//!< Path to the game resources
	
	/* Game state */
	List *enemies;					//!< List of the current in-game enemies
	List *towers;					//!< List of the current in-game towers
	List *bullets;					//!< List of in-game bullets (for rendering)

	/* Sub-objects */
	Viewport *viewport; 			//!< Main map display viewport
	Menu *menu; 					//!< Right sidebar menu
} Engine;

Engine *createEngine(SDL_Surface*, const char*);

void drawEnemy(Engine *engine, Enemy *enemy);
void drawEnemyList(Engine *engine, List* list);
void drawTower(Engine *engine, Tower *tower);
void drawTowerList(Engine *engine, List *list);
void drawBullet(Engine *engine, Bullet *bullet);

#endif
