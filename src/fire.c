/*
** EPITECH PROJECT, 2020
** Code_CSFML
** File description:
** cursor
*/

#include "../include/my.h"

runner_t create_fire(void)
{
    runner_t fire = {0};
    fire.rect.top = 0;
    fire.rect.left = 0;
    fire.rect.width = 300;
    fire.rect.height = 300;
    fire.position.x = 1500;
    fire.position.y = 720;
    fire.texture = sfTexture_createFromFile("ground/fire.png", NULL);
    fire.sprite = sfSprite_create();
    sfSprite_setTexture(fire.sprite, fire.texture, sfTrue);
    return (fire);
}

runner_t rect_update_fire(runner_t fire)
{
    if (fire.i == 0)
        fire.rect.left += 300;
    if (fire.i == 1)
        fire.rect.left -= 300;

    if (fire.rect.left == 600)
        fire.i = 1;
    if (fire.rect.left == 0)
        fire.i = 0;
    return (fire);
}

runner_t x_update_fire(runner_t fire, float speed)
{
    fire.position.x -= 5 + speed;
        if (fire.position.x <= -500) {
            fire.position.x = 1500;
        }
    return (fire);
}

runner_t update_fire(runner_t fire, float speed)
{
    static int y = 0;

    fire.time = sfClock_getElapsedTime(fire.clock);
    float sec = fire.time.microseconds / 1000000.0;
    if (sec > 0.01) {
        if (y == 0) {
            fire = rect_update_fire(fire);
            y += 10;
        }
        else
            y--;
        fire = x_update_fire(fire, speed);
        sfSprite_setTextureRect(fire.sprite, fire.rect);
        sfClock_restart(fire.clock);
    }
    sfSprite_setPosition(fire.sprite, fire.position);
    return (fire);
}