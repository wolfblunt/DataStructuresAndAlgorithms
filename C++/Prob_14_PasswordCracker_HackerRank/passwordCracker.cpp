#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
int f =0;
/*
 * Complete the 'passwordCracker' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY passwords
 *  2. STRING loginAttempt
 */

void verifyPassword(vector<string> passwords, string loginattempt, vector<string> &v, int n)
{
    if(loginattempt.length()==0)
    {
        f=1;
        return;
    }
    for(int i=0;i<n && f==0;i++)
    {
        string a = passwords[i];
        string b(loginattempt, 0, a.size());
        if(a==b)
        {
            string c(loginattempt, a.size(),loginattempt.size()-a.size());
            v.push_back(a);
            verifyPassword(passwords,c,v,n);
            if(f==0)
            {
                v.pop_back();
                break;
            }
        }
    }
}

string passwordCracker(vector<string> passwords, string loginAttempt) {
    vector<string> v;
    int n = passwords.size();
    verifyPassword(passwords, loginAttempt, v,n);
    string s;
    if(f==1)
    {
        for(int i=0;i<v.size();i++)
        {
            if(i==v.size()-1){
                s+=v[i];
            }
            else{
                s+=v[i]+" ";   
            }
        }
        string t = s;
        return t;
    }
    else{
        return "WRONG PASSWORD";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string passwords_temp_temp;
        getline(cin, passwords_temp_temp);

        vector<string> passwords_temp = split(rtrim(passwords_temp_temp));

        vector<string> passwords(n);

        for (int i = 0; i < n; i++) {
            string passwords_item = passwords_temp[i];

            passwords[i] = passwords_item;
        }

        string loginAttempt;
        getline(cin, loginAttempt);
        f=0;
        string result = passwordCracker(passwords, loginAttempt);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
