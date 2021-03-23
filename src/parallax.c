/*
** EPITECH PROJECT, 2021
** parallax
** File description:
** parallax for runner
*/

#include "../include/my.h"

runner_t moove_foreground(sfRenderWindow *window,
                         runner_t foreground,
                         float speed)
{
    foreground.time = sfClock_getElapsedTime(foreground.clock);
    float sec = foreground.time.microseconds / 1000000.0;
    if (sec > 0.001) {
        foreground.vect.x -= 5 + speed;
        if (foreground.vect.x <= -2800) {
            foreground.vect.x = 0;
        }
        sfSprite_setPosition(foreground.sprite, foreground.vect);
        sfClock_restart(foreground.clock);
    }
    return (foreground);
}

runner_t moove_preground(sfRenderWindow *window,
                         runner_t preground,
                         float speed)
{
    preground.time = sfClock_getElapsedTime(preground.clock);
    float sec = preground.time.microseconds / 1000000.0;
    if (sec > 0.001) {
        preground.vect.x -= (5 + speed)/2;
        if (preground.vect.x <= -2800) {
            preground.vect.x = 0;
        }
        sfSprite_setPosition(preground.sprite, preground.vect);
        sfClock_restart(preground.clock);
    }
    return (preground);
}

runner_t moove_background(sfRenderWindow *window,
                         runner_t background,
                         float speed)
{
    background.time = sfClock_getElapsedTime(background.clock);
    float sec = background.time.microseconds / 1000000.0;
    if (sec > 0.001) {
        background.vect.x -= (5 + speed)/5;
        if (background.vect.x <= -2800) {
            background.vect.x = 0;
        }
        sfSprite_setPosition(background.sprite, background.vect);
        sfClock_restart(background.clock);
    }
    return (background);
}

runner_t moove_sky(sfRenderWindow *window, runner_t sky, float speed)
{
    sky.time = sfClock_getElapsedTime(sky.clock);
    float sec = sky.time.microseconds / 1000000.0;
    if (sec > 0.001) {
        sky.vect.x -= (5 + speed)/20;
        if (sky.vect.x <= -1400) {
            sky.vect.x = 0;
        }
        sfSprite_setPosition(sky.sprite, sky.vect);
        sfClock_restart(sky.clock);
    }
    return (sky);
}