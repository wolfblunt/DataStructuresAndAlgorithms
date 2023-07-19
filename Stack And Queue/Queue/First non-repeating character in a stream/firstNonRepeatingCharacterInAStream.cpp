// First non-repeating character in a stream

class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char, int> freq;
		    queue<char> q;
		    string ans;
		    for(int i=0;i<A.length();i++)
		    {
		        freq[A[i]]++;
		        q.push(A[i]);
		        
		        while(!q.empty())
		        {
		            if(freq[q.front()] > 1)
		            {
		                q.pop();
		            }
		            else
		            {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        if(q.empty())
		        {
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};