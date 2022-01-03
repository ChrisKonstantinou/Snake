#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "../lib/timebase.h"

int mssleep(long miliseconds)
{
   struct timespec rem;
   struct timespec req= {
       (int)(miliseconds / 1000),
       (miliseconds % 1000) * 1000000
   };

   return nanosleep(&req , &rem);
}