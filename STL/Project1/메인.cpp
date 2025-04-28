//-----------------------------------------------------------
// 2025.1 학기		 STL 4월 28일 월요일				(8주 2일)
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

extern bool 관찰;

int main(){	
	//save("메인.cpp");

	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	array<int,10> arr{ 1,2,3,4,5,6,7,8,9,10 };

	while (true)
	{
		cout << "몇번째 데이터를 원하는가:";
		int num;
		cin >> num;

		try
		{
			cout << "찾은 값 :" << vec.at(num) << endl;
		}
		catch (const std::exception& e)
		{
			cout << e.what();
			cout << " - 0부터 9까지 값을 입력해주세요." << endl;
		}
	}

}