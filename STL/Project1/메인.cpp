//-----------------------------------------------------------
// 2025.1 학기		 STL 5월 08일 목요일				(9주 2일)
// 2025.05.05 -> 추후 보강 (6/19) <- 종강
//-----------------------------------------------------------
// STL Container - Containers are objects that store other objects.
// array<T,N> - 유일하게 크기가 고정
// vector<T> - random access가 가능(=> [] 연산자 제공), O(1)(상수시간) access, O(1) push_back()
// deque<T> - random access, []연산자, O(1) access, O(1) push_front(), push_back()
// list<T> - O(1) insert, delete, 자료구조를 활용한 전용함수 제공(remove, sort, splice)
// STL의 알고리즘 1.수정X 2.수정O 3.정렬
//-----------------------------------------------------------

#include <iostream>
#include <deque>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool 관찰;

int main(){	
	deque<int> deq;
	//save("메인.cpp");
}