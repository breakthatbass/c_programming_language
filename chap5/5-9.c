/*
 * Exercise 5-9: Rewrite the routines day_of_year and month_day
 * with pointers instead of indexing.
 */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int get_digits(int);

// day_of_year: set day of year from month & day
int day_of_year(int year, int month, int day)
{
    int i, leap;
    char *p;

    // check for wrong amount of digits
    if (get_digits(year) != 4 || get_digits(month) > 2 || get_digits(day) > 2) {
        printf("day_of_year error: an argument is wrong\n");
        return -1;
    }
    // check for negative numbers
    if (year < 1 || month < 1 || day < 1) {
        printf("day_of_year error: an argument is wrong\n");
        return -1;
    }

    // leap is 0 if not a leap year, 1 if it is
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

    p = daytab[leap];
    for (i = 1; i < month; i++)
        day += *++p;
    return day;
} 

// month_day: set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    char *p;

    // check for wrong amount of digits
    if (get_digits(year) != 4 || get_digits(yearday) > 3) {
        printf("month_day error: an argument is wrong\n");
        return;
    }
    // check for negative numbers
    if (year < 1 || yearday < 1) {
        printf("month_day error: an argument is wrong\n");
        return;
    }

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

    p = daytab[leap];
    for (i = 1; yearday > *++p; i++)
        yearday -= *p;
    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int month = 8;
    int day = 5;

    int m;
    int d;

    int doy = day_of_year(2020, month, day);
    printf("day of year is : %d\n", doy);

    month_day(2020, doy, &m, &d);

    printf("month day function returns: month: %d day: %d\n", month, day);

    return 0;
}

// for error checking in day_of_year and month_day functions
int get_digits(int n)
{
    int length = 1;
    while (n /= 10)
        length++;
    return length;
}
