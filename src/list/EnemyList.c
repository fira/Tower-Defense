/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */


#include "EnemyList.h"



/**
 * \fn void moveEnemyList(List* list);
 * \brief Moves an List of enemy.
 * The function moves each enemy of a list.
 * 
 * \see moveEnemy
 * \param list A list of Enemy to move.
 */
void moveEnemyList(Map *map, List* list) {
	moveEnemy(map, list->item);
	while(list->nextList) {
		list = list->nextList;
		moveEnemy(map, list->item);
	}
}

/**
 * \fn Enemy* getEnemyFromList(Case *cell, List *list)
 * \brief get an enemy who is in a particular cell
 *
 * \param cell the cell where an enemy stand
 *	\param list a list of enemies
 */

Enemy* getEnemyFromList(Case *cell, List *list){
	while(list){
		Enemy *spotedEnemy = (Enemy*)list->item;	
		if(spotedEnemy->x == cell->xx && spotedEnemy->y == cell->yy){
			return spotedEnemy;
		}
		list = list->nextList;
	}
  return NULL;
}


/**
 * \fn void removeEnemyFromList(Enemy* enemy, List* list)
 * \brief Function which removes an enemy in a List.
 *
 * \param enemy The enemy to remove from the list.
 * \param list A list of enemy.
 */
void removeEnemyFromList(Enemy* enemy, List* list){
	List* previousList = list;
	// Search of item which contains the enemy
	while(list->item != enemy){
		if(list) { 
			// if the enemy is not in the list, we delete it
			removeEnemy(enemy);
			return;
		}
		previousList = list;
		list = list->nextList;
	}
	previousList->nextList = list->nextList;
	removeEnemy(enemy);
	if(previousList != list){
		free(list);
	}
}

