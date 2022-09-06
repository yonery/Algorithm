// SWEA 5650번 핀볼 게임

/*
 시뮬레이션 문제입니다. 처음 제자리로 돌아오거나 블랙홀에 빠지면 이동을 종료합니다.
도형마다 전환되는 방향을 return 함수로 정해서 구현하고 웜홀은 벡터에 저장하여 해당 인덱스와 같은 원홀일 경우 위치를 변환해도록 구현했습니다.



 패쓰하기까지 꽤나 고전했습니다ㅠㅠ
이유는 벽과 삼각형이 붙어있을 때 3번 튕겨야하는데 일반적인 벽에 부딪힐 경우 좌표 유지시 방향과 충돌 횟수만 증가시키면 삼각형의 추가 충돌이 빠졌습니다. 
그래서 외벽을 사각형으로 도형으로 초기화해주고 네모에 튕긴 것처럼 구현해주니 패쓰했습니다.
 => 벽에 부딪혀도 점수를 얻는 다는 것에 착안하여 
 */

#include<iostream>
#include <vector>
using namespace std;

int map[102][102];
int N, res;
vector <pair<int, int >> wh;
vector <pair<int, int>> s;

struct point {
	int xpos;
	int ypos;
};

// 웜홀 처리
point find(int x, int y) {
	point t;
	t.xpos = x, t.ypos = y;
	for (int i = 0; i < wh.size(); i++) {
		int wx = wh[i].first, wy = wh[i].second;
		if (map[wx][wy] == map[x][y]) {
			if (wx == x && wy == y) {
				continue;
			}
			else {
				t.xpos = wx, t.ypos = wy;
				break;
			}
		}
	}
	return t;
}
// 부딪힐 경우 방향 변환
int make_d(int dir, int m) {
	if (m == 1) {
		if (dir == 0)
			return 2;
		else if (dir == 1)
			return 0;
		else if (dir == 2)
			return 3;
		else if (dir == 3)
			return 1;
	}
	else if (m == 2) {
		if (dir == 0)
			return 2;
		else if (dir == 1)
			return 3;
		else if (dir == 2)
			return 1;
		else if (dir == 3)
			return 0;
	}
	else if (m == 3) {
		if (dir == 0)
			return 1;
		else if (dir == 1)
			return 3;
		else if (dir == 2)
			return 0;
		else if (dir == 3)
			return 2;
	}
	else if (m == 4) {
		if (dir == 0)
			return 3;
		else if (dir == 1)
			return 2;
		else if (dir == 2)
			return 0;
		else if (dir == 3)
			return 1;
	}
	else if (m == 5) {
		if (dir == 0)
			return 2;
		else if (dir == 1)
			return 3;
		else if (dir == 2)
			return 0;
		else if (dir == 3)
			return 1;
	}

	return dir;
}

void dfs(int start, int x, int y, int dir, int cnt) {
	//cout << x << " " << y <<" : "<<dir<< "\n";
	int nx = x, ny = y, nd = dir;
    while(1){
	if (map[nx][ny] == -1) {
		res = res > cnt ? res : cnt;
		//cout << "end\n\n";
		return;
	}
	if (map[nx][ny] == 50 && cnt != -1) {
		res = res > cnt ? res : cnt;
		//cout << "end\n\n";
		return;
	}
	if (map[nx][ny] >= 6 && map[nx][ny] <= 10) {
		point txy;
		txy = find(nx, ny);
		nx = txy.xpos, ny = txy.ypos;
		cnt--;
	}
	nd = make_d(nd, map[nx][ny]);


	if (nd == 0) {
		for (int i = ny + 1; i <= N + 1; i++) {
			if (map[nx][i] != 0) {
				ny = i;
				break;
			}
		}
	}
	else if (nd == 1) {
		for (int i = nx + 1; i <= N + 1; i++) {
			if (map[i][ny] != 0) {
				nx = i;
				break;
			}
		}
	}
	else if (nd == 2) {
		for (int i = ny - 1; i >= 0; i--) {
			if (map[nx][i] != 0) {
				ny = i;
				break;
			}
		}
	}
	else if (nd == 3) {
		for (int i = nx - 1; i >= 0; i--) {
			if (map[i][ny] != 0) {
				nx = i;
				break;
			}
		}
	}
        cnt++;
    }

}

int main(){
    int T;
    cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{

		cin >> N;
		res = 0;
		//map[102][102] = { 0 };
		wh.clear();
		s.clear();

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 0)
					s.push_back({ i, j });
				else if (map[i][j] >= 6 && map[i][j] <= 10)
					wh.push_back({ i, j });

			}
		}
		for (int i = 0; i <= N + 1; i++) {
			map[i][0] = 5;
			map[i][N + 1] = 5;
			map[0][i] = 5;
			map[N + 1][i] = 5;
		}
        
        if(s.size() >0){
		for (int i = 0; i < s.size(); i++) {
			int x = s[i].first, y = s[i].second;
			for (int j = 0; j < 4; j++) {
				map[x][y] = 50;
				//cout << "start\n";
				dfs(i, x, y, j, -1);
				map[x][y] = 0;
			}
		}
        }
        else
            res = -1;
		cout << "#" << test_case << " " << res << "\n";


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
