#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include "../lib/gfx.h"
#include "../lib/snake.h"
#include "../lib/food.h"
#include "../lib/timebase.h"

int main () 
{
    char c;
    int ysize = 600;
    int xsize = 800;

    Snake snake;
    Food food;

    gfx_open(xsize, ysize, "Snake");

    init_snake(&snake);
    init_food(&food);
    change_location(&food, xsize, ysize);

    while (1)
    {
        gfx_clear();

        draw_snake(&snake);

        if (food.is_eaten)
        {
            change_location(&food, xsize, ysize);
            food.is_eaten = false;
        }

        draw_food(&food);

        if (gfx_event_waiting())
        {
            c = gfx_wait();
            if (c == 'q') break;
            if (c == 'a') snake.direction = 'L';
            if (c == 'd') snake.direction = 'R';
            if (c == 'w') snake.direction = 'U';
            if (c == 's') snake.direction = 'D';

            if (c == 'f') food.is_eaten = true;
            
        }

        update_snake(&snake, xsize, ysize);

        if (snake.x == food.x && snake.y == food.y) food.is_eaten = true;
        

        mssleep(50);
    }

    return 0;
}


