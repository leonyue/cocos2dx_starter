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
    
    
    return true;
}


void World::stopGame(cocos2d::Ref *pSender) {
    Director::getInstance()->popScene();
}
