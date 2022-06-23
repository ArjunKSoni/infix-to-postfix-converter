#include <bits/stdc++.h>
using namespace std;

bool charCheck(char k,string operato){
    for(int i=0;i<6;i++){
        if(k==operato[i])return 0;
    }return 1;
}
void display(char k[50],int it){
    for(int i=0;i<=it;i++){
        cout<<k[i];
    }cout<<endl;
}

void solver(string str,map<char,int>&mp,stack<char>&st,string operato){
    char k[50];
    int it=-1;
    st.push('(');
    for(int i=0;i<str.length();i++){
        char we=str[i];
        if(charCheck(we,operato))k[++it]=we;
        else{
            char q=st.top();
            if(mp[q]>mp[we]){
                k[++it]=q;
                st.pop();st.push(we);
            }else if(we==')'){
                while(st.top()!='('){
                    q=st.top();k[++it]=q;
                    st.pop();
                }
            }
            else{
                st.push(we);
            }
        }
    }if(!st.empty()){
        while(st.top()!='('){
            char q=st.top();k[++it]=q;
            st.pop();
        }
    }
    display(k,it);
}

int main(){
    map<char,int>mp;
    stack<char>st;
    mp['(']=0;
    mp['/']=4;
    mp['*']=3;
    mp['+']=2;
    mp['-']=1;
    string operato="(/*+-)";
    string str;
    cout<<"enter the valid expression : ";cin>>str;
    solver(str ,mp,st,operato);
}