// Phần tử đầu tiên lớn hơn bên phải ( Next Greater Element)
#include <bits/stdc++.h>
#include<stack>
using namespace std;


//cách 1
// int main(){
//     int n;cin>>n;
//     int a[n];
//     for(int &x : a) cin >> x;
//     for(int i=0;i<n;i++){
//         int res = -1;
//         for(int j=i+1;j<n;j++){
//             if(a[j]>a[i]){
//                 res=a[j];
//                 break;
//             }
//         }
//         cout << res << " ";
//     }
// }

//cách 2

int main(){
    int n;cin>>n;
    int a[n],b[n];
    for(int &x : a) cin >> x;

    stack<int> st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.push(i);
        }else{
            while(!st.empty() && a[st.top()] < a[i]){
                b[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        b[st.top()] = -1;
        st.pop();
    }
    for(int x : b){
        cout << x << " ";
    }
}