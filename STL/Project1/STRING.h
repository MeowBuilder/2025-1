//-------------------------------------------------------------------------------------------------
// STRING.h - STL의 동작을 이해하기 위한 class / std::string과 유사하게 작성
//
// 2025. 4. 10 - 시작
// 2025. 4. 14 - 이동의미론(move semantics) 구현
// 2025. 5. 1 - operator==
// 2025. 5. 15 - begin(), end() 제공
// 2025. 5. 19 - rbegin(), rend() 제공 -> class 아니면 안됨
// 2025. 5. 22 - 반복자가 질문에 응답하도록 한다.
// 2025. 5. 22 - begin(), end()가 반복자를 리턴하도록 한다.
// 2025. 5. 26 - sort가능하도록 필요한 연산자를 모두 코딩
//				(C++ 연산자 오버로딩을 잘 이해해야 할 수 있다.)
//-------------------------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <memory>

// Iterator adaptor - 반복자의 인터페이스를 제공하지만 실제는 다르게 동작
// 표준반복자가 제공해야할 다섯가지 타입을 제공한다.

class STRING_Reverse_Iterator {
public:
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

public:
	explicit STRING_Reverse_Iterator(char* p) : p{ p } { }; // explicit -> 자동 형변환 막기
	
	// 반복자라면 제공해야할 기본동작이 있다.
	void operator++(){
		--p;
	}

	char operator*() const
	{
		return *(p - 1);
	}

	bool operator==(const STRING_Reverse_Iterator& rhs) const
	{
		return p == rhs.p;
	}
private:
	char* p;
};

class STRING_Iterator
{
public:
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

public:
	// 2025. 5. 26 special 함수인 default ctor를 요구
	STRING_Iterator() = default;

	STRING_Iterator(char* p) : p{ p } {};

	// 이건 의미를 제대로 코딩해야 한다.
	// 2025. 5. 26 수정 - 자기 자신을 리턴해야한다.
	STRING_Iterator& operator++()
	{
		++p;
		return *this;
	}

	// 2025. 5. 26 수정
	// 원래는 리턴값이 l-value가 아님 -> &를 리턴하고 const를 제거함
	char& operator*()
	{
		return *p;
	}

	// cv-qualifier는 오버로딩으로 구분 가능하다.
	char& operator*() const
	{
		return *p;
	}
	
	// <=> 작성 후 주석처리 -> 우주선 연산의 뭔가뭔가로 다시 살림
	bool operator==(const STRING_Iterator& rhs) const
	{
		return p == rhs.p;
	}

	// sort가 동작하도록 필요 연산자 추가
	// 2025. 5. 26
	difference_type operator-(const STRING_Iterator& rhs) const
	{
		return p - rhs.p;	// 연산의 결과가 클래스의 불변성(invariants)을 해치나 관찰
	}

	STRING_Iterator& operator--()
	{
		--p;
		return *this;
	}

	// 모든 relational operation을 할 수 있게 <=>를 정의해 본다.
	// <, <=, ==, !=, >=, > ==압축=> <=>
	auto operator<=>(const STRING_Iterator& rhs) const
	{
		return p <=> rhs.p;
	}

	STRING_Iterator operator+(difference_type n) const
	{
		return p + n;
	}

	STRING_Iterator operator-(difference_type n) const
	{
		return p - n;
	}

private:
	char* p{}; // = nullptr;
};

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
	// 사전식정렬하도록 수정 - 2025. 5. 15
	bool operator<(const STRING&) const;

	// 같은 객체인지 비교 == - 2025. 5. 1 
	bool operator==(const STRING&) const;

	size_t size() const;

	// 2025. 5. 15
	STRING_Iterator begin() const;
	STRING_Iterator end() const;

	// 2025. 5. 19
	STRING_Reverse_Iterator rbegin() const;
	STRING_Reverse_Iterator rend() const;


private:
	size_t num{};
	std::unique_ptr<char[]> p{};

	size_t id;				// 2025. 4. 10 관찰을 위한 객체 고유번호

	friend std::ostream& operator<<(std::ostream&, const STRING&);

	friend std::istream& operator>>(std::istream&, STRING&);	// 2025. 4. 14

	static size_t gid;		// 2025. 4. 10 고유번호 생성
};
