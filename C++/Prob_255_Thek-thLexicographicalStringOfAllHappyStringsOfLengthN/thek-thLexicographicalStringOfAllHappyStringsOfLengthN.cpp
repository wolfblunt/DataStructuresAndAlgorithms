// O(2^N)

class Solution {
public:
    string getHappyString(int n, int k) {
        queue<string> q;
        vector<string> v;

        q.push("a");
        q.push("b");
        q.push("c");

        while(!q.empty())
        {
            string curr = q.front();
            q.pop();

            if(curr.length() == n)
            {
                v.push_back(curr);  
                continue;
            }

            string left = curr;
            string right = curr;

            if(left.back() == 'a')
            {
                left.push_back('b');
                right.push_back('c');
            }
            else if(left.back() == 'b')
            {
                left.push_back('a');
                right.push_back('c');
            }
            else
            {
                left.push_back('a');
                right.push_back('b');
            }

            q.push(left);
            q.push(right);
        }

        if(v.size() < k)
        {
            return "";
        }

        return v[k-1];
    }
};