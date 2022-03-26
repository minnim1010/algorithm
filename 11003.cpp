#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int N, L;
int ar[5000000];
int s;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    deque<pair<int, int>> dq;
    for (int i = 0; i < N; ++i) {
        cin >> ar[i];
    }

    for (int i = 0; i < N; ++i) {
        s = i-L+1;
        if(s < 0) s = 0;
        if(!dq.empty() && dq.front().second < s)
            dq.pop_front();
        while(!dq.empty() && dq.back().first > ar[i]){
            dq.pop_back();
        }
        dq.push_back(make_pair(ar[i], i));

        cout << dq.front().first << ' ';
    }

    return 0;
}
