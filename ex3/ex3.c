// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // Your code here
    int ret = fork();
    int status;

    if(ret < 0) {
        perror("fork");
        exit(1);
    } else if (ret == 0) {
        printf("Hello!\n");
    } else {
        while (waitpid (ret, &status, WNOHANG) == 0) {
            sleep(1);
        }
        printf("Goodbye!\n");
    }
    return 0;
}
