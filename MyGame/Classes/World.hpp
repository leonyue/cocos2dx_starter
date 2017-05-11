//
//  World.hpp
//  MyGame
//
//  Created by dj.yue on 2017/5/11.
//
//

#ifndef __MyGame__World__
#define __MyGame__World__

#include "cocos2d.h"

class World : public cocos2d::Scene
{
public:
    World();
    ~World();
    
    static cocos2d::Scene* createScene();
    void stopGame(cocos2d::Ref * pSender);
    
    virtual bool init();
    
    CREATE_FUNC(World);
};

#endif /* defined(__MyGame__World__) */
