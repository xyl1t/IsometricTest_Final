//
//  noise.cpp
//  IsometricTest
//
//  Created by Marat Isaw on 24.12.19.
//  Copyright © 2019 Marat Isaw. All rights reserved.
//

#include "noise.hpp"
#include "common.hpp"
#include <cmath>

float** combineNoise_sub(float** noise1, float** noise2, int w, int h)
{
    if(w <= 0 || h <= 0) NULL;
    
    float** result = new float*[h];
    for (int i = 0; i < h; i++) {
        result[i] = new float[w];
    }
    
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            result[j][i] = clamp(noise1[j][i] - noise2[j][i], 0, 1);
        }
    }
    
    return result;
}

float** generateFallOffMap(int w, int h, float intensity)
{
    float** map = new float*[h];
    for (int i = 0; i < h; i++) {
        map[i] = new float[w];
    }
    
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h; j++)
        {
            float x = (i / (float)w) * 2 - 1;
            float y = (j / (float)h) * 2 - 1;
            
            float val = fadeControl(fmax(abs(x), abs(y)), 3, 2.5f);
            
            map[j][i] = val;
        }
    }
    
    return map;
}

float** generateNoise(int width, int height, int size, int oct)
{
    float** buffer = new float*[height];
    for(int i = 0; i < height; i++)
        buffer[i] = new float[width];
    
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            buffer[j][i] = 0;
    
    for(int octaves = 1; octaves <= oct; octaves++)
    {
        int gridSize = size / octaves;
        int w = width / (gridSize);
        int h = height / (gridSize);
        float** values = new float*[h + 2];
        for(int i = 0; i < h + 2; i++)
            values[i] = new float[w + 2];
        
        for(int i = 0; i < h + 2; i++)
            for(int j = 0; j < w + 2; j++)
            {
                values[i][j] = (rand() / (float)RAND_MAX) * 2 - 1;
            }
        
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                int x = i / gridSize;
                int y = j / gridSize;
                
                if(x >= w+1) continue;
                if(y >= h+1) continue;
                
                float val_tl = values[y][x];          // value top left
                float val_tr = values[y][x + 1];      // value top righ¥t
                float val_bl = values[y + 1][x];      // value bottom left
                float val_br = values[y + 1][x + 1];  // value bottom right
                
                float xd = fade(i % gridSize / (float)gridSize);
                float yd = fade(j % gridSize / (float)gridSize);
                
                float val_t = lerp(val_tl, val_tr, xd);
                float val_b = lerp(val_bl, val_br, xd);
                float val_f = lerp(val_t, val_b, yd);
                
                buffer[j][i] += val_f / octaves;
                
                buffer[j][i] = clamp(buffer[j][i], -1, 1);
            }
        }
        
        for (int i = 0; i < h; i++) {
            delete[] values[i];
        } delete[] values;
    }
    
    return buffer;
}
