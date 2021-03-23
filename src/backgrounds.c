/*
** EPITECH PROJECT, 2021
** background
** File description:
** backgound initialiser
*/

#include "../include/my.h"

runner_t create_foreground(void)
{
    runner_t foreground = {0};
    foreground.texture = sfTexture_createFromFile("ground/foreground.png",NULL);
    foreground.sprite = sfSprite_create();
    sfSprite_setTexture(foreground.sprite, foreground.texture, sfTrue);
    return (foreground);
}

runner_t create_preground(void)
{
    runner_t preground = {0};
    preground.texture = sfTexture_createFromFile("ground/preground.png", NULL);
    preground.sprite = sfSprite_create();
    sfSprite_setTexture(preground.sprite, preground.texture, sfTrue);
    return (preground);
}

runner_t create_background(void)
{
    runner_t background = {0};
    background.texture = sfTexture_createFromFile("ground/background.png",NULL);
    background.sprite = sfSprite_create();
    sfSprite_setTexture(background.sprite, background.texture, sfTrue);
    return (background);
}

runner_t create_sky(void)
{
    runner_t sky = {0};
    sky.texture = sfTexture_createFromFile("ground/[4] sky.jpg", NULL);
    sky.sprite = sfSprite_create();
    sfSprite_setTexture(sky.sprite, sky.texture, sfTrue);
    return (sky);
}
