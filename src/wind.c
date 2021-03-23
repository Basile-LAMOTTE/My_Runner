/*
** EPITECH PROJECT, 2020
** Code_CSFML
** File description:
** cursor
*/

#include "../include/my.h"

runner_t create_wind(void)
{
    runner_t wind = {0};
    wind.rect.top = 0;
    wind.rect.left = 0;
    wind.rect.width = 1400;
    wind.rect.height = 1080;
    wind.position.x = 0;
    wind.position.y = 200;
    wind.texture = sfTexture_createFromFile("ground/wind.png", NULL);
    wind.sprite = sfSprite_create();
    sfSprite_setTexture(wind.sprite, wind.texture, sfTrue);
    return (wind);
}

runner_t rect_update_wind(runner_t wind)
{
    if (wind.i == 0)
        wind.rect.left += 1400;
    if (wind.i == 1)
        wind.rect.left -= 1400;

    if (wind.rect.left == 5600)
        wind.i = 1;
    if (wind.rect.left == 0)
        wind.i = 0;
    return (wind);
}

runner_t update_wind(runner_t wind)
{
    wind.time = sfClock_getElapsedTime(wind.clock);
    float sec = wind.time.microseconds / 1000000.0;
    if (sec > 0.1) {
        wind = rect_update_wind(wind);
        sfSprite_setTextureRect(wind.sprite, wind.rect);
        sfClock_restart(wind.clock);
    }
    sfSprite_setPosition(wind.sprite, wind.position);
    return (wind);
}