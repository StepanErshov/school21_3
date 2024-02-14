#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

int isDateInRange(const Record* record, const char* startDate, const char* endDate) {
    char recordDate[11];
    sprintf(recordDate, "%.2d.%.2d.%.4d", record->day, record->month, record->year);

    return strcmp(startDate, recordDate) <= 0 && strcmp(recordDate, endDate) <= 0;
}

int clearStateByDate(const char* filePath, const char* startDate, const char* endDate) {
    FILE* file = fopen(filePath, "r+b");
    if (file == NULL) {
        printf("n/a\n");
        return 0;
    }

    int recordsToRemove = 0;
    Record record;
    while (fread(&record, sizeof(Record), 1, file) == 1) {
        if (isDateInRange(&record, startDate, endDate)) {
            recordsToRemove++;
        }
    }

    if (recordsToRemove == 0) {
        fclose(file);
        if (truncate(filePath, 0) != 0) {
            printf("n/a\n");
            return 0;
        } else {
            printf("File cleared\n");
            return 0;
        }
    }

    rewind(file);
    int newSize = 0;
    while (fread(&record, sizeof(Record), 1, file) == 1) {
        if (!isDateInRange(&record, startDate, endDate)) {
            fseek(file, newSize * sizeof(Record), SEEK_SET);
            fwrite(&record, sizeof(Record), 1, file);
            newSize++;
        }
    }

    if (ftruncate(fileno(file), newSize * sizeof(Record)) != 0) {
        printf("n/a\n");
        return 0;
    } else {
        printf("File cleared\n");
        return 0;
    }
}

int main(void) {
    char filename[1024];
    scanf("%1023s", filename);
    char startDate[1024];
    scanf("%1023s", startDate);
    char endDate[1024];
    scanf("%1023s", endDate);

    clearStateByDate(filename, startDate, endDate);
    return 0;
}