#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "../lib/gfx.h"
#include "../lib/snake.h"
#include "../lib/food.h"


void init_food(Food * food)
{
    food->x = 0;
    food->y = 0;
    food->size = 30;
    food->is_eaten = false;
}

void add_food(Food * food, int screen_size_x, int screen_size_y)
{
    if (food->is_eaten) return;

    food->x = rand() % screen_size_x;
    food->y = rand() % screen_size_y;

    gfx_rect(food->x, food->y, food->size, food->size);

}


