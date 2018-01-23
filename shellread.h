#ifndef __SHELLREAD_H

#define __SHELLREAD_H
#include <stdlib.h>
#include <stdio.h>
#define GREEN   "\x1b[32m"
#define DEFAULT   "\x1b[0m"


char* shell_read(char* path)
{
  char* command;
  command=(char*)malloc((100)*1);
  int i=0;
  while(i<100){
   command[i]=' ';
   i++;
  }
  printf(GREEN "> %s :" DEFAULT,path);
  fgets(command, 100, stdin); //scanf("%s",&command);
  return command;
}
#endif
