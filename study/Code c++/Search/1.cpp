#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int l,int r,int x){
    while(l<=r){
        int m = (l+r)/2;
        if(a[m]==x){
            return m;
        }else{
            if(a[m] > x){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
    }
    return -1;
}


int main(){
    int a[] = {7, 10, 15, 19, 23, 28, 32, 34, 42, 49, 52};
    int n = 11;
    int x = 28;
    int l = 0;
    int r = 10;
    cout << binarySearch(a,l,r,x);
}