
#include <stdlib.h>
#include <stdio.h>
#include "path.h" //for finding the current absolute path
#include "shellread.h"
#include "parse.h"
#include "execute.h"
int main(int argc, char **argv)
{
 int status;
do{
  char* path=get_path();
  status=1;

  char* input_string=shell_read(path);

  int t=no_of_tokens(input_string);

  //printf("number of tokens : %d \n",t);
  char** tokenised_string_array=tokenise(input_string);
  status=cmd_execute(tokenised_string_array);

}while(status);
return 1;
}
