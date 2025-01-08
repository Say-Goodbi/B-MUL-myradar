/*
** EPITECH PROJECT, 2024
** Lib
** File description:
** Returns a number, from its given string form.
** Can return -1 if string isn't a positive number.
*/

#include "myradar.h"

double scientific_multiplicator(char *str)
{
    double mult = 1;
    double factor = 1;
    int i = 0;

    if (str[i] != 'e')
        return mult;
    i++;
    if (str[i] == '+')
        factor = 10;
    if (str[i] == '-')
        factor = 0.1;
    i++;
    while (str[i] != 0 && str[i] > 47 && str[i] < 58) {
        mult *= factor;
        i++;
    }
    return mult;
}

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
