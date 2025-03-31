//----------------------------------------------------
// save.cpp - 한 학기 강의를 잘 저장하는 함수
//											2025.03.13
//----------------------------------------------------

#include <string_view>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include "save.h"

void save(std::string_view filename)
{
	// 1.인자로 전달된 파일을 읽기 모드로 연다.
	std::ifstream in{ filename.data() }; // RAII

	if (not in)
	{
		std::cout << filename << "을 열 수 없습니다." << std::endl;
		exit(20250310);
	}

	// 저장했다는 것을 화면에 표시
	std::cout << filename << "(" << std::filesystem::file_size(filename) << " bytes) 저장하였습니다." << std::endl;

	// 2.쓰기모드로 저장할 파일을 (덧붙이기 모드로) 연다
	std::ofstream out{ "2025 1학기 STL 강의저장.txt", std::ios::app }; // { } <- uniform initializer



	// 시간 기록
	auto now = std::chrono::system_clock::now(); // epoch로 부터 경과된 tick 수를 얻는다.
	auto utc = std::chrono::system_clock::to_time_t(now); // UTC
	auto lt = std::localtime(&utc); // 지역시간(한국)으로 변경

	auto old = out.imbue(std::locale("Ko-KR")); // 스트림의 지역을 변경

	out << "\n" << "\n";
	out << "==========================================" << "\n";
	out << "저장한 시간: " << std::put_time(lt, "%c %A") << "\n";
	out << "==========================================" << "\n";
	out << "\n";

	out.imbue(old); // 변경 이전으로 복원

	// 3.파일을 읽어서 저장할 파일에 덧붙인다.
	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator{ out });
}