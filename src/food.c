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
    food->x = 0;
    food->y = 0;

    food->size = 35;
    food->is_eaten = false;
}

void add_food(Food * food, int screen_size_x, int screen_size_y)
{
    //This function is not used 
    
    /*
    if (food->is_eaten) return;

    food->x = rand() % screen_size_x;
    food->y = rand() % screen_size_y;

    gfx_rect(food->x, food->y, food->size, food->size);
    */
    return;
}

void change_location(Food * food, int screen_size_x, int screen_size_y)
{
    srand(time(0));
    food->x = rand() % screen_size_x;
    while (food->x % food->size != 0) food->x ++;
    
    food->y = rand() % screen_size_y;
    while (food->y % food->size != 0) food->y ++;
}

void draw_food(Food * food)
{
    gfx_color(0, 255, 0);
    gfx_rect(food->x, food->y, food->size, food->size);
}