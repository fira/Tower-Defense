/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/

#include "bullet.h"
/**
 * \fn Bullet* createBullet(Tower *tower)
 * \brief create a new bullet
 * only tower must be able to create it's own bullet, and only when it target an enemy
 * \param tower the tower the bullet belong to
 */

Bullet* createBullet(Tower *tower){
	Bullet *bullet;
	if(tower->target){
		bullet = malloc(sizeof (Bullet));
		bullet->type = tower->type->typeBul;
		bullet->target = tower->target;
	}else{
		bullet = NULL;
	}
  return bullet;
}

/**
 * \fn void drawBullet(Bullet *bullet)
 * \brief draw a bullet
 *
 * \param bullet a bullet to draw
 */
 
void drawBullet(Bullet *bullet){
	SDL_Rect position;
	position.x = bullet->target->x; //=xx
	position.y = bullet->target->y; //=yy
	blitToViewport(_viewport, bullet->type->image, NULL, &position);
}

/**
 * \fn void animateBullet(Bullet *bullet)
 * \brief move the bullet to an enemy and draw it
 *	Depreciated, recode your own function!
 * \param bullet the bullet to animate
 */
 
void animateBullet(Bullet *bullet){
/*	if(!(bullet->position->xx == bullet->position->x && bullet->position->yy == bullet->position->y)){*/
		drawBullet(bullet);
/*	}*/
}

