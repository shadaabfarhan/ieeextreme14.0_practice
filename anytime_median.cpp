#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k,t,pm;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    priority_queue<int , vector<int >,greater<int >>mih;
    priority_queue<int >mah;
    while(t--){
        cin>>n;
        cin>>k;
        mah.push(k);
        pm=k;
        cout<<k<<' ';
        for(int i=1;i<n;i++){
            cin>>k;
            if(mah.size()>mih.size()){
                if(k<pm){
                    mih.push(mah.top());
                    mah.pop();
                    mah.push(k);
                    pm=mah.top();
                }
                else{
                    mih.push(k);
                }
                cout<<pm<<' ';
            }
            else if(mah.size()<mih.size()){
                if(k<pm){
                    mah.push(k);
                    pm=mah.top();
                }
                else{
                    mah.push(mih.top());
                    mih.pop();
                    mih.push(k);
                    pm=mah.top()
;                }
                cout<<pm<<' ';
            }
            else{
                if(k<=pm){
                    mah.push(k);
                    pm=mah.top();
                }
                else{
                    mih.push(k);
                    pm=mih.top();
                }
                cout<<pm<<' ';
            }
            
        }
        while(mih.size()!=0){
            mih.pop();
        }
        while(mah.size()!=0){
            mah.pop();
        }
        cout<<'\n';
        
    }
    return 0;
}
