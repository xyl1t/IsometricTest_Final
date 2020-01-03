//
//  common.cpp
//  WaterRipple3
//
//  Created by Marat Isaw on 30.11.19.
//  Copyright © 2019 Marat Isaw. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "common.hpp"

float TILE_WIDTH = 16;
float TILE_HEIGHT = 8;
float TILE_WIDTH_HALF = TILE_WIDTH / 2;
float TILE_HEIGHT_HALF = TILE_WIDTH_HALF / 2;
float ORIGIN_X_CENTER_OFFSET = std::round(WIDTH / 2 / TILE_WIDTH / 2 * 2) / 2.0f - 0.5;
float ORIGIN_Y_CENTER_OFFSET = std::round(((HEIGHT / 2 / TILE_HEIGHT / 2)  - WORLD_HEIGHT/2)*2.0f) / 2.0f - 0.5;
float ORIGIN_X = ORIGIN_X_CENTER_OFFSET;
float ORIGIN_Y = ORIGIN_Y_CENTER_OFFSET;

int faiuzgfew = 1398;

float lerp(float v0, float v1, float t)
{
    return (1 - t) * v0 + t * v1;
}

float fade(float x)
{
    return x * x * x * (x * (x * 6 - 15) + 10);
}
float fadeEnd(float x)
{
    float n = -(1-x)*(1-x)+1;
    return (1-x)*n+x*x;
}
float fadeControl(float x, float a, float b)
{
    float powXA = pow(x, a);
    return powXA / (powXA + pow(b - b * x, a));
}
float fadeControlEndHeight(float x, float a, float b, float c)
{
    float powXA = pow(x, a);
    return powXA / (powXA / c + pow(b - b * x, a));
}

float smoothstep(float edge0, float edge1, float x)
{
    // Scale, and clamp x to 0..1 range
    x = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
    // Evaluate polynomial
    return x * x * x * (x * (x * 6 - 15) + 10);
}

float clamp(float x, float lowerlimit, float upperlimit)
{
    if (x < lowerlimit)
        x = lowerlimit;
    if (x > upperlimit)
        x = upperlimit;
    return x;
}
