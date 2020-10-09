/* libcuss © 2019 David Given
 * This library is distributable under the terms of the 2-clause BSD license.
 * See COPYING.cpmish in the distribution root directory for more information.
 */

#include "libcuss.h"
#include "textmode.h"

void con_clear_to_eol(void)
{
    if (screeny >= SCREENHEIGHT)
            return;

    uint16_t i = SCREENWIDTH - screenx;
    if ((i != 0) && (screeny == (SCREENHEIGHT-1)))
        i--;

    while (i--) {
        tilemap[screeny][screenx].tile = ' ';
//        tilemap[screeny][screenx].flags = TEXTMODE_DEFAULT_COLOUR;
    }

    con_goto(screenx, screeny);

}

