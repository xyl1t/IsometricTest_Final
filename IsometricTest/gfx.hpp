//
//  gfx.hpp
//  WaterRipple3
//
//  Created by Marat Isaw on 30.11.19.
//  Copyright © 2019 Marat Isaw. All rights reserved.
//

#ifndef gfx_hpp
#define gfx_hpp

#include <iostream>
#include <cmath>
#include "common.hpp"


struct Vertex
{
    int x;
    int y;
    uint32_t extra;
};

extern int gfx_WIDTH;
extern int gfx_HEIGHT;

void gfx_init(int w, int h);

void gfx_sortVerticesByY(Vertex arr[], int n);

void gfx_drawLine(uint32_t*& pixels, uint32_t color, int x1, int y1, int x2, int y2);
void gfx_drawLineN(uint32_t*& pixels, uint32_t color, int x1, int y1, int x2, int y2);
void gfx_drawLineAdd(uint32_t*& pixels, uint32_t color, int x1, int y1, int x2, int y2);
void gfx_drawLine(uint32_t*& pixels, uint32_t color, Vertex v1, Vertex v2);

void gfx_fillBottomFlatTriangle(uint32_t*& pixels, uint32_t c1, uint32_t c2, uint32_t c3, int x1, int y1, int x2, int y2, int x3, int y3);
void gfx_fillBottomFlatTriangle(uint32_t*& pixels, int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, int a1, int a2, int a3, int x1, int y1, int x2, int y2, int x3, int y3);
void gfx_fillBottomFlatTriangle(uint32_t*& pixels, uint32_t color, int x1, int y1, int x2, int y2, int x3, int y3);

void gfx_fillTopFlatTriangle(uint32_t*& pixels, uint32_t c1, uint32_t c2, uint32_t c3, int x1, int y1, int x2, int y2, int x3, int y3);
void gfx_fillTopFlatTriangle(uint32_t*& pixels, int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, int a1, int a2, int a3, int x1, int y1, int x2, int y2, int x3, int y3);
void gfx_fillTopFlatTriangle(uint32_t*& pixels, uint32_t color, int x1, int y1, int x2, int y2, int x3, int y3);

void gfx_drawTriangle(uint32_t*& pixels, uint32_t c1, uint32_t c2, uint32_t c3, int x1, int y1, int x2, int y2, int x3, int y3);
void gfx_drawTriangle(uint32_t*& pixels, int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3, int x1, int y1, int x2, int y2, int x3, int y3);
void gfx_drawTriangle(uint32_t*& pixels, uint32_t color, int x1, int y1, int x2, int y2, int x3, int y3);

void gfx_drawTriangleOutline(uint32_t*& pixels, uint32_t color, int x1, int y1, int x2, int y2, int x3, int y3);
void gfx_drawTriangleOutlineAdd(uint32_t*& pixels, uint32_t color, int x1, int y1, int x2, int y2, int x3, int y3);

void gfx_fillRectangle(uint32_t*& pixels, uint32_t color, int x, int y, int w, int h);
void gfx_fillRectangleAdd(uint32_t*& pixels, uint32_t color, int x, int y, int w, int h);
void gfx_drawRectangle(uint32_t*& pixels, uint32_t color, int x, int y, int w, int h);


#endif /* gfx_hpp */
