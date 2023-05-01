#include <stdio.h>
#include <time.h>
#include <utmp.h>

int main() {
    FILE *file;
    struct utmp currentRecord;

    file = fopen("/var/log/wtmp", "rb");
    fseek(file,0,SEEK_END);
    long int pos = ftell(file);
    FILE *note = fopen("timestamp/time.txt","w");
    pos -= sizeof(currentRecord);
    fseek(file,pos,SEEK_SET);
    if (file) {
        while (fread(&currentRecord, sizeof(currentRecord), 1, file) == 1) {   // fread function returns the number of elements that were successfully read .
                                                                                // Since we requested only 1 to be read, this condition must hold true 
            if (currentRecord.ut_type == USER_PROCESS) {
                time_t loginTime = currentRecord.ut_tv.tv_sec;
                fprintf(note, "%s",ctime(&loginTime)); 
                printf("Login time: %s", ctime(&loginTime));
            }
        }
        fclose(file);
        fclose(note);
    } else {
        printf("Failed to open /var/log/wtmp\n");
    }
    return 0;
}

