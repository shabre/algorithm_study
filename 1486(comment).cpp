#include <cstdio> 
#include <iostream>
#include <vector>
#include <algorithm>


/*
이번에는 그나마 보기 괜찮은 코드라고 생각합니다.

기본 아이디어는 역시 플로이드-워셜 알고리즘입니다
대신 제가 이전에 풀었던 케빈 베이컨 문제와 다른 점이라면 directed graph라는 점이겠네요.

최백준씨 강의에 따르면 양방향 그래프는 연결 리스트로 구현하는게 좋다고 했는데
연결 리스트로 플로이드-워셜 알고리즘을 어떻게 구현해야 할 지 모르겠어서 그냥 인접행렬을 사용했습니다.

x, y 좌표로 나타낼 수 있기 때문에 이차원 배열이 편하긴 할텐데, 그냥 일차원 배열로 바꾸어서 풀었습니다.
벡터 v에는 각 좌표의 높이가 들어가고(index는 [10][10] 크기의 경우 0부터 99까지겠죠)
dis 배열에는 일차원으로 바뀐 좌표간 거리가 들어갑니다.
여기서 벡터 v에 들어가 있는 높이를 잘 비교해서 1 혹은 두 값 차의 제곱을 넣어야 합니다.

여기까지가 초기화 과정이고, 나머지는 플로이드-워셜 알고리즘을 돌리면 값이 잘 튀어나옵니다.

또 하나 중요한건 (어떤 지점까지 가는데 걸리는 시간 + (0,0) 좌표까지 돌아오는 시간 < d)라는 건데
알고리즘 다 돌리고 그대로 비교를 하면 바로 나옵니다.
이 부분을 포함해 최고 높이를 구하는 부분(즉 정답을 구하는 부분)을 조금 더 효율적으로 구현할 수 있을 것 같기는 한데
뭐 어차피 시간이 오래 걸리는 부분은 아니니까 대충 구현했습니다...

시간복잡도는 대충 O((n*m)^3)인데 n,m <=25 라 문제없이 돌아가는 것 같네요

*/
#define BIG 987654321
using namespace std;

int dis[630][630] = { BIG };

int main(void) {
	int n, m, t, d;
	char garbage;
	scanf("%d %d %d %d", &n, &m, &t, &d);
	scanf("%c", &garbage); // 개행문자 처리
	vector<int> v;
	vector<int> ans;

	for (int i = 0; i < n*m; i++) {
		for (int j = 0; j < n*m; j++) {
			dis[i][j] = BIG;
			if (i == j) {
				dis[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char t;
			scanf("%c", &t);
			v.push_back(t - 65);
		}
		scanf("%c", &garbage); // 개행문자 처리
	}

	for (int i = 0; i < n*m; i++) {
		if (v[i] > 25) {
			v[i] -= 6;
		}
	}

	for (int i = 0; i < n * m; i++) { 
		if (i % m != 0) { // 왼쪽 있음
			if (v[i] >= v[i - 1]) { // 현재 지점이 왼쪽 지점보다 높거나 같음
				if (v[i] - v[i - 1] <= t) {
					dis[i][i - 1] = 1;
				}
			}
			else {
				if (v[i - 1] - v[i] <= t) {
					dis[i][i - 1] = (v[i] - v[i - 1]) * (v[i] - v[i - 1]);
				}
			}
		}
		if (i % m != m-1) { // 오른쪽 있음
			if (v[i] >= v[i + 1]) { // 현재 지점이 오른쪽 지점보다 높거나 같음
				if (v[i] - v[i + 1] <= t) {
					dis[i][i + 1] = 1;
				}
			}
			else {
				if (v[i + 1] - v[i] <= t) {
					dis[i][i + 1] = (v[i] - v[i + 1]) * (v[i] - v[i + 1]);
				}
			}
		}
		if (i / m != 0) { // 위쪽 있음
			if (v[i] >= v[i - m]) { // 현재 지점이 위쪽 지점보다 높거나 같음
				if (v[i] - v[i - m] <= t) {
					dis[i][i - m] = 1;
				}
			}
			else {
				if (v[i - m] - v[i] <= t) {
					dis[i][i - m] = (v[i] - v[i - m]) * (v[i] - v[i - m]);
				}
			}
		}
		if (i / m != n - 1) { // 아래쪽 있음
			if (v[i] >= v[i + m]) { // 현재 지점이 아래쪽 지점보다 높거나 같음
				if (v[i] - v[i + m] <= t) {
					dis[i][i + m] = 1;
				}
			}
			else {
				if (v[i + m] - v[i] <= t) {
					dis[i][i + m] = (v[i] - v[i + m]) * (v[i] - v[i + m]);
				}
			}
		}
	}

	for (int k = 0; k < n*m; k++) {
		for (int i = 0; i < n*m; i++) {
			for (int j = 0; j < n*m; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n*m; i++) {
		if (dis[0][i] + dis[i][0] > d) {
			continue;
		}
		ans.push_back(v[i]);	
	}

	sort(ans.begin(), ans.end());
	int size = ans.size();
	if (size == 0) {
		cout << v[0];
		cin >> n;
		return 0;
	}
	int max = ans[size - 1];

	cout << max << '\n';
	cin >> n;
}