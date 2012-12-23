//
//  Terrain.h
//  TinyWingsX
//
//  Created by jie ding on 12/20/12.
//
//

#ifndef __TinyWingsX__Terrain__
#define __TinyWingsX__Terrain__

#include <iostream>
#include "cocos2d.h"

#define kMaxHillKeyPoints   101
#define kMaxHillVertices    1000
#define kMaxBorderVertices  5000
#define kHillSegmentWidth   15

class Terrain : public cocos2d::CCNode
{
public:
    Terrain();
    virtual ~Terrain();
    CREATE_FUNC(Terrain);
private:
    CC_SYNTHESIZE(cocos2d::CCSprite*, m_pSprite, Sprite);
    CC_PROPERTY(float, m_fOffsetX, OffsetX);
    float m_fScreenWidth;
    float m_fScreenHeight;
    int m_nTextureSize;
    int m_nHillKeyPoints;
    int m_nHillVertices;
    int m_nBorderVertices;
    int m_nFromkeyPoint;
    int m_nToKeyPoint;
    cocos2d::ccVertex2F m_aHillKeyPoints[kMaxHillKeyPoints];
    cocos2d::ccVertex2F m_aHillVertices[kMaxHillVertices];      
    cocos2d::ccVertex2F m_aHillTexCoords[kMaxHillVertices];
    cocos2d::ccVertex2F m_aBorderVertices[kMaxBorderVertices];  //long curve
    bool init();
    void generateHillKeyPoints();
    void generateBorderVertices();
    void resetRenderHill();
    virtual void draw();

};

#endif /* defined(__TinyWingsX__Terrain__) */
