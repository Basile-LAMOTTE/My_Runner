/*
** EPITECH PROJECT, 2020
** Code_CSFML
** File description:
** cursor
*/

#include "../include/my.h"

global_t speed_update(global_t global)
{
    global.time = sfClock_getElapsedTime(global.clock);
    float sec = global.time.microseconds / 1000000.0;
    if (sec > 0.001) {
        if (global.lockLooseScreen == 0)
            global.speed += 0.01;
        sfClock_restart(global.clock);
    }
    return (global);
}

runner_t display_score(sfRenderWindow *window, global_t global, runner_t score)
{
    char array[5];
    char *src;
    char *dst;
    score.font = sfFont_createFromFile("ground/arial.ttf");
    score.text = sfText_create();
    gcvt(global.speed, 4, array);
    for (src = dst = array; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != '.')
            dst++;
    }
    *dst = '\0';
    sfText_setString(score.text, array);
    sfText_setPosition(score.text, score.position);
    sfText_setFont(score.text, score.font);
    sfText_setCharacterSize(score.text, 30);
    sfRenderWindow_drawText(window, score.text, NULL);
    return score;
}

runner_t display_finalScore(sfRenderWindow *window,
                            global_t global,
                            runner_t score)
{
    score.position.x = 950;
    score.position.y = 815;
    display_score(window, global, score);
    return score;
}