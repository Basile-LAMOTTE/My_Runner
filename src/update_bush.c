
/*
** EPITECH PROJECT, 2020
** Code_CSFML
** File description:
** cursor
*/

#include <../include/my.h>

runner_t jump(runner_t bush)
{
    bush.time2 = sfClock_getElapsedTime(bush.clock2);
    float sec = bush.time2.microseconds / 1000000.0;
    if (bush.position.y >= 0) {
        if (sec > 0.01) {
            bush.position.y -= 20;
            if (bush.position.y <= 700) {
                bush.w = 1;
            }
            else
                bush.w = 0;
            sfSprite_setPosition(bush.sprite, bush.vect);
            sfClock_restart(bush.clock2);
        }
    }
    return (bush);
}

runner_t user_action(runner_t bush)
{
    bush.time2 = sfClock_getElapsedTime(bush.clock2);
    float sec = bush.time2.microseconds / 1000000.0;
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        bush = jump(bush);
    else
        if (bush.position.y <= 850) {
            if (sec > 0.01) {
                bush.position.y += 10;
                sfSprite_setPosition(bush.sprite, bush.vect);
                sfClock_restart(bush.clock2);
            }
        }
    return (bush);
}

runner_t angle_update(runner_t bush)
{
    if (bush.i == 0)
        bush.angle += 1;
    if (bush.i == 1)
        bush.angle -= 1;

    if (bush.angle == 7)
        bush.i = 1;
    if (bush.angle == -7)
        bush.i = 0;
    return (bush);
}

int bush_mouvement(runner_t bush)
{
    bush.time = sfClock_getElapsedTime(bush.clock);
    float sec = bush.time.microseconds / 1000000.0;
    if (sec > 0.2) {
        if (bush.rect.left == 500) {
        	bush.rect.left = -125;
        }
        bush.rect.left += 125;
        bush = angle_update(bush);
        sfSprite_rotate(bush.sprite, bush.angle);
        sfSprite_setPosition(bush.sprite, bush.vect);
        sfClock_restart(bush.clock);
    }
    return (bush.rect.left);
}

