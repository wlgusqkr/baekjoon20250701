#include <bits/stdc++.h>
using namespace std;

int n, x, arr[100005], ret;
int main(){
    
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    
    sort(&arr[0], &arr[n]);
    
    int l = 0, h = n - 1;
    
    while( h > l ) {
        if((arr[l] + arr[h]) == x) ret++;
        if ((arr[l] + arr[h]) < x) l++;
        else if ((arr[l] + arr[h]) >= x) h--;
    }
    
    cout << ret;
    
    
}
