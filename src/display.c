/*
** EPITECH PROJECT, 2021
** display
** File description:
** display most of the program sprites
*/

#include "../include/my.h"

void display_sprites(sfRenderWindow *window, const runner_t foreground, 
                                                 const runner_t preground,
                                                 const runner_t background,
                                                 const runner_t sky,
                                                 const runner_t bush,
                                                 const runner_t eagle,
                                                 const runner_t wind,
                                                 const runner_t fire)
{
    sfRenderWindow_drawSprite(window, sky.sprite, NULL);
    sfRenderWindow_drawSprite(window, background.sprite, NULL);
    sfRenderWindow_drawSprite(window, preground.sprite, NULL);
    sfRenderWindow_drawSprite(window, foreground.sprite, NULL);
    sfRenderWindow_drawSprite(window, wind.sprite, NULL);
    sfRenderWindow_drawSprite(window, bush.sprite, NULL);
    sfRenderWindow_drawSprite(window, eagle.sprite, NULL);
    sfRenderWindow_drawSprite(window, fire.sprite, NULL);
}


void display_sprites_withoutWind(sfRenderWindow *window, 
                                                 const runner_t foreground, 
                                                 const runner_t preground,
                                                 const runner_t background,
                                                 const runner_t sky,
                                                 const runner_t bush,
                                                 const runner_t eagle,
                                                 const runner_t fire)
{
    sfRenderWindow_drawSprite(window, sky.sprite, NULL);
    sfRenderWindow_drawSprite(window, background.sprite, NULL);
    sfRenderWindow_drawSprite(window, preground.sprite, NULL);
    sfRenderWindow_drawSprite(window, foreground.sprite, NULL);
    sfRenderWindow_drawSprite(window, bush.sprite, NULL);
    sfRenderWindow_drawSprite(window, eagle.sprite, NULL);
    sfRenderWindow_drawSprite(window, fire.sprite, NULL);
}