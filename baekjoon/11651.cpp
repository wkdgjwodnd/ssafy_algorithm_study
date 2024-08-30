#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
	int x;
	int y;
};

bool cal(Point a, Point b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

vector<Point> v;
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int ty, tx;
		cin >> tx >> ty;
		v.push_back({ tx, ty });
	}

	sort(v.begin(), v.end(), cal);

	for (int i = 0; i < N; i++) cout << v[i].x << " " << v[i].y << "\n";

}