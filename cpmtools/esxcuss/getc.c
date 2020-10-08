/* libcuss © 2020 David Given
 * This library is distributable under the terms of the 2-clause BSD license.
 * See COPYING.cpmish in the distribution root directory for more information.
 */

#include <input.h>
#include "libcuss.h"

static uint8_t last_key = 0;
static uint8_t next_key = 0;
uint8_t con_getc(void)
{
    // Stop holding the previous key
    while(next_key==last_key) {
        next_key = in_inkey();
    }

    // Now wait for a new key
    while(!next_key) {
        next_key = in_inkey();
    }

    // Remember they key so we don't repeat it
    last_key = next_key;

	return next_key;
}


