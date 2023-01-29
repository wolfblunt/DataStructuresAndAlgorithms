// Stack using linked list

public class Stack{
	Node top;
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
	public static Stack stack_push(Stack list, int data)
	{
		Node new_node = new Node(data);
		new_node.next = list.top;
		list.top = new_node;
		return list;
	}

	public static Stack stack_pop(Stack list)
	{
		list.top = list.top.next;
		return list;
	}

	public static void peek(Stack list)
	{
		if(list.top!=null){
			System.out.println("Top lement of the stack : "+(list.top).data);
		}
		else{
			System.out.println("Stack is Empty");
		}
	}

	public static void printStack(Stack list)
	{
		Node curr_ptr = list.top;
		System.out.println("------------Stack----------");
		while(curr_ptr!=null)
		{
			System.out.println(curr_ptr.data);
			curr_ptr = curr_ptr.next;
		}
	}

	public static void main(String[] args) {
		Stack new_stack = new Stack();
		new_stack = stack_push(new_stack, 4);
		new_stack = stack_push(new_stack, 14);
		new_stack = stack_push(new_stack, 5);
		new_stack = stack_push(new_stack, 15);
		new_stack = stack_push(new_stack, 555);
		printStack(new_stack);
		stack_pop(new_stack);
		printStack(new_stack);
		peek(new_stack);
		stack_pop(new_stack);
		peek(new_stack);
		new_stack = stack_push(new_stack, 666);
		peek(new_stack);
	}
}