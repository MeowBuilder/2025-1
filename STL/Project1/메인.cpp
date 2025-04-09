//-----------------------------------------------------------
// 2025.1 �б�		 STL 4�� 07�� ������				(5�� 2��)
// �߰����(30)	- 4�� 24�� ����� (8�� 1��)
// ��������(30)	- 4�� 10�� ����� (6�� 1��)
//-----------------------------------------------------------
// class STRING �ۼ����� - std::string�� ������ ������ �Ѵ�.
//-----------------------------------------------------------

#include <iostream>
#include <string>
#include <memory>
#include "save.h"

using namespace std;

class STRING {
public:
	STRING(const char* str) : num{ strlen(str) } { // T[N] -> T* collapsing
		p.release();					// �����ÿ� �̷��� �� �ʿ�� ����.
		p = make_unique<char[]>(num);
		memcpy(p.get(), str, num);		// DMA(Direct Memory Access)�� �����ϴ�. CPU��ġ�� �ʰ� �ʰ�� �޸� ����.
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
	STRING s{ "std::string�� ������ Ŭ����" };

	cout << "s�� �����ϴ� �ڿ��� ����Ʈ �� : " << s.size() << endl;

	//STRING t = s;
	cout << s << endl;
	//cout << t << endl;
	//save("����.cpp");
}