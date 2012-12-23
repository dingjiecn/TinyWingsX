//
//  Game.cpp
//  TinyWingsX
//
//  Created by jie ding on 12/14/12.
//
//

#include "Game.h"
#include "Sky.h"
#include "Terrain.h"

using namespace cocos2d;

Game::Game()
{
    CCLOG("construct game");
}

Game::~Game()
{
    
}

bool Game::init()
{
    CCLayer::init();
    this->scheduleUpdate();
    this->setSky(Sky::create());
    this->addChild(m_pSky);
    
    this->setTerrain(Terrain::create());
    this->addChild(m_pTerrain);
    m_pTerrain->setScale(0.5f);
    return true;
}

void Game::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    
}

cocos2d::CCScene* Game::scene()
{
    CCScene* pScene = CCScene::create();
    CCLayer* pLayer = Game::create();
    pScene->addChild(pLayer);
    return pScene;
}

void Game::update(float dt)
{
    static float fSkyOffsetX = 0;
    fSkyOffsetX += dt * 500.0f;
    //m_pSky->setOffsetX(fSkyOffsetX);
    
    CCSize sz = CCDirector::sharedDirector()->getWinSize();
    float minScale = sz.height / 1024.0f;
    
    static float fSkyScale = 1.0f;
    static float f = 0.005f;
    if(fSkyScale >= 1.0f || fSkyScale <= minScale)
    {
        f = -f;
    }

    fSkyScale += f;
    //m_pSky->setScale(fSkyScale);
    
    //static float fTerrainScale = 1.0f;
    //fTerrainScale -= 0.001f;
    //m_pTerrain->setScale(fTerrainScale);
    
    
    m_pTerrain->setOffsetX(fSkyOffsetX);

}
