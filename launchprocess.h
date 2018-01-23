#ifndef __LAUNCHPROCESS_H

#define __LAUNCHPROCESS_H
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int launchprocess(char **tokenised_input)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {

    if (execvp(tokenised_input[0], tokenised_input) == -1) {
      perror("console");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {

    perror("console");
  } else {

    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}
#endif
