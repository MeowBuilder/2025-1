//-----------------------------------------------------------
// 2025.1 학기		 STL 4월 21일 월요일				(7주 2일)
// 중간고사(30)	- 4월 24일 목요일 (8주 1일)
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

extern bool 관찰;

// [문제] vector는 어떻게 메모리를 관리하는가??

int main(){
	vector<int> v;

	int i{ 0 };

	size_t old = v.capacity();

	for (int i = 0; i < 10000; ++i)
	{
		v.push_back(i);
		if (old != v.capacity())
		{
			cout << "v가 재할당하지 않고 원소를 담을 수 있는 개수" << v.capacity() << endl;
			old = v.capacity();
			//v.shrink_to_fit();
			
		}
	}


	//save("메인.cpp");
}