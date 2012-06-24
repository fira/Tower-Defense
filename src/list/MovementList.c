/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */


#include "MovementList.h"


/**
 * \fn MovementList* newMovementList(Movement firstMovement)
 * \brief Creates a new list and adds it's first Movement.
 *
 * \param firstMovement The first Movement of the list.
 * \return The first pointer of the list.
 */
MovementList* newMovementList(Movement firstMovement) {
	MovementList* newList = (MovementList*)malloc(sizeof *newList);
	newList->movement = firstMovement;
	newList->nextMovement = NULL;
	return newList; 
}


/**
 * \fn MovementList* headMovement(Movement movement, MovementList* list)
 * \brief Adds a movement in a list.
 * 
 * \param movement The movement to add.
 * \param list 
 */
MovementList* headMovement(Movement movement, MovementList* list) {
	MovementList* firstMovementList = newMovementList(movement);
	firstMovementList->nextMovement = list;
	return firstMovementList;
}

/**
 * \fn Movement getNextMovement(MovementList** list)
 * \brief Gets a Movement from a MovementList.
 * 
 * \param list The List of movement.
 * \return The next movement.
 */
Movement getNextMovement(MovementList** list) {
	MovementList* toFree = *list;
	Movement nextMovement = (*list)->movement;
	*list = (*list)->nextMovement;
	free(toFree);
	return nextMovement;
}

