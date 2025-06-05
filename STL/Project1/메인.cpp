//-----------------------------------------------------------
// 2025.1 학기		 STL 6월 5일 목요일				(13주 2일)
// 6/19 목요일 15주 2일 - 기말시험
//-----------------------------------------------------------
// Unordered Associative Container - hash 기반
//-----------------------------------------------------------

#include <iostream>
#include "string"
#include <unordered_set>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool 관찰;

// trade - off				찾기 성능(time)		공간 성능(memory)
// Sequence					- O(N)				- N
// Associative				- O(log N)			- N + pointer
// Unordered Associative	- O(1)				- N + table + pointer

int main(){
	unordered_set<string> us{ "1","22","333","4444","55555" };

	for (const string& s : us)
	{
		cout << s << endl;
	}

	cout << std::hash<string>{}("55555") << endl;
	cout << std::hash<string>{}("4444") << endl;

	//save("메인.cpp");
}