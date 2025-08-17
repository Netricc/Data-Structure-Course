#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
template <class t>
class Stack {
    int top;
    t item [MAX_SIZE];

    public:

    Stack(){
        top = -1;
    }

    void push(t Element){
        if (top >= MAX_SIZE - 1){
            cout << "Stack full on push";
        }else{
            top++;
            item[top] = Element;
        }
    }

    bool isEmpty(){
        return top < 0;
    }

    void pop(){
        if (isEmpty()){
            cout << "stack empty on pop";
        }else{
            top--;
        }
    }

    void pop(t&Element){
        if (isEmpty()){
            cout << "stack empty on pop";
        }else{
            Element = item[top];
            top--;
        }
    }


    t getTop(t&stackTop){
        if(isEmpty()){
            cout << "Stack empty on getTop";
            return 1;
        }
        else {
            stackTop = item[top];
            return stackTop;
        }

    }

    void printStack(){
        for (t i = top; i >= 0; i--){
            cout << item[i] << endl;
        }
    }

};



int main()
{

    Stack<int> mystack;

    mystack.push(10);
    mystack.push(20);
    mystack.push(30);
    mystack.push(50);

    int y = 0;
    mystack.getTop(y);

    cout << mystack.isEmpty() << endl;
    cout << mystack.getTop(y) << endl;
    mystack.printStack();
    cout << y << endl;
    
    mystack.pop();
    mystack.pop();
    
    
    mystack.printStack();


    return 0;
}