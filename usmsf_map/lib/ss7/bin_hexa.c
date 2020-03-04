
#include <stdio.h>
#include <ctype.h>

#include <iXtypes.h>
#include <ua_log.h>

int prn_bin(char c);

int get_hex_data(unsigned char *str)
{
    int            n = 0;
    int            c;
    int            sig = 0;
    unsigned char  byte;
    unsigned char  fourbit;

    while(1)
    {
        c = getchar();
        if(c == EOF)
            break;
        if(c == '#')
        {
            while(c != '\n')
                c = getchar();
        }

        if(!isalnum(c))
            continue;

        if(isdigit(c))
            fourbit = c - '0';
        else if(isalpha(c))
        {
            if(isupper(c))
                fourbit = c - 'A' + 10;
            else
                fourbit = c - 'a' + 10;
        }

        if(sig == 0)
        {
            byte = fourbit;
            byte <<= 4;    
            sig = 1;
        }
        else
        {
            byte += fourbit;
            sig = 0;
            str[n++] = byte;
        }
    }

    return n;            
}


/* make one-byte value from two chars which are in hexadecimal format */
int hex_to_byte(char c1, char c2)
{
    int            val = 0;

    if(isdigit(c1))
        val = c1 - '0';
    else if(isalpha(c1))
        val = toupper(c1) - 'A' + 10;
    val = val << 4;

    if(isdigit(c2))
        val += c2 - '0';
    else if(isalpha(c2))
        val += toupper(c2) - 'A' + 10;

    return val;
}


int prn_str_hex(unsigned char *s, int len)
{
    int             i;
    char            buf[1024], *ptr = buf;

    if(len < 1 || s == NULL)
        return IXERR;

    if(len > 256)
        len = 256;

    for(i = 0; i < len; i++)
    {
        if(i % 5 == 0)
            sprintf(ptr, "\t%02X", s[i]);
        else
            sprintf(ptr, " %02X", s[i]);

        ptr += strlen(ptr);
        *ptr = 0;
        if(i % 15 == 14)
        {
            uaLog(L_MAJ, "%s", buf);
            ptr = buf;
        }
    }

    if(i % 15 != 0)
        uaLog(L_MAJ, "%s", buf);

    return IXOK;
}


int prn_str_bin(unsigned char *str, int len)
{
    int         i;

    for(i = 0; i < len; i++)
    {
        prn_bin(*str++);
        putchar(' ');
    }
    putchar('\n');
    return IXOK;
}


int prn_bin(char c)
{
    int         i, bit;

    for(i = 0, bit = 1 << 7; i < 8; i++)
    {
        if(c & bit)
            putchar('1');
        else
            putchar('0');
        bit = bit >> 1;
    }
    return IXOK;
}


int prn_char(unsigned char *s, int len)
{
    int         i;

    for(i = 0; i < len; i++)
        uaLog(L_MAJ, "%02d ", *s++);

    uaLog(L_MAJ, "");
    return IXOK;
}


int prn_2char(unsigned short *s, int len)
{
    int         i;

    for(i = 0; i < len; i++)
        uaLog(L_MAJ, "%02d ", *s++);

    uaLog(L_MAJ, "");
    return IXOK;
}


int make_str_hex(unsigned char *trg, unsigned char *s, int len,
                 int f_cols, int l_cols)
{
    int        i;
    int        n = 0;
    char       buf[1024], *ptr = buf;

    if(len < 1 || s == NULL)
        return IXERR;

    if(f_cols == 0 || l_cols == 0)
        return IXERR;

    if(len > 256)
        len = 256;

    memset(buf, 0, 1024);

    for(i = 0; i < len; i++)
    {
        if(i % l_cols == 0)
        {
            sprintf(ptr, "\n");
            ptr += strlen(ptr);
        }

        if(i % f_cols == 0)
            sprintf(ptr, "\t%02X", s[i]);
        else
            sprintf(ptr, " %02X", s[i]);
        ptr += strlen(ptr);
        n += strlen(ptr);
        if(n > 1020)
            break;
        *ptr = 0;
    }

    strcpy(trg, buf);
    return IXOK;
}


int make_str_hex2(unsigned char *trg, unsigned char *s, int len,
                  int f_cols, int l_cols)
{
    int        i;
    int        n = 0;
    char       buf[1024], *ptr = buf;

    if(len < 1 || s == NULL)
        return IXERR;

    if(f_cols == 0 || l_cols == 0)
        return IXERR;

    if(len > 256)
        len = 256;

    memset(buf, 0, 1024);

    for(i = 0; i < len; i++)
    {
        if(i % l_cols == l_cols -1)
        {
            sprintf(ptr, "\n");
            ptr += strlen(ptr);
        }

        if(i % f_cols == f_cols -1)
            sprintf(ptr, "%02X\t", s[i]);
        else
            sprintf(ptr, "%02X ", s[i]);
        ptr += strlen(ptr);
        n += strlen(ptr);
        if(n > 1020)
            break;
        *ptr = 0;
    }

    strcpy(trg, buf);
    return IXOK;
}

