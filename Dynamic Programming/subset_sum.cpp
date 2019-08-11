#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void subsetSum(int a[], int n, int sum){
    bool res[n+1][sum+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j==0) res[i][j] = true;
            else if(i==0) res[i][j] = false;
            else res[i][j] = (res[i-1][j] || res[i-1][j-a[i-1]]);
        }
    }
    //cout << res[n][sum]<<endl;
    res[n][sum] ? (cout<<"subset exists"<<endl) : (cout<<"subset doesn't exist"<<endl);
    if(res[n][sum]){
        vector <int> sol;
        int i=n, j=sum;
        while(i>0 && j>0){
            if(res[i-1][j]) i--;
            else{
                sol.push_back(a[i-1]);
                j -= a[i-1];
                i--;
            }
        }
        cout << "The subset is" << endl;
        for(i=sol.size()-1; i>=0; i--) cout << sol[i] << " ";
    }
}

int main(){
    int n, sum;
    cout << "Enter no. of elements" << endl;
    cin >> n;
    int a[n];
    cout << "enter the elements" << endl;
    for(int i=0; i<n; i++) cin >> a[i];
    cout << "enter the subset sum" << endl;
    cin >> sum;
    subsetSum(a,n,sum);
    return 0;
}
