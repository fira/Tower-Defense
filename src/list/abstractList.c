/*
 dev: Fira and Nepta
 Copyright © 2012
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */


#include "abstractList.h"

/**
 * \fn List* newList(void* item)
 * \brief Creates a new generic list and adds it's first enemy.
 *
 * \param item The first item of the list.
 * \return The first pointer of the list.
 */
List* newList(void* item) {
	List* newList = malloc(sizeof *newList);
	newList->item = item;
	newList->nextList = NULL;
	return newList; 
}
 
/**
 * \fn void pushList(List* list, void* item)
 * \brief Function which adds an enemy at the end of a List.
 *
 * \param list A generic list.
 * \param item The item to add in the list.
 */
void pushList(List* list, void* item) {
	while(list->nextList != NULL) {
		list = list->nextList;
	}
	list->nextList = (List*)malloc(sizeof *list);
	list->nextList->item = item;
	list->nextList->nextList = NULL;
}

