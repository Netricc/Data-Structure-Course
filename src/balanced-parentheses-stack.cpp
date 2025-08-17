#include <iostream>
#include <string>
#include <stack>
#include <limits>

using namespace std;

bool arePair(char open, char close){
    if(open == '(' && close == ')'){
        return true;
    }
    else if(open == '{' && close == '}'){
        return true;
    }
    else if(open == '[' && close == ']'){
        return true;
    }

    return false;
}

bool isBalanced(string exp)
{
    stack<char>s;
    for (size_t i = 0; i < exp.length(); i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            s.push(exp[i]);
        }else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if (s.empty() || !arePair(s.top(), exp[i])){
                return false;
                
            }else{
                s.pop();
            }
        }

    }

    return s.empty();
}



int main(){

    string express;
    cout << "Enter an expression: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, express);
    if(isBalanced(express)){
        cout << "Balanced" << endl;
    }else{
        cout << "Not Balanced" << endl;
    }

    return 0;
}