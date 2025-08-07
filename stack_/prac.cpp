#include<stack>
#include <iostream>
using namespace std;

int main() {
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    cout<<"Top stack element : " << myStack.top() << endl;
    myStack.pop();
    cout<<"After poping one element : " << myStack.top() <<endl;
    
    
    return 0;
}