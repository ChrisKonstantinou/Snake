#ifndef FOOD_H_
#define FOOD_H_

#include <stdbool.h>
#include "../lib/gfx.h"

typedef struct
{
    int x;
    int y;
    int size;
    bool is_eaten;

} Food;

void init_food(Food *);
//void add_food(Food *, int , int);
void change_location(Food *, int , int);
void draw_food(Food *);

#endif