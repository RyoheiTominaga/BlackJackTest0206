#include <iostream> //入出力
#include <iomanip>
#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//
// 試験用ブラックジャックソース
// 正常動作していない。
//

enum PERSON
{
	DEALER, PLAYER, PLAYER2,PLAYER3
};
Person* persons[] = { new Dealer("Dealer"),new Player("tomi"),new Player("ryo"),new Player("tomiRyo")};
const int num = sizeof(persons) / sizeof(Person*);
// ★★★★★★★★★★★★★★★★
void showCardInformation(Person**p) {
	cout << left << endl;
	for (int i = 0;i < num;++i) {
		cout << setw(15) << "============";
		cout << "";
	}
	cout << endl;
	for (int i = 0;i < num;++i) {

		cout << setw(15);p[i]->showName();
		
	}
	for (int i = 0;i < num;++i) {
		cout << setw(15); p[i]->showHand();
		
	}
	cout << endl;
	for (int i = 0;i < num;++i) {
		cout << setw(15) << "============";
		cout << "";
	}
}

static void showResult(Person** p)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	cout << "============================" << endl;
	for (int i = 1;i < num;++i) {
		p[i]->showName();
		cout << endl;
		p[i]->showHand();
	}
	/*cout << "player" << endl;
	p[0]->showHand();*/
	cout << "============================" << endl;
	cout << "dealer" << endl;
	p[0]->showHand();
	cout << "============================" << endl;

	for (int i = 1;i < num;++i) {
		if (p[i]->getScore() > p[0]->getScore()) {
			p[i]->showName();
			cout << "Win!" << endl;
		}
		else if (p[i]->getScore() < p[0]->getScore()) {
			p[i]->showName();
			cout << "Lose" << endl;
		}
		else {
			p[i]->showName();
			cout << "Push" << endl;
		}
	}
}

static void showHand(Person* p,int i)
{
	//手札の表示
	cout << "====================" << endl;
	p[i].showName();
	cout << endl;
	p[i].showHand();
	cout << "====================" << endl;
}

//メイン関数
int main() {

	int sNum = 0;//バーストしていない人数
	srand((unsigned int)time(NULL));

	

	//各オブジェクトの生成
	Shoe shoe;
	

	//----カードの配布 ... 初期
	cout << "====================" << endl;
	for (int i = 0; i < num; i++)
	{
		persons[i]->hit(shoe);
		showHand(persons[i], i);
	}
	//プレイヤーに2枚目を配布
	for (int i = 1;i < num;++i) {
		persons[i]->hit(shoe);
		showHand(persons[i], i);
	}
	//ディーラーに2枚目を配布
	
	persons[DEALER]->hit(shoe);


	// ----　勝負開始
	//プレイヤーの実行
	//バーストしているかどうか判別
	for (int i = 1;i < num;++i) {
		if (persons[i]->play(&shoe)) {
			//バーストせずstandした
			sNum++;

		}
	}
	if (sNum > 0) {
		//ディーラーの手札を表示
		showHand(persons[DEALER], DEALER);

		//ディーラーの自動実行
		persons[DEALER]->play(&shoe);

		//結果の表示
		showResult(persons);
	}

	else {
			cout << "Burst Players Lose" << endl;
		 }
		cout << "====================" << endl;
		return 0;
	
}