#ifndef __PATH_H

#define __PATH_H
#include <unistd.h> 

char* get_path(){
    char *buf;
    buf=(char *)malloc(100*sizeof(char));
    getcwd(buf,100);
    return buf;
    }
    
#endif
