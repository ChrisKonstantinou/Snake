#ifndef SNAKE_H_
#define SNAKE_H_

#include <stdbool.h>
#include "../lib/gfx.h"



typedef struct
{
    int x;
    int y;
    int length;
    int size;
    bool alive;
    
    //-----
    char direction;

} Snake;

void init_snake(Snake *);
void draw_snake(Snake *);
void update_snake(Snake *, char);

#endif