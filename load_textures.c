/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** Loadsz textures from png file
*/

#include "myradar.h"

my_texture_t *load_textures(void)
{
    my_texture_t *textures = my_calloc(TEXTURES_NB, sizeof(my_texture_t));
    my_texture_t tplane = {"Plane",
        sfTexture_createFromFile("png/plane.png", NULL)};
    my_texture_t ttower = {"Tower",
        sfTexture_createFromFile("png/tower.png", NULL)};

    if (textures == NULL)
        return NULL;
    textures[0] = tplane;
    textures[1] = ttower;
    for (int i = 0; i < TEXTURES_NB; i++) {
        if (textures[i].texture == NULL) {
            my_put_str(2, textures[i].name);
            my_put_str(2, " not loaded.\n");
            return NULL;
        }
    }
    return textures;
}
