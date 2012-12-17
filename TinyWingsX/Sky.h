//
//  Sky.h
//  TinyWingsX
//
//  Created by 胡 蓉 on 12-12-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef TinyWingsX_Sky_h
#define TinyWingsX_Sky_h

#include "cocos2d.h"

class Sky : public cocos2d::CCNode
{
public:
    Sky();
    virtual ~Sky();
    CREATE_FUNC(Sky);
    bool init();
    CC_PROPERTY(float, m_fOffsetX, OffsetX);
    CC_PROPERTY(float, m_fScale, Scale);
private:
    int m_nTextureSize;
    float m_fSkyWidth;
    float m_fSkyHeight;
    cocos2d::CCSize m_szWin;
    CC_SYNTHESIZE(cocos2d::CCSprite*, m_pSprite, Sprite);
    cocos2d::CCTexture2D* generateTexture();
    void initSprite();
};


#endif
