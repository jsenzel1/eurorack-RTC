#ifndef jfunc_h
#define jfunc_h

#include <math.h>
#include <stdlib.h>

void randomSeed(int32_t seed)
{
  if (seed != 0) {
    srandom(seed);
  }
}

int32_t random(int32_t howbig)
{
  if (howbig == 0) {
    return 0;
  }
  return random() % howbig;
}

int32_t random(int32_t howsmall, int32_t howbig)
{
  if (howsmall >= howbig) {
    return howsmall;
  }
  int32_t diff = howbig - howsmall;
  return random(diff) + howsmall;
}

int32_t map(int32_t x, int32_t in_min, int32_t in_max,     int32_t out_min, int32_t            out_max)
{
  return (x - in_min) * (out_max - out_min) /              (in_max - in_min) +        out_min;
}

#endif
