#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node * next;
	 Node(int a){
		this -> data = a;
		this -> next = NULL;
	}
	  //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertathead(Node* &head,int d){
	
	Node * temp = new Node(d);
	temp -> next = head;
	head = temp;
	
}

void  print(Node* &head)
{
	Node* temp = head;
	while(temp != NULL){
	cout<< temp -> data <<" ";
	temp = temp -> next;
    }
cout<<endl;
}
void insertattail(Node* &tail,int d){
	Node* temp = new Node(d);
	tail -> next = temp;
	tail = temp;
}
void insertatpos(Node * &tail,Node * &head, int pos,int d){
	if (pos == 1){
		insertathead(head,d);
		return ;
	}
	Node* temp = head;
	int cnt = 1;
	while(cnt < pos-1){
		temp = temp -> next;
		cnt++;
	}
	if(temp ->next == NULL){
		insertattail(tail,d);
		return;
	}
	Node* insertnode = new Node(d);
	insertnode -> next = temp -> next;
	temp -> next = insertnode;
}
void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}
	
int main()
{
	Node* node1 = new Node(15);
	Node* head = node1;
	Node* tail = node1;
	insertattail(tail,18);
	print(head);
	insertathead(head,14);
	print(head);
	insertatpos(tail,head,4,21);
	print(head);
	



	return 0;
	
}
