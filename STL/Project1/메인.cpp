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
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool 관찰;

int main(){	
	//save("메인.cpp");

	ifstream in{ "메인.cpp" };
	if (not in)
		return 2021182009;

	list<STRING> words{ istream_iterator<STRING>{in},{} };

	// [문제] 사용자가 입력한 단어가 리스트에 있는 지 알려주자.
	// 단어가 없으면 없다라고 출력하고 있으면 리스트의 몇 번째 단어인지 출력하라.

	while (true)
	{
		cout << "찾을 단어는? ";
		STRING 단어;
		cin >> 단어;

		auto find_word = find(words.begin(), words.end(), 단어);
		if (find_word == words.end())
		{
			cout << "없음" << endl;
		}
		else
		{
			cout << distance(words.begin(), find_word) << endl;
		}
	}

}