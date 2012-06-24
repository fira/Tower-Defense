/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */

#ifndef LIST
#define LIST

#include "abstractList.h"
#include "../enemy/enemy.h"

void moveEnemyList(List* list);
void drawEnemyList(List* list);
void removeEnemyFromList(Enemy* enemy, List* list);

#endif
