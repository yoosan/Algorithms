
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}


int main()
{
    int t = 0;
    cin >> t;
    while (t--){
        int l , n;
        cin >> l >> n;
        int  minlen = 0, maxlen = 0;
        while (n--){
            int position = 0;
            cin >> position;
            int little = min(position, l - position);
            int big = max(position, l - position);
            minlen = max(minlen, little);
            maxlen = max(maxlen, big);
        }
        cout << minlen << " " << maxlen << endl;
    }
    return 0;
}
