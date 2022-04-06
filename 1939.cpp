#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

typedef struct{
    int dst;
    int w;
} BRIDGE;

int N, M, A, B;
int C;
vector<BRIDGE> land[10001];
bool visited[10001] = {0};

bool dfs(int src, int dst, int weight){

    if(visited[src]) return false;

    visited[src] = true;
    if(src == dst) return true;

    for (auto it = land[src].begin(); it < land[src].end(); ++it) {
        if(it->w >= weight && dfs(it->dst, dst, weight))
                return true;
    }

    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int left = 1, right = 1;

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        cin >> A >> B >> C;
        land[A].push_back({B, C});
        land[B].push_back({A, C});
        right = max(right, C);
    }

    cin >> A >> B;

    while(left <= right){
        memset(visited, 0, sizeof(visited));

        int mid = (left+right)/2;
        if(dfs(A, B, mid))
            left = mid+1;
        else
            right = mid-1;
    }

    cout << right;

    return 0;
}

