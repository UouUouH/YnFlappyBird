#include "PipeSprite.h"
#include "define.h"
#include "SimpleAudioEngine.h"
bool PipeSprite::init(int tag)
{
    auto origin = Director::getInstance()->getVisibleOrigin();
   // auto visibleSize = Director::getInstance()->getVisibleSize();
    
    if (tag == 1)//up pipe
    {
        this->initWithSpriteFrameName("pipe_up.png");
        this->setPosition(origin.x+this->getContentSize().width/2, origin.y+this->getContentSize().height/2);
    }
    else{
        
        this->initWithSpriteFrameName("pipe_down.png");
        this->setPosition(origin.x+this->getContentSize().width/2, origin.y+this->getContentSize().height*3/2+THROUGH_HEIGHT);
    }
    
    auto body = PhysicsBody::create();
    auto shape = PhysicsShapeBox::create(this->getContentSize());
    body->addShape(shape);
    body->setDynamic(false);
    
    body->setGravityEnable(false);
    
    body->setCategoryBitmask(PIPE);
    body->setCollisionBitmask(BIRD);
    body->setContactTestBitmask(0);
    
    
    return true;
}

PipeSprite* PipeSprite::create(int tag)
{
    PipeSprite* pipeSprite = new PipeSprite();
    if(pipeSprite && pipeSprite->init(tag))
    {
        pipeSprite->autorelease();
        return pipeSprite;
    }
    else
    {
        delete pipeSprite;
        pipeSprite = NULL;
        return NULL;
    }
}


















//end







