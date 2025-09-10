#define STACK_UNDERFLOW 1;
#include<iostream>
using namespace std;
struct node
    {
        int data;
        node *next;
    };
class Queue{
    private:
    node *top;
    public:
    Queue(){
        top=nullptr;
    }
    void push(int element){
       
            node *temp=new node;
            temp->data=element;
            temp->next=top;
            top=temp;   
    }
    int peek(){
        if(top==nullptr)
            throw STACK_UNDERFLOW;
        return top->data;
    }
    int pop(){
        if(top==nullptr)
            throw STACK_UNDERFLOW;
        int item=top->data;
        node* temp=top;
        top=top->next;
        delete temp;
        return item;
        
    }
    void reverse(Queue &s){
        Queue temp1;
        while (s.top!=nullptr)
        {
            temp1.push(s.pop());
        }
        Queue temp2;
        while (s.top!=nullptr)
        {
            temp2.push(temp1.pop());
        }

        while (temp2.top!=nullptr)
        {
            s.push(temp2.pop());
        }
        
    }
    void checkPalindrome(int data){
        Queue S;
        int comp1=data,comp2=0;
         while (comp1!=0)
        {
            S.push(comp1%10);
            comp1=comp1/10;
            comp2=S.peek()+comp2*10;
        }
        if(comp2==data)
        cout<<"palindrome";
        else
        cout<<"not a palindrome";
        
    }
    ~Queue(){
        while (top!=nullptr)
        {
            pop();
        }
        
    }
  
    
};

int main(){
    Queue arr;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.pop();
    cout<<arr.peek()<<endl;
    arr.checkPalindrome(312121370);
   

}