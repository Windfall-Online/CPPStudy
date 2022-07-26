#include <iostream>
using namespace std;

// ������ ���� : �ʱ�ȭ ����Ʈ

// ��� ���� �ʱ�ȭ ? �پ��� ������ ����

// �ʱ�ȭ �� �ұ�? ������
// - ���� ���濡 �߿�
// - ������ �� �ּҰ��� ����Ǿ� ���� ���

// �ʱ�ȭ ���
// - ������ ������
// - �ʱ�ȭ ����Ʈ
// - C++11 ����

// �ʱ�ȭ ����Ʈ
// - �ϴ� ��� ���迡�� ���ϴ� �θ� ������ ȣ���� �� �ʿ��ϴ�
// - ������ ������ �ʱ�ȭ vs �ʱ�ȭ ����Ʈ
// -- �Ϲ� ������ �� ���� ����
// -- ��� Ÿ���� Ŭ������ �� ���� �߻�
// -- �����԰� ���ÿ� �ʱ�ȭ�� �ʿ��� ��� (���� Ÿ��, const Ÿ��)

class Inventory
{
public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) { cout << "Inventory(int size)" << endl; _size = size; }

	~Inventory() { cout << "~Inventory()" << endl; }
public:
	int _size = 10;
};

class Player
{
public:

	Player() {}
	Player(int id){}

public:
};

// Is-A ���� (Knight Is-A Player?) ���� �÷��̾�� OK -> ���
// Is-A ���� (Knight Is-A Inventory?) ���� �κ��丮��? No -> ����

// Has-A ���� (Knight Has-A Inventory? ���� �κ��丮�� �����ϰ� �ִ� ���� �ִ�)
// OK -> ���� ����

class Knight : public Player
{
public:
	Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100)
		/*
		��ó�� ����
		Player�� �����ڸ� �˾Ƽ� ���������� ȣ��
		Inventory�� �⺻ �����ڰ� ���� ȣ��
		Inventory()
		*/
	{
		_hp = 100;
	}
public:

	int _hp;
	// �κ��丮�� ��ó�� �������� �������
	Inventory _inventory;

	int& _hpRef;
	const int _hpConst;
};

int main()
{
	Knight k;

	cout << k._hp << endl;
}