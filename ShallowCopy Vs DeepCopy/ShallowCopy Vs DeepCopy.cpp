#include <iostream>
using namespace std;

// ������ ���� : ���� ���� vs ���� ����

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	~Pet()
	{
		cout << "~Pet()" << endl;
	}
	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
	Pet& operator=(const Pet& pet)
	{
		cout << "operator=(const Pet& pet)" << endl;
		return *this;
	}
};

class RabbitPet : public Pet
{

};

class TurtlePet : public Pet
{

};

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}
	// ���� ������
	Player(const Player& player)
	{
		cout << "Player(const Player& player)" << endl;
		_level = player._level;
	}
	// ���� ���� ������
	Player& operator=(const Player& player)
	{
		cout << "operator=(const Player& player)" << endl;
		_level = player._level;
		return *this;
	}
public:
	int _level = 0;
};

class Knight : public Player
{
public:
	Knight()
	{
		//_pet = new Pet();
	}

	Knight(const Knight& knight) : Player(knight), _pet(knight._pet)
	{
		cout << "Knight(const Knight& knight)" << endl;
		_hp = knight._hp;
		//_pet = new Pet(*knight._pet);   // ���� ����
	}

	Knight& operator=(const Knight& knight)
	{

		cout << "operator=(const Knight& knight)" << endl;
		Player::operator=(knight);
		_hp = knight._hp;
		//_pet = new Pet(*knight._pet);   // ���� ����
		_pet = knight._pet;
		return *this;
	}

	~Knight()
	{
		//delete _pet;
	}
public:
	int _hp = 100;
	Pet _pet;

};

int main()
{
	//Pet* pet = new Pet();

	Knight knight; // �⺻ ������
	knight._hp = 200;
	knight._level = 99;
	//knight._pet = pet;

	//cout << "-------- ���� ������--------" << endl;
	//Knight knight2 = knight; // ���� ������
	////Knight knight3(knight);

	
	Knight knight3; // �⺻ ������
	cout << "-------- ���� ���� ������--------" << endl;
	knight3 = knight; // ���� ���� ������

	// [���� ������] + [���� ���� ������]
	// �� �� �ȸ�����ָ� �����Ϸ��� '�Ͻ�������' ������ش�

	// �߰� ���) �����Ϸ��� �˾Ƽ� �� ������ش�?
	// �����ϼ���~ ���� ������ �Ѿ���?/ << NO

	// [���� ���� Shallow Copy]
	// ��� �����͸� ��v�� ������ '�Ȱ���' ���� (�޸� ���� ���� �״�� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> �ּҰ��� �Ȱ��� ���� -> ������ ��ü�� ����Ű�� ���°� ��
	// Stack : Knight1 [ hp 0x1000 ] -> Heap 0x1000 Pet [	]
	// Stack : Knight2 [ hp 0x1000 ] 
	// Stack : Knight3 [ hp 0x1000 ] 

	// [���� ���� Deep Copy]
	// ��� �����Ͱ� ����(�ּ�) ���̶��, �����͸� ���� ������ش� (���� ��ü�� �����ϴ� ������ ���� ���� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> ���ο� ��ü�� ���� -> ������ ��ü�� ����Ű�� ����
	// Stack : Knight1 [ hp 0x1000 ] -> Heap 0x1000 Pet [	]
	// Stack : Knight2 [ hp 0x1000 ] -> Heap 0x2000 Pet [	]
	// Stack : Knight3 [ hp 0x1000 ] -> Heap 0x3000 Pet [	]

	// ����)
	// - �Ͻ��� ���� ������ Steps
	// 1) �θ� Ŭ������ ���� ������ ȣ��
	// 2) ��� Ŭ������ ���� ������ ȣ��
	// 3) ����� �⺻ Ÿ���� ��� �޸� ���� (���� ���� Shallow Copy)
	// - ������ ���� ������ Steps
	// 1) �θ� Ŭ������ �⺻ ������ ȣ��
	// 2) ��� Ŭ������ �⺻ ������ ȣ�� 

	// - �Ͻ��� ���� ���� ������ Steps
	// 1) �θ� Ŭ������ ���� ���� ������ ȣ��
	// 2) ��� Ŭ������ ���� ���� ������ ȣ��
	// 3) ����� �⺻ Ÿ���� ��� �޸� ���� (���� ���� Shallow Copy)
	// - ������ ���� ���� ������ Steps
	// 1) �˾Ƽ� ���ִ°� ����

	// �� �̷��� ȥ�������?
	// ��ü�� '����' �Ѵٴ� ���� �� ��ü�� ������ ��ġ��Ű���� ��
	// ���� �⺻������ ���� ���� (Shallow Copy) ������� ����
	

	// ������ ���� -> [��� å��]�� ���α׷������� �����ϰڴٴ� �ǹ�

}
