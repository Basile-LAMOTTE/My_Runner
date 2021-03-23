/*
** EPITECH PROJECT, 2020
** Code_CSFML
** File description:
** main
*/

#include "include/my.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfRenderWindow *create_window()
{
    sfRenderWindow *new_window;
    sfVideoMode video_mode;

    video_mode.bitsPerPixel = 32;
    video_mode.width = 1400;
    video_mode.height = 1080;
    new_window = sfRenderWindow_create(video_mode, "RUNNER", sfClose, NULL);
    if (new_window == NULL)
        return (NULL);
    sfRenderWindow_setPosition(new_window, (sfVector2i){300, 0});
    sfRenderWindow_setFramerateLimit(new_window, 60);
    return (new_window);
}

int basic_event_window(sfRenderWindow *window, runner_t bush)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter) {
            bush.lockLooseScreen = 0;
        }
    }
    return bush.lockLooseScreen;
}

int main(int ac, char **av)
{
    if (helpme(ac, av) != 1)
        return (1);
    sfRenderWindow *window = create_window();
    global_t global;
    global.clock = sfClock_create();
    global.speed = 0;
    global.lockLooseScreen = 0;
    runner_t score;
    score.position.y = 100;
    score.position.x = 1200;
    runner_t eagle = create_eagle();
    eagle.clock = sfClock_create();
    runner_t fire = create_fire();
    fire.clock = sfClock_create();
    runner_t fire2 = create_fire();
    fire2.clock = sfClock_create();
    fire2 = place_obstacle(fire2);
    runner_t bush = create_bush();
    bush.clock = sfClock_create();
    bush.clock2 = sfClock_create();
    runner_t wind = create_wind();
    wind.clock = sfClock_create();
    runner_t foreground = create_foreground();
    foreground.clock = sfClock_create();
    runner_t preground = create_preground();
    preground.clock = sfClock_create();
    runner_t background = create_background();
    background.clock = sfClock_create();
    runner_t sky = create_sky();
    sky.clock = sfClock_create();
    runner_t looseScreen = create_loose_screen();
    global.soundWind = sfMusic_createFromFile("ground/wind.ogg");
    global.soundEagle = sfMusic_createFromFile("ground/eagle.wav");
    global.soundFire = sfMusic_createFromFile("ground/fire.wav");
    global.music = sfMusic_createFromFile("ground/Grimace and Grinde.ogg");
    global.activWind = sfMusic_createFromFile("ground/spWind.wav");
    if (!global.soundWind)
        return 1;
    sfMusic_play(global.soundWind);
    sfMusic_play(global.music);
    if (window == NULL)
        return (84);
    while (sfRenderWindow_isOpen(window)) {
        bush.lockLooseScreen = basic_event_window(window, bush);
        fire2.x = 0;
        foreground = moove_foreground(window, foreground, global.speed);
        preground = moove_preground(window, preground, global.speed);
        background = moove_background(window, background, global.speed);
        sky = moove_sky(window, sky, global.speed);
        bush = update_bush(bush);
        wind = update_wind(wind);
        eagle = update_eagle(eagle, global.speed);
        fire = update_fire(fire, global.speed);
        fire2 = place_fire(global.speed, fire2);
        global = speed_update(global);
        sfRenderWindow_clear(window, sfBlack);
        if (bush.w == 1) {
            display_sprites(window, foreground, preground, background, sky, bush, eagle, wind, fire);
        }
        else
            display_sprites_withoutWind(window, foreground, preground, background, sky, bush, eagle, fire);
        bush.w = 0;
        if (fire2.x == 1)
            sfRenderWindow_drawSprite(window, fire2.sprite, NULL);
        display_score(window, global, score);
        if (colision(bush, fire, eagle, global) == 1 || global.lockLooseScreen == 1) {
            display_loose_screen(window, looseScreen);
            global.lockLooseScreen = 1;
            display_finalScore(window, global, score);
        }
        sfRenderWindow_display(window);
    }
    destroyer(global, eagle, fire, fire2, bush);
    sfRenderWindow_destroy(window);
    return (0);
}