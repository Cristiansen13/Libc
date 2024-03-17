#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int puts(const char *s){
    int len = strlen(s);
    char *buff = malloc(len+1);
    strcpy(buff, s);
    buff[len] = '\n';
    int result =  write(1, buff, len+1);
    free(buff);
    if (result < 0) {
		errno = -result;
		return -1;
	}
	return result;
}
