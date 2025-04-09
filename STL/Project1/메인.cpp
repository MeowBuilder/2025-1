//-----------------------------------------------------------
// 2025.1 학기		 STL 4월 07일 월요일				(5주 2일)
// 중간고사(30)	- 4월 24일 목요일 (8주 1일)
// 과제설명(30)	- 4월 10일 목요일 (6주 1일)
//-----------------------------------------------------------
// class STRING 작성시작 - std::string과 유사한 동작을 한다.
//-----------------------------------------------------------

#include <iostream>
#include <string>
#include <memory>
#include "save.h"

using namespace std;

class STRING {
public:
	STRING(const char* str) : num{ strlen(str) } { // T[N] -> T* collapsing
		p.release();					// 생성시에 이렇게 할 필요는 없다.
		p = make_unique<char[]>(num);
		memcpy(p.get(), str, num);		// DMA(Direct Memory Access)가 가능하다. CPU거치지 않고 초고속 메모리 복사.
	};

	size_t size() const {
		return num;
	};

private:
	size_t num{};
	unique_ptr<char[]> p{};

	friend ostream& operator<<(ostream& os, const STRING& s) {
		for (int i = 0; i < s.num; ++i) {
			os << s.p[i];
		}
		return os;
	}
};


int main(){
	STRING s{ "std::string과 유사한 클래스" };

	cout << "s가 관리하는 자원의 바이트 수 : " << s.size() << endl;

	//STRING t = s;
	cout << s << endl;
	//cout << t << endl;
	//save("메인.cpp");
}