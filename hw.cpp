#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
pair<int, int> find_pos(vector<vector<char>>&mat , char word)
{
    for(int i = 0 ;i < mat.size(); i ++)
    {
        for(int j =0; j < mat[0].size() ; j++)
        {
            if(mat[i][j] == word)
            {
                return {i , j};
            }
        }
    }
    return {-1 , -1};
}
string hashconv(string & word , vector<vector<char>>&mat){
    int pos = 0;
    string temp = word;
    string final = "";
    if(((int)temp.size() % 2) != 0)
    {
        temp += 'x';
    }
    for(int i = 0; i<temp.size() ; i+=2)
    {
        int w1 = temp[i];
        int w2 = temp[i+1];
        auto pos1 = find_pos(mat , w1);
        auto pos2 = find_pos(mat , w2);
        if(pos1.first == pos2.first)
        {
            final += mat[pos1.first][(pos1.second+1)%5];
            final += mat[pos2.first][(pos2.second+1)%5];
        }
        else if(pos1.second == pos2.second)
        {
            final += mat[(pos1.first+1)%5][pos1.second];
            final += mat[(pos1.first + 1) % 5][pos1.second];
        }
        else
        {
            final += mat[pos1.first][pos2.second];
            final += mat[pos2.first][pos1.second];
        }
    }
    return final;
}

int main() 
{
    vector<vector<char>>mat(5 , vector<char>(5 , 'A')) ; 
    string word ; 
    cout<<"enter the word ";
    cin>>word ;
    string output="";
    unordered_map<char ,bool>visited;
    int pos = 0 ;
    int row = -1;
    int col = -1;
    for(int i = 0 ; i < 5 ; i++ )
    {
        for(int j = 0 ; j < 5 ; j++)
        {
         if(pos == word.size())
         {
             row = i;
             col = j;
             break;
         }
         else 
         {
             mat[i][j] = word[pos];
             visited[word[pos]] = true;
             pos += 1;
         }
        }
        if(row != -1 && col != -1) break;
    }
    cout<<row<<" "<<col;
    for(int i = 0 ; i < 5 ; i ++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            if(mat[i][j] == 'A'){
                
                for(int k = 0 ; k < 26 ; k++)
                {
                    char element = 'a' + k;
                    if(element == 'i') continue;
                        if(!visited[element])
                        {
                            mat[i][j] = element;
                            visited[element] = true;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                }
                
            }
        }
        cout<<endl;
    }
    for(int i =0; i < 5 ;i ++)
    {
        for(int j = 0; j < 5 ;j ++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    output = hashconv(word , mat);
    cout<<output<<endl;
    return 0;
}