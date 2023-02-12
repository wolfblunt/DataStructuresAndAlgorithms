// Prime List

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    bool isPrime(int n)
    {
        if (n == 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i <= sqrt(n); i += 6)
        {   
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    
    int nearestPrime(int n)
    {
        int prime1, prime2;
        if (n == 1)
            return 2;
    
        for (int i = n; i > 1; i--)
        {
            if (isPrime(i))
            {
                prime1 = i;
                break;
            }
        }
    
        for (int i = n; i < n * n; i++)
        {
            if (isPrime(i))
            {
                prime2 = i;
                break;
            }
        }
        if (abs(n - prime1) > abs(n - prime2))
        {
            return prime2;
        }
        else if (abs(n - prime1) < abs(n - prime2))
        {
            return prime1;
        }
        else
        {
            if (prime1 > prime2)
                return prime2;
            else
                return prime1;
        }
    }

    Node *primeList(Node *head){
        Node *curr = head;

        while (curr)
    
        {
            if (!isPrime(curr->val))
            {
                int new_val = nearestPrime(curr->val);
                curr->val = new_val;
            }
            curr = curr->next;
        }
        return head;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}