//-----------------------------------------------------------
// 2025.1 �б�		 STL 4�� 28�� ������				(8�� 2��)
//-----------------------------------------------------------
// STL Container - Containers are objects that store other objects.
// array - 
// vector - 
//-----------------------------------------------------------

#include <iostream>
#include <vector>
#include <array>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool ����;

int main(){	
	//save("����.cpp");

	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	array<int,10> arr{ 1,2,3,4,5,6,7,8,9,10 };

	while (true)
	{
		cout << "���° �����͸� ���ϴ°�:";
		int num;
		cin >> num;

		try
		{
			cout << "ã�� �� :" << vec.at(num) << endl;
		}
		catch (const std::exception& e)
		{
			cout << e.what();
			cout << " - 0���� 9���� ���� �Է����ּ���." << endl;
		}
	}

}