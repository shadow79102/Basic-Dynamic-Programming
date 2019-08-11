#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void minCoins(vector <int> coins, int sum){
    int n = coins.size();
    vector <int> res(sum+1, 10000), sol(sum+1, -1);
    res[0] = 0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=sum; j++){
            if(coins[i] <= j){
                int temp = 1+res[j-coins[i]];
                if(temp < res[j]){
                    res[j] = temp;
                    sol[j] = i;
                }
            }
        }
    }
    if(res[sum] == 10000) cout << "Not possible" << endl;
    else{
        cout << res[sum] << " coins needed\nand the coins are ";
        int i = sum;
        do{
            cout << coins[sol[i]] << " ";
            i -= coins[sol[i]];
        }while(i>0);
    }
}

int main(){
    int n, sum;
    cout << "enter no. of types of coins" << endl;
    cin >> n;
    vector <int> coins(n);
    cout << "enter values of coins" << endl;
    for(int i=0; i<n; i++) cin >> coins[i];
    cout << "enter total sum" << endl;
    cin >> sum;
    minCoins(coins,sum);

    return 0;
}
