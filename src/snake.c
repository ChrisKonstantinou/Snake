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

    snake->size = GLOBAL_SIZE;
    snake->direction = 'R';
    
}

void draw_snake(Snake * snake)
{
    gfx_color(255, 255, 255);

    for (int i = 0; i < snake->length; i++)
    {
        gfx_rect(snake->x + i*snake->size, snake->y, snake->size, snake->size);
    }
}

void update_snake(Snake * snake, int screen_size_x, int screen_size_y)
{
    //We will update snake's position based on the c char variable
    //U is for up, R is for right, L is for left, D is for down
    switch (snake->direction)
    {
        case 'U':
            snake->y -= snake->size;
            break;
        case 'R':
            snake->x += snake->size;
            break;
        case 'L':
            snake->x -= snake->size;
            break;
        case 'D':
            snake->y += snake->size;
            break;

        default:
            break;
    }

    if (snake->x >= screen_size_x) snake->x = 0;
    if (snake->x < 0) snake->x = screen_size_x;

    if (snake->y >= screen_size_y) snake->y = 0;
    if (snake->y < 0) snake->y = screen_size_y;

}