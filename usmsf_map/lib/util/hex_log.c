#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iXtypes.h>
#include <ua_log.h>


/* 
 * dumps size bytes of *data to stdout. Looks like:
 * [0000] 75 6E 6B 6E 6F 77 6E 20  30 FF 00 00 00 00 39 00 unknown 0.....9.
 * (in a single line of course)
 */
void _hex_str_dump(void *data, unsigned char *out, int size)
{
	unsigned char *p = data;
	unsigned char *o = out;
	unsigned char c;
	int n;
	char bytestr[4] = {0};
	char addrstr[10] = {0};
	char hexstr[ 16*3 + 5] = {0};
	char charstr[16*1 + 5] = {0};

	o += sprintf(o, "------------------------------------------------------------------------------\n");
	for(n=1;n<=(int)size/2;n++) {
#if 1 
		if (n%16 == 1) {
			/* store address for this line */
			snprintf(addrstr, sizeof(addrstr), "%.4lx", ((unsigned long int)p-(unsigned long int)data));
		}
#endif
		c = *p;
		if (isalnum(c) == 0) {
			c = '.';
		}

		/* store hex str (for left side) */
		snprintf(bytestr, sizeof(bytestr), "%02X ", *p);
		strncat(hexstr, bytestr, sizeof(hexstr)-strlen(hexstr)-1);

		/* store char str (for right side) */
		snprintf(bytestr, sizeof(bytestr), "%c", c);
		strncat(charstr, bytestr, sizeof(charstr)-strlen(charstr)-1);

		if(n%16 == 0) {
			/* line completed */
			o += sprintf(o, "[%4.4s]   %-50.50s  %s\n", addrstr, hexstr, charstr);
			hexstr[0] = 0;
			charstr[0] = 0;
		} else if(n%8 == 0) {
			/* half line: add whitespaces */
			strncat(hexstr, "  ", sizeof(hexstr)-strlen(hexstr)-1);
			strncat(charstr, " ", sizeof(charstr)-strlen(charstr)-1);
		}
		p++; /* next byte */
	}

	if (strlen(hexstr) > 0) {
		/* print rest of buffer if not empty */
		o += sprintf(o, "[%4.4s]   %-50.50s  %s\n", addrstr, hexstr, charstr);
	}
	o += sprintf(o, "------------------------------------------------------------------------------\n");
}

int MakeStrHexa(char *trg, unsigned char *s, int len, int *remain,
                int f_cols, int l_cols)
{
    int        i;
    int        n = 0;
    char       buf[1024], *ptr = buf;
	int		   m = 0;
 
    if(len < 1 || s == NULL)
        return IXERR;
 
    if(f_cols == 0 || l_cols == 0)
        return IXERR;
 
    if(len > 256)
        len = 256;
 
    memset(buf, 0, 1024);
 
    for(i = 0; i < len; i++)
    {
        if(i != 0 && i % l_cols == 0)
        {
            sprintf(ptr, "\n");            
            ptr += strlen(ptr);
        }
 
        if(i != 0 && (i+1) % f_cols == 0)
		{
            sprintf(ptr, "%02X    ", s[i]);
		}
        else
		{
            sprintf(ptr, "%02X ", s[i]);
		}
		
        n += strlen(ptr);
        ptr += strlen(ptr);
        if(n > 1020)
            break;
        *ptr = 0;
    }
 
    strncpy(trg, buf, n);
	trg[n]=0;
    *remain = i;
    return IXOK;
}
