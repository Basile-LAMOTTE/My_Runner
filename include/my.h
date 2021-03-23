/*
** EPITECH PROJECT, 2020
** Code_Button_CSFML
** File description:
** hunter
*/

#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#ifndef HUNTER_H_
#define HUNTER_H_

typedef struct runner_s runner_t;
typedef struct global_s global_t;

struct runner_s
{
    sfVector2f position;
    sfSprite *sprite;
    sfText* text;
    sfFont* font;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f vect;
    sfClock *clock;
    sfClock *clock2;
    sfTime time;
    sfTime time2;
    int i;
    int lockSpeed;
    float speed;
    int blablabla;
    int lockLooseScreen;
    int y;
    int x;
    int w;
    float angle;
};

struct global_s
{
    sfMusic* soundWind;
    sfMusic* activWind;
    sfMusic* soundEagle;
    sfMusic* soundFire;
    sfMusic* music;
    sfClock *clock;
    sfTime time;
    float speed;
    int lockLooseScreen;
    float s;
};

/***Bush***/
runner_t create_bush(void);
runner_t update_bush(runner_t bush);
int bush_mouvement(runner_t bush);
runner_t user_action(runner_t bush);
void destroy_bush(runner_t bush);

/***Eagle***/
runner_t create_eagle(void);
runner_t update_eagle(runner_t eagle, float speed);
void display_eagle(sfRenderWindow *window, runner_t eagle);
void destroy_eagle(runner_t eagle);

/***Menus***/
int colision(runner_t bush, runner_t eagle, runner_t fire, global_t global);
runner_t create_loose_screen(void);
void display_loose_screen(sfRenderWindow *window, runner_t looseScreen);

/***Speed/Score***/
global_t speed_update(global_t global);
runner_t display_score(sfRenderWindow *window, global_t global, runner_t score);
runner_t display_finalScore(sfRenderWindow *window, global_t global, runner_t score);

/***Fire***/
runner_t create_fire(void);
runner_t place_obstacle(runner_t fire2);
runner_t place_fire(float speed, runner_t fire2);
runner_t update_fire(runner_t fire, float speed);
runner_t x_update_fire(runner_t fire, float speed);
runner_t rect_update_fire(runner_t fire);
void display_fire(sfRenderWindow *window, runner_t fire);
void destroy_fire(runner_t fire);

/***Management***/
void destroyer(global_t global, runner_t eagle, runner_t fire, runner_t fire2, runner_t bush);

/***Wind***/
runner_t create_wind(void);
runner_t update_wind(runner_t wind);
void display_wind(sfRenderWindow *window, runner_t wind);
void destroy_wind(runner_t wind);

/***Parallax***/
void create_allbackground(void);
runner_t create_foreground(void);
runner_t moove_foreground(sfRenderWindow *window, runner_t foreground, float speed);
runner_t create_preground(void);
runner_t moove_preground(sfRenderWindow *window, runner_t preground, float speed);
runner_t create_background(void);
runner_t moove_background(sfRenderWindow *window, runner_t background, float speed);
runner_t create_sky(void);
runner_t moove_sky(sfRenderWindow *window, runner_t sky, float speed);
void display_sprites(sfRenderWindow *window, 
                                                 const runner_t foreground, 
                                                 const runner_t preground,
                                                 const runner_t background,
                                                 const runner_t sky,
                                                 const runner_t bush,
                                                 const runner_t eagle,
                                                 const runner_t wind,
                                                 const runner_t fire);
void display_sprites_withoutWind(sfRenderWindow *window, const runner_t foreground, 
                                                 const runner_t preground,
                                                 const runner_t background,
                                                 const runner_t sky,
                                                 const runner_t bush,
                                                 const runner_t eagle,
                                                 const runner_t fire);

/***Miscellaneous***/
int helpme(int ac, char **av);

#endif /* !hunter_H_ */