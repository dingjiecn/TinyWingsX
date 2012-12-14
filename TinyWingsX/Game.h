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

class Game : public cocos2d::CCLayer
{
public:
    Game();
    virtual ~Game();
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    static cocos2d::CCScene* scene();
    
};

#endif /* defined(__TinyWingsX__Game__) */
