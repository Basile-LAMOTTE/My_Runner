/*
** EPITECH PROJECT, 2020
** Code_CSFML
** File description:
** cursor
*/

#include "../include/my.h"

runner_t create_bush(void)
{
    runner_t bush = {0};
    bush.rect.top = 0;
    bush.rect.left = 0;
    bush.rect.width = 123;
    bush.rect.height = 150;
    bush.position.x = 200;
    bush.position.y = 850;
    bush.w = 0;
    bush.texture = sfTexture_createFromFile("ground/bush.png", NULL);
    bush.sprite = sfSprite_create();
    sfSprite_setTexture(bush.sprite, bush.texture, sfTrue);
    return (bush);
}

runner_t update_bush(runner_t bush)
{
    bush.rect.left = bush_mouvement(bush);
    bush = user_action(bush);
    sfSprite_setPosition(bush.sprite, bush.position);
    sfSprite_setTextureRect(bush.sprite, bush.rect);
    return (bush);
}