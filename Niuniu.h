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

	bool isGreatNiuniu();//�O�_���׷�����(���aĹ�o5���m���A�`1��6)
	bool isCommonNiuniu();//�O�_������(���aĹ�o3���m���A�`1��4)
	bool isNiuniu7ToNiuniu9();//�O�_���j�I(���aĹ�o2���m���A�`1��3)
	bool isNiuniu1ToNiuniu6();//�O�_���p�I(���aĹ�o1���m���A�`1��2)
	bool isMaleOolong();//�O�_���a���Q�s(���aĹ�o1���m���A�`1��2)
	bool isNothing();//�O�_���Q�s(���a�鱼�`�X)   �Ƶ��G����a�P���a�����P���ŲյP�ɡA��������P���̤j�����i�C

	void printHowToPlay();//�������k
	void changeCard();//��j��10���P�令10
	int getPoint();//�p����I��
	int point();//�p��u�����I��
	void addCard(int);//�[�P
	void printCard();//�L�X�P��
	void printPoint();//�L�X�̲��I��
	void abaaba();//�d��
};

#endif