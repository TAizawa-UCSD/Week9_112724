#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
  char command[256];
  while(1){
    printf(" -> ");
    fgets(command, sizeof(command), stdin);
    command[strlen(command) - 1] = 0;

    pid_t result = fork();
    //run the command in the child process, in the parent process...?
    if(result == 0){
      char* args[] = {command, NULL};
      execvp(command, args);
      
      printf("The command is: %s\n", command);
    } else {
      
    }
    
  }
}
