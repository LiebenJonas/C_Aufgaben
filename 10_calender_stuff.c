//
// Created by jonas on 18/12/2024.
//

#include <stdio.h>
void print_year_and_weekday(int day, int mon, int year);
int get_days_for_mon(int mon);

int main_10() {
    print_year_and_weekday(31, 3, 1900);

    return 0;
}

void print_year_and_weekday(int day, int mon, int year) {
    if (mon < 3 && year <= 1900) {
        printf("Calculation impossible. Too early");
    }

    if (mon > 2 && year >= 2100) {
        printf("Calculation impossible. Too late");
    }

    int weekday_count = (year - 1900) * 365;
    weekday_count += (year / 1900) / 4;
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) //Schaltjahr
    {
        // ist Schaltjahr
        if (mon > 1) weekday_count--;
        if (mon > 2) weekday_count--;
    }

    for (int i = 1; i < mon; i++) {
        weekday_count += get_days_for_mon(i);
    }
    weekday_count += day;

    char* day_name;
    switch (weekday_count % 7) {
    case 0: day_name = "Sonntag";
        break;
    case 1: day_name = "Montag";
        break;
    case 2: day_name = "Dienstag";
        break;
    case 3: day_name = "Mittwoch";
        break;
    case 4: day_name = "Donnerstag";
        break;
    case 5: day_name = "Freitag";
        break;
    case 6: day_name = "Samstag";
        break;
    }

    printf("Wochentag: %s", day_name);
}


int get_days_for_mon(int mon) {
    switch (mon) {
    case 1:
        return 31;
    case 2:
        return 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    }
}
