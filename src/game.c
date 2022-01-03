#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include "../lib/gfx.h"
#include "../lib/snake.h"
#include "../lib/food.h"

int mssleep(long miliseconds)
{
   struct timespec rem;
   struct timespec req= {
       (int)(miliseconds / 1000),
       (miliseconds % 1000) * 1000000
   };

   return nanosleep(&req , &rem);
}


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
        update_snake(&snake, c);
        add_food(&food, xsize, ysize);
        

        if (gfx_event_waiting())
        {
            c = gfx_wait();
            if (c == 'q') break;
            if (c == 'a') snake.direction = 'L';
            if (c == 'd') snake.direction = 'R';
            if (c == 'w') snake.direction = 'U';
            if (c == 's') snake.direction = 'D';
            
            printf("%c\n", c);
        }
        mssleep(200);
    }

    return 0;
}


