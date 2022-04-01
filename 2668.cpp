#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int N, ar[101] = {0}, ans = 0;
bool visit[101];
vector<int> num_ans;

bool dfs(int idx, vector<int> num){
    if(!num.empty() && num[0] == idx){
        return true;
    }
    if(visit[idx])
        return false;
    num.push_back(idx);
    visit[idx] = true;
    return dfs(ar[idx], num);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> ar[i];
    }


    for (int i = 1; i <= N; ++i) {
        vector<int> num;
        memset(visit, 0, sizeof(bool)*101);
        if(dfs(i, num)){
            ans++;
            num_ans.push_back(i);
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < ans; ++i) {
        cout << num_ans[i] << '\n';
    }

    return 0;
}
