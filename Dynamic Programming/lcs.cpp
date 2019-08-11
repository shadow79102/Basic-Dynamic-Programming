#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2){
    int l1 = s1.length(), l2 = s2.length();
    int res[l1+1][l2+1];
    for(int i=0; i<=l1; i++){
        for(int j=0; j<=l2; j++){
            if(i==0 || j==0) res[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) res[i][j] = 1+res[i-1][j-1];
            else res[i][j] = max(res[i-1][j], res[i][j-1]);
        }
    }
    int i=l1, j=l2;
    vector <char> ans;
    while(i>0 && j>0){
        if(res[i][j] == res[i][j-1]) j--;
        else if(res[i][j] == res[i-1][j]) i--;
        else{
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
    }
    cout << "length of lcs is " << res[l1][l2] << endl;
    cout << "The subsequence is" << endl;
    for(i=ans.size()-1; i>=0; i--) cout << ans[i];
}

int main(){
    string s1,s2;
    cout << "Enter 1st string" << endl;
    cin >> s1;
    cout << "Enter 2nd string" << endl;
    cin >> s2;
    lcs(s1,s2);

    return 0;
}
