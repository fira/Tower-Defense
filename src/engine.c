/*
 FIXME
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */

#include "engine.h"

/* Starts the game engine on a given SDL Surface, that should have been
initialized beforehand. It also requires the path to the game resources.  */
Engine *createEngine(SDL_Surface *screen, const char* respath) { return NULL; }
void updateEngine(Engine *engine) {}

// FIXME
const char *getPath(char *file) { return NULL; }



/* Drawing functions */
	 
void drawEnemy(Engine *engine, Enemy *enemy) {
	updateEnemyAnim(enemy);
	blitToViewport(engine->viewport, enemy->animation.currentFrame, getRect(&enemy->animation), &(enemy->animPosition));
}

/**
 * \fn void drawTowerList(List* list)
 * \brief Draws an List of tower.
 * The function draws each tower of a list.
 * 
 * \see drawTower
 * \param list A list of Tower to draw.
 */
void drawTowerList(Engine *engine, List* list) {
	drawTower(engine, list->item);
	while(list->nextList) {
		list = list->nextList;
		drawTower(engine, list->item);
	}
}

/**
 * \fn void drawBullet(Bullet *bullet)
 * \brief draw a bullet
 *
 * \param bullet a bullet to draw
 */
 
void drawBullet(Engine *engine, Bullet *bullet){
	SDL_Rect position;
	position.x = bullet->target->animPosition.x; //=xx
	position.y = bullet->target->animPosition.y; //=yy
	position.x += bullet->target->animPosition.w; //anim offset
	position.y += bullet->target->animPosition.h + 7; //anim offset + a little to hit the body
	blitToViewport(engine->viewport, bullet->type->image, NULL, &position);
}

/**
 * \fn void drawTower(Tower* tower)
 * \brief Draws a tower in the map.
 * 
 * \param tower A tower to draw.
 */
void drawTower(Engine *engine, Tower* tower) {
	SDL_Rect position;
	Case* cell = getCase(engine->viewport->map, tower->x, tower->y);
	position.x = cell->x;
	position.y = cell->y;
	cell->hasTower = true;
	blitToViewport(engine->viewport, tower->type->image, NULL, &position);
}

/**
 * \fn void drawEnemyList(List* list)
 * \brief Draws an List of enemy.
 * The function draws each enemy of a list.
 * 
 * \see drawEnemy
 * \param list A list of Enemy to draw.
 */
void drawEnemyList(Engine *engine, List* list) {
	drawEnemy(engine, list->item);
	while(list->nextList) {
		list = list->nextList;
		drawEnemy(engine, list->item);
	}
}
