/*
** EPITECH PROJECT, 2020
** Code_CSFML
** File description:
** cursor
*/

#include "../include/my.h"

runner_t create_eagle(void)
{
    runner_t eagle = {0};
    eagle.rect.top = 0;
    eagle.rect.left = 0;
    eagle.rect.width = 300;
    eagle.rect.height = 300;
    eagle.position.x = 1500;
    eagle.position.y = 300;
    eagle.texture = sfTexture_createFromFile("ground/eagle.png", NULL);
    eagle.sprite = sfSprite_create();
    sfSprite_setTexture(eagle.sprite, eagle.texture, sfTrue);
    return (eagle);
}

runner_t rect_update_eagle(runner_t eagle)
{
    if (eagle.i == 0)
        eagle.rect.left += 300;
    if (eagle.i == 1)
        eagle.rect.left -= 300;

    if (eagle.rect.left == 900)
        eagle.i = 1;
    if (eagle.rect.left == 0)
        eagle.i = 0;
    return (eagle);
}

runner_t y_update_eagle(runner_t eagle)
{
    if (eagle.x == 0) {
        eagle.position.y += 10;
        eagle.y++;
    }
    if (eagle.x == 1) {
        eagle.position.y -= 10;
        eagle.y--;
    }
    if (eagle.y == 3)
        eagle.x = 1;
    if (eagle.y == -3)
        eagle.x = 0;
    return (eagle);
}

runner_t x_update_eagle(runner_t eagle, float speed)
{
    eagle.position.x -= 10 + speed;
        if (eagle.position.x <= -500) {
            eagle.position.x = 1500;
            eagle.position.y = rand() % 500;
        }
    return (eagle);
}

runner_t update_eagle(runner_t eagle, float speed)
{
    static int y = 0;

    eagle.time = sfClock_getElapsedTime(eagle.clock);
    float sec = eagle.time.microseconds / 1000000.0;
    if (sec > 0.01) {
        if (y == 0) {
            eagle = rect_update_eagle(eagle);
            eagle = y_update_eagle(eagle);
            y += 10;
        }
        else
            y--;
        eagle = x_update_eagle(eagle, speed);
        sfSprite_setTextureRect(eagle.sprite, eagle.rect);
        sfClock_restart(eagle.clock);
    }
    sfSprite_setPosition(eagle.sprite, eagle.position);
    return (eagle);
}