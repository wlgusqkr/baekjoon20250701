#include<bits/stdc++.h>

using namespace std;

int num, arr[23][23], ret = 9999999;

int go(vector<int>& start, vector<int>& link) {
    pair<int, int> ret;
    for(int i = 0 ; i < num / 2; i++) {
        for(int j = 0 ; j < num / 2; j++) {
            if(i == j) continue;
            ret.first += arr[start[i]][start[j]];
            ret.second += arr[link[i]][link[j]];
        }
    }
    return abs(ret.first - ret.second);
}


int main(){
    vector<int> vec;
    cin >> num;
    
    for(int i = 0 ; i < num; i++) {
        for(int j = 0; j < num; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0 ; i < (1 << num); i++) {
        vector<int> start, link;
        if(__builtin_popcount(i) != num / 2) continue;
        for(int j = 0; j < num; j++) {
            if( i & (1 << j)) start.push_back(j);
            else link.push_back(j);
        }
        ret = min(ret, go(start, link));
    }
    cout << ret;
}
