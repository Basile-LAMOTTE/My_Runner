/*
** EPITECH PROJECT, 2020
** Code_CSFML
** File description:
** cursor
*/

#include "../include/my.h"

runner_t create_loose_screen(void)
{
    runner_t looseScreen = {0};
    looseScreen.texture=sfTexture_createFromFile("ground/looseScreen.png",NULL);
    looseScreen.sprite = sfSprite_create();
    sfSprite_setTexture(looseScreen.sprite, looseScreen.texture, sfTrue);
    return (looseScreen);
}

void display_loose_screen(sfRenderWindow *window, runner_t looseScreen)
{
    sfRenderWindow_drawSprite(window, looseScreen.sprite, NULL);
}

int colision(runner_t bush, runner_t eagle, runner_t fire, global_t global)
{
    if (bush.position.x + 61 >= eagle.position.x + 50 && bush.position.x <= eagle.position.x + 200) {
        if (bush.position.y + 75 >= eagle.position.y +50 && bush.position.y <= eagle.position.y + 200) {
            if (global.lockLooseScreen == 0)
                sfMusic_play(global.soundFire);
            return 1;
        }
    }

    if (bush.position.x + 61 >= fire.position.x + 50 && bush.position.x <= fire.position.x + 200) {
        if (bush.position.y + 75 >= fire.position.y + 50 && bush.position.y <= fire.position.y + 200) {
            sfMusic_play(global.soundEagle);
            return 1;
        }
    }
    return 0;
}