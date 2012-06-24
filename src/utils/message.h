/*
 news dev: Nepta && Fira
 Copyright © 2012
 
 You should have received a copy of the
 GNU General Public License along with this program.
 If not, see  <http://www.gnu.org/licenses/>.
 */

#ifndef __message_H__
#define __message_H__

#include <stdio.h>
#include <SDL/SDL_ttf.h>
#include "../map/case.h"
#include "../enemy/enemy.h"
#include "../utils/viewport.h"


SDL_Surface* printIntTTF(Viewport* viewport, int number, Case cell, TTF_Font *font);
SDL_Surface* printHudTTF(SDL_Surface* screen, int message, TTF_Font *font);
SDL_Surface* printLifeTTF(Viewport* viewport, Enemy *enemy, TTF_Font *miniFont);

#endif /* __message_H__ */


