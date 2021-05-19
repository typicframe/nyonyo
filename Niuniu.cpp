#include"Niuniu.h"
#include"BetMoney.h"
#include"washCard.h"
#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;

int Niuniu::playTimes = 0;
Niuniu::Niuniu()
{
	for (int i = 0; i < size; i++)
		card[i] = getFinallyCard(i);
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < size - 1; i++)
			if (card[i] > card[i + 1])
			{
				int a = card[i];
				card[i] = card[i + 1];
				card[i + 1] = a;
			}
	}
}

bool Niuniu::isGreatNiuniu()
{
	int total = 0;
	for (int i = 0; i < Niuniu::size; i++)
		if (card[i] >= 10) total++;
	if (total == 5)
		return 1;
	else
		return 0;
}
bool Niuniu::isCommonNiuniu()
{
	if (point() % 10 == 0 && point() != 0 && isGreatNiuniu() == 0)
		return 1;
	else
		return 0;
}
bool Niuniu::isNiuniu7ToNiuniu9()
{
	if (point() <= 9 && point() >= 7)
		return 1;
	else
		return 0;
}
bool Niuniu::isNiuniu1ToNiuniu6()
{
	if (point() <= 6 && point() >= 1)
		return 1;
	else
		return 0;
}
bool Niuniu::isMaleOolong()
{
	if (point() == 0 && card[4] == 10 && isNothing() == 0)
		return 1;
	else
		return 0;
}
bool Niuniu::isNothing()
{
	int total = 0;
	for (int i = 0; i < Niuniu::size; i++)
		if (card[i] < 10) total++;
	if (point() == 0 && total == 5)
		return 1;
	else
		return 0;
}

