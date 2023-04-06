#include <stdio.h>
#include <time.h>
#include <utmp.h>

int main() {
    FILE *file;
    struct utmp currentRecord;

    file = fopen("/var/log/wtmp", "rb");
    if (file) {
        while (fread(&currentRecord, sizeof(currentRecord), 1, file) == 1) {
            if (currentRecord.ut_type == USER_PROCESS) {
                time_t loginTime = currentRecord.ut_tv.tv_sec;
                printf("Login time: %s", ctime(&loginTime));
            }
        }
        fclose(file);
    } else {
        printf("Failed to open /var/log/wtmp\n");
    }
    return 0;
}

