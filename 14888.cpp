#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int ar[11] = {0};
int op_num[4];
int mymin = 1000000000, mymax = -1000000000;

void solution(int cal, int idx){
    if(idx == N){
        if(cal < mymin)
            mymin = cal;
        if(cal > mymax)
            mymax = cal;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if(op_num[i] > 0){
            --op_num[i];
            if(i == 0){
                solution(cal+ar[idx], idx+1);
            }
            else if(i == 1){
                solution(cal-ar[idx], idx+1);
            }
            else if(i == 2){
                solution(cal*ar[idx], idx+1);
            }
            else
                solution(cal/ar[idx], idx+1);
            ++op_num[i];
        }
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> ar[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> op_num[i];
    }

    solution(ar[0], 1);

    cout << mymax << '\n' << mymin;

    return 0;
}
