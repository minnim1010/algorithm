#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

int N, K, Q, M, S, E, idx, attend_num, cnt = 0;
int st[5003] = {0};
int sum[5003] = {0};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> Q >> M;

    for (int i = 0; i < K; ++i){
        cin >> idx;
        st[idx] = -1;
    }

    for (int i = 0; i < Q; ++i){
        cin >> attend_num;
        if(st[attend_num] != -1){
            for (int j = attend_num; j <= N+2; j+=attend_num) {
                if(st[j] == -1) continue;
                st[j] = 1;
            }
        }
    }

    for (int i = 0; i <= N+2; ++i) {
        if(st[i] == -1) st[i] = 0;
    }

    for (int i = 3; i <= N+2; ++i) {
        cnt += st[i];
        sum[i] = cnt;
    }

    for (int i = 0; i < M; ++i){
        cin >> S >> E;

        cout << E-S+1 - (sum[E] - sum[S-1])<< '\n';
    }

    return 0;
}
