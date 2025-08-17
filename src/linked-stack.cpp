#include <iostream>
#include <string>
using namespace std;



template<class t>

class Stack{

    struct Node
        {
            t data;
            Node* next;
            // Node(t new_data){
            //     this->data = new_data;
            //     this->next = nullptr;
            // }
        };

        Node*top,*cur;

    public : 

        Stack(){
            top = NULL;
            cur = NULL;
        }

        void push(t newItem){
            Node *newItemPtr = new Node;
            if(newItemPtr == NULL){
                cout << "Stack push cannot allocate memory";
            }
            else{
                newItemPtr->data=newItem;
                newItemPtr->next=top;
                top = newItemPtr;   
            }

        }

        bool isEmpty(){
            return top==NULL;
        }

        void pop(){
            if (isEmpty()){
                cout << "Stack empty on pop";
            }
            else{
                Node*temp = top;
                top = top->next;
                delete temp;
            }
        }

        void pop(t&stackTop){
            if (isEmpty()){
                cout << "Stack empty on pop";
            }
            else{
                stackTop = top->data;
                Node*temp = top;
                top = top->next;
                delete temp;
            }
        }

        void getTop(t&stackTop){
            if (isEmpty()){
                cout << "Stack empty on getTop";
            }
            else{
                stackTop = top->data;
            }
        }

        void display(){
            Node* temp = top;
            
            while(temp != NULL){
                cout << "| " << temp->data << " |" << endl;
                temp = temp->next;
            }
            if (!isEmpty()) {
                string underline(to_string(top->data).size() + 4, '-');
                cout << underline << endl;
            }
        }


};


int main(){

    Stack<int>s;

    s.push(100);
    s.push(200);
    s.push(300);

    s.pop();

    int x = 0;

    s.display();

    s.getTop(x);

    cout << x << endl;

    return 0;
}