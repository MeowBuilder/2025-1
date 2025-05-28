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
	string name; // �̸�, ����[3, 15], ['a', 'z']�θ� ����
	int score; // ����
	size_t id; // ���̵�, ��ġ�� ���̵� ���� �� ����
	size_t num; // free store�� Ȯ���� ����Ʈ ��
	unique_ptr<char[]> p; // free store�� Ȯ���� �޸�

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
		println("�̸�:{:<15}, ���̵�:{:<16}, ����:{:<16}, �ڿ�:{:<16}", name, id, score, num);
		cout.write(p.get(), num); // num���� ��� -> '\0'�� ��� ����� ���� �ذ�
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
	// 1��
	ifstream in{ "2025 STL ���� ���� - 2021182009",ios::binary };
	if (not in) return 2021182009;

	for (Player& data : players)
	{
		data.read(in);
	}

	cout << "==========1��==========" << endl;
	players.back().show();



	// 2�� ==============================
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
	//	cout << "���� �ð�: " << duration.count() << "ms\n";

	//	cout << fixed; // �Ҽ��� ǥ�� ����
	//	cout << "��� ����:" << average << endl; // �Ҽ��� ǥ���ؾ���
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
	//cout << "���� �ð�: " << duration.count() << "ms\n";

	cout << "==========2��==========" << endl;
	maxPlayer->show();

	cout << fixed; // �Ҽ��� ǥ�� ����
	cout << "��� ����:" << average << endl; // �Ҽ��� ǥ���ؾ���


	


	// 3�� ==============================
	//�ð� �ʹ� ���� �ɸ�
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

	ofstream out{ "�������̵�.txt" };
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
				out << "�̸� :" << players[i - 1].getName() << ", ID :" << players[i - 1].getId();
				++countsame;
				isFirstSame = true;
			}
			out << " / " << "�̸� :" << players[i].getName() << ", ID :" << players[i].getId();
			++countsame;
		}
		else
		{
			if (isFirstSame) out << endl;
			isFirstSame = false;
		}
	}

	cout << "==========3��==========" << endl;
	cout << "���� id�� ���� ��ü ��: " << countsame << '\n';



	// 4�� ==============================
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
	//	cout << "���� �ð�: " << duration.count() << "ms\n";
	//	cout << "a�� 10���� �̻��� ��ü ��: " << count10A << '\n';
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
	//cout << "���� �ð�: " << duration.count() << "ms\n";
	
	cout << "==========4��==========" << endl;
	cout << "a�� 10���� �̻��� ��ü ��: " << count10A << '\n';
	
	
	// 5�� ==============================

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


	cout << "==========5��==========" << endl;

	while (true)
	{
		cout << "====================" << endl << "ID�� �Է��ϼ���. : ";
		size_t inputID;
		if (!(cin >> inputID))
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "ID�Է��� �ùٸ��� �ʽ��ϴ�." << endl;
			continue;
		}

		// ID ���� Ž��
		auto start = lower_bound(playersById.begin(), playersById.end(), inputID, [](const Player* a, size_t id) {
				return a->getId() < id;
			});

		if (start == playersById.end() || (*start)->getId() != inputID) {
			cout << "�ش� ID�� ���� Player�� �������� �ʽ��ϴ�.\n";
			continue;
		}

		auto end = start;
		while (end != playersById.end() && (*end)->getId() == inputID)
			++end;

		// ID ���� ���
		cout << "\n[ID ���� ���]\n";
		if (start != playersById.begin())
			(*prev(start))->show();

		for (auto ptr = start; ptr != end; ++ptr)
			(*ptr)->show();

		if (end != playersById.end())
			(*end)->show();

		// �̸� ���� ���
		cout << "\n[Name ���� ���]\n";
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

		// ���� ���� ���
		cout << "\n[Score ���� ���]\n";
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
	//	cout << "====================" << endl << "ID�� �Է��ϼ���. : ";
	//	size_t inputID;
	//	if (!(cin >> inputID))
	//	{
	//		cin.clear();
	//		cin.ignore(100, '\n');
	//		cout << "ID�Է��� �ùٸ��� �ʽ��ϴ�." << endl;
	//		continue;
	//	}

	//	// ID ���� ����
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
	//		cout << "�ش� ID�� ���� Player�� �������� �ʽ��ϴ�.\n";
	//		continue;
	//	}

	//	// ���� ID ���� Player ���
	//	cout << "\n[ID ���� ���]" << endl;
	//	if (range_id.first != players.begin())
	//		prev(range_id.first)->show();

	//	for (auto it = range_id.first; it != range_id.second; ++it)
	//		it->show();

	//	if (range_id.second != players.end())
	//		range_id.second->show();

	//	// name/score ���� �񱳿� �� ���� (�ߺ� ���� ���� set ���)
	//	set<string> namesToFind;
	//	set<int> scoresToFind;

	//	for (auto it = range_id.first; it != range_id.second; ++it)
	//	{
	//		namesToFind.insert(it->getName());
	//		scoresToFind.insert(it->getScore());
	//	}

	//	// �̸� ���� ����
	//	sort(players.begin(), players.end(), [](const Player& a, const Player& b)
	//		{
	//			return a.getName() < b.getName();
	//		});

	//	cout << "\n[Name ���� ���]" << endl;
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

	//	// ���� ���� ����
	//	sort(players.begin(), players.end(), [](const Player& a, const Player& b)
	//		{
	//			return a.getScore() < b.getScore();
	//		});

	//	cout << "\n[Score ���� ���]" << endl;
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