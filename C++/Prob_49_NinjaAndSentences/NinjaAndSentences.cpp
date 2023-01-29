#include <bits/stdc++.h>
using namespace std;

void createSentencesUtil(vector < vector < string > > & arr,int m, vector<string> &res)
{
    if(m==arr.size())
    {
        for(auto a:res){
            cout<<a<<" ";
        }
            cout << endl;
        return;
    }
    
    for(int i=0;i<arr[m].size();i++)
    {
        res.push_back(arr[m][i]);
        createSentencesUtil(arr, m+1, res);
        res.pop_back();
    }
}

void createSentences(vector < vector < string > > & arr) {
    vector<string> res;
    createSentencesUtil(arr, 0, res);

    return;
}

int main()
{
    cout<<"Hello";
    vector<vector<string>> arr {{"you","we"}, {"have","are"}, {"sleep","eat","drink"}}; 
    createSentences(arr);
    return 0;
}