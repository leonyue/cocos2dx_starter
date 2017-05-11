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
    
    bool m_gameOver;//游戏是否结束
    int score;
    int spDir;//表示精灵的方向 1，up 2 down
    int speed;//跳跃速度
    int m_level;//关卡编号
    bool jump;//表示是否精灵在跳跃，如果跳跃不处理屏幕的触摸
    
    
    static cocos2d::Scene* createScene();
    void stopGame(cocos2d::Ref * pSender);
    void update(float delta);
    void loadLevel(int level);
    virtual bool init();
    CREATE_FUNC(World);
};

#endif /* defined(__MyGame__World__) */
