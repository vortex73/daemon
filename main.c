#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <sys/inotify.h>
#include <signal.h>

int fd = -1;

int main(int argc, char *argv[])
{

    typedef struct inotify_event EVENT ;
    const EVENT*  watchevent;
    char* prompt;
    char* path = NULL;
    char* token = NULL;

    const uint32_t bitmask = IN_ACCESS | IN_CREATE | IN_CLOSE | IN_DELETE | IN_MODIFY | IN_MOVE_SELF;

    char buffer[4096];
    int readn;

    if (argc<2) {
        fprintf(stderr, "bleh: try, bleh PATH");
        exit(1);
    }
    path = malloc(sizeof(char)*(strlen(argv[1]))+1);
    strcpy(path, argv[1]);
    token =  strtok(path, "/");
    while (token!= NULL) {
        path = token;
        token = strtok(NULL, "/");
    } 
    
    fd = inotify_init();
    if (fd==1) {
        fprintf(stderr, "Error init-ing the instance");
        exit(2);
    }
    int watchman = inotify_add_watch(fd, argv[1], bitmask);
    if (watchman==-1) {
        fprintf(stderr, "Unable to add file to watchman");
        exit(3);
    }

    while (1) {
        printf("OOOOOOO");
        readn = read(fd, buffer, sizeof(buffer));
        if (readn==-1) {
            fprintf(stderr, "another error msg");
            exit(4);
        }
        for (char* ptr = buffer; ptr< buffer+ readn; ptr+=sizeof(EVENT)+watchevent->len) {
            prompt = NULL;
            watchevent = (const EVENT*) ptr;
            if (watchevent->mask & IN_ACCESS) {
                prompt = "File accessed";
            }
            if (watchevent->mask & IN_DELETE) {
                prompt = "File deleted";
            }
            if (watchevent->mask & IN_CLOSE) {
                prompt = "File closed";
            }
            if (watchevent->mask & IN_CREATE) {
                prompt = "File created";
            }
            if (watchevent->mask & IN_MODIFY) {
                prompt = "File modified";
            }
            if (watchevent->mask & IN_MOVE_SELF) {
                prompt = "File moved";
            }
            printf("%s\n", prompt);
        }
    }

    return EXIT_SUCCESS;
}
