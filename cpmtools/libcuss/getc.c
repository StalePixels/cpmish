/* libcuss © 2020 David Given
 * This library is distributable under the terms of the 2-clause BSD license.
 * See COPYING.cpmish in the distribution root directory for more information.
 */

#include <cpm.h>
#include "libcuss.h"

#if defined LIBCUSS_ANSI
static uint8_t pending;

static uint8_t read_byte(void)
{
	uint8_t c = pending;
	if (c)
	{
		pending = 0;
		return c;
	}
	return cpm_bios_conin();
}

uint8_t con_getc(void)
{
	uint8_t c = read_byte();
	if ((c != 27) || !cpm_bios_const())
		return c;

	c = cpm_bios_conin();
	if ((c != '[') && (c != 'O'))
	{
		pending = c;
		return 27;
	}

	switch (cpm_bios_conin())
	{
		case 'A': return LIBCUSS_KEY_UP[0];
		case 'B': return LIBCUSS_KEY_DOWN[0];
		case 'C': return LIBCUSS_KEY_RIGHT[0];
		case 'D': return LIBCUSS_KEY_LEFT[0];
	}
	return 27;
}
#else
uint8_t con_getc(void)
{
	return cpm_bios_conin();
}
#endif
