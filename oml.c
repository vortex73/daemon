#include <stdio.h>
#include <string.h>
#include <utmp.h>
#include <stdlib.h>
#include <time.h>
//void utmpprint(struct utmp *log);

int main() {

    int logsize = 10;
    FILE *file;
    struct utmp log[logsize];
        int i = 0;

    file = fopen("/var/log/wtmp", "rb");
    if (file) {
            fread(&log, sizeof(struct utmp), logsize, file);
            for(i = 0; i < logsize; i++) {
                time_t tim =  log[i].ut_tv.tv_sec;
                struct tm * timm = gmtime(&tim);
                char* logg = ctime(&timm);
                    //utmpprint(&log[i]);
      printf("%s\n",logg);

            }
    } else {
            return(0);
    }
    return(0);
}


//void utmpprint(struct utmp *log) {
//    printf("{ ut_type: %i, ut_pid: %i, ut_line: %s, ut_id: %s,ut_user: %s, ut_host:   %s, ut_exit: { e_termination: %i,e_exit: %i }, ut_session: %i, timeval: { tv_sec: %i, tv_usec: bleh},ut_addr_v6:  }\n\n", log->ut_type, log->ut_pid, log->ut_line,
//        log->ut_id, log->ut_user, log->ut_host, log->ut_exit.e_termination,
//        log->ut_exit.e_exit, log->ut_session, log->ut_tv.tv_sec
//        );
//}
