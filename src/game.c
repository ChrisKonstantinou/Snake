#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
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

    while (1)
    {
        
        draw_snake(&snake);
        update_snake(&snake);
        add_food(&food, xsize, ysize);
        

        if (gfx_event_waiting())
        {
            c = gfx_wait();
            if (c == 'q') break;
            if (c == 'a') snake.direction = 'L';
            if (c == 'd') snake.direction = 'R';
            if (c == 'w') snake.direction = 'U';
            if (c == 's') snake.direction = 'D';
            
        }
        mssleep(200);
    }

    return 0;
}


