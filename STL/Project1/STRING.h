//-------------------------------------------------------------------------------------------------
// STRING.h - STL의 동작을 이해하기 위한 class / std::string과 유사하게 작성
//
// 2025. 4. 10 - 시작
// 2025. 4. 14 - 이동의미론(move semantics) 구현
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

	// 이동생성자와 이동할당연산자 2025. 4. 14
	STRING(STRING&&);
	STRING& operator=(STRING&&);

	// 기본정렬을 위한 < 2025. 4. 14
	bool operator<(const STRING&) const;

	size_t size() const;

private:
	size_t num{};
	std::unique_ptr<char[]> p{};

	size_t id;				// 2025. 4. 10 관찰을 위한 객체 고유번호

	friend std::ostream& operator<<(std::ostream&, const STRING&);

	friend std::istream& operator>>(std::istream&, STRING&);	// 2025. 4. 14
	
	static size_t gid;		// 2025. 4. 10 고유번호 생성
};