//-----------------------------------------------------------
// 2025.1 �б�		 STL 6�� 5�� �����				(13�� 2��)
// 6/19 ����� 15�� 2�� - �⸻����
//-----------------------------------------------------------
// Unordered Associative Container - hash ���
//-----------------------------------------------------------

#include <iostream>
#include "string"
#include <unordered_set>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool ����;

// trade - off				ã�� ����(time)		���� ����(memory)
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

	//save("����.cpp");
}