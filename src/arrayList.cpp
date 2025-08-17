#include <iostream>
using namespace std;


class arrayList {
    int*arr;
    int maxSize;
    int length;

 public:
    
    arrayList(int s){
        if  (s < 0)
            maxSize = 10;
        else{ 
            maxSize = s;
        }
        length = 0;
        arr = new int[maxSize];
    }

    bool isEmpty(){
        return length == 0;
    }

    bool isFull(){
        return length == maxSize;
    }

    int getSize(){
        return length;
    }
    void print(){
        for (size_t i = 0; i < length; i++){
            cout <<arr[i] << " ";
        }
        cout << endl;
    }

    void insertAt(int pos, int element){
        if (isFull()){
            cout << "The list is full on insertAt";
        }
        else if(pos < 0 || pos>length){
            cout << "Out of Range";
        }else{
            for (int i = length; i > pos; i--){
                arr[i] = arr[i - 1];
                arr[pos] = element;
                length++;
            }
        }
    }

    void removeAt(int pos){
        if (isEmpty()){
            cout << "Empty List";
        }
        else if (pos < 0 ||  pos > length){
            cout << "out of range";
        }else{
            for (int i = pos; i < length; i++){
                arr[i] = arr[i + 1];
                length--;
            }
        }
    }
};



int main(){


    cout << "Hello world" << endl;
}