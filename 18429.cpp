#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, K;
int visit[8] = {0};
int ar[8], cnt = 0;
int up[8] = {0};

bool satisfy(){
    int muscle = 0;
    for (int i = 0; i < N; ++i) {
        if(muscle < 0) return false;
        muscle += ar[up[i]];
        muscle -= K;
    }
    return true;
}

void solution(int idx){
    if(idx == N){
        if(satisfy()){
            cnt++;
        }
        return;
    }

    for (int i = 0; i < N; ++i) {

        up[idx] = i;
        if(!visit[i]){
            visit[i] = true;
            solution(idx+1);
            visit[i] = false;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> ar[i];
    }

    solution(0);

    cout << cnt;

    return 0;
}
