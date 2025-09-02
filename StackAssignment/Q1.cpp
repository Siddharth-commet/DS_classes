// Develop a menu driven program demonstrating the following operations on a Stack using array:
// (i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().
#include<iostream>
using namespace std;

class stack{

    int arr[10];
    int top = -1;
    public:
    stack(){

    }

    void push(int num){
        top++;
        arr[top]=num;
    }

    void pop(){
        arr[top]=INT16_MIN;
        top--;
    }

    int isEmpty(){
        if(top==-1)
        {return 1; };
        return 0;
    }

    int isFull(){
        if (top==9)
        {
            return 1;
        }
        return 0;
        
    }

    void display(){
        cout<<"<================================>\n";
        for (int i = 0; i <= top; i++)
        {
            cout<<arr[i]<<"\n";
        }
        
    }

    int peek(){
        cout<<arr[top];
        return arr[top];
    }

};

int main(){
    stack stackk;
    stackk.push(10);
        stackk.push(5148);
        stackk.push(8);
        stackk.push(5);
        stackk.push(555);
        stackk.push(9144);
        stackk.display();
        stackk.pop();
        stackk.pop();
        stackk.display();

        while (!stackk.isEmpty())
        {
            stackk.pop();
            cout<<"Popped\n";
        }
        stackk.display();
        
    
    return 0;
}