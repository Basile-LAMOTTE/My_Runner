/*
** EPITECH PROJECT, 2020
** Code_CSFML
** File description:
** cursor
*/

#include "../include/my.h"

runner_t place_fire(float speed, runner_t fire2)
{
    static int y = 0;
    fire2.time = sfClock_getElapsedTime(fire2.clock);
    float sec = fire2.time.microseconds / 1000000.0;
    if (sec > 0.01) {
        if (y == 0) {
            fire2 = rect_update_fire(fire2);
            y += 10;
        }
        else
            y--;
        fire2.position.x -= 5 + speed;
        sfSprite_setTextureRect(fire2.sprite, fire2.rect);
        sfClock_restart(fire2.clock);
    }
    sfSprite_setPosition(fire2.sprite, fire2.position);
    fire2.x = 1;
    return fire2;
}

runner_t place_obstacle(runner_t fire2)
{
    FILE *fp = fopen("./obstacle", "r");
    char *line = NULL;
    size_t len = 0;
    int nread;
    int j = 0;
    while ((nread = getline(&line, &len, fp)) != -1) {
        for (int i = 0; line[i]; ++i)
            if (line[i] == 'x') {
                fire2.position.x = i * 100;
                fire2.position.y = j * 100;
            }
        ++j;
    }
    return fire2;
}

// ? 300 / 300