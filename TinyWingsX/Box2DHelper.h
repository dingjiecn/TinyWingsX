//
//  Box2DHelper.h
//  TinyWingsX
//
//  Created by jie ding on 12/14/12.
//
//

#ifndef __TinyWingsX__Box2DHelper__
#define __TinyWingsX__Box2DHelper__

#include <iostream>

class Box2DHelper
{
public:
    // ignore CC_CONTENT_SCALE_FACTOR
    static float pointsPerMeter();
    static float metersPerPoint();
    
    // consider CC_CONTENT_SCALE_FACTOR
    static float pixelsPerMeter();
    static float metersPerPixel();
};

#endif /* defined(__TinyWingsX__Box2DHelper__) */