void Niuniu::startToPlay()
{
	cout << "妞妞牌張介紹:" << endl;
	cout << "  妞妞一般使用一副撲克牌。" << endl;
	cout << "  牌面A=1點，2~9即為牌面點數，J、Q、K都算10點，又稱「公牌」。" << endl;
	cout << "  牌局中如果需要比大小，順序是A最小，接下來依序為2、3、4…10、J、Q、K。" << endl;
	cout << "  如果號碼相同可以比花色，原則是黑桃＞紅心＞方塊＞梅花(梅花Q＞紅心J、黑桃K＞黑桃K)。\n" << endl;
	cout << "遊戲規則:" << endl;
	cout << "1.妞妞桌上角色" << endl;
	cout << "  妞妞可以由數個人同時進行，由一人擔任莊家，其他人則是閒家。" << endl;
	cout << "  莊家可以由一人固定擔任，或是各人依序輪流擔任。" << endl;
	cout << "  每局的莊家與閒家確認後，首先由閒家下注，通常會規定最低注額與單局注額上限。" << endl;
	cout << "2.下注、派牌、比牌" << endl;
	cout << "  妞妞下注完畢後，按每人一張的方式發牌給莊家和各閒家，依序發至每人都有5張牌為止。" << endl;
	cout << "  每個人要將拿到的5張牌分拆成前2張與後3張的組合，每個閒家各自與莊家比大小，" << endl;
	cout << "  輸牌便損失注金，如果贏牌便可以向莊家索取規定倍數的彩金。" << endl;
	cout << "3.妞妞組牌與點數" << endl;
	cout << "  妞妞點數合計為10的倍數就是「妞」，組牌的優先原則是後三張牌的點數必須合計為10的倍數，稱為「有妞」，" << endl;
	cout << "  此時可將前2張牌的點數相加，取其個位數即為這手牌的點數。前2張牌正好也是10的倍數便是「妞妞」，" << endl;
	cout << "  如果5張手牌全部都是公牌稱為「至尊」或「五公」(部分博弈網站稱其為終極妞妞)。反之，如果5張手牌任取3張都無法組成妞，" << endl;
	cout << "  就是「烏龍」。\n" << endl;
	cout << "是否開始遊戲??是(請輸入Y)否(請輸入N) ";
	char YorN;
	cin >> YorN;
	while (1)
	{
		if (YorN == 'Y')
		{
			cout << "開始遊戲\n\n";
			Niuniu aaaaa;
			aaaaa.kkkkk(); int playerMoney, total = 0;
			cout << "請輸入你的賭金(不玩請輸入-1): ";
			cin >> playerMoney;
			while (playerMoney != -1)
			{
				BetMoney c(playerMoney);
				c.isMoneyBigThanZero();
				if (c.IsMoneyBigThanZero())
				{
					cout << "你的牌是:\n";
					Niuniu player;
					player.printWashCard();
					player.printPoint();

					Sleep(1000);
					cout << "莊家的牌是:\n";
					Niuniu computer;
					computer.printWashCard();
					computer.printPoint();
					if (c.winOrLostMoney() < 0)
					{
						cout << "你輸了" << -c.winOrLostMoney() << "元" << endl;
						total += c.winOrLostMoney();
					}
					else if (player.point() < computer.point())
					{
						cout << "你輸了" << c.winOrLostMoney() << "元" << endl;
						total += -c.winOrLostMoney();
					}
					else
					{
						cout << "你贏了" << c.winOrLostMoney() << "元" << endl;
						total += c.winOrLostMoney();
					}
					Sleep(1000);
					(total > 0 ? cout << "目前贏了: " << total << "元\n" : cout << "目前輸了: " << -total << "元\n");
					cout << "\n請輸入你的賭金(不玩請輸入-1): ";
					cin >> playerMoney;
				}
				else
				{
					cout << "\n請輸入你的賭金(不玩請輸入-1): ";
					cin >> playerMoney;
					continue;
				}
			}
			(total >= 0 ? cout << "恭喜你贏了 " << total << "元\n" : cout << "哈哈哈你輸了" << -total << "元\n");
			break;
		}
		else if (YorN == 'N')
		{
			cout << "再見了您咧!!!\n\n";
			break;
		}
		else
		{
			cout << "請輸入正確!!!\n\n";
			cout << "是否開始遊戲??是(請輸入Y)否(請輸入N) ";
			cin >> YorN;
		}
	}
}
void Niuniu::changeCard()
{
	for (int i = 0; i < Niuniu::size; i++)
		if (card[i] > 10)
			card[i] = 10;
}
int Niuniu::getPoint()
{
	changeCard();

	if ((card[0] + card[1] + card[2]) % 10 == 0)
		return card[3] + card[4];
	else if ((card[0] + card[2] + card[3]) % 10 == 0)
		return card[1] + card[4];
	else if ((card[0] + card[3] + card[4]) % 10 == 0)
		return card[1] + card[2];
	else if ((card[0] + card[1] + card[3]) % 10 == 0)
		return card[2] + card[4];
	else if ((card[0] + card[1] + card[4]) % 10 == 0)
		return card[2] + card[3];
	else if ((card[0] + card[2] + card[4]) % 10 == 0)
		return card[1] + card[3];
	else if ((card[1] + card[2] + card[3]) % 10 == 0)
		return card[0] + card[4];
	else if ((card[1] + card[3] + card[4]) % 10 == 0)
		return card[0] + card[2];
	else if ((card[1] + card[2] + card[4]) % 10 == 0)
		return card[0] + card[3];
	else if ((card[2] + card[3] + card[4]) % 10 == 0)
		return card[0] + card[1];
	else
		return 0;
}
void Niuniu::addCard(int userCard)
{
	card[index] = userCard;
	index++;
}
void Niuniu::printCard()
{
	for (int i = 0; i < Niuniu::size; i++)
		cout << card[i] << " ";
	cout << endl;
}
int Niuniu::point()
{
	int point = getPoint();
	if (point % 10 == 0 && point != 0)
		return 10;
	else
	{
		while (true)
			{
				point = getPoint() % 10;
				if (point < 10)
					break;
			}
			return point;
	}
}
void Niuniu::printPoint()
{
	//cout << "原來的牌是: ";
	//printCard();
	changeCard();
	//cout << "後來的牌是: ";
	//printCard();
	playTimes++;
	(playTimes % 2 == 0 ? cout << "    莊家的分數是: " << point() << " 分\n\n" : cout << "    你的分數是: " << point() << " 分\n\n");
}
void Niuniu::abaaba()
{
	const int userSize = 5;
	int a[userSize] = { 2,8,10,11,12 };
	int b[userSize] = { 1,2,3,4,5 };
	int c[userSize] = { 2,2,7,9,11 };
	int d[userSize] = { 10,10,10,11,12 };
	int e[userSize] = { 1,4,5,9,9 };
	int f[userSize] = { 1,1,1,1,2 };
	Niuniu userNiuniu, comNiuniu, bookmakerNiuniu, ab, cd, ef;
	for (int i = 0; i < userSize; i++)
		userNiuniu.addCard(a[i]);
	for (int i = 0; i < userSize; i++)
		comNiuniu.addCard(b[i]);
	for (int i = 0; i < userSize; i++)
		bookmakerNiuniu.addCard(c[i]);
	for (int i = 0; i < userSize; i++)
		ab.addCard(d[i]);
	for (int i = 0; i < userSize; i++)
		cd.addCard(e[i]);
	for (int i = 0; i < userSize; i++)
		ef.addCard(f[i]);
	userNiuniu.printPoint();
	cout << "是否為終極妞妞 " << userNiuniu.isGreatNiuniu() << endl;
	cout << "是否為妞妞 " << userNiuniu.isCommonNiuniu() << endl;
	cout << "是否為大點 " << userNiuniu.isNiuniu7ToNiuniu9() << endl;
	cout << "是否為小點 " << userNiuniu.isNiuniu1ToNiuniu6() << endl;
	cout << "是否為帶公烏龍 " << userNiuniu.isMaleOolong() << endl;
	cout << "是否為烏龍 " << userNiuniu.isNothing() << endl << endl;
	comNiuniu.printPoint();
	cout << "是否為終極妞妞 " << comNiuniu.isGreatNiuniu() << endl;
	cout << "是否為妞妞 " << comNiuniu.isCommonNiuniu() << endl;
	cout << "是否為大點 " << comNiuniu.isNiuniu7ToNiuniu9() << endl;
	cout << "是否為小點 " << comNiuniu.isNiuniu1ToNiuniu6() << endl;
	cout << "是否為帶公烏龍 " << comNiuniu.isMaleOolong() << endl;
	cout << "是否為烏龍 " << comNiuniu.isNothing() << endl << endl;
	bookmakerNiuniu.printPoint();
	cout << "是否為終極妞妞 " << bookmakerNiuniu.isGreatNiuniu() << endl;
	cout << "是否為妞妞 " << bookmakerNiuniu.isCommonNiuniu() << endl;
	cout << "是否為大點 " << bookmakerNiuniu.isNiuniu7ToNiuniu9() << endl;
	cout << "是否為小點 " << bookmakerNiuniu.isNiuniu1ToNiuniu6() << endl;
	cout << "是否為帶公烏龍 " << bookmakerNiuniu.isMaleOolong() << endl;
	cout << "是否為烏龍 " << bookmakerNiuniu.isNothing() << endl << endl;
	ab.printPoint();
	cout << "是否為終極妞妞 " << ab.isGreatNiuniu() << endl;
	cout << "是否為妞妞 " << ab.isCommonNiuniu() << endl;
	cout << "是否為大點 " << ab.isNiuniu7ToNiuniu9() << endl;
	cout << "是否為小點 " << ab.isNiuniu1ToNiuniu6() << endl;
	cout << "是否為帶公烏龍 " << ab.isMaleOolong() << endl;
	cout << "是否為烏龍 " << ab.isNothing() << endl << endl;
	cd.printPoint();
	cout << "是否為終極妞妞 " << cd.isGreatNiuniu() << endl;
	cout << "是否為妞妞 " << cd.isCommonNiuniu() << endl;
	cout << "是否為大點 " << cd.isNiuniu7ToNiuniu9() << endl;
	cout << "是否為小點 " << cd.isNiuniu1ToNiuniu6() << endl;
	cout << "是否為帶公烏龍 " << cd.isMaleOolong() << endl;
	cout << "是否為烏龍 " << cd.isNothing() << endl << endl;
	ef.printPoint();
	cout << "是否為終極妞妞 " << ef.isGreatNiuniu() << endl;
	cout << "是否為妞妞 " << ef.isCommonNiuniu() << endl;
	cout << "是否為大點 " << ef.isNiuniu7ToNiuniu9() << endl;
	cout << "是否為小點 " << ef.isNiuniu1ToNiuniu6() << endl;
	cout << "是否為帶公烏龍 " << ef.isMaleOolong() << endl;
	cout << "是否為烏龍 " << ef.isNothing() << endl << endl;
}
void Niuniu::kkkkk()
{
	for (int i = 0; i < 101; i++)
	{
		int a = i;
		if (a % 4 == 0)
			cout << "遊戲加載中.   ";
		else if (a % 4 == 1)
			cout << "遊戲加載中..  ";
		else
			cout << "遊戲加載中... ";
		cout << setw(5) << i << "%" << "\r";
		Sleep(250);
	}
	cout << "\n遊戲加載成功請開始你的遊戲\n\n";
}