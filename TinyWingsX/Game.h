//
//  Game.h
//  TinyWingsX
//
//  Created by jie ding on 12/14/12.
//
//

#ifndef __TinyWingsX__Game__
#define __TinyWingsX__Game__

#include <iostream>
#include "cocos2d.h"

class Sky;

class Game : public cocos2d::CCLayer
{
public:
    Game();
    virtual ~Game();
    CREATE_FUNC(Game);
    bool init();
    virtual void update(float dt);
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    static cocos2d::CCScene* scene();
private:
    CC_SYNTHESIZE(Sky*, m_pSky, Sky);
    
};

#endif /* defined(__TinyWingsX__Game__) */
