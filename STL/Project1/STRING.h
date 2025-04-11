//-------------------------------------------------------------------------------------------------
// STRING.h - STL의 동작을 이해하기 위한 class / std::string과 유사하게 작성
//
// 2025. 4. 10 - 시작
//-------------------------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <memory>

class STRING {
public:
	STRING();
	~STRING();
	
	STRING(const char* str);	// 생성자

	// 복사생성자와 복사할당연산자 2025. 4. 10
	STRING(const STRING&);
	STRING& operator=(const STRING&);

	size_t size() const;

private:
	size_t num{};
	std::unique_ptr<char[]> p{};

	size_t id;				// 2025. 4. 10 관찰을 위한 객체 고유번호

	friend std::ostream& operator<<(std::ostream& os, const STRING& s);
	
	static size_t gid;		// 2025. 4. 10 고유번호 생성
};