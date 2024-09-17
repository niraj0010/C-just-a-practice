#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

void myclear() {
    system("clear");
}

void mydir(char *directory) {
    char command[256];
    if (directory == NULL) {
        snprintf(command, sizeof(command), "ls -al");
    } else {
        snprintf(command, sizeof(command), "ls -al %s", directory);
    }
    system(command);
}

void myenviron() {
    for (char **env = environ; *env != 0; env++) {
        printf("%s\n", *env);
    }
}

int main() {
    char input[256];

    while (1) {
        printf("P2$ ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Remove the newline character from the input
        input[strcspn(input, "\n")] = 0;

        // Tokenize the input
        char *command = strtok(input, " ");
        char *argument = strtok(NULL, " ");

        if (strcmp(command, "myclear") == 0) {
            myclear();
        } else if (strcmp(command, "mydir") == 0) {
            mydir(argument);
        } else if (strcmp(command, "myenviron") == 0) {
            myenviron();
        } else if (strcmp(command, "myquit") == 0) {
            break;
        } else {
            system(input);
        }
    }

    return 0;
}

