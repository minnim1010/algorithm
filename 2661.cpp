#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int N;
int ar[81] = {0};
int ans[81] = {0};
bool flag = false;

bool isGood(int idx){
    int end = idx/2;
    for (int i = 2; i <= end; ++i) {
        if(!memcmp(ar+idx-2*i+1, ar+idx-i+1, sizeof(int)*i))
            return false;
    }
    return true;
}

void solution(int idx){
    if(flag) return;

    if(idx == N+1){
        for (int i = 1; i <= idx; ++i) {
            if(ans[i] < ar[i])
                break;
            else if(ans[i] > ar[i]){
                memcpy(ans, ar, sizeof(int)*idx);
                flag = true;
                break;
            }
        }
        return;
    }

    for (int i = 1; i <= 3; ++i) {
        if(i == ar[idx-1]) continue;
        ar[idx] = i;
        if(isGood(idx)){
            solution(idx+1);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        ans[i] = 4;
    }

    ar[1] = 1;
    solution(2);

    for (int i = 1; i <= N; ++i) {
        cout << ans[i];
    }

    return 0;
}
