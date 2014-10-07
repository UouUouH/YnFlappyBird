#include "GameOver.h"
#include "cocos2d.h"
#include "define.h"
#include "GuiderLayer.h"
#include "Score.h"
USING_NS_CC;

bool Scoreboard::init()
{
	_tempScore = 0;
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//score board
	auto scoreboard = Sprite::createWithSpriteFrameName("score_panel.png");

	this->setPosition(origin.x+visibleSize.width/2, origin.y-scoreboard->getContentSize().height/2);

	scoreboard->setPosition(origin.x+visibleSize.width/2-this->getPositionX(), origin.y-scoreboard->getContentSize().height/2-this->getPositionY());
	this->addChild(scoreboard);


	//metal
	int score = getScore();
	Sprite* metal = NULL;
	if(score < COPPER_MEDAL)
	{
		metal = Sprite::createWithSpriteFrameName("medals_2.png");
	}
	else if(score < SILVER_MEDAL)
	{
		metal = Sprite::createWithSpriteFrameName("medals_3.png");
	}
	else if(score < SILVER_MEDAL)
	{
		metal = Sprite::createWithSpriteFrameName("medals_0.png");
	}
	else 
	{
		metal = Sprite::createWithSpriteFrameName("medals_1.png");
	}
	metal->setPosition(scoreboard->getPositionX()-65, scoreboard->getPositionY()-4);
	this->addChild(metal);

	//score
	auto strScore = __String::createWithFormat("%d",score);
	_scoreLabel = Label::createWithBMFont("font2.fnt",strScore->getCString());
	_scoreLabel->setPosition(scoreboard->getPositionX()+70, scoreboard->getPositionY()+10);
	this->addChild(_scoreLabel);
	if(score > 0)
	{
		this->schedule(schedule_selector(Scoreboard::addScoreAnimation),ADDSCORE_FRE);
	}

	// best score
	int topScore = this->getTopScore();
	if(topScore < score)
	{
		auto newTopScore = Sprite::createWithSpriteFrameName("new.png");
		newTopScore->setPosition(scoreboard->getPositionX()+35, scoreboard->getPositionY()-5);
		this->addChild(newTopScore);
		this->SaveTopScore(score);
		topScore = score;
	}
	auto strTopScore = __String::createWithFormat("%d",topScore);
	auto topScoreLabel = Label::createWithBMFont("font2.fnt",strTopScore->getCString());
	topScoreLabel->setPosition(scoreboard->getPositionX()+70, scoreboard->getPositionY()-30);
	this->addChild(topScoreLabel);
	
	return true;
}
void Scoreboard::SaveTopScore(int n)
{
	TopScore::getInstance()->SaveTopScore(n);
}
int Scoreboard::getScore()
{
	return Score::getInstance()->getScore();
}
int Scoreboard::getTopScore()
{
	return TopScore::getInstance()->getTopScore();
}
void Scoreboard::addScoreAnimation(float)
{
	auto str = __String::createWithFormat("%d",_tempScore);
	_scoreLabel->setString(str->getCString());
	if(_tempScore == this->getScore())
	{
		this->unschedule(schedule_selector(Scoreboard::addScoreAnimation));
	}
	_tempScore++;
}


//----------------game over--------------------------

bool GameOver::init()
{
	
  //  this->schedule(schedule_selector(Land::moveLand ), LAND_VELOCITY);
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//1 game over logo
	auto gameOverLogo = Sprite::createWithSpriteFrameName("text_game_over.png");
	gameOverLogo->setPosition(origin.x+visibleSize.width/2, origin.y+visibleSize.height*4/5);
	this->addChild(gameOverLogo);

	//2 scoreboard
	auto scoreboard = Scoreboard::create();
//	scoreboard->setPosition(origin.x+visibleSize.width/2, origin.y);
	this->addChild(scoreboard);
	float xx = scoreboard->getPositionX();
	auto scoreboardMoveto = MoveTo::create(SCOREBORD_TIME,Point(scoreboard->getPositionX(), origin.y+visibleSize.height/2));
	auto scoreboardMoveOver = CallFuncN::create(CC_CALLBACK_0(GameOver::createMenu,this));
	auto scoreboardActionSequence = Sequence::create(scoreboardMoveto, scoreboardMoveOver,NULL);
	scoreboard->runAction(scoreboardActionSequence);

	return true;
}
void GameOver::playAgain()
{
	Director::getInstance()->replaceScene(TransitionFade::create(CHANGESCENE_TIME,GuiderLayer::createScene()));
}
void GameOver::GetRank()
{
	log("get rank");
}
void GameOver::createMenu()
{
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto playAgainSprite = Sprite::createWithSpriteFrameName("button_play.png");
	auto playAgainMenu = MenuItemSprite::create(playAgainSprite,playAgainSprite,CC_CALLBACK_0(GameOver::playAgain,this));

	auto getRankSprite = Sprite::createWithSpriteFrameName("button_score.png");
	auto getRankMenu = MenuItemSprite::create(getRankSprite,getRankSprite,CC_CALLBACK_0(GameOver::GetRank,this));

	int intervalWidth = (visibleSize.width - playAgainSprite->getContentSize().width -  getRankSprite->getContentSize().width)/3;
	playAgainMenu->setPosition(origin.x+intervalWidth+playAgainSprite->getContentSize().width/2, origin.y + visibleSize.height*0.27);
	getRankMenu->setPosition(origin.x+intervalWidth*2+playAgainSprite->getContentSize().width + getRankSprite->getContentSize().width/2, origin.y + visibleSize.height*0.27);

	auto menu = Menu::create(playAgainMenu, getRankMenu, NULL);
	menu->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);

}