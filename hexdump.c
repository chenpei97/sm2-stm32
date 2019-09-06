#include <stdio.h>
#include <string.h>

#define DEBUG(fmt,arg...) fprintf(stderr, fmt"\n", ##arg)
//#define DEBUG(fmt,arg...) debug_print(fmt"\n", ##arg)

void hexdump(const void *data, unsigned int len)
{
	char str[160], octet[10];
	unsigned int ofs, i, k;
	const unsigned char *buf = (const unsigned char *)data;
	const char *dimm = "+------------------------------------------------------------------------------+";

	DEBUG("%s", dimm);
	DEBUG("| Offset  : 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F   0123456789ABCDEF |");
	DEBUG("%s", dimm);

	for (ofs = 0; ofs < len; ofs += 16) {
		sprintf( str, "| %08x: ", ofs );

		for (i = 0; i < 16; i++) {
			if ((i + ofs) < len)
				sprintf( octet, "%02X ", buf[ofs + i] );
			else
				strcpy( octet, "   " );

			strcat( str, octet );
		}
		strcat( str, "  " );
		k = strlen( str );

		for (i = 0; i < 16; i++) {
			if ((i + ofs) < len)
				str[k++] = (0x20 <= (buf[ofs + i]) &&  (buf[ofs + i]) <= 0x7E) ? buf[ofs + i] : '.';
			else
				str[k++] = ' ';
		}

		str[k] = '\0';
		DEBUG("%s |", str);
	}

	DEBUG("%s", dimm);
}


