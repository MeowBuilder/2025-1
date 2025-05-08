//-----------------------------------------------------------
// 2025.1 학기		 STL 5월 08일 목요일				(9주 2일)
// 6/19 목요일 15주 2일 - 기말시험
// 5/12 월요일 - 졸업작품 중간발표수업은 한다.
//-----------------------------------------------------------
// STL Container - Containers are objects that store other objects.
// array<T,N> - 유일하게 크기가 고정
// vector<T> - random access가 가능(== [] 연산자 제공), O(1)(상수시간) access, O(1) push_back()
// deque<T> - random access, []연산자, O(1) access, O(1) push_front(), push_back()
// list<T> - O(1) insert, delete, 자료구조를 활용한 전용함수 제공(remove, sort, splice)
// STL의 알고리즘 1.수정X 2.수정O 3.정렬
//-----------------------------------------------------------

#include <iostream>
#include <vector>
#include <deque>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool 관찰;

class Test
{
	char x[1'000'000];
};

int main(){	
	{
		vector<Test> vec;
		while (true) {
			try
			{
				vec.emplace_back();
			}
			catch (const std::exception& e)
			{
				cout << e.what() << endl;
				cout << "최대 개수 - " << vec.size() << endl;
				break;
			}
		}
	}

	//save("메인.cpp");
}