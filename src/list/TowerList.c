/*
 dev: Mickeymouse, Moutarde and Nepta
 manager: Word
 Copyright © 2011
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */


#include "TowerList.h"
/**
 * \fn void drawTowerList(List* list)
 * \brief Draws an List of tower.
 * The function draws each tower of a list.
 * 
 * \see drawTower
 * \param list A list of Tower to draw.
 */
void drawTowerList(List* list) {
	drawTower(list->item);
	while(list->nextList) {
		list = list->nextList;
		drawTower(list->item);
	}
}

