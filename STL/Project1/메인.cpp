//-----------------------------------------------------------
// 2025.1 �б�		 STL 4�� 21�� ������				(7�� 2��)
// �߰����(30)	- 4�� 24�� ����� (8�� 1��)
//-----------------------------------------------------------
// STL Container - Containers are objects that store other objects.
// array - 
// vector - 
//-----------------------------------------------------------

#include <iostream>
#include <vector>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool ����;

// [����] vector�� ��� �޸𸮸� �����ϴ°�??

int main(){
	vector<int> v;

	int i{ 0 };

	size_t old = v.capacity();

	for (int i = 0; i < 10000; ++i)
	{
		v.push_back(i);
		if (old != v.capacity())
		{
			cout << "v�� ���Ҵ����� �ʰ� ���Ҹ� ���� �� �ִ� ����" << v.capacity() << endl;
			old = v.capacity();
			//v.shrink_to_fit();
			
		}
	}


	//save("����.cpp");
}