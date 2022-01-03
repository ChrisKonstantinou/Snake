#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../lib/gfx.h"
#include "../lib/snake.h"

void init_snake(Snake * snake)
{
    snake->x = 0;
    snake->y = 0;

    snake->alive = true;
    snake->length = 1;

    snake->size = 35;
    snake->direction = 'R';
    
}

void draw_snake(Snake * snake)
{
    gfx_clear();
    gfx_color(255, 255, 255);

    for (int i = 0; i < snake->length; i++)
    {
        gfx_rect(snake->x + i*snake->size, snake->y, snake->size, snake->size);
    }
}

void update_snake(Snake * snake, char c)
{
    //We will update snake's position based on the c char variable
    switch (snake->direction)
    {

        case 'U':
            printf("Snake up\n");
            snake->y -= snake->size;
            break;
        case 'R':
            printf("Snake right\n");
            snake->x += snake->size;
            break;
        case 'L':
            printf("Snake left\n");
            snake->x -= snake->size;
            break;
        case 'D':
            printf("Snake down\n");
            snake->y += snake->size;
            break;

        default:
            break;
    }

}