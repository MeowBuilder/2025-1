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

int main(){
	관찰 = true;

	vector<STRING> v;
	
	v.emplace_back("12345"); // 인자만 전달 => 관리하는 메모리에서 생성자를 호출

	cout << "==========" << endl;

	//save("메인.cpp");
}