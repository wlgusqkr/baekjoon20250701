#include <bits/stdc++.h>
using namespace std;

int N;

char sign[10];
int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int main() {
    
    cin >> N;
    
    for(int i = 0 ; i < N; i++) {
        cin >> sign[i];
    }

    // true를 하고 전체를 돌았는데 true라면 통과 false라면 다시 돌기
    bool ok = true;

    sort(arr, arr + 10, greater<>());

    do{
        ok = true;
        for(int i = 0 ; i < N; i++) {
            char c = sign[i];
            if(c == '<') {
                if( arr[i] > arr[i + 1] ){
                    ok = false;
                    break;
                }
            } else if (c == '>') {
                if( arr[i] < arr[i + 1] ){
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            break;
        }
        
        reverse(arr + (N + 1), arr + 10);
        
    }while(prev_permutation(arr, arr + (N + 1)));
        
    if(ok) {
        for(int i = 0 ;i <= N; i++) {
            cout << arr[i];
        }
    }
    
    cout << endl;
    sort(arr, arr + 10);
    
    do{
        ok = true;
        for(int i = 0 ; i < N; i++) {
            char c = sign[i];
            if(c == '<') {
                if( arr[i] > arr[i + 1] ){
                    ok = false;
                    break;
                }
            } else if (c == '>') {
                if( arr[i] < arr[i + 1] ){
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            break;
        }
        
        reverse(arr + (N + 1), arr + 10);
        
    }while(next_permutation(arr, arr + (N + 1)));
        
    if(ok) {
        for(int i = 0 ;i <= N; i++) {
            cout << arr[i];
        }
    }
    cout << endl;
    
}
