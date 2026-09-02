#include<iostream>
#include<string>
using namespace std;
int main(){
    string input;
    getline(cin,input);
    string key;
    cin>>key;
    string final="";
    int len = input.length();
    for(int i = 0; i < len ; i++)
    {
        int pos = (i%((int)key.size()));
        int val = ((input[i]-'A')+(key[pos]-'A'))%26;
        final += 'A'+val;
    }
    for(auto it : final)
    {
        cout<<it<<" ";
    }
    return 0;
}