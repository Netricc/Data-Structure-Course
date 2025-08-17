#include <iostream>
using namespace std;

template <class type>
class linkedQueue {

 private:
    struct Node
    {
        type item;
        Node *next;
    };
    Node*frontPtr;
    Node*rearPtr;
    int length;

 public:
    linkedQueue():frontPtr(NULL),rearPtr(NULL),length(0)
    {}

    bool isEmpty(){
        return length == 0;
    }

    void enqueue(type element){

        // * In Case Of Empty Queue
        if(isEmpty()){
            frontPtr = new Node;
            frontPtr->item = element;
            frontPtr->next = NULL;
            rearPtr = frontPtr;
            length++;
        }


        // * In Case Of Presentation Of Elements
        else{
            Node *newPtr=new Node;
            newPtr->item = element;
            newPtr-> next= NULL;
            rearPtr->next = newPtr;
            rearPtr = newPtr;
            length++;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout << "the Queue is Empty on dequeue" << endl;
        }
        else{
            Node* tempPtr = frontPtr;
            if(frontPtr==NULL)
                {
                    rearPtr = NULL;
                    length = 0;
                }
            else{
                frontPtr=frontPtr->next;
                tempPtr->next = NULL;
                delete tempPtr;
                length--;
            }

        }
    }

    void clearQueue() {
        while(frontPtr != nullptr){
            Node* CurPtr = frontPtr;
            frontPtr=frontPtr->next;
            CurPtr = NULL;
            delete CurPtr;
        }

        rearPtr = NULL;
        length = 0;

    }

    void displayQueue(){
        Node* cur=frontPtr;
        while(cur!=NULL){
            cout<<cur->item << endl;
            cur = cur->next;
        }
    }
};

int main(){
    linkedQueue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.dequeue();

    q.displayQueue();
}