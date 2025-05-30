//-----------------------------------------------------------
// 2025.1 �б�		 STL 5�� 29�� �����				(12�� 2��)
// 6/19 ����� 15�� 2�� - �⸻����
//-----------------------------------------------------------
// Associative Container
// - set<key>			: key�� value�� �������� �ʴ´�.
// - Map<key, value>	: <���̵��׷�, ���>
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool ����;

// [����] "�̻��� ������ �ٸ���.txt"�� �ٿ�޴´�.
// [1] vector<STRING> v; �� �����϶�.
// [2] ��� �� �ܾ�� ��������� ����϶�.

int main(){	
	ifstream Alice{ "�̻��� ������ �ٸ���.txt" };
	if (not Alice)
	{
		cout << "������ ����." << endl;
		return 18651126;
	}

	//vector<STRING> v;
	//v.reserve(30000);
	// ���� �ٲ� �� ���� ������. =(����)> reserve�� �ܾ�� �̻��� �Ǹ� ���ʿ��� STRING������ ����.

	set<STRING> v{ istream_iterator<STRING>{Alice},{} }; // vector������ STRING�� ������ ��û����. but Associative �����̳ʿ����� �δ��� ����.

	//STRING in;
	//while (Alice >> in)
	//{
	//	v.push_back(in);
	//}

	cout << "�ܾ��� ���� :" << v.size() << endl;

	//save("����.cpp");
	//���� = true;
}