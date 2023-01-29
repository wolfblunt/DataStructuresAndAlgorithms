// Doubly Linked List

public class DoublyLinkedList{
	Node head;
	static class Node{
		int data;
		Node next;
		Node prev;

		Node(int d){
			data = d;
			next = null;
			prev = null;
		}
	}

	public static DoublyLinkedList insert(DoublyLinkedList list, int data)
	{
		Node new_node = new Node(data);
		new_node.next = null;
		new_node.prev = null;
		if(list.head==null){
			list.head = new_node;
		}
		else{
			Node curr_node = list.head;
			while(curr_node.next!=null){
				curr_node = curr_node.next;
			}
			curr_node.next = new_node;
			new_node.prev = curr_node;
		}
		return list;
	}

	public static DoublyLinkedList insertAtIndex(DoublyLinkedList list, int data, int index)
	{
		Node new_node = new Node(data);
		Node curr_ptr = list.head;
		if(index==0)
		{
			new_node.next = curr_ptr;
			curr_ptr.prev = new_node;
			list.head = new_node;
			return list;
		}
		for(int i=0; i<index-1;i++)
		{
			if(curr_ptr == null){
				System.out.print("Can't insert element");
			}
			curr_ptr = curr_ptr.next;
		}
		new_node.next = curr_ptr.next;
		new_node.prev = curr_ptr;
		curr_ptr.next = new_node;
		return list;
	}

	public static DoublyLinkedList deletenode(DoublyLinkedList list, int index)
	{
		Node curr_ptr = list.head;
		Node temp = null;
		Node prev_ptr = null;
		if(index==0){
			temp = curr_ptr.next;
			temp.prev = null;
			list.head = temp;
			return list;
		}
		for(int i=0;i<index;i++){
			prev_ptr = curr_ptr;
			curr_ptr = curr_ptr.next;
		}
		if(curr_ptr.next == null)
		{
			prev_ptr.next = null;
			return list;
		}
		temp = curr_ptr.next;
		prev_ptr.next = curr_ptr.next;
		temp.prev = prev_ptr;
		return list;
	}

	public static void printdll(DoublyLinkedList list)
	{
		Node curr_ptr = list.head;
		System.out.println("------------Doubly lINKED List----------");
		while(curr_ptr!=null)
		{
			System.out.println(curr_ptr.data);
			curr_ptr = curr_ptr.next;
		}
	}

	public static void main(String[] args) {
		DoublyLinkedList list = new DoublyLinkedList();

		list = insert(list, 23);
		list = insert(list, 45);
		list = insert(list, 34);
		list = insert(list, 56);
		list = insert(list, 1);
		printdll(list);

		list = insertAtIndex(list, 4444, 5);
		printdll(list);

		list = deletenode(list, 0);
		printdll(list);
	}
}