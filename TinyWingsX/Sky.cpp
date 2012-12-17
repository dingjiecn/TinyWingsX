//
//  Sky.cpp
//  TinyWingsX
//
//  Created by 胡 蓉 on 12-12-15.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <OpenGLES/ES1/gl.h>
#include "Sky.h"

using namespace cocos2d;

Sky::Sky():m_fScale(1.0f), m_fOffsetX(0.0f), m_pSprite(NULL), m_nTextureSize(512)
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
    CCTexture2D* pTex = this->generateTexture();
    CCRect texRect = CCRectMake(0, 0, 480, 320);
    this->setSprite(CCSprite::createWithTexture(pTex, texRect));
    m_pSprite->setPosition(ccp(240, 160));
    this->addChild(m_pSprite);    
}

CCTexture2D* Sky::generateTexture()
{
    CCRenderTexture* pRenderTexture = CCRenderTexture::create(m_nTextureSize, m_nTextureSize);
    pRenderTexture->beginWithClear(0.55f, 0.80f, 0.86f, 1.0f);
    
    //gradient
    float alpha = 0.3f;
    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    ccVertex2F vertices[4];
    ccColor4F colors[4];
    vertices[0] = (ccVertex2F){0, 0};                               colors[0] = (ccColor4F){1, 1, 1, 0};
    vertices[1] = (ccVertex2F){m_nTextureSize, 0};                  colors[1] = (ccColor4F){1, 1, 1, 0};
    vertices[2] = (ccVertex2F){0, m_nTextureSize};                  colors[2] = (ccColor4F){1, 1, 1, alpha};
    vertices[3] = (ccVertex2F){m_nTextureSize, m_nTextureSize};     colors[3] = (ccColor4F){1, 1, 1, alpha};
    
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(4, GL_FLOAT, 0, colors);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, (GLsizei)4);
    
    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    
    //noise
    CCSprite* pSprite = CCSprite::create("blocks.png");
    pSprite->setPosition(ccp(m_nTextureSize / 2, m_nTextureSize / 2));
    pSprite->setScale(1.0f);
    pSprite->setBlendFunc((ccBlendFunc){GL_DST_COLOR, GL_ZERO});
    pSprite->visit();
    pRenderTexture->end();
    
    CCTexture2D* pTex = pRenderTexture->getSprite()->getTexture();
    ccTexParams params = {GL_NEAREST, GL_NEAREST, GL_REPEAT, GL_REPEAT};
    pTex->setTexParameters(&params);
    return pTex;
    
//    CCRenderTexture *rt = [CCRenderTexture renderTextureWithWidth:textureSize height:textureSize];
//	
//	ccColor3B c = (ccColor3B){140, 205, 221};
//	ccColor4F cf = ccc4FFromccc3B(c);
//	
//	[rt beginWithClear:cf.r g:cf.g b:cf.b a:cf.a];
//	
//	// layer 1: gradient
//	
//	float gradientAlpha = 0.3f;
//	
//	glDisable(GL_TEXTURE_2D);
//	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//	
//	ccVertex2F vertices[4];
//	ccColor4F colors[4];
//	int nVertices = 0;
//	
//	vertices[nVertices] = (ccVertex2F){0, 0};
//	colors[nVertices++] = (ccColor4F){1, 1, 1, 0};
//	vertices[nVertices] = (ccVertex2F){textureSize, 0};
//	colors[nVertices++] = (ccColor4F){1, 1, 1, 0};
//	
//	vertices[nVertices] = (ccVertex2F){0, textureSize};
//	colors[nVertices++] = (ccColor4F){1, 1, 1, gradientAlpha};
//	vertices[nVertices] = (ccVertex2F){textureSize, textureSize};
//	colors[nVertices++] = (ccColor4F){1, 1, 1, gradientAlpha};
//    
//	// adjust vertices for retina
//	for (int i=0; i<nVertices; i++) {
//		vertices[i].x *= CC_CONTENT_SCALE_FACTOR();
//		vertices[i].y *= CC_CONTENT_SCALE_FACTOR();
//	}
//	
//	glVertexPointer(2, GL_FLOAT, 0, vertices);
//	glColorPointer(4, GL_FLOAT, 0, colors);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//	glDrawArrays(GL_TRIANGLE_STRIP, 0, (GLsizei)nVertices);
//	
//	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//	glEnable(GL_TEXTURE_2D);	
//	
//	// layer 2: noise
//	
//	CCSprite *s = [CCSprite spriteWithFile:@"noise.png"];
//	[s setBlendFunc:(ccBlendFunc){GL_DST_COLOR, GL_ZERO}];
//	s.position = ccp(textureSize/2, textureSize/2);
//	s.scale = (float)textureSize/512.0f*CC_CONTENT_SCALE_FACTOR();
//	glColor4f(1,1,1,1);
//	[s visit];
//	
//	[rt end];
//	
//	return rt.sprite.texture;
//    return NULL;
}

void Sky::setOffsetX(float var)
{
    if(m_fOffsetX == var)
        return;
    
    m_fOffsetX = var;
    m_pSprite->setTextureRect(CCRectMake(m_fOffsetX, 0, 480, 320));
    
}

float Sky::getOffsetX()
{
    return m_fOffsetX;
}

void Sky::setScale(float var)
{
    if(m_fScale == var)
        return;
    
    m_fScale = var;
    
}

float Sky::getScale()
{
    return m_fScale;
}



