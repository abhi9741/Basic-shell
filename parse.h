#ifndef __PARSE_H

#define __PARSE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int no_of_tokens(char* command){ //function for finding out number of words just to cross check
 int n_tk =0;
 int i=0;
 while(1){
  if (command[i]==' '){
   n_tk++;
   if(command[i+1]==' '){
    break;
   }
  }
  i++;
 }
 return n_tk;
}

char** tokenise(char *line)
{
  int  pos = 0;
  char **tokens = malloc(74 * sizeof(char*));
  char *token;
  token = strtok(line, " \t\r\n\a");
  while (token != NULL) {
    tokens[pos] = token;
    pos++;
    token = strtok(NULL, " \t\r\n\a");
  }
  tokens[pos] = NULL;
  return tokens;
}
#endif
