// Queue using linked list
 class Queue
 {
 	Node front, rear;
 	static class Node
 	{
 		int data;
 		Node next;
 		Node(int d)
 		{
 			data = d;
 			next = null;
 		}
 	}

 	public static Queue enqueue(Queue list,int data)
 	{
 		Node new_node = new Node(data);
 		if(list.rear==null)
 		{
 			list.rear = list.front = new_node;
 			return list;
 		}
 		list.rear.next = new_node;
 		list.rear = list.rear.next;
 		return list;
 	}

 	public static void printList(Queue list)
 	{
 		Node curr_ptr = list.front;
 		while(curr_ptr!=null)
 		{
 			System.out.print(curr_ptr.data);
 		}
 	}

 	public static void main(String[] args) {
 		Queue list = new Queue();
 		list = enqueue(list, 5);
 		list = enqueue(list, 6);
 		list = enqueue(list, 9);
 		printList(list);
 	}
 }