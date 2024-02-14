#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} Record;

int dateEquals(const Record* record, const char* searchDate) {
    char recordDate[11];
    sprintf(recordDate, "%.2d.%.2d.%.4d", record->day, record->month, record->year);
    return strcmp(searchDate, recordDate) == 0;
}

int searchByDate(const char* filePath, const char* searchDate) {
    FILE* file = fopen(filePath, "rb");
    if (file == NULL) {
        printf("n/a\n");
        return 0;
    }

    Record record;
    while (fread(&record, sizeof(Record), 1, file) == 1) {
        if (dateEquals(&record, searchDate)) {
            printf("%d\n", record.code);
            fclose(file);
            return 0;
        }
    }

    printf("n/a\n");
    fclose(file);
    return 0;
}

int main(void) {
    char filename[1024];
    scanf("%1023s", filename);
    char searchDate[1024];
    scanf("%1023s", searchDate);

    searchByDate(filename, searchDate);

    return 0;
}