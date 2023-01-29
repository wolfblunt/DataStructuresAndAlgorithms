#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

/*
 * Complete the 'reverseK' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST head
 *  2. INTEGER k
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* reverseK(SinglyLinkedListNode* head, int k) {
    SinglyLinkedListNode *currPtr=head;
    SinglyLinkedListNode *prevPtr=NULL;
    SinglyLinkedListNode *nextPtr=NULL;
    int i=0;
    int l=0;
    while(currPtr!=NULL)
    {
        l+=1;
        currPtr = currPtr->next;
    }
    if(l<k)
    {
        return head;
    }
    while(i<k && head!=NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr=currPtr;
        currPtr = nextPtr;
        i++;
    }
    if (currPtr!=NULL)
    {
        currPtr->next = reverseK(nextPtr, k);
    }

    return prevPtr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        SinglyLinkedList* H = new SinglyLinkedList();

        string H_count_temp;
        getline(cin, H_count_temp);

        int H_count = stoi(ltrim(rtrim(H_count_temp)));

        for (int i = 0; i < H_count; i++) {
            string H_item_temp;
            getline(cin, H_item_temp);

            int H_item = stoi(ltrim(rtrim(H_item_temp)));

            H->insert_node(H_item);
        }

        string K_temp;
        getline(cin, K_temp);

        int K = stoi(ltrim(rtrim(K_temp)));

        SinglyLinkedListNode* HEAD = reverseK(H->head, K);

        print_singly_linked_list(HEAD, " ", fout);
        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
