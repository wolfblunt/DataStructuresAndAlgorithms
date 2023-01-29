#include<iostream>
#include<map>
using namespace std;

class Node
{
	public:
    long long int key;
    long long int value;
    Node *previous;
    Node *next;
    Node(long long int k, long long int v)
    {
    	key = k;
    	value = v;
    }
};

class LRU
{	
	public:
	Node* head = new Node(-1,-1);
	Node* tail = new Node(-1,-1);
	long long int capacity;
	map<long long int, Node *> LRUMap;

	LRU(long long int cacheCapacity)
	{
		capacity = cacheCapacity;
		head->next = tail;
		tail->previous = head;
	}

	void addNodeInCache(Node *newNode)
	{
		Node *temp = head->next;
		head->next = newNode;
		newNode->previous = head;
		newNode->next = temp;
		temp->previous = newNode;
	}

	void deleteNodeInCache(Node *deleteNode)
	{
		Node *previousNode = deleteNode->previous;
		Node *nextNode = deleteNode->next;
		nextNode->previous = previousNode;
		previousNode->next = nextNode;
	}

	long long int get(long long int key)
	{
		if(LRUMap.find(key)!=LRUMap.end())
		{
			Node *temp = LRUMap[key];
			long long int tempValue = temp->value;
			LRUMap.erase(key);
			deleteNodeInCache(temp);
			addNodeInCache(temp);
			LRUMap[key] = head->next;
			return tempValue;
		}

		return -1;
	}

	void set(long long int key, long long int value)
	{
		if(LRUMap.find(key)!=LRUMap.end())
		{
			Node *keyPresent = LRUMap[key];
			LRUMap.erase(key);
			deleteNodeInCache(keyPresent);
		}

		if(LRUMap.size() == capacity)
		{
			LRUMap.erase(tail->previous->key);
			deleteNodeInCache(tail->previous);
		}

		Node* newNode = new Node(key, value);
		addNodeInCache(newNode);
		LRUMap[key] = head->next;
	}
};

int main()
{
	LRU *LRUCache = new LRU(2);

	LRUCache->set(1,10);

	cout << "Value for the key: 1 is " << LRUCache->get(1) << "\n";
	
	LRUCache->set(2,20);
	cout << "Value for the key: 2 is " << LRUCache->get(2) << "\n";

	LRUCache->set(3,30);
	cout << "Value for the key: 2 is " << LRUCache->get(3) << "\n";

	LRUCache->set(4,40);
	cout << "Value for the key: 2 is " << LRUCache->get(4) << "\n";

	cout << "Value for the key: 2 is " << LRUCache->get(1) << "\n";
	LRUCache->set(10000,5000000000);
	cout << "Value for the key: 10000 is " << LRUCache->get(10000) << "\n";

	LRUCache->set(5,500);
	cout << "Value for the key: 5 is " << LRUCache->get(5) << "\n";

	return 0;
}