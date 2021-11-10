#include<fstream>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	while (n > 0) {
		int kind_number;
		cin >> kind_number;
		map < string, vector<string>> closet;


		for (int i = 0; i < kind_number; ++i) {
			string kind, cloth;
			cin >> cloth >> kind;

			auto find_cloth = closet.find(kind);
			if (find_cloth != closet.end()) {
				find_cloth->second.push_back(cloth);
			}
			else {
				vector<string> clothes;
				clothes.push_back("none");
				clothes.push_back(cloth);

				closet.insert({ kind, clothes });
			}
		}

		int cloth_case = 1;
		for (auto i = closet.begin(); i != closet.end(); ++i) {
			cloth_case *= i->second.size();
		}
		cloth_case -= 1;

		cout << cloth_case << endl;

		n--;
	}
	return 0;
}
