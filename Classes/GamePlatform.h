#ifndef _GAMEPLATFORM_
#define _GAMEPLATFORM_

#include "cocos2d.h"

class GamePlatform : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual void onEnter() override;
   
 
    virtual bool init();
   // void moveLand(float);//schedule_selector 必须包含一个float型的参数
	//void stopLandMove();
    
    CREATE_FUNC(GamePlatform);
	bool onContactBegin(cocos2d::PhysicsContact& contact);
	void gameOver();

private:
	//cocos2d::Sprite* _spriteland1;
	//cocos2d::Sprite* _spriteland2;
    cocos2d::Sprite* _spriteBird;
    cocos2d::Layer* _pipeLayer;
	cocos2d::Node* _landLayer;
    cocos2d::EventListenerTouchOneByOne * _touchOneByOneListenr;
	cocos2d::EventListenerPhysicsContact* _contactListener;
   
};

#endif // __LAND_H__
