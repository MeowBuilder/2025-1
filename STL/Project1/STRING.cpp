//-------------------------------------------------------------------------------------------------
// STRING.cpp - STL의 동작을 이해하기 위한 class / std::string과 유사하게 작성
//
// 2025. 4. 10 - 시작
// 2025. 4. 10 - 복사생성/복사할당연산자, 스페셜 함수의 동작 관찰
//-------------------------------------------------------------------------------------------------
#include <memory>
#include <print>
#include "STRING.h"

size_t STRING::gid{ 0 };		// 2025. 4. 10 고유번호 생성

STRING::STRING()
	: id{ ++gid }
{
	std::println("[{:6}] {:<16} 자원수:{:4}, 주소:{:16} 자원의주소:{:16}",
		id, "디폴트생성", num, (void*)this, (void*)p.get());
}

STRING::~STRING()
{
	std::println("[{:6}] {:<16} 자원수:{:4}, 주소:{:16} 자원의주소:{:16}",
		id, "소멸자", num, (void*)this, (void*)p.get());
}

STRING::STRING(const char* str) 
	: num{ strlen(str) }, id{ ++gid }
{
	p.release();
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), str, num);

	std::println("[{:6}] {:<16} 자원수:{:4}, 주소:{:16} 자원의주소:{:16}",
		id, "생성자(char*)", num, (void*)this, (void*)p.get());
};

// 복사생성자와 복사할당연산자 2025. 4. 10
STRING::STRING(const STRING& other)	// 복사 생성은 할당을 이용해서 코딩하라
	:id{ ++gid }
{
	*this = other;

	std::println("[{:6}] {:<16} 자원수:{:4}, 주소:{:16} 자원의주소:{:16}",
		id, "복사생성자", num, (void*)this, (void*)p.get());
}

STRING& STRING::operator=(const STRING& other)
{
	if (this == &other) return *this; // [int* p = &a] => address of /// [int& r = a] => reference

	num = other.num;

	p.release();
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), other.p.get(), num);

	std::println("[{:6}] {:<16} 자원수:{:4}, 주소:{:16} 자원의주소:{:16}",
		id, "copy operator=", num, (void*)this, (void*)p.get());

	return *this;
}

size_t STRING::size() const 
{
	return num;
};

std::ostream& operator<<(std::ostream& os, const STRING& s)
{
	for (int i = 0; i < s.num; ++i) {
		os << s.p[i];
	}
	return os;
}