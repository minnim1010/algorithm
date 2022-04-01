#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef struct {
    int x;
    int y;
} LOCATE;

int N, M, tmp, size_h = 0, size_ch = 0, ans = 1300;
vector<LOCATE> home, chick;
int dis[13][100] = {0};

int calChickDistance(vector<int> chick){
    int chickDis = 0;

    for (int i = 0; i < size_h; ++i) {
        int min = 100;
        for (auto j = chick.begin(); j < chick.end(); ++j) {
            if(min > dis[*j][i])
                min = dis[*j][i];
        }
        chickDis += min;
    }
    return chickDis;
}

void solution(vector<int> chick, int idx){
    int size = chick.size();

    if(idx > size_ch)
        return;

    if(size == M){
        int dis = calChickDistance(chick);
        if(ans > dis) ans = dis;
        return;
    }

    vector<int> nchick;
    nchick.assign(chick.begin(), chick.end());
    nchick.push_back(idx);

    solution(nchick, idx+1);
    solution(chick, idx+1);
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> tmp;
            if (tmp == 1)
                home.push_back({i, j});
            else if(tmp == 2)
                chick.push_back({i, j});
        }
    }

    size_h = home.size();
    size_ch = chick.size();

    //각 치킨 집에 대한 각 집의 거리 계산
    for (int i = 0; i < size_ch; ++i) {
        for (int j = 0; j < size_h; ++j) {
            dis[i][j] = abs(chick[i].x-home[j].x) + abs(chick[i].y-home[j].y);
        }
    }

    vector<int> chick;
    solution(chick, 0);

    cout << ans;

    return 0;
}
