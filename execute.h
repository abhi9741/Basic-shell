#ifndef __EXECUTE_H

#define __EXECUTE_H
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "launchprocess.h"

int cd(char **tokenised_input);
int help(char **tokenised_input);
int exits(char **tokenised_input);

char *explicit_funcs_str[] = {
  "cd",
  "help",
  "exit"
};

int (*explicit_funcs_func[]) (char **) = {&cd,&help,&exits};
int cd(char **tokenised_input)
{
  if (tokenised_input[1] == NULL) {
    fprintf(stderr, " expected argument to \"cd\" ,use ls for finding out files and directories in current directory :)\n");
  } else {
    if (chdir(tokenised_input[1]) != 0) {
      perror("shell");
    }
  }
  return 1;
}


int help(char **tokenised_input)
{
  int i;
  printf("this shell is developed by abhinav ,harsha,deepak,shwethamsh; @mahindra ecole centrale.\n");
  printf("The following are functions we wrote explicitly :\n");

  for (i = 0; i < 3; i++) {
    printf("  %s\n", explicit_funcs_str[i]);
  }

  printf(" use man COMMAND YOU WANT TO SEARCH for knowing details about other functions. \n");
  return 1;
}

int exits(char **tokenised_input)
{
  printf("\033[31m" "preparing to close terminal......... \n" "\x1b[0m");
  return 0;
}

int cmd_execute(char **tokenised_input)
{
  int i;

  if (tokenised_input[0] == NULL) {
    printf("\033[31m" " no input received :( \n" "\x1b[0m");
    return 1;
  }

  for (i = 0; i < 3; i++) {
    if (strcmp(tokenised_input[0], explicit_funcs_str[i]) == 0) {
      return (*explicit_funcs_func[i])(tokenised_input);
    }
  }

  return launchprocess(tokenised_input);
}
#endif
