// { Driver Code Starts
// driver

import java.util.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class GfG{
    
    static void printList(Node n){
        while(n!=null){
            System.out.print(n.data+" ");
            n = n.next;
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while (T-- > 0) {
            
            int n = sc.nextInt();
            int val = sc.nextInt();
            
            Node first = new Node(val);
            Node tail = first;
            for(int i=0; i<n-1; i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }
            
            int m = sc.nextInt();
            val = sc.nextInt();
            
            Node second = new Node(val);
            tail = second;
            for(int i=0; i<m-1; i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }
            
            Solution g = new Solution();
            Node res = g.addTwoLists(first, second);
            printList(res);
        }
    }
}
// } Driver Code Ends


/* node for linked list

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

*/

class Solution{
    
    static Node reverseList(Node head)
    {
        Node curr_ptr = head;
        Node next_ptr = null;
        Node prev_ptr = null;
        while(curr_ptr!=null)
        {
            next_ptr = curr_ptr.next;
            curr_ptr.next = prev_ptr;
            prev_ptr = curr_ptr;
            curr_ptr = next_ptr;
        }
        return prev_ptr;
    }
    
    //Function to add two numbers represented by linked list.
    static Node addTwoLists(Node first, Node second){
        // code here
        // return head of sum list
        Node first_node = reverseList(first);
        Node second_node = reverseList(second);
        int carry = 0;
        Node temp_ptr = new Node(0);
        Node head_ptr = temp_ptr;
        while(first_node!=null || second_node!=null || carry!=0)
        {
            int sum = 0;
            if(first_node!=null)
            {
                sum+=first_node.data;
                first_node = first_node.next;
            }
            if(second_node!=null)
            {
                sum+=second_node.data;
                second_node = second_node.next;
            }
            sum += carry;
            carry = sum/10;
            Node new_node = new Node(sum%10);
            temp_ptr.next = new_node;
            temp_ptr = temp_ptr.next;
        }
        head_ptr = reverseList(head_ptr.next);
        return head_ptr;
    }
}