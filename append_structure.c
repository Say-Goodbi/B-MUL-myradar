/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Append structure from a script' line
*/

#include "myradar.h"

int append_tower(llist_t **towers, char **structure)
{
    tower_t *new_tower = NULL;

    if (ptrlen(structure) != 4 || my_strcmp(structure[0], "T") != 0)
        return -1;
    new_tower = create_tower(structure);
    if (new_tower != NULL) {
        push_to_list(towers, new_tower);
        return 0;
    }
    return -1;
}

int append_plane(llist_t **planes, char **structure)
{
    plane_t *new_plane = NULL;

    if (ptrlen(structure) != 7 || my_strcmp(structure[0], "A") != 0)
        return -1;
    new_plane = create_plane(structure);
    if (new_plane != NULL) {
        push_to_list(planes, new_plane);
        return 0;
    }
    return -1;
}

int append_structure(structures_t *towers_and_planes, char *lineptr)
{
    char **structure = str_to_word_array(lineptr, ' ');

    if (towers_and_planes == NULL || lineptr == NULL || structure == NULL)
        return -1;
    if (structure[0] == NULL)
        return -1;
    switch (structure[0][0]) {
        case 'A' :
            return append_plane(&towers_and_planes->planes, structure);
        case 'T' :
            return append_tower(&towers_and_planes->towers, structure);
    }
    return -1;
}
