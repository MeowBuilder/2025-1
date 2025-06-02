//-----------------------------------------------------------
// 2025.1 학기		 STL 6월 2일 월요일				(13주 1일)
// 6/19 목요일 15주 2일 - 기말시험
//-----------------------------------------------------------
// Associative Container
// - set<key>			: key와 value를 구분하지 않는다.
// - Map<key, value>	: <아이돌그룹, 멤버>
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <array>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool 관찰;

int main(){

	ifstream Alice{ "이상한 나라의 앨리스.txt" };
	if (not Alice)
	{
		cout << "파일이 없다." << endl;
		return 18651126;
	}

	multiset<STRING> s{ istream_iterator<STRING>{Alice},{} };
	cout << "ㄷㅏㄴㅇㅓㅇㅡㅣ ㄱㅐㅅㅜ :" << s.size() << endl;

	// [문제] multiset<STRING> s에 저장된 모든 알파벳의 사용횟수를 다음과 같이
	// 사용된 횟수기준 내림차순으로 출력하라
	// 대문자는 소문자로 바꾸자
	// e - 13618
	// t - 10726
	// ...
	// z - 78

	array<int, 26> a{};

	for (const STRING& word : s)
	{
		for (char ch : word)
		{
			if (isalpha(ch))
			{
				ch = tolower(ch);
				a[ch - 'a']++;
			}
		}
	}


	for (size_t i = 0; i < a.size(); ++i)
	{
		cout << static_cast<char>('a' + i) << " - " << a[i] << endl;
	}

	//save("메인.cpp");
}