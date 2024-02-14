#include <stdio.h>
#include <stdlib.h>

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

int readRecord(FILE* file, Record* record) { return fread(record, sizeof(Record), 1, file); }

int writeRecord(FILE* file, const Record* record) { return fwrite(record, sizeof(Record), 1, file); }

int compareRecords(const void* a, const void* b) {
    const Record* recordA = (const Record*)a;
    const Record* recordB = (const Record*)b;

    if (recordA->year != recordB->year) {
        return recordA->year - recordB->year;
    }
    if (recordA->month != recordB->month) {
        return recordA->month - recordB->month;
    }
    if (recordA->day != recordB->day) {
        return recordA->day - recordB->day;
    }
    if (recordA->hour != recordB->hour) {
        return recordA->hour - recordB->hour;
    }
    if (recordA->minute != recordB->minute) {
        return recordA->minute - recordB->minute;
    }
    if (recordA->second != recordB->second) {
        return recordA->second - recordB->second;
    }
    return 0;
}

void printRecord(const Record* record) {
    printf("%04d %02d %02d %02d %02d %02d %d %d\n", record->year, record->month, record->day, record->hour,
           record->minute, record->second, record->status, record->code);
}

void printFileContents(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("n/a\n");
        return;
    }

    Record record;
    int count = 0;

    while (readRecord(file, &record)) {
        printRecord(&record);
        count++;
    }

    if (count == 0) {
        printf("n/a\n");
    }

    fclose(file);
}

void sortAndPrintFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("n/a\n");
        return;
    }

    Record* records = NULL;
    int count = 0;
    int capacity = 0;

    while (1) {
        if (count >= capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            records = realloc(records, capacity * sizeof(Record));
            if (!records) {
                printf("n/a\n");
                fclose(file);
                return;
            }
        }

        if (readRecord(file, &records[count]) != 1) {
            break;
        }

        count++;
    }

    if (count == 0) {
        printf("n/a\n");
        free(records);
        fclose(file);
        return;
    }

    qsort(records, count, sizeof(Record), compareRecords);

    for (int i = 0; i < count; i++) {
        printRecord(&records[i]);
    }

    free(records);
    fclose(file);
}

void addRecordToFile(const char* filename) {
    FILE* file = fopen(filename, "ab");
    if (!file) {
        printf("n/a\n");
        return;
    }

    Record record;
    scanf("%d %d %d %d %d %d", &record.year, &record.month, &record.day, &record.hour, &record.minute,
          &record.second);
    scanf("%d", &record.status);
    scanf("%d", &record.code);

    if (writeRecord(file, &record) != 1) {
        printf("n/a\n");
    }

    fclose(file);
}

int main() {
    char filename[1024];
    scanf("%1023s", filename);

    int choice;

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printFileContents(filename);
                return 0;
                break;
            case 1:
                sortAndPrintFile(filename);
                return 0;
                break;
            case 2:
                addRecordToFile(filename);
                sortAndPrintFile(filename);
                return 0;
                break;
            case 3:
                return 0;
            default:
                printf("n/a");
                return 0;
                break;
        }
    }

    return 0;
}
