/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011

 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
*/


#include "enemy.h"

/**
 * \fn Enemy* createEnemy(int x, int y, TypeEn* type)
 * \brief Function which creates an enemy.
 *
 * \param x Define the horizontal position of the enemy.
 * \param y Define the vertical position of the enemy.
 * \param type The type of the enemy.
 * \param target Where the enemy is going
 * \return The pointer on the enemy, in order to use it.
 */
Enemy* createEnemy(Map* map, int x, int y, TypeEn* type, Case *target) {
	Enemy* enemy = (Enemy*)malloc( sizeof(Enemy) );

	enemy->x = x;
	enemy->y = y;
	enemy->type = type;
	enemy->animation = createAnimation(type->picture);
	Case *anim_start = getCase(map, x,y);
	anim_start->hasEnemy = true;
	enemy->animPosition.x = anim_start->x;
	enemy->animPosition.y = anim_start->y;
	enemy->animPosition.h = anim_start->y;   
	enemy->animPosition.w = anim_start->x;
	enemy->life = type->maxLife;
	enemy->speed = type->normalSpeed;
	enemy->isPoisoned = false;
	enemy->list = NULL;
	
	/* If we didn't give a target to the enemy, he sits still */
	if(target) enemy->dest = target;
	else enemy->dest = anim_start;
	
	return enemy;
}

/**
 * \fn void updateEnemyAnim(Enemy* enemy)
 * \brief Update the enemy animation according to its intended position
 *
 * \param enemy Enemy to update
 */
void updateEnemyAnim(Enemy* enemy) {
	switch(enemy->animation.direction) {
		case RIGHT:
			enemy->animPosition.x++;
			break;
		case LEFT:
			enemy->animPosition.x--;
			break;
		case UP:
			enemy->animPosition.y--;
			break;
		case DOWN:
			enemy->animPosition.y++;
			break;
		default:
			break;
	}
	SDL_Rect animOffset = enemy->animPosition;
	animOffset.x += animOffset.w;
	animOffset.y += animOffset.h;
}

/**
 * \fn SDL_Rect* getRect(Animation *anim)
 * \brief 
 *
 * \param anim 
 */
SDL_Rect* getRect(Animation* anim) {
	SDL_Rect* frame = &anim->animation_state[anim->direction];
	frame->x += anim->currentFrame->w / 3;
	frame->x %= anim->currentFrame->w;
	return frame;
}

/**
 * \fn void moveEnemy(Enemy* enemy)
 * \brief Moves an enemy.
 * The function moves an enemy according to the nextMovement function.
 * 
 * \see nextMovement
 * \param enemy Enemy to move.
 */
void moveEnemy(Map* map, Enemy* enemy){
	SDL_Rect anim = enemy->animPosition;
	Case *nextCase = getCase(map, enemy->x, enemy->y);
	
	if(anim.x == nextCase->x && anim.y == nextCase->y){
		enemy->animation.direction = nextMovement(map, enemy);
		nextCase->hasEnemy--;
		int hasMove = true;
		switch(enemy->animation.direction){
			case RIGHT:
				enemy->x++;
				break;
			case LEFT:
				enemy->x--;
				break;
			case DOWN:
				enemy->y++;
				break;
			case UP:
				enemy->y--;
			default:
				hasMove = false;
				break;
		}
		if(hasMove){
			nextCase = getCase(map, enemy->x, enemy->y);
			nextCase->hasEnemy++;
		}
	}
}


/**
 * \fn Movement nextMovement(Enemy* enemy);
 * \brief Compute where the monster must go.
 * The function juste checks the free cells against the enemy
 * and chooses randomly one of them.
 * 
 * \param enemy An Enemy whithout a path.
 */
Movement nextMovement(Map *map, Enemy* enemy){
	int x = enemy->x;
	int y = enemy->y;
	
	Case *currentCase = getCase(map, x,y);

	if(currentCase->xx == enemy->dest->xx && currentCase->yy == enemy->dest->yy) {
		return STAY;
	}
	if(!enemy->list) {
		enemy->list = searchPath(map, *currentCase, *(enemy->dest));
		return STAY;
	}
	
	return getNextMovement(&enemy->list);
}


/**
 * \fn void removeEnemy(Enemy* enemy)
 * \brief Kills an enemy.
 * 
 * \param enemy The enemy to kill.
 */
void removeEnemy(Enemy* enemy) {
	free(enemy);
	enemy = NULL;
}
