#pragma once

#include "common.h"

class Shoe;

class Person
{
private:
	char _name;
	int _hand[HAND_SIZE];	// 理論上これくらい持てばOK...に今回はしちゃう
	bool _calcUpdate;
	int _cardNum;
	int _score;

public:
	// コンストラクタ
	Person(const char *name);
	//デストラクタ
	virtual ~Person();

	void copy(const Person& other);
	//スコアの取得(hitされた時のみ再計算される)
	int getScore();

	//カードの追加
	void hit(Shoe shoe);

	//手札を表示
	void showHand();

	//ターン処理
	bool play(Shoe* shoe);

	//名前表示
	void showName();

	

protected:
	void playBase(Shoe* shoe);	//ターン処理本体

	
};

