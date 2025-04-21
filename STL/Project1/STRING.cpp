//-------------------------------------------------------------------------------------------------
// STRING.cpp - STL의 동작을 이해하기 위한 class / std::string과 유사하게 작성
//
// 2025. 4. 10 - 시작
// 2025. 4. 10 - 복사생성/복사할당연산자, 스페셜 함수의 동작 관찰
// 2025. 4. 14 - 선택적 관찰하도록 전역변수를 사용, 이동의미론(move semantics) 구현
//-------------------------------------------------------------------------------------------------
#include <memory>
#include <print>
#include "STRING.h"

size_t STRING::gid{ 0 };		// 2025. 4. 10 고유번호 생성
bool 관찰{ false };

STRING::STRING()
	: id{ ++gid }
{
	if (관찰)
	{
		std::println("[{:6}] {:<16} 자원수:{:4}, 주소:{:16} 자원의주소:{:16}",
			id, "디폴트생성", num, (void*)this, (void*)p.get());
	}
}

STRING::~STRING()
{
	if (관찰)
	{
		std::println("[{:6}] {:<16} 자원수:{:4}, 주소:{:16} 자원의주소:{:16}",
			id, "소멸자", num, (void*)this, (void*)p.get());
	}
}

STRING::STRING(const char* str) 
	: num{ strlen(str) }, id{ ++gid }
{
	p.release();
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), str, num);

	if (관찰)
	{
		std::println("[{:6}] {:<16} 자원수:{:4}, 주소:{:16} 자원의주소:{:16}",
			id, "생성자(char*)", num, (void*)this, (void*)p.get());
	}
};

// 복사생성자와 복사할당연산자 2025. 4. 10
STRING::STRING(const STRING& other)	// 복사 생성은 할당을 이용해서 코딩하라
	:num{ other.num }, id{ ++gid }
{
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), other.p.get(), num);

	if (관찰)
	{
		std::println("[{:6}] {:<16} 자원수:{:4}, 주소:{:16} 자원의주소:{:16}",
			id, "복사생성자", num, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(const STRING& other)
{
	if (this == &other) return *this; // [int* p = &a] => address of /// [int& r = a] => reference

	num = other.num;

	p.release();
	p = std::make_unique<char[]>(num);
	memcpy(p.get(), other.p.get(), num);

	if (관찰)
	{
		std::println("[{:6}] {:<16} 자원수:{:4}, 주소:{:16} 자원의주소:{:16}",
			id, "copy operator=", num, (void*)this, (void*)p.get());
	}

	return *this;
}

STRING::STRING(STRING&& other)
	: num{ other.num }, id{ ++gid }
{
	p.reset(other.p.release());

	//other.num = 0;

	if (관찰)
	{
		std::println("[{:6}] {:<16} 자원수:{:4}, 주소:{:16} 자원의주소:{:16}",
			id, "이동생성자", num, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(STRING&& other)
{
	if (this == &other)
		return *this;

	num = other.num;
	p.release();
	p.reset(other.p.release());

	//other.num = 0;

	if (관찰)
	{
		std::println("[{:6}] {:<16} 자원수:{:4}, 주소:{:16} 자원의주소:{:16}",
			id, "move operator=", num, (void*)this, (void*)p.get());
	}

	return *this;
}

// 기본정렬을 위한 < 2025. 4. 14
bool STRING::operator<(const STRING& rhs) const
{
	return size() < rhs.size();
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

std::istream& operator>>(std::istream& is, STRING& s)	// 2025. 4. 14
{
	std::string str;
	is >> str;

	s.num = str.size();
	s.p.release();
	s.p = std::make_unique<char[]>(s.num);
	memcpy(s.p.get(), str.data(), s.num);

	return is;
}