#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <array>
#include <print>
#include <algorithm>

//#include <numeric>
//#include <set>
//#include <chrono>

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
	Player() {};

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
		cout.write(p.get(), num); // num개만 출력 -> '\0'이 없어서 생기는 문제 해결
		cout << endl;
	}

	int getScore() const { return score; };
	int getId() const { return id; };
	string getName() const { return name; }

	char* getp() { return p.get(); };
	size_t getnum() { return num; };
};

array<Player, 250'0000> players;

array<Player*, 250'0000> playersById;
array<Player*, 250'0000> playersByName;
array<Player*, 250'0000> playersByScore;

int main()
{
	// 1번
	ifstream in{ "2025 STL 과제 파일 - 2021182009",ios::binary };
	if (not in) return 2021182009;

	for (Player& data : players)
	{
		data.read(in);
	}

	cout << "==========1번==========" << endl;
	players.back().show();



	// 2번 ==============================
	//{
	//	auto start = chrono::high_resolution_clock::now();

	//	auto maxelement = max_element(players.begin(), players.end(), [](const Player& lhs, const Player& rhs)
	//		{
	//			return lhs.getScore() < rhs.getScore();
	//		});

	//	(*maxelement).show();

	//	double sum{};

	//	sum = accumulate(players.begin(), players.end(), 0.0, [](double sum, const Player& a)
	//		{
	//			return sum + a.getScore();
	//		});

	//	double average = sum / players.size();

	//	auto end = chrono::high_resolution_clock::now();
	//	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	//	cout << "실행 시간: " << duration.count() << "ms\n";

	//	cout << fixed; // 소수점 표현 고정
	//	cout << "평균 점수:" << average << endl; // 소수점 표현해야함
	//}

	
	//auto start = chrono::high_resolution_clock::now();

	double sum = 0.0;
	const Player* maxPlayer = &players[0];

	for (const Player& p : players)
	{
		sum += p.getScore();
		if (p.getScore() > maxPlayer->getScore())
			maxPlayer = &p;
	}

	double average = sum / players.size();

	//auto end = chrono::high_resolution_clock::now();
	//auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	//cout << "실행 시간: " << duration.count() << "ms\n";

	cout << "==========2번==========" << endl;
	maxPlayer->show();

	cout << fixed; // 소수점 표현 고정
	cout << "평균 점수:" << average << endl; // 소수점 표현해야함


	


	// 3번 ==============================
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

	cout << "==========3번==========" << endl;
	cout << "같은 id를 가진 객체 수: " << countsame << '\n';



	// 4번 ==============================
	//{
	//	auto start = chrono::high_resolution_clock::now();
	//	size_t count10A{ 0 };

	//	for (Player& data : players)
	//	{
	//		sort(data.getp(), data.getp() + data.getnum());

	//		size_t acount{ 0 };

	//		for (size_t i = 0; i < data.getnum(); ++i)
	//		{
	//			if (data.getp()[i] == 'a')
	//			{
	//				++acount;
	//			}
	//			else break;
	//		}

	//		if (acount >= 10)
	//		{
	//			++count10A;
	//		}
	//	}
	//	auto end = chrono::high_resolution_clock::now();
	//	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	//	cout << "실행 시간: " << duration.count() << "ms\n";
	//	cout << "a가 10글자 이상인 객체 수: " << count10A << '\n';
	//}
	
	
	//auto start = chrono::high_resolution_clock::now();
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
	//auto end = chrono::high_resolution_clock::now();

	//auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	//cout << "실행 시간: " << duration.count() << "ms\n";
	
	cout << "==========4번==========" << endl;
	cout << "a가 10글자 이상인 객체 수: " << count10A << '\n';
	
	
	// 5번 ==============================

	for (size_t i = 0; i < players.size(); ++i) {
		playersById[i] = &players[i];
		playersByName[i] = &players[i];
		playersByScore[i] = &players[i];
	}

	sort(playersById.begin(), playersById.end(), [](const Player* a, const Player* b) {
		return a->getId() < b->getId();
		});
	sort(playersByName.begin(), playersByName.end(), [](const Player* a, const Player* b) {
		return a->getName() < b->getName();
		});
	sort(playersByScore.begin(), playersByScore.end(), [](const Player* a, const Player* b) {
		return a->getScore() < b->getScore();
		});


	cout << "==========5번==========" << endl;

	while (true)
	{
		cout << "====================" << endl << "ID를 입력하세요. : ";
		size_t inputID;
		if (!(cin >> inputID))
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "ID입력이 올바르지 않습니다." << endl;
			continue;
		}

		// ID 기준 탐색
		auto start = lower_bound(playersById.begin(), playersById.end(), inputID, [](const Player* a, size_t id) {
				return a->getId() < id;
			});

		if (start == playersById.end() || (*start)->getId() != inputID) {
			cout << "해당 ID를 가진 Player가 존재하지 않습니다.\n";
			continue;
		}

		auto end = start;
		while (end != playersById.end() && (*end)->getId() == inputID)
			++end;

		// ID 기준 출력
		cout << "\n[ID 기준 출력]\n";
		if (start != playersById.begin())
			(*prev(start))->show();

		for (auto ptr = start; ptr != end; ++ptr)
			(*ptr)->show();

		if (end != playersById.end())
			(*end)->show();

		// 이름 기준 출력
		cout << "\n[Name 기준 출력]\n";
		for (auto ptr = start; ptr != end; ++ptr)
		{
			string targetName = (*ptr)->getName();

			auto front = lower_bound(playersByName.begin(), playersByName.end(), targetName, [](const Player* a, const string& val) {
					return a->getName() < val;
				});

			if (front == playersByName.end() || (*front)->getName() != targetName) continue;

			auto back = front;
			while ((back + 1) != playersByName.end() && (*(back + 1))->getName() == targetName)
				++back;

			if (front != playersByName.begin())
				(*(front - 1))->show();

			(*ptr)->show();

			if ((back + 1) != playersByName.end())
				(*(back + 1))->show();

			cout << "----\n";
		}

		// 점수 기준 출력
		cout << "\n[Score 기준 출력]\n";
		for (auto ptr = start; ptr != end; ++ptr)
		{
			int targetScore = (*ptr)->getScore();

			auto front = lower_bound(playersByScore.begin(), playersByScore.end(), targetScore, [](const Player* a, int val) {
					return a->getScore() < val;
				});

			if (front == playersByScore.end() || (*front)->getScore() != targetScore) continue;

			auto back = front;
			while ((back + 1) != playersByScore.end() && (*(back + 1))->getScore() == targetScore)
				++back;

			if (front != playersByScore.begin())
				(*(front - 1))->show();

			(*ptr)->show();

			if ((back + 1) != playersByScore.end())
				(*(back + 1))->show();

			cout << "----\n";
		}
	}

	//size_t inputID{};
	//while (true)
	//{
	//	cout << "====================" << endl << "ID를 입력하세요. : ";
	//	size_t inputID;
	//	if (!(cin >> inputID))
	//	{
	//		cin.clear();
	//		cin.ignore(100, '\n');
	//		cout << "ID입력이 올바르지 않습니다." << endl;
	//		continue;
	//	}

	//	// ID 기준 정렬
	//	sort(players.begin(), players.end(), [](const Player& a, const Player& b)
	//		{
	//			return a.getId() < b.getId();
	//		});

	//	Player keyID(inputID);
	//	auto range_id = equal_range(players.begin(), players.end(), keyID,
	//		[](const Player& a, const Player& b)
	//		{
	//			return a.getId() < b.getId();
	//		});

	//	if (range_id.first == range_id.second)
	//	{
	//		cout << "해당 ID를 가진 Player가 존재하지 않습니다.\n";
	//		continue;
	//	}

	//	// 동일 ID 가진 Player 출력
	//	cout << "\n[ID 기준 출력]" << endl;
	//	if (range_id.first != players.begin())
	//		prev(range_id.first)->show();

	//	for (auto it = range_id.first; it != range_id.second; ++it)
	//		it->show();

	//	if (range_id.second != players.end())
	//		range_id.second->show();

	//	// name/score 기준 비교용 값 저장 (중복 제거 위해 set 사용)
	//	set<string> namesToFind;
	//	set<int> scoresToFind;

	//	for (auto it = range_id.first; it != range_id.second; ++it)
	//	{
	//		namesToFind.insert(it->getName());
	//		scoresToFind.insert(it->getScore());
	//	}

	//	// 이름 기준 정렬
	//	sort(players.begin(), players.end(), [](const Player& a, const Player& b)
	//		{
	//			return a.getName() < b.getName();
	//		});

	//	cout << "\n[Name 기준 출력]" << endl;
	//	for (const string& targetName : namesToFind)
	//	{
	//		Player keyName(targetName);

	//		auto range_name = equal_range(players.begin(), players.end(), keyName,
	//			[](const Player& a, const Player& b)
	//			{
	//				return a.getName() < b.getName();
	//			});

	//		if (range_name.first != players.begin())
	//			prev(range_name.first)->show();

	//		if (range_name.first != range_name.second)
	//			range_name.first->show();

	//		if (range_name.second != players.end())
	//			range_name.second->show();

	//		cout << "----" << endl;
	//	}

	//	// 점수 기준 정렬
	//	sort(players.begin(), players.end(), [](const Player& a, const Player& b)
	//		{
	//			return a.getScore() < b.getScore();
	//		});

	//	cout << "\n[Score 기준 출력]" << endl;
	//	for (int targetScore : scoresToFind)
	//	{
	//		Player keyScore(targetScore);

	//		auto range_score = equal_range(players.begin(), players.end(), keyScore,
	//			[](const Player& a, const Player& b)
	//			{
	//				return a.getScore() < b.getScore();
	//			});

	//		if (range_score.first != players.begin())
	//			prev(range_score.first)->show();

	//		if (range_score.first != range_score.second)
	//			range_score.first->show();

	//		if (range_score.second != players.end())
	//			range_score.second->show();

	//		cout << "----" << endl;
	//	}
	//}

}