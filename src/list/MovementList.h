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
#include "../enemy/typeEn.h"

typedef struct MovementList {
	Movement movement;
	struct MovementList* nextMovement;
} MovementList;


MovementList* newMovementList(Movement firstMovement);
MovementList* headMovement(Movement movement, MovementList* list);
Movement getNextMovement(MovementList** list);

#endif
