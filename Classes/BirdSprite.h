#ifndef _BirdSprite_
#define _BirdSprite_
#include "cocos2d.h"
USING_NS_CC;

class BirdSprite :
	public cocos2d::Sprite
{
public:

    static BirdSprite* getInstance();
	bool init();
	static BirdSprite* create();
    void PrepareToFly();
    void StayIdle();
    //设置飞行时小鸟的头的方向
    void SetFlyingDirection();
    void dying();
    //每次点击屏幕后向上飞行一下
    void FlyUpward();
};

#endif