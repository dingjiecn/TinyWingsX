//
//  Sky.cpp
//  TinyWingsX
//
//  Created by 胡 蓉 on 12-12-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Sky.h"

using namespace cocos2d;

Sky::Sky():m_fScale(1.0f), m_fOffsetX(0.0f), m_pSprite(NULL), m_nTextureSize(1024), m_fSkyWidth(0), m_fSkyHeight(0)
{
    CCLog("contruct sky");
}

Sky::~Sky()
{
    CCLog("destruct sky");
}

bool Sky::init()
{
    this->initSprite();
    return true;
}

void Sky::initSprite()
{
    m_szWin = CCDirector::sharedDirector()->getWinSize();
    m_fSkyHeight = m_nTextureSize;
    m_fSkyWidth = m_szWin.width / m_szWin.height * m_nTextureSize;
    CCTexture2D* pTex = this->generateTexture();
    CCRect texRect = CCRectMake(0, 0, m_fSkyWidth, m_fSkyHeight);
    this->setSprite(CCSprite::createWithTexture(pTex, texRect));
    m_pSprite->setAnchorPoint(ccp(1.0f / 8.0f, 0));
    m_pSprite->setPosition(ccp(m_szWin.width / 8.0f, 0));
    this->addChild(m_pSprite);    
}

CCTexture2D* Sky::generateTexture()
{
    CCRenderTexture* pRenderTexture = CCRenderTexture::create(m_nTextureSize, m_nTextureSize);
    pRenderTexture->beginWithClear(0.55f, 0.80f, 0.86f, 1.0f);
    
    //gradient
    float alpha = 1.0f;
    ccColor4B color1 = {255, 255, 255, 0};
    ccColor4B color2 = {255, 255, 255, 255};
    CCLayerGradient* pLayerColor = CCLayerGradient::create(color1, color2);
    pLayerColor->setContentSize(CCSizeMake(m_nTextureSize, m_nTextureSize));
    pLayerColor->setPosition(ccp(0, 0));
    pLayerColor->visit();
    
    //noise
    CCSprite* pSprite = CCSprite::create("noise.png");
    pSprite->setPosition(ccp(m_nTextureSize / 2, m_nTextureSize / 2));
    pSprite->setBlendFunc((ccBlendFunc){GL_DST_COLOR, GL_ZERO});
    pSprite->setScale(m_nTextureSize / 512.0f);
    pSprite->visit();
    
    pRenderTexture->end();
    CCTexture2D* pTex = pRenderTexture->getSprite()->getTexture();
    ccTexParams params = {GL_NEAREST, GL_NEAREST, GL_REPEAT, GL_REPEAT};
    pTex->setTexParameters(&params);
    return pTex;

}

void Sky::setOffsetX(float var)
{
    if(m_fOffsetX == var)
        return;
    
    m_fOffsetX = var;
    m_pSprite->setTextureRect(CCRectMake(m_fOffsetX, 0, m_fSkyWidth, m_fSkyHeight));
    
}

float Sky::getOffsetX()
{
    return m_fOffsetX;
}

void Sky::setScale(float var)
{
    static float fMinScale =  m_szWin.height / m_fSkyHeight;
    if(var < fMinScale)
        var = fMinScale;
    
    if(m_fScale == var)
        return;
    
    m_fScale = var;
    m_pSprite->setScale(m_fScale);    
}

float Sky::getScale()
{
    return m_fScale;
}



