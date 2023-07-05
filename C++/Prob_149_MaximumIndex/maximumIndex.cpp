// Maximum Index

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int left = 0;
        int right = n-1;
        int answer = 0;
        while(left<right)
        {
            int diff = right-left;
            if(arr[left] <= arr[right])
            {
                answer = max(answer, diff);
                left++;
                right = n-1;
            }
            else
            {
                right--;
                if(diff <= answer)
                {
                    left++;
                    right = n-1;
                }
            }
        }
        return answer;
    }

};