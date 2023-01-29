class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> um;
        vector<string> result;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            string temp=s.substr(i,10);
            //cout<<"Temp : "<<temp<<"\n";
            if(!um.count(temp))
            {
                um[temp]=1;
                //cout<<"FirstTime: "<<temp<<"\n";
            }
            else{
                um[temp]+=1;
                //cout<<"AnotherTime: "<<temp<<"\n";
            }
        }
        for(auto a:um)
        {
            if(a.second>1)
            {
                result.push_back(a.first);
            }
        }
        return result;
    }
};