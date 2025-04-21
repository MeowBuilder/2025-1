#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <array>
#include <print>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

class Player
{
private:
	string name; // 이름, 길이[3, 15], ['a', 'z']로만 구성
	int score; // 점수
	size_t id; // 아이디, 겹치는 아이디 있을 수 있음
	size_t num; // free store에 확보한 바이트 수
	unique_ptr<char[]> p; // free store에 확보한 메모리

public:
	void write(ostream& os)
	{
		os.write((char*)this, sizeof(Player));
		os.write((char*)p.get(), num);
	}

	void read(istream& is)
	{
		is.read((char*)this, sizeof(Player));
		p.release();
		p = make_unique<char[]>(num);
		is.read((char*)p.get(), num);
	}

	void show() const
	{
		println("이름:{:<15}, 아이디:{:<16}, 점수:{:<16}, 자원:{:<16}", name, id, score, num);
		cout << p.get() << endl;
	}

	int getScore() const { return score; };
	int getId() const { return id; };
	string getName() const { return name; }

	char* getp() { return p.get(); };
	size_t getnum() { return num; };
};

array<Player, 250'0000> players;



int main()
{
	ifstream in{ "2025 STL 과제 파일 - 2021182009",ios::binary };
	if (not in) return 2021182009;

	for (Player& data : players)
	{
		data.read(in);
	}

	players.back().show();

	auto maxelement = max_element(players.begin(), players.end(), [](const Player& lhs, const Player& rhs)
		{
			return lhs.getScore() < rhs.getScore();
		});

	(*maxelement).show();

	unsigned long long sum{};

	sum = accumulate(players.begin(), players.end(), 0LL, [](unsigned long long sum, const Player& a)
		{
			return sum + a.getScore();
		});

	long double average = static_cast<long double>(sum) / players.size();

	cout << fixed; //이거로 소수점 표현 고정
	cout << "평균 점수:" << average << endl; // 소수점 표현해야함


	//시간 너무 오래 걸림
	//size_t cnt{};

	//for (size_t i = 0; i < players.size(); ++i)
	//{
	//	for (size_t j = i+1; j < players.size(); ++j)
	//	{
	//		if (players[i].getId() == players[j].getId())
	//		{
	//			++cnt;
	//		}
	//	}
	//}

	//cout << cnt;

	ofstream out{ "같은아이디.txt" };
	size_t countsame{ 0 };
	bool isFirstSame{ false };

	sort(players.begin(), players.end(), [](const Player& a, const Player& b)
		{
			return a.getId() < b.getId();
		});


	for (size_t i = 1; i < players.size(); ++i)
	{
		if (players[i].getId() == players[i - 1].getId())
		{
			if (!isFirstSame)
			{
				out << "이름 :" << players[i - 1].getName() << ", ID :" << players[i - 1].getId();
				++countsame;
				isFirstSame = true;
			}
			out << " / " << "이름 :" << players[i].getName() << ", ID :" << players[i].getId();
			++countsame;
		}
		else
		{
			if (isFirstSame) out << endl;
			isFirstSame = false;
		}
	}

	cout << "같은 id를 가진 객체 수: " << countsame << '\n';

	size_t count10A{ 0 };

	for (Player& data : players)
	{
		sort(data.getp(), data.getp() + data.getnum());

		size_t acount = count(data.getp(), data.getp() + data.getnum(), 'a');
		if (acount >= 10)
		{
			++count10A;
		}
	}

	cout << "a가 10글자 이상인 객체 수: " << count10A << '\n';

	size_t inputID{};
	while (true)
	{
		cout << "====================" << endl << "ID를 입력하세요. : ";
		if (!(cin >> inputID))
		{
			cin.clear(); // 에러플래그 지우기
			cin.ignore(100, '\n'); // 입력버퍼 100개 삭제
			cout << "ID입력이 올바르지 않습니다." << endl;
			continue;
		}

		sort(players.begin(), players.end(), [](const Player& lhs, const Player& rhs)
			{
				return lhs.getId() < rhs.getId();
			});

		for (const Player& data : players)
		{
		}
	}
}