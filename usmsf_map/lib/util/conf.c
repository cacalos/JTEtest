
#include <stdio.h>

#include <iXtypes.h>
#include <ua_log.h>


int getConf(char *file, char *conf, char *data)
{
    FILE     *fp;
    char      buf[1024];
    char     *token, *last;

    if((fp = fopen(file, "r")) == NULL)
    {
        uaLog(L_CRT, "Can't open config file <%s>", file);
        return IXERR;
    }

    while(fgets(buf, 1024, fp) != NULL)
    {
        if(buf[0] == '#' || buf[0] == '\n')
            continue;

        token = (char *)strtok_r(buf, " =\t\n", &last);
        if(strcasecmp(token, conf) == 0)
        {
            token = (char *)strtok_r(NULL, " =\t\n", &last);
			if(token != NULL) {
				strcpy(data, token);
			} else {
				data[0] = '\0';
			}
            //strcpy(data, token);
            fclose(fp);
            return IXOK;
        }
    }

    fclose(fp);

    uaLog(L_CRT, "Can't find config variable '%s' in <%s>",
        conf, file);

    return IXERR;
}

