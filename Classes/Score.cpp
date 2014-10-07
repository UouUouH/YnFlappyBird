#include "Score.h"
USING_NS_CC;


static Score* scoreInstance = NULL;

Score* Score::getInstance()
{
	if(scoreInstance == NULL)
	{
		scoreInstance = new Score();
		scoreInstance->init();
	}
	return scoreInstance;
}
bool Score::init()
{
	auto origin=Director::getInstance()->getVisibleOrigin();
	auto visibleSize=Director::getInstance()->getVisibleSize();

	

	auto str = __String::createWithFormat("%d",0);
	this->_scoreLabel = Label::createWithBMFont("font1.fnt",str->getCString());
	//this->setPosition(origin.x+visibleSize.width/2,origin.y+visibleSize.height*0.85);
	this->_scoreLabel->setPosition(origin.x+visibleSize.width/2,origin.y+visibleSize.height*0.85);
	this->addChild(_scoreLabel);

	this->initScore();
	return true;
}
void Score::initScore()
{
	_score = 0;
	auto str = __String::createWithFormat("%d",_score);
	_scoreLabel->setString(str->getCString());
}
void Score::addScore()
{
	_score++;
	auto str = __String::createWithFormat("%d",_score);
	_scoreLabel->setString(str->getCString());
}
int Score::getScore()
{
	return _score;
}


//-----------------top score------------------------
static TopScore* topScoreInstance = NULL;
TopScore* TopScore::getInstance()
{
	if(topScoreInstance == NULL)
	{
		topScoreInstance = new TopScore();
		topScoreInstance->initTopScoreFile();
	}
	return topScoreInstance;
}
void TopScore::SaveTopScore(int topScore)
{
	UserDefault::getInstance()->setIntegerForKey("topScore",topScore);
	UserDefault::getInstance()->flush();
}
int TopScore::getTopScore()
{
	int n = UserDefault::getInstance()->getIntegerForKey("topScore");
	return n;
}
void TopScore::initTopScoreFile()
{
	if(UserDefault::getInstance()->getBoolForKey("isTopScoreFileExist"))
	{
		return ;
	}
	else
	{
		UserDefault::getInstance()->setBoolForKey("isTopScoreFileExist",true);
		UserDefault::getInstance()->setIntegerForKey("topScore",0);
		UserDefault::getInstance()->flush();
		return ;
	}
}









//end







