//
//  Box2DHelper.cpp
//  TinyWingsX
//
//  Created by jie ding on 12/14/12.
//
//

#include "Box2DHelper.h"
#include "cocos2d.h"

using namespace cocos2d;

float Box2DHelper::pointsPerMeter()
{
	return 32.0f;
}

float Box2DHelper::metersPerPoint()
{
	return 1.0f / Box2DHelper::pointsPerMeter();
}

float Box2DHelper::pixelsPerMeter()
{
	return Box2DHelper::pointsPerMeter() * CC_CONTENT_SCALE_FACTOR();
}

float metersPerPixel()
{
	return 1.0f / Box2DHelper::pixelsPerMeter();
}