/*
 dev: Fira and Nepta
 Copyright © 2012
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */

#ifndef __abstractList_H__
#define __abstractList_H__
#include <stdlib.h>

typedef struct List {
	void* item;
	struct List* nextList;
} List;

List* newList(void* item);
void pushList(List* list, void* item);

#endif /* __abstractList_H__ */

