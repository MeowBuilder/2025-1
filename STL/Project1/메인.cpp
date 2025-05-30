//-----------------------------------------------------------
// 2025.1 학기		 STL 5월 29일 목요일				(12주 2일)
// 6/19 목요일 15주 2일 - 기말시험
//-----------------------------------------------------------
// Associative Container
// - set<key>			: key와 value를 구분하지 않는다.
// - Map<key, value>	: <아이돌그룹, 멤버>
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "save.h"
#include "STRING.h"

using namespace std;

extern bool 관찰;

// [문제] "이상한 나라의 앨리스.txt"를 다운받는다.
// [1] vector<STRING> v; 에 저장하라.
// [2] 모두 몇 단어로 만들었는지 출력하라.

int main(){	
	ifstream Alice{ "이상한 나라의 앨리스.txt" };
	if (not Alice)
	{
		cout << "파일이 없다." << endl;
		return 18651126;
	}

	//vector<STRING> v;
	//v.reserve(30000);
	// 값을 바꿔 꼭 비교해 보세요. =(개인)> reserve가 단어수 이상이 되면 불필요한 STRING생성이 없다.

	set<STRING> v{ istream_iterator<STRING>{Alice},{} }; // vector에서는 STRING의 생성이 엄청나다. but Associative 컨테이너에서는 부담이 없다.

	//STRING in;
	//while (Alice >> in)
	//{
	//	v.push_back(in);
	//}

	cout << "단어의 개수 :" << v.size() << endl;

	//save("메인.cpp");
	//관찰 = true;
}