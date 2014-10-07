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


class Land : public cocos2d::Node
{
public:
	virtual bool init();
	void moveLand(float);
	void stopLandMove();
	CREATE_FUNC(Land);
	private:
	cocos2d::Sprite* _spriteland1;
	cocos2d::Sprite* _spriteland2;
};

#endif //_LandSprite_