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
	cout << "�����P�i����:" << endl;
	cout << "  �����@��ϥΤ@�Ƽ��J�P�C" << endl;
	cout << "  �P��A=1�I�A2~9�Y���P���I�ơAJ�BQ�BK����10�I�A�S�١u���P�v�C" << endl;
	cout << "  �P�����p�G�ݭn��j�p�A���ǬOA�̤p�A���U�Ө̧Ǭ�2�B3�B4�K10�BJ�BQ�BK�C" << endl;
	cout << "  �p�G���X�ۦP�i�H����A��h�O�®�֬��ߡ֤���ֱ���(����Q�֬���J�B�®�K�ֶ®�K)�C\n" << endl;
	cout << "�C���W�h:" << endl;
	cout << "1.������W����" << endl;
	cout << "  �����i�H�ѼƭӤH�P�ɶi��A�Ѥ@�H������a�A��L�H�h�O���a�C" << endl;
	cout << "  ���a�i�H�Ѥ@�H�T�w����A�άO�U�H�̧ǽ��y����C" << endl;
	cout << "  �C�������a�P���a�T�{��A�����Ѷ��a�U�`�A�q�`�|�W�w�̧C�`�B�P�槽�`�B�W���C" << endl;
	cout << "2.�U�`�B���P�B��P" << endl;
	cout << "  �����U�`������A���C�H�@�i���覡�o�P�����a�M�U���a�A�̧ǵo�ܨC�H����5�i�P����C" << endl;
	cout << "  �C�ӤH�n�N���쪺5�i�P����e2�i�P��3�i���զX�A�C�Ӷ��a�U�ۻP���a��j�p�A" << endl;
	cout << "  ��P�K�l���`���A�p�GĹ�P�K�i�H�V���a�����W�w���ƪ��m���C" << endl;
	cout << "3.�����յP�P�I��" << endl;
	cout << "  �����I�ƦX�p��10�����ƴN�O�u���v�A�յP���u����h�O��T�i�P���I�ƥ����X�p��10�����ơA�٬��u�����v�A" << endl;
	cout << "  ���ɥi�N�e2�i�P���I�Ƭۥ[�A����Ӧ�ƧY���o��P���I�ơC�e2�i�P���n�]�O10�����ƫK�O�u�����v�A" << endl;
	cout << "  �p�G5�i��P�������O���P�٬��u�ܴL�v�Ρu�����v(�����իٺ����٨䬰�׷�����)�C�Ϥ��A�p�G5�i��P����3�i���L�k�զ����A" << endl;
	cout << "  �N�O�u�Q�s�v�C\n" << endl;
	cout << "�O�_�}�l�C��??�O(�п�JY)�_(�п�JN) ";
	char YorN;
	cin >> YorN;
	while (1)
	{
		if (YorN == 'Y')
		{
			cout << "�}�l�C��\n\n";
			Niuniu aaaaa;
			aaaaa.kkkkk(); int playerMoney, total = 0;
			cout << "�п�J�A�����(�����п�J-1): ";
			cin >> playerMoney;
			while (playerMoney != -1)
			{
				BetMoney c(playerMoney);
				c.isMoneyBigThanZero();
				if (c.IsMoneyBigThanZero())
				{
					cout << "�A���P�O:\n";
					Niuniu player;
					player.printWashCard();
					player.printPoint();

					Sleep(1000);
					cout << "���a���P�O:\n";
					Niuniu computer;
					computer.printWashCard();
					computer.printPoint();
					if (c.winOrLostMoney() < 0)
					{
						cout << "�A��F" << -c.winOrLostMoney() << "��" << endl;
						total += c.winOrLostMoney();
					}
					else if (player.point() < computer.point())
					{
						cout << "�A��F" << c.winOrLostMoney() << "��" << endl;
						total += -c.winOrLostMoney();
					}
					else
					{
						cout << "�AĹ�F" << c.winOrLostMoney() << "��" << endl;
						total += c.winOrLostMoney();
					}
					Sleep(1000);
					(total > 0 ? cout << "�ثeĹ�F: " << total << "��\n" : cout << "�ثe��F: " << -total << "��\n");
					cout << "\n�п�J�A�����(�����п�J-1): ";
					cin >> playerMoney;
				}
				else
				{
					cout << "\n�п�J�A�����(�����п�J-1): ";
					cin >> playerMoney;
					continue;
				}
			}
			(total >= 0 ? cout << "���ߧAĹ�F " << total << "��\n" : cout << "�������A��F" << -total << "��\n");
			break;
		}
		else if (YorN == 'N')
		{
			cout << "�A���F�z��!!!\n\n";
			break;
		}
		else
		{
			cout << "�п�J���T!!!\n\n";
			cout << "�O�_�}�l�C��??�O(�п�JY)�_(�п�JN) ";
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
	//cout << "��Ӫ��P�O: ";
	//printCard();
	changeCard();
	//cout << "��Ӫ��P�O: ";
	//printCard();
	playTimes++;
	(playTimes % 2 == 0 ? cout << "    ���a�����ƬO: " << point() << " ��\n\n" : cout << "    �A�����ƬO: " << point() << " ��\n\n");
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
	cout << "�O�_���׷����� " << userNiuniu.isGreatNiuniu() << endl;
	cout << "�O�_������ " << userNiuniu.isCommonNiuniu() << endl;
	cout << "�O�_���j�I " << userNiuniu.isNiuniu7ToNiuniu9() << endl;
	cout << "�O�_���p�I " << userNiuniu.isNiuniu1ToNiuniu6() << endl;
	cout << "�O�_���a���Q�s " << userNiuniu.isMaleOolong() << endl;
	cout << "�O�_���Q�s " << userNiuniu.isNothing() << endl << endl;
	comNiuniu.printPoint();
	cout << "�O�_���׷����� " << comNiuniu.isGreatNiuniu() << endl;
	cout << "�O�_������ " << comNiuniu.isCommonNiuniu() << endl;
	cout << "�O�_���j�I " << comNiuniu.isNiuniu7ToNiuniu9() << endl;
	cout << "�O�_���p�I " << comNiuniu.isNiuniu1ToNiuniu6() << endl;
	cout << "�O�_���a���Q�s " << comNiuniu.isMaleOolong() << endl;
	cout << "�O�_���Q�s " << comNiuniu.isNothing() << endl << endl;
	bookmakerNiuniu.printPoint();
	cout << "�O�_���׷����� " << bookmakerNiuniu.isGreatNiuniu() << endl;
	cout << "�O�_������ " << bookmakerNiuniu.isCommonNiuniu() << endl;
	cout << "�O�_���j�I " << bookmakerNiuniu.isNiuniu7ToNiuniu9() << endl;
	cout << "�O�_���p�I " << bookmakerNiuniu.isNiuniu1ToNiuniu6() << endl;
	cout << "�O�_���a���Q�s " << bookmakerNiuniu.isMaleOolong() << endl;
	cout << "�O�_���Q�s " << bookmakerNiuniu.isNothing() << endl << endl;
	ab.printPoint();
	cout << "�O�_���׷����� " << ab.isGreatNiuniu() << endl;
	cout << "�O�_������ " << ab.isCommonNiuniu() << endl;
	cout << "�O�_���j�I " << ab.isNiuniu7ToNiuniu9() << endl;
	cout << "�O�_���p�I " << ab.isNiuniu1ToNiuniu6() << endl;
	cout << "�O�_���a���Q�s " << ab.isMaleOolong() << endl;
	cout << "�O�_���Q�s " << ab.isNothing() << endl << endl;
	cd.printPoint();
	cout << "�O�_���׷����� " << cd.isGreatNiuniu() << endl;
	cout << "�O�_������ " << cd.isCommonNiuniu() << endl;
	cout << "�O�_���j�I " << cd.isNiuniu7ToNiuniu9() << endl;
	cout << "�O�_���p�I " << cd.isNiuniu1ToNiuniu6() << endl;
	cout << "�O�_���a���Q�s " << cd.isMaleOolong() << endl;
	cout << "�O�_���Q�s " << cd.isNothing() << endl << endl;
	ef.printPoint();
	cout << "�O�_���׷����� " << ef.isGreatNiuniu() << endl;
	cout << "�O�_������ " << ef.isCommonNiuniu() << endl;
	cout << "�O�_���j�I " << ef.isNiuniu7ToNiuniu9() << endl;
	cout << "�O�_���p�I " << ef.isNiuniu1ToNiuniu6() << endl;
	cout << "�O�_���a���Q�s " << ef.isMaleOolong() << endl;
	cout << "�O�_���Q�s " << ef.isNothing() << endl << endl;
}
void Niuniu::kkkkk()
{
	for (int i = 0; i < 101; i++)
	{
		int a = i;
		if (a % 4 == 0)
			cout << "�C���[����.   ";
		else if (a % 4 == 1)
			cout << "�C���[����..  ";
		else
			cout << "�C���[����... ";
		cout << setw(5) << i << "%" << "\r";
		Sleep(250);
	}
	cout << "\n�C���[�����\�ж}�l�A���C��\n\n";
}