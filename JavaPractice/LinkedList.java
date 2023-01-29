// Linked List

public class LinkedList{
	Node head;
	static class Node{
		int data;
		Node next;

		//constructor
		Node(int d){
			data = d;
			next = null;
		}
	}

	public static LinkedList insert(LinkedList list, int data)
	{
		Node new_node = new Node(data);
		new_node.next = null;

		if(list.head == null)
		{
			list.head = new_node;
		}
		else{
			Node last = list.head;
			while(last.next!=null){
				last = last.next;
			}

			last.next = new_node;
		}

		return list;
	}

	public static LinkedList insertIndex(LinkedList list, int index, int data)
	{
		Node curr_node = list.head;
		Node new_node = new Node(data);
		for(int i=0;i<index-1;i++){
			curr_node = curr_node.next;
			if(curr_node==null){
				System.out.print("Can't insert element");
				return list;
			}
		}
		new_node.next = curr_node.next;
		curr_node.next = new_node;
		return list;
	}

	public static LinkedList deleteNode(LinkedList list, int index)
	{
		Node curr_node = list.head, prev_node = null;
		if(index==0){
			curr_node = curr_node.next;
			list.head = curr_node;
			return list;
		}
		for(int i=0;i<index;i++){
			if(curr_node==null){
				System.out.print("Nothing to delete");
				return list;
			}
			else{
				prev_node = curr_node;
				curr_node = curr_node.next;

			}
		}
		prev_node.next = curr_node.next;
		return list;
	}

	public static void printList(LinkedList list)
	{
		Node curr_node = list.head;
		System.out.println("--------Linked List---------");
		while(curr_node!= null){
			System.out.println(curr_node.data);
			curr_node = curr_node.next;
		}
	}

	public static void main(String[] args) {
		LinkedList list = new LinkedList();

		list = insert(list, 23);
		list = insert(list, 34);
		list = insert(list, 54);
		list = insert(list, 12);
		list = insert(list, 45);
		list = insert(list, 78);
		list = insert(list, 1);
		list = insert(list, 11);

		printList(list);
		list = insertIndex(list, 3, 1111);
		printList(list);
		deleteNode(list, 3);
		printList(list);
	}
}