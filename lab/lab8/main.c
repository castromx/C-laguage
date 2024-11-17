#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*Develop a function with a variable number of parameters, each of which is a structure that
has two fields: <Data> and <Quantity> (the data is specified by the character string dd.mm.rr).
The function should find and return the structure that is closest to the present
date (it's a good idea for this function to call a helper function to compare
two two)*/

typedef struct {
    char date[11];
    int count;
} DateStructur;


time_t date_to_timestamp(const char *date) {
    struct tm tm = {0};
    if (sscanf(date, "%2d.%2d.%4d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year) != 3) {
        printf("Incorrect date format: %s\n", date);
        return -1;
    }
    tm.tm_mon -= 1;
    tm.tm_year -= 1900;
    return mktime(&tm);
}


DateStructur find_nearest_date(int count, DateStructur dates[]) {
    time_t today;
    time(&today);

    DateStructur nearest_date = dates[0];
    time_t min_diff = llabs(today - date_to_timestamp(dates[0].date));

    for (int i = 1; i < count; i++) {
        time_t current_ts = date_to_timestamp(dates[i].date);
        if (current_ts == -1) {
            continue;
        }

        time_t diff = llabs(today - current_ts);
        if (diff < min_diff) {
            min_diff = diff;
            nearest_date = dates[i];
        }
    }

    return nearest_date;
}

int main() {
    DateStructur dates[] = {
        {"12.11.2023", 6},
        {"05.06.2024", 8},
        {"18.09.2024", 12},
        {"18.11.2024", 15}
    };

    DateStructur result = find_nearest_date(4, dates);

    printf("near date: %s, count: %d\n", result.date, result.count);

    return 0;
}
