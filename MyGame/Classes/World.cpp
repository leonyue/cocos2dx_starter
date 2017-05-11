//
//  World.cpp
//  MyGame
//
//  Created by dj.yue on 2017/5/11.
//
//

#include "World.hpp"

USING_NS_CC;

World::World()
{
}

World::~World()
{
}

Scene* World::createScene()
{
    return World::create();
}


bool World::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto stopGameItem = cocos2d::MenuItemLabel::create(Label::createWithTTF("Stop Game", "fonts/arial.ttf", 24), CC_CALLBACK_1(World::stopGame, this));
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    stopGameItem->setPosition(Vec2(origin.x + stopGameItem->getContentSize().width / 2, origin.y + visibleSize.height - stopGameItem->getContentSize().height / 2));
    
    auto menu = Menu::create(stopGameItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu,1);
    
    Vector<SpriteFrame *>allf;
    for (int i = 1; i < 7; i++) {
        auto sf = SpriteFrame::create(StringUtils::format("run%d.png",i), Rect(0, 0, 100, 100));
        allf.pushBack(sf);
    }
    

    // add player
    auto an = Animation::createWithSpriteFrames(allf);
    an->setDelayPerUnit(0.03);
    auto ani = Animate::create(an);
    auto Sp = Sprite::create();
    Sp -> setTag(110);
    Sp -> runAction(RepeatForever::create(ani));
    this->addChild(Sp,101);
    Sp->setPosition(200,50);
    this->scheduleUpdate();
    
    //add score
    auto lableScore = Label::createWithBMFont("futura-48.fnt", "365");
    this->addChild(lableScore);
    lableScore->setTag(111);
    lableScore->setPosition(Director::getInstance()->getWinSize().width-200,Director::getInstance()->getWinSize().height/2);
    
    this->jump = false;
    this->score = 0;
    
    //add touch
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan=[&](Touch* t, Event* e) {
        if (!this->jump) {
            jump = true;
            speed = 30;
            spDir = 1;
        }
        return true;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void World::update(float delta) {
    auto sp = this->getChildByTag(110);
    float positionY;
    if (jump) {
        positionY = sp->getPositionY() + speed;
        speed -= 2;
        if (positionY <= 50) {
            positionY = 50;
            jump = false;
            speed = 0;
        }
        sp->setPositionY(positionY);
    }
}

void World::stopGame(cocos2d::Ref *pSender) {
    Director::getInstance()->popScene();
}
