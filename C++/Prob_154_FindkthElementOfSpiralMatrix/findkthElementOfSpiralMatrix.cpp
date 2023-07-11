// Find kth element of spiral matrix

class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int leftColumn=0;
 		int rightColumn=m-1;
 		int leftRow=0;
 		int rightRow=n-1;
 		int count=0;
 		
 		while(leftRow <= rightRow || leftColumn <= rightColumn)
 		{
 		    for(int i=leftColumn;i<=rightColumn;i++)
 		    {
 		        if(++count==k)
 		        {
 		            return a[leftRow][i];
 		        }
 		    }
 		    leftRow++;
 		    
 		    for(int i=leftRow;i<=rightRow;i++)
 		    {
 		        if(++count==k)
 		        {
 		            return a[i][rightColumn];
 		        }
 		    }
 		    rightColumn--;
 		    
 		    if(leftRow > rightRow && leftColumn > rightColumn)
 		    {
 		        break;
 		    }
 		    
 		    for(int i=rightColumn;i>=leftColumn;i--)
 		    {
 		        if(++count==k)
 		        {
 		            return a[rightRow][i];
 		        }
 		    }
 		    rightRow--;
 		    
 		    for(int i=rightRow;i>=leftRow;i--)
 		    {
 		        if(++count==k)
 		        {
 		            return a[i][leftColumn];
 		        }
 		    }
 		    leftColumn++;
 		}
 		
 		return -1;
    }
};