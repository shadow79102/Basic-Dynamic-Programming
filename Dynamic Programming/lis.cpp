#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector <int> a, vector <int> prev, int x){
    if(x == -1) return;
    print(a,prev,prev[x]);
    cout << a[x] << " ";
}

void lis(vector <int> a){
    int n = a.size();
    vector <int> res(n,1);
    vector <int> prev(n,-1);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[j] < a[i]){
                int temp = 1+res[j];
                if(temp > res[i]){
                    res[i] = temp;
                    prev[i] = j;
                }
            }
        }
    }
    int largest = INT_MIN, max_i;
    for(int i=0; i<n; i++){
        if(res[i] > largest){
            largest = res[i];
            max_i = i;
        }
    }
    cout << "length of lis: " << largest << endl << "and the sequence is" << endl;
    print(a,prev,max_i);
}

int main(){
    int n;
    cout << "enter no. of elements" << endl;
    cin >> n;
    vector <int> a(n);
    cout << "enter the elements" << endl;
    for(int i=0; i<n; i++) cin >> a[i];
    lis(a);

    return 0;
}
