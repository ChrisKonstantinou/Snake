#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "../lib/gfx.h"
#include "../lib/snake.h"
#include "../lib/food.h"


void init_food(Food * food)
{
    srand(time(0));

    food->x = 0;
    food->y = 0;

    food->size = GLOBAL_SIZE;
    food->is_eaten = false;
}

void change_location(Food * food, int screen_size_x, int screen_size_y)
{
    //While loop adds 1 to the food.x and food.y values until it 'fits' inside an acceptable square
    
    food->x = rand() % (screen_size_x - 2 * food->size);
    while (food->x % food->size != 0) food->x ++;
    
    food->y = rand() % (screen_size_y - 2 * food->size);
    while (food->y % food->size != 0) food->y ++;
}


void draw_food(Food * food)
{
    gfx_color(0, 255, 0);
    gfx_rect(food->x, food->y, food->size, food->size);
}