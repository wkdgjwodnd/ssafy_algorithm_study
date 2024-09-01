#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
	int age;
	int idx;
	string name;
};

bool cal(Person a, Person b) {
	if (a.age == b.age) {
		return a.idx < b.idx;
	}
	return a.age < b.age;
}

vector<Person> v;
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		string str;
		cin >> tmp;
		cin >> str;
		v.push_back({ tmp,i, str });
	}

	sort(v.begin(), v.end(), cal);

	for (int i = 0; i < N; i++) {
		cout << v[i].age << " ";
		for (int j = 0; j < v[i].name.length(); j++)
		{
			cout << v[i].name[j];
		}
		cout << "\n";
	}

}