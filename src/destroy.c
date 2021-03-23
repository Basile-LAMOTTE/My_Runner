/*
** EPITECH PROJECT, 2021
** DESTROY
** File description:
** The official destroyer of this project
*/

#include "../include/my.h"

void destroy_music(int nb, ...)
{
    va_list ap;
    va_start(ap, nb);
    for (int i = 0; i < nb; ++i)
        sfMusic_destroy(va_arg(ap, sfMusic *));
    va_end(ap);
}

void destroy_sprite(int nb, ...)
{
    va_list ap;
    va_start(ap, nb);
    for (int i = 0; i < nb; ++i)
        sfSprite_destroy(va_arg(ap, sfSprite *));
    va_end(ap);
}

void destroy_texture(int nb, ...)
{
    va_list ap;
    va_start(ap, nb);
    for (int i = 0; i < nb; ++i)
        sfTexture_destroy(va_arg(ap, sfTexture *));
    va_end(ap);
}

void destroy_clock(int nb, ...)
{
    va_list ap;
    va_start(ap, nb);
    for (int i = 0; i < nb; ++i)
        sfClock_destroy(va_arg(ap, sfClock *));
    va_end(ap);
}

void destroyer(global_t global, runner_t eagle, runner_t fire, runner_t fire2, runner_t bush)
{
    destroy_music(5,
        global.music, global.activWind, 
        global.soundWind, global.soundEagle,
        global.soundFire);
    destroy_sprite(4,
        eagle.sprite, fire.sprite,
        fire2.sprite, bush.sprite);
    destroy_texture(4,
        eagle.texture, fire.texture,
        fire2.texture, bush.texture);
    destroy_clock(5,
        eagle.clock, fire.clock,
        fire2.clock, bush.clock,
        bush.clock2);
}