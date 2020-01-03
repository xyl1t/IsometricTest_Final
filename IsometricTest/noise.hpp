//
//  noise.hpp
//  IsometricTest
//
//  Created by Marat Isaw on 24.12.19.
//  Copyright © 2019 Marat Isaw. All rights reserved.
//

#ifndef noise_hpp
#define noise_hpp

#include <iostream>

float** combineNoise_sub(float** noise1, float** noise2, int w, int h);

float** generateFallOffMap(int w, int h, float intensity);

float** generateNoise(int width, int height, int size, int oct);

#endif /* noise_hpp */
