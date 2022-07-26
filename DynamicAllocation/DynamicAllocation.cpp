#include <iostream>
using namespace std;

// ������ ���� : ���� �Ҵ�


// �޸� ���� ����
// - ������ �ڵ尡 ����Ǵ� ���� -> �ڵ� ����
// - ����(global)/����(static) ���� -> ������ ����
// - ���� ����/ �Ű� ���� -> ���� ����
// - ���� �Ҵ� -> �� ����


// ���ݱ��� ������ ����/���� ������ �̿��ؼ�
// �̷� ���� ���α׷��� �� ����� �Դ�!


// ���� ��Ȳ)
// - MMORPG ���� 1��~5���� ���� 1����~500������
// - ���� ���� �̺�Ʈ -> 5�е��� ���Ͱ� 10�� ���� ����

// - ���� ����
// �Լ��� ������ ���� �����Ǵ� �Ҿ����� �޸�
// ��� �Լ��� �Ű������� �ѱ�ٰų�,  �ϴ� �뵵�δ� OK
// - �޸� ����
// ���α׷��� ����Ǵ� ���߿��� '������' ���Ǵ�

// �������)
// - �ʿ��Ҷ��� ����ϰ�, �ʿ������ �ݳ��� �� �ִ�!
// - �׷��鼭�� (���ð��� �٤Ѱ�) �츮�� ����/�Ҹ� ������ ������ �� �ִ�!
// - �׷� �Ƹ��ٿ� �޸� ����? -> HEAP
// �����Ҵ�� ������ �Լ�/������ : malloc, free, new, delete, new[], delete[]

// malloc
// - �Ҵ��� �޸� ũ�⸦ �ǳ��ش�
// - �޸� �Ҵ� �� ���� �ּҸ� ����Ű�� �����͸� ��ȯ���ش� (�޸� ������nullptr)��ȯ



// new / delete
// - C++�� �߰���
// - malloc/free �Լ�! new/delete�� ������(operator)


// new[] / delete[]
// - new�� malloc�� ���� ���� �ѵ� ~ �迭�� ���� N�� �����͸� ���� �Ҵ��Ϸ���?
// new/delete�� ����


// malloc/free vs new/delete
// - ��� ���Ǽ� new/delete�� �н�!
// - Ÿ�Կ� ������� Ư���� ũ���� �޸� ������ �Ҵ��������? -> malloc/free��!

// �׷��� ���� ���� ���� �ٺ����� �߿��� ���̴� ���� ����!!
// new/delete�� (����Ÿ���� Ŭ������ ���) ������/�Ҹ��ڸ� ȣ�����ش�!!!



class Monster
{
public:
	Monster()
	{
		cout << "Monster()" << endl;
	}
	~Monster()
	{
		cout << "~Monster()" << endl;
	}
public:
	int _hp;
	int _x;
	int _y;

};

// Monster monster[500 * 10000];

int main()
{
	// ���� ���� [�޸���] [LOL] [���÷��̾�]
	// ------------------------------
	// Ŀ�� ���� (Windows ���� �ٽ� �ڵ�)


	// ���� ����) �ü������ �����ϴ� API ȣ��
	// Ŀ�� ����) �޸� �Ҵ��ؼ� �ǳ���
	// ���� ����) ����

	// �ѹ� �޸𸮸� ���� �� ŭ�����ϰ� ����
	// �׸��� �ɰ��� ��
	// [ [ 12 ][ ]                                                 ]
	// C++������ �⺻������ CRT(C��Ÿ�� ���̺귯��)�� [�� ������]�� ���� �� ���� ���
	// ��, ���� ���Ѵٸ� �츮�� ���� API�� ���� ���� �����ϰ� ������ ���� ���� (MMORPG ���� �޸� Ǯ��)
	
	// �׷��� ���! void* ?? ���̵��� �����ʹ� ����?
	// *�� �����ϱ� �����ʹ� ������ (�ּҸ� ��� �ٱ���) => OK
	// Ÿ�� ���� void �ƹ��͵� ����? => NO
	// Ÿ�� ���� void ���� �ִ��� �𸣰����ϱ� �װ� ������ ��ȯ�ؼ� ����ض� => OK
	void* pointer = malloc(sizeof(Monster));

	Monster* m1 = (Monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	// ���� 4����Ʈ�� �Ҵ��ߴٸ�?
	// Heap Overflow
	// - ��ȿ�� �� ������ �ʰ��ؼ� ����ϴ� ����

	// free�� �����ִ� ���
	// �������°� �ƹ������� ����
	// �޸� ����
	// �Ĳ��ϰ� ��ó���� ����!!
	free(pointer);
	pointer = nullptr;
	m1 = nullptr;
	// Double free
	// - �̰� ��κ� �׳� ũ���ø� ���� ��

	// Use-After-Free
	// - ���α׷��� ���� : OMG ���ߴ�!
	// - ��Ŀ ���� : �ɺô�!

	Monster* m2 = new Monster;
	m2->_hp = 200;
	m2->_x = 1;
	m2->_y = 2;
	delete m2;

	Monster* m3 = new Monster[5];
	m3->_hp = 100;
	m3->_x = 1;
	m3->_y = 2;
	
	Monster* m4 = (m3 + 1);
	m4->_hp = 100;
	m4->_x = 1;
	m4->_y = 2;

	delete[] m3;

}
