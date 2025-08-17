#include <iostream>
#include <string>
using namespace std;



template<class t>

class arrayQueueType
{
        int rear;
        int front;
        int length;
        t *arr;
        size_t maxSize;

    public:
        ~arrayQueueType() {
            delete[] arr;
        }
        arrayQueueType(size_t size){
            front = 0;
            maxSize = size;
            arr=new t[size];
            rear = maxSize - 1;
            length = 0;
        }

        bool isEmpty(){
            return length == 0;
        }

        bool isFull(){
            return length == maxSize;
        }

        void enQueue(t Element){
            if (isFull()){
                cout << "Queue Full Can't Enqueue ...!" << endl;
            }
            else{
                rear = (rear + 1) % maxSize;
                arr[rear] = Element;
                length++;
            }
        }

        void deQueue(){
            if(isEmpty()){
                cout << "Empty Queue Can't Dequeue ...!" << endl;
            }else{

                front  = (front + 1) % maxSize;
                --length;

            }
        }

        t frontQueue(){
            if(isEmpty()){
                cout << "The Queue Is Empty On frontQueue" << endl;
                return t();
            }
            return arr[front];
        }

        t rearQueue(){
            if(isEmpty()){
                cout << "The Queue Is Empty On rearQueue" << endl;
                return t();
            }
            return arr[rear];
        }

        void clear(){
            while(length != 0){
                deQueue();
            }
        }

        size_t getAvailableSpace(){
            return maxSize - length;
        }


        void printQueue(){
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            cout << "Front" << endl << endl;
            for (size_t i = front; i != (rear + 1) % maxSize; i = (i + 1) % maxSize)
                cout << arr[i] << endl;
            cout << endl << "Back";
        }


        int  queueSearch(t element){
            int pos = -1;

            if(!isEmpty()){
                for (size_t i = front; i != (rear + 1); i = (i + 1) % maxSize) {
                    if (arr[i] == element){
                        pos = i;
                        break;
                    }
               
                    
                }
            }else{
                cout << "Q is empty !" << endl;
            }


            return pos;
        }

    
};

int main(){
    arrayQueueType<int> q(3);

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);



    cout << q.queueSearch(3) << endl;


    

    return 0;
}