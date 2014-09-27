#ifndef _GUIDERLAYER_
#define _GUIDERLAYER_

#include "cocos2d.h"

class GuiderLayer : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    virtual void onEnter() override;
    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GuiderLayer);
private:
    cocos2d::EventListenerTouchOneByOne* _touchOneByeOne;
};

#endif // __HELP_SCENE_H__
