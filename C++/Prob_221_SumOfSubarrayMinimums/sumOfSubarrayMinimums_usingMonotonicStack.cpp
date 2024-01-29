// Sum of Subarray Minimums - O(n)

class Solution {
public:
    /*
        we need to calculate the CONTRIBUTION of each element in the total answer. We need to find the ending point in left as well as  right side.

  X X (X |E| X X X) X   
  -> Here '(' is the last valid end point on left side for E
  -> ')' is the last valid end point on right side for E

    contribution[i] = left[i] * right[i]  
  -> left[i] & right[i] is length of last possible bracket on left and right side resp.
  
    */

    int sumSubarrayMins(vector<int>& arr) {
        // monotonic stack
        int n = arr.size();
        vector<int> left(n,-1);
        vector<int> right(n,-1);

        stack<int> st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i] < arr[st.top()])
            {
                st.pop();
            }
            if(!st.empty())
            {
                left[i] = i-st.top();
            }
            else
            {
                left[i] = i+1;
            }

            st.push(i);
        }

        while(!st.empty())
        {
            st.pop();
        }


        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            if(!st.empty())
            {
                right[i] = st.top()-i;
            }
            else
            {
                right[i] = n-i;
            }

            st.push(i);
        }

        int sum = 0;
        
        int mod = 1e9+7;
        for(int i=0;i<n;i++)
        {
            long long contri = (left[i]*right[i])%mod;
            contri = (contri*arr[i]) % mod;
            sum = (sum + contri) % mod;
        }

        return sum%mod;
    }
};