#ifndef _GAMEPLATFORM_
#define _GAMEPLATFORM_

#include "cocos2d.h"

class GamePlatform : public cocos2d::Layer
{
public:
   
    virtual void onEnter() override;
   
    static GamePlatform* getInstance();
     virtual bool init();
    void move(float);//schedule_selector 必须包含一个float型的参数
	void stop();
    
    CREATE_FUNC(GamePlatform);


private:
	cocos2d::Sprite* _spriteland1;
	cocos2d::Sprite* _spriteland2;
    cocos2d::Sprite* _spriteBird;
    cocos2d::EventListenerTouchOneByOne * _touchOneByOneListenr;
    
   
};

#endif // __LAND_H__
