//
//  common.h
//  WaterRipple3
//
//  Created by Marat Isaw on 30.11.19.
//  Copyright © 2019 Marat Isaw. All rights reserved.
//

#ifndef common_h
#define common_h

#define WIDTH 1280
#define HEIGHT 720

//1067
//600

#define WORLD_WIDTH 512
#define WORLD_HEIGHT 512

extern float TILE_WIDTH;
extern float TILE_HEIGHT;
extern float TILE_WIDTH_HALF;
extern float TILE_HEIGHT_HALF;

extern float ORIGIN_X;
extern float ORIGIN_Y;
extern float ORIGIN_X_CENTER_OFFSET;
extern float ORIGIN_Y_CENTER_OFFSET;


inline int worldToScreenX(int x, int y) {
    return (ORIGIN_X * TILE_WIDTH) + (x - y) * TILE_WIDTH_HALF + TILE_WIDTH_HALF;
}
inline int worldToScreenY(int x, int y) {
    return (ORIGIN_Y * TILE_HEIGHT) + (x + y) * TILE_HEIGHT_HALF;
}
inline int screenToWorldX(int x, int y) {
    return ((x - TILE_WIDTH_HALF - ORIGIN_X * TILE_WIDTH) / (float)TILE_WIDTH_HALF + (y - ORIGIN_Y * TILE_HEIGHT) / (float)TILE_HEIGHT_HALF) / 2;
}
inline int screenToWorldY(int x, int y) {
    return ((y - ORIGIN_Y * TILE_HEIGHT) / (float)TILE_HEIGHT_HALF - ((x - TILE_WIDTH_HALF - ORIGIN_X * TILE_WIDTH) / (float)TILE_WIDTH_HALF)) / 2;
}

float lerp(float v0, float v1, float t);
float clamp(float x, float lowerlimit, float upperlimit);
float smoothstep(float edge0, float edge1, float x);
float fade(float x);
float fadeControl(float x, float a, float b);
float fadeControlEndHeight(float x, float a, float b, float c);
float fadeEnd(float x);

#endif /* common_h */
