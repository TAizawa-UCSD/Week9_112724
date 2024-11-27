#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

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
      printf("Could not run the command: %s\n", command);
      exit(29);
    } else {
      printf("PID: %d\n", result);
      int status;
      //wait: returns when a child process finishes
      wait(&status);
      printf("The child process finished: %d\n", WEXITSTATUS(status));
    }
    
  }
}
