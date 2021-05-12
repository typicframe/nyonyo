#ifndef NIUNIU_H
#define NIUNIU_H

#include<string>
using namespace std;

class Niuniu
{
private:
	int index = 0, size = 5;
	int card[5];
public:
	Niuniu();

	bool isGreatNiuniu();//是否為終極妞妞(閒家贏得5倍彩金，注1賠6)
	bool isCommonNiuniu();//是否為妞妞(閒家贏得3倍彩金，注1賠4)
	bool isNiuniu7ToNiuniu9();//是否為大點(閒家贏得2倍彩金，注1賠3)
	bool isNiuniu1ToNiuniu6();//是否為小點(閒家贏得1倍彩金，注1賠2)
	bool isMaleOolong();//是否為帶公烏龍(閒家贏得1倍彩金，注1賠2)
	bool isNothing();//是否為烏龍(閒家輸掉注碼)   備註：當莊家與閒家持有同等級組牌時，比較雙方手牌中最大的那張。

	void printHowToPlay();//解釋玩法
	void changeCard();//把大於10的牌改成10
	int getPoint();//計算原點數
	int point();//計算真正的點數
	void addCard(int);//加牌
	void printCard();//印出牌組
	void printPoint();//印出最終點數
	void abaaba();//範例
};

#endif