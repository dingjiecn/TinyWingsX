//
//  Game.cpp
//  TinyWingsX
//
//  Created by jie ding on 12/14/12.
//
//

#include "Game.h"

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
    CCLOG("%f", dt);
}
