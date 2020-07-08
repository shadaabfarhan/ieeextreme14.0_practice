#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int cuts;

bool check(string &s,pair<int,int>p){
    char c=s[p.first];
    for(int i=p.first;i<=p.second;i++){
        if(s[i]!=c){
            return 0;
        }
    }
    return 1;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        string s;
        cuts=0;
        cin>>s;
        queue<pair<int,int>>q;
        q.push({0,s.length()-1});
        pair<int,int>p;
        bool flag = 0;
        while(!q.empty()){
            int n= q.size();
            while(n--){
                p= q.front();
                q.pop();
                if(check(s,p)){
                    flag=1;
                    break;
                }
                if((p.second-p.first+1)%2==0){
                    int mid =p.first + (p.second-p.first+1)/2;
                    if(mid>=p.first && mid<=p.second){
                        q.push(make_pair(p.first,mid-1));
                        q.push(make_pair(mid,p.second));
                    }
                }
            }
            if(flag){
                break;
            }
            cuts++;
        }
        if(flag){
            cout<<cuts <<'\n';
        }
        else{
            cout<< -1 << '\n';
        }
    }
    return 0;
}
