/*
** EPITECH PROJECT, 2024
** Lib
** File description:
** Returns a number, from its given string form.
** Can return -1 if string isn't a positive number.
*/

#include "myradar.h"

float my_atof(char const *str)
{
    int i = 0;
    int e = 1;
    double tot = 0;

    if (str == NULL)
        return -1;
    while (str[i] > 47 && str[i] < 58) {
        tot *= 10;
        tot += str[i] - 48;
        i++;
    }
    if (str[i] == '.') {
        i++;
        while (str[i] > 47 && str[i] < 58) {
            e *= 10;
            tot += (double)(str[i] - 48) / e;
            i++;
        }
    }
    return i > 0 ? tot : -1;
}
