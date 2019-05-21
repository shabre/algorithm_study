#include <cstdio>
#include <iostream>
#include <vector>

#define MAX 987654321

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> v;
	v.resize(n + 1);

	for (int i = 0; i < n; i++) {	// 벡터 초기화
		for (int j = 0; j < n; j++) {
			if (i == j) {
				v[i].push_back(0);
			}
			v[i].push_back(MAX);
		}
	}
	
	while (m--) { // 입력받은대로 인접 그래프 그리기
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		v[t1 - 1][t2 - 1] = 1;
		v[t2 - 1][t1 - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == MAX) printf("INF ", v[i][j]);
			else printf("%3d ", v[i][j]);
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++) { // 플로이드-워셜 알고리즘 수행. 시간복잡도는 O(n^3)인데 n <= 100에 2초 안에 수행되면 되기 때문에 ok
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (v[k][j] > v[k][i] + v[i][j]) {
					v[k][j] = v[k][i] + v[i][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == MAX) printf("INF ", v[i][j]);
			else printf("%3d ", v[i][j]);
		}
		cout << '\n';
	}

	int min = MAX, ans = 0;
	for (int i = n-1; i >= 0; i--) {
		int s = 0;
		for (int j = 0; j < n; j++) {
			s += v[i][j];
		}
		if (min >= s) {
			min = s;
			ans = i;
		}
	}
	printf("%d", ans+1); // 인덱스로 쓴 거라 +1 해줘야 올바른 번호 출력

	cin >> n;
}