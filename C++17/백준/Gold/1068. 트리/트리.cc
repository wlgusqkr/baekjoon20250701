#include <bits/stdc++.h>
using namespace std;

int arr[55];

int N, deleteNum, topNum, res;
int main() {
    
    cin >> N;
    
    for(int i = 0 ; i < N; i++) {
        cin >> arr[i];
        if(arr[i] == -1) {
            topNum = i;
        }
    }
    cin >> deleteNum;
    arr[deleteNum] = -2;
    queue<int> que;

    if(deleteNum != topNum) {
        que.push(topNum);
    }
    
    while(que.size() != 0) {
        
        int top = que.front();
        que.pop();
        
        vector<int> vec;
        
        int count = 0;
        
        for(int i = 0 ; i < N; i++){
            if(top == arr[i]) {
                count++;
                vec.push_back(i);
            }
        }
        if(count == 0) {
            res++;
        } else {
            for(int k : vec) {
                que.push(k);
            }
        }
        
        
    }
    cout << res;

}
