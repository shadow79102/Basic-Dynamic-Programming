#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void knapsack(int w[], int v[], int n, int W){
    int res[n+1][W+1];
    for(int i=0; i<=n; i++)
        res[i][0] = 0;
    for(int i=0; i<=W; i++)
        res[0][i] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(w[i-1] > j)
                res[i][j] = res[i-1][j];
            else
                res[i][j] = max((v[i-1]+res[i-1][j-w[i-1]]), (res[i-1][j]));
        }
    }
    vector <int> sol;
    int i=n, j=W;
    while(i>0 && j>0){
        //cout << i << j << endl;
        if(res[i][j] != res[i-1][j]){
            sol.push_back(w[i-1]);
            j-=w[i-1];
            i--;
        }
        else i--;

    }
    cout << "maximum possible value is " << res[n][W] << endl;
    cout << "the selected weights are ";
    for(i=sol.size()-1; i>=0; i--) cout << sol[i] << " ";
}

int main(){
    int n, W;
    cout << "Enter no. of items" << endl;
    cin >> n;
    int w[n],v[n];
    cout << "Enter weights of items" << endl;
    for(int i=0; i<n; i++)
        cin >> w[i];
    cout << "Enter values of items" << endl;
    for(int i=0; i<n; i++)
        cin >> v[i];
    cout << "Enter max weight" << endl;
    cin >> W;
    knapsack(w,v,n,W);
    return 0;
}
