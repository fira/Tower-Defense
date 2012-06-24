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
 * \brief create a new bullet
 * only tower must be able to create it's own bullet, and only when it target an enemy
 * \param typeBul the type of the bullet
 * \param target an enemy to hit
 */

Bullet* createBullet(TypeBul *typeBul, Enemy *target){
	Bullet *bullet;
	bullet = malloc(sizeof (Bullet));
	bullet->type = typeBul;
	bullet->target = target;
  return bullet;
}

/**
 * \fn void animateBullet(Bullet *bullet)
 * \brief move the bullet to an enemy and draw it
 *	VERY Deprecated, recode your own function!
 * \param bullet the bullet to animate
 */ 
 
void animateBullet(Bullet *bullet){
/*	if(!(bullet->position->xx == bullet->position->x && bullet->position->yy == bullet->position->y)){*/
		/* OR DONT. drawBullet(bullet); */
/*	}*/
}

/**
 * \fn int damageEnemy(int damages, Enemy *enemy)
 * \brief do damages to an enemyFont
 *
 * \param damages damages an enemy must take
 * \param enemy an enemy to reduce life
 * \return return a zero value if enemy have no life left
 */
 
int damageEnemy(int damages, Enemy *enemy){
	enemy->life -= damages;
  return enemy->life > 0;
}

