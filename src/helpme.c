
/*
** EPITECH PROJECT, 2020
** Code_CSFML
** File description:
** cursor
*/

#include <../include/my.h>

int helpme(int ac, char **av)
{
    if (ac == 1)
        return (1);
    else if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            printf("[ EPITECH PROJECT, 2020 ]\n");
            printf("-Code_CSFML-\n\n");
            printf("     My Runner    \n");
            printf("\n Welcome !\n");
            printf("\n   ➣ My_runner is a simple game in which you incarne a bush in the desert.\n");
            printf("     You'll need to avoid obstacles to go the futher as possible !\n");
            printf("     Good luck with that, and have fun !\n");
            printf("\n\n");
        }
        else {
            printf("'-h' for info\n");
            return (84);
        }
    }
    return (0);
}