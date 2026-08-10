#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
class comp{
    public:
    bool operator()(const pair<char,int>&a , const pair<char,int>&b)
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
    for(int it = 0 ; it < PlainText.size() ; it++)
    {
        // if(it == ' ')
        // {
        //     continue;
        // }
        // else
        auto key = PlainText[it];
        if((key>='a' && key<='z')||(key>='A' && key<='Z')||(key>='0' && key<='9'))
        {
            FinalPlain += key;
            visited_in_Plain[key] = true;
        }
    }
    string FinalWord= "";
    for(auto it : word)
    {
        // if(it == ' ')
        // {
        //     continue;
        // }
        if((it>='a' && it<='z')||(it>='A' && it<='Z')||(it>='0' && it<='9'))
        {
            FinalWord += it;
        }
    }
    cout<<" finalword : "<<FinalWord<<endl;
    if (FinalWord.empty())
        {
            cout << "Invalid word!" << endl;
            return 0;
        }
    int left_words =min((((int)FinalPlain.size())%((int)FinalWord.size())) , (int)FinalWord.size() - (((int)FinalPlain.size())%((int)FinalWord.size())));
    cout<<left_words<<endl;
    for(int i = 0 ; i<26; i++)
    {
        if(left_words == 0) break;
        if(visited_in_Plain['a'+i]) continue;
        FinalPlain += ('a' + i);
        left_words -= 1;
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