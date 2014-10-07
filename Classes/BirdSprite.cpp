#include "BirdSprite.h"
#include "define.h"
#include "SimpleAudioEngine.h"

static BirdSprite* instance = NULL;
BirdSprite* BirdSprite::getInstance()
{
    if (instance == NULL) {
        instance = new BirdSprite();
        instance->init();
    }
    return instance;
}
bool BirdSprite::init()
{
    auto origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    
    this->initWithSpriteFrameName("bird0_0.png");
    
    
    auto body = PhysicsBody::create();
    auto shape = PhysicsShapeCircle::create(BIRD_RADIUS);
    body->addShape(shape);
    body->setDynamic(true);
    
    body->setGravityEnable(false);
    body->setLinearDamping(0.7f);
    
    body->setCategoryBitmask(BIRD);
    body->setCollisionBitmask(LAND|PIPE);
    body->setContactTestBitmask(LAND|PIPE);
    
    this->setPhysicsBody(body);
    this->setPosition(origin.x+visibleSize.width/2, origin.y+visibleSize.height*0.6);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sfx_die.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sfx_hit.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sfx_point.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sfx_swooshing.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sfx_wing.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("effect.wav");
    
    
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(1);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sfx_wing.mp3",false, 1, 0, 1);
    

    return true;
}

BirdSprite* BirdSprite::create()
{
    BirdSprite* birdSprite = new BirdSprite();
    if(birdSprite && birdSprite->init())
    {
        birdSprite->autorelease();
        return birdSprite;
    }
    else
    {
        delete birdSprite;
        birdSprite = NULL;
        return NULL;
    }
}

void BirdSprite::StayIdle()
{
    this->getPhysicsBody()->setGravityEnable(false);
}
//点开始游戏时调用
void BirdSprite::PrepareToFly()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(1);
   // CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sfx_wing.mp3",true);
    this->getPhysicsBody()->setGravityEnable(true);
    auto animate = Animate::create(AnimationCache::getInstance()->getAnimation(BIRD_ANIMATION));
    this->runAction(RepeatForever::create(animate));
    //this->getPhysicsBody()->setVelocity(GRAVITY);

}
void BirdSprite::FlyUpward()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(1);

    //CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sfx_wing.mp3",false, 1, 0, 1);

    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sfx_wing.mp3",false, 1, 0, 1);
    this->getPhysicsBody()->setVelocity(VELOCITY);
}
//小鸟飞行状态，用来控制
void BirdSprite::SetFlyingDirection()
{
    this->setRotation(this->getPhysicsBody()->getVelocity().y*-0.1);
}

void BirdSprite::dying()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sfx_die.mp3",false, 1, 0, 1);
    this->getPhysicsBody()->setGravityEnable(true);
    this->setRotation(BIRD_DIE_ROTATION);
    this->stopAllActions();
    this->getPhysicsBody()->setContactTestBitmask(0);
}




















//end







