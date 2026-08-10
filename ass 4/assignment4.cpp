#include<iostream>
#include<vector>
#include<string>
using namespace std;
class comp{
    public:
    bool operator()(pair<char,int>&a , pair<char,int>&b)
    {
        return a.first < b.first;
    }
};
int main(){
    string PlainText ;
    string word;
    cout<<"enter the word :";
    getline(cin , word);
    cout<<"enter the plain Text :";
    getline(cin , PlainText);
    string FinalPlain= "";
    unordered_map<char,bool>visited_in_Plain;
    for(auto it : PlainText)
    {
        if(it == ' ')
        {
            continue;
        }
        else
        {
            FinalPlain += it;
            visited_in_Plain[it] = true;
        }
    }
    string FinalWord= "";
    for(auto it : word)
    {
        if(it == ' ')
        {
            continue;
        }
        else
        {
            FinalWord += it;
        }
    }
    cout<<" finalword : "<<FinalWord<<endl;
    int left_words =min((((int)FinalPlain.size())%((int)FinalWord.size())) , (int)FinalWord.size() - (((int)FinalPlain.size())%((int)FinalWord.size())));
    cout<<left_words<<endl;
    for(int i = 26 - left_words ; i<26; i++)
    {
        FinalPlain += ('a' + i);
    }
    cout<<" finalPlain : "<<FinalPlain<<endl;
    vector<pair<char,int>>store;
    for(int i = 0 ; i < FinalWord.size() ; i++)
    {
        store.push_back({FinalWord[i] , i});
    }
    sort(store.begin() , store.end(), comp());
    string cypherText = "";
    for(int i = 0 ; i < store.size() ; i++)
    {
        int pos = store[i].second;
        while(pos < FinalPlain.size())
        {
            cypherText+= FinalPlain[pos];
            pos += FinalWord.size();
        }
    }
    cout<<endl<<cypherText<<endl;

    return 0;
}