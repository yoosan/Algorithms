#include <iostream>
#include <stack>
using namespace std;

int Volume(int *height, int n){
    int h = height[0];
    int v = 0;
    int t = 0;
    for (int i = 0; i < n; i++){    //先从左到右遍历一遍，先以最左为最高点，遇到
        if (height[i] < h)          //小于最高点的，就在临时变量加上高度差。直到
            t += h - height[i];     //遇到大于等于原最高点，此时在结果上加上临时
        else {                      //变量，更新最高，重置临时变量。再从右到左一次
            h = height[i];          //相当于最高的点把一段分为两部分，第一次遍历
            v += t;                 //得到左半边的体积，第二次遍历得到右半边的。
            t = 0;
        }
    }
    
    h = height[n-1];
    t = 0;
    for (int i = n - 1; i > -1; i--){
        if (height[i] < h)
            t += h - height[i];
        else {
            v += t;
            h = height[i];
            t = 0;
        }
    }
    return v;
}


int main()
{
    int a[] = { 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    
    cout << Volume(a, 11)<<endl;
    
}