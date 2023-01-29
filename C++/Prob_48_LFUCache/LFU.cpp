class Node
{
	public:
    int key;
    int value;
    int count;
    Node *previous;
    Node *next;
    Node(int k, int v)
    {
    	key = k;
    	value = v;
    	count = 1;
    }
};

class MyCustomList
{	
	public:
	Node* head;
	Node* tail;
	int size;

	MyCustomList()
	{
		head = new Node(-1,-1);
		tail = new Node(-1,-1);
		head->next = tail;
		tail->previous = head;
		size = 0;
	}

	void addNode(Node *newNode)
	{
		Node *temp = head->next;
		head->next = newNode;
		newNode->previous = head;
		newNode->next = temp;
		temp->previous = newNode;
		size++;
	}

	void deleteNode(Node *deleteNode)
	{
		deleteNode->next->previous = deleteNode->previous;
		deleteNode->previous->next = deleteNode->next;
		size--;
	}
};


class LFUCache
{
	public:
		map<int, Node *>NodeMap;
		map<int, MyCustomList *>frequencyListMap;
		int capacity;
		int minFrequency;
		int currentSize; //curSize

		LFUCache(int cp)
		{
			minFrequency = 0;
			currentSize = 0;
			capacity = cp;
		}

		void updateListMap(Node *node)
		{
			NodeMap.erase(node->key);
			frequencyListMap[node->count]->deleteNode(node);
			if(node->count == minFrequency){
				if(frequencyListMap[node->count]->size==0){
					minFrequency++;
				}
			}
			MyCustomList *freqList;

			if(frequencyListMap.find(node->count+1)!= frequencyListMap.end())
			{
				freqList = frequencyListMap[node->count+1];
			}
			else
			{
				 freqList = new MyCustomList();
			}
			node->count= node->count + 1;
			freqList->addNode(node);
			frequencyListMap[node->count]=freqList;
        	NodeMap[node->key]=node;
		}

		int get(int key) 
	    {
	        if(NodeMap.find(key)!=NodeMap.end())
	        {
	            Node *resultNode = NodeMap[key];
	            int NodeValue = resultNode->value;
	            
	            updateListMap(resultNode);
	            
	            return NodeValue;
	        }
	        return -1;
	    }

	    void put(int key, int value)
	    {
	    	if(capacity == 0)
	    	{
	    		return ;
	    	}
	    	if(NodeMap.find(key)!=NodeMap.end())
	    	{
	    		Node *node = NodeMap[key];
	    		node->value = value;
	    		updateListMap(node);
	    	}
	    	else
	    	{
	    		if(currentSize==capacity)
	    		{
	    			MyCustomList *newlist = frequencyListMap[minFrequency];
	    			NodeMap.erase(newlist->tail->previous->key);
	    			newlist->deleteNode(newlist->tail->previous);
	    			currentSize = currentSize - 1;
	    		}
	    	

                currentSize = currentSize + 1;
                minFrequency = 1;

                MyCustomList *freqList;
                if(frequencyListMap.find(minFrequency)!= frequencyListMap.end())
                {
                    freqList = frequencyListMap[minFrequency];
                }
                else
                {
                     freqList = new MyCustomList();
                }

                Node *newNode = new Node(key, value);
                freqList->addNode(newNode);
                frequencyListMap[minFrequency] = freqList;
                NodeMap[key] = newNode;
            }
	    }

};