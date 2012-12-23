//
//  Terrain.cpp
//  TinyWingsX
//
//  Created by jie ding on 12/20/12.
//
//

#include "Terrain.h"

using namespace cocos2d;

Terrain::Terrain()
{
    m_pSprite = NULL;
    m_fOffsetX = 0.0f;
    CCSize sz = CCDirector::sharedDirector()->getWinSize();
    m_fScreenWidth = sz.width;
    m_fScreenHeight = sz.height;
    m_nTextureSize = 0;
    m_nHillKeyPoints = 0;
    m_nHillVertices = 0;
    m_nFromkeyPoint = 0;
    m_nToKeyPoint = 0;
    srand(time(NULL));
    
}

Terrain::~Terrain()
{
    
}

bool Terrain::init()
{
    this->generateHillKeyPoints();
    this->generateBorderVertices();
    return true;
}

void Terrain::setOffsetX(float var)
{
    if(m_fOffsetX == var)
        return;
    
    m_fOffsetX = var;
    this->setPosition(ccp(m_fScreenWidth / 8 - m_fOffsetX * this->getScale(), 0));
    this->resetRenderHill();
}

float Terrain::getOffsetX()
{
    return m_fOffsetX;
}

void Terrain::generateHillKeyPoints()
{
    m_nHillKeyPoints = 0;

    m_aHillKeyPoints[0] = (ccVertex2F){-m_fScreenWidth/4, m_fScreenHeight*3/4};
    m_aHillKeyPoints[1] = (ccVertex2F){0, m_fScreenHeight/2};
    
    int mindx = 160, rangedx = 80;
    //int mindx = 3, rangedx = 5;
    int mindy = 60, rangedy = 60;
    float maxH = m_fScreenHeight;
    float minH = 20;
    
    float x, y, dx, dy;
    x = 0;
    y = m_fScreenHeight/2;
    int sign = -1;
    for(int i = 2; i < kMaxHillKeyPoints - 1; i++)
    {
        dx = mindx + rand() % rangedx;
        x += dx;
        dy = mindy + rand() % rangedy;
        y += sign * dy;
        
        if(y > maxH)
            y = maxH;
        else if(y < minH)
            y = minH;
        
        sign *= -1;
        m_aHillKeyPoints[i] = (ccVertex2F){x, y};
    }
    
    x += mindx + rangedx;
    y = 0;
    m_aHillKeyPoints[kMaxHillKeyPoints-1] = (ccVertex2F){x, y};
    
}

void Terrain::draw()
{
    
    CCPoint *vertices = new CCPoint[kMaxHillKeyPoints];
    for(int i = 0; i < kMaxHillKeyPoints - 1; i++)
    {
        ccVertex2F pt = m_aHillKeyPoints[i];
        CCPoint pt1 = CCPoint(pt.x, pt.y);
        pt = m_aHillKeyPoints[i + 1];
        CCPoint pt2 = CCPoint(pt.x, pt.y);
        ccDrawColor4B(255, 0, 0, 255);
        ccPointSize(10.0f);
        ccDrawPoint(pt1);
    }
    delete []vertices;
    
    ccDrawColor4B(0, 0, 0, 255);
    vertices = new CCPoint[m_nBorderVertices];
    for(int i = 0; i < m_nBorderVertices - 1; i++)
    {
        ccVertex2F pt = m_aBorderVertices[i];
        CCPoint pt1 = CCPoint(pt.x, pt.y);
        pt = m_aBorderVertices[i + 1];
        CCPoint pt2 = CCPoint(pt.x, pt.y);
        ccDrawLine(pt1, pt2);
        ccPointSize(5.0f);
        ccDrawPoint(pt1);
    }
    delete []vertices;

}

void Terrain::resetRenderHill()
{
    
}

void Terrain::generateBorderVertices()
{
    m_nBorderVertices = 0;
    ccVertex2F v1, v2, v0;
    for(int i = 0; i < kMaxHillKeyPoints - 1; i++)
    {
        v1 = m_aHillKeyPoints[i];
        v2 = m_aHillKeyPoints[i + 1];
        int nSeg = floorf((v2.x - v1.x) / kHillSegmentWidth);
        float dx = (v2.x - v1.x) / nSeg;
        float da = M_PI / nSeg;
        
        float yMid = (v1.y + v2.y) / 2;
        float ySub = (v1.y - v2.y) / 2;
        m_aBorderVertices[m_nBorderVertices++] = v1;
        for(int j = 1; j <= nSeg; j++)
        {
            v0.x = v1.x + j * dx;
            v0.y = yMid + ySub * cosf(j * da);            
            m_aBorderVertices[m_nBorderVertices++] = v0;
        }
    }
}

