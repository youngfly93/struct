#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main(){
    int flag = 0,n;
    cin >> n;
    vector<string> ops(n),s;
    string target;
    for(int i =0;i<n;i++) cin >> ops[i];
    cin >> target;
    for(int i = 0;i<n;i++){
        if(target == ops[i]){
            flag = 1;
            s.push_back(ops[i]);
            break;
        }
        if(ops[i] == "return") && !s.empty() s.pop_back();
        else s.push_back(ops[i]);  
    }
    if(flag){
        for(int i = 0;i < s.size();i++){
            if(i) cout << "->";
            cout << s[i];
        }
        cout<<endl;
    } else{
        cout << "NOT REFERENCED" << endl;
    }
    return 0;
}