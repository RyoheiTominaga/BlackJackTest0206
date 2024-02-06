#pragma once

#include "common.h"

class Shoe;

class Person
{
private:
	char _name;
	int _hand[HAND_SIZE];	// ���_�ケ�ꂭ�炢���Ă�OK...�ɍ���͂����Ⴄ
	bool _calcUpdate;
	int _cardNum;
	int _score;

public:
	// �R���X�g���N�^
	Person(const char *name);
	//�f�X�g���N�^
	virtual ~Person();

	void copy(const Person& other);
	//�X�R�A�̎擾(hit���ꂽ���̂ݍČv�Z�����)
	int getScore();

	//�J�[�h�̒ǉ�
	void hit(Shoe shoe);

	//��D��\��
	void showHand();

	//�^�[������
	bool play(Shoe* shoe);

	//���O�\��
	void showName();

	

protected:
	void playBase(Shoe* shoe);	//�^�[�������{��

	
};

