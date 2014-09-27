#ifndef __LAND_H__
#define __LAND_H__

#include "cocos2d.h"

class Land : public cocos2d::Layer
{
public:
   
    virtual bool init();  
    void move(float);//schedule_selector �������һ��float�͵Ĳ���
	void stop();
    
    CREATE_FUNC(Land);
private:
	cocos2d::Sprite* m_spriteland1;
	cocos2d::Sprite* m_spriteland2;
    cocos2d::EventListenerTouchOneByOne * _touchOneByOneListenr;
};

#endif // __LAND_H__
