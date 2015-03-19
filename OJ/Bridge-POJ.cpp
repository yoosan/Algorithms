
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

int n, i, j, k, a[100000];

int ans = 0;

int main()
{
    int n = 0;
    cin >> n;
    for(i = 0; i < n; i ++) cin >> a[i];
    
    if (n == 1) {
        cout << a[0] << endl << a[0] << endl;
        return 0;
    }
    
    int nn = n;
    sort(a, a + n);
    
    while (n > 3) {
        if (a[0] + a[n-2] < 2 * a[1]){
            ans += 2 * a[0] + a[n-1] + a[n-2];
        }
        else {
            ans += 2 * a[1] + a[0] + a[n-1];
        }
        n -= 2;
    }
    
    if (n == 2) ans += a[1];
    else ans += a[0] + a[n-1] + a[1];
    
    cout << ans << endl;
    
    n = nn;
    
    while (n > 3){
        if (a[0] + a[n-2] < 2 * a[1]){
            cout << a[0] <<" " << a[n-1] <<endl;
            cout << a[0] << endl;
            cout << a[0] <<" " << a[n-2] <<endl;
            cout << a[0] << endl;
        }
        else {
            cout << a[0] <<" " <<a[1] <<endl;
            cout << a[0] << endl;
            cout <<a[n-2] <<" " << a[n-1] <<endl;
            cout << a[1] <<endl;
        }
        n -= 2;
    }
    
    if (n==2) cout << a[0] << " " << a[1] <<endl;
    else {
        cout << a[0] << " "<< a[n-1] <<endl;
        cout << a[0] << endl;
        cout << a[0] << " " <<a[1] << endl;
    }
    
    return 0;
}
