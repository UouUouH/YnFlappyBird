#ifndef _LandSprite_
#define _LandSprite_

#include "cocos2d.h"
USING_NS_CC;

class LandSprite :
	public cocos2d::Sprite
{
public:
	//n : ����ƫ��Զ��ľ������Լ�content�Ŀ�ȵļ���
	bool init(float n);
	//n : ����ƫ��Զ��ľ������Լ�content�Ŀ�ȵļ���
	static LandSprite* create(float n);
};

#endif //_LandSprite_