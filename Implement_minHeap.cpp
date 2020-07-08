#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class heapper{
    private : vector<int > v;
              int idx;
    public:
    heapper(void);
    void insert(int k);
    void getmin(void);
    void delmin(void);   
    void heapify(int i);    
};

heapper :: heapper(void){
    v.clear();
    idx=-1;
}

void heapper :: insert(int k){
    v.push_back(k);
    idx++;
    int temp, i= idx;
    while(i>0 && v[i]< v[(i-1)/2]){
        temp=v[(i-1)/2];
        v[(i-1)/2]=v[i];
        v[i]=temp;
        i=(i-1)/2;
    }
}

void heapper :: getmin(void){
    if(idx==-1){
        cout<<"Empty"<<'\n';
    }
    else{
        cout<<v[0]<<'\n';
    }
}

void heapper :: delmin(void){
    if(idx==-1){
        return;
    }
    if(idx==0){
        v.clear();
        idx--;
        return ;
    }
    v[0]=v[idx];
    idx--;
    v.pop_back();
    heapify(0);
}

void heapper :: heapify(int i){
    int lar=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<=idx && v[lar]>v[l]){
        lar=l;
    }
    if(r<=idx && v[lar]>v[r]){
        lar=r;
    }
    if(lar!=i){
        int t=v[i];
        v[i]=v[lar];
        v[lar]=t;
    }
    else{
        return;
    }
    heapify(lar);
}

int main() {
    
    int n,k;
    cin>>n;
    string s;
    heapper h;
    for(int j=0;j<n;j++){
        cin>>s;
        if(s[0]=='i'){
            cin>>k;
            h.insert(k);
        }
        if(s[0]=='g'){
            h.getmin();
        }
        if(s[0]=='d'){
            h.delmin();
        }
    }
    return 0;
}
