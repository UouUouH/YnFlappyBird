#ifndef __GAMERUNNING_SCENE_H__
#define __GAMERUNNING_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();


    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
    //virtual void onEnter() override;
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
	
};

#endif // __GAMERUNNING_SCENE_H__
