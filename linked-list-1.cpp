#include <iostream>
#include <string>
using namespace std;
//creatin Node for linked list
class Node{
    public:
    int age;
    string name;
    Node* next;
};
//create a function to add Node a block at the beginnig of linked list
void front(Node**head,int var1,string var2){
    Node* newNode = new Node();
    newNode->age = var1;
    newNode->name = var2;
    newNode->next = *head;
    *head = newNode;
}
//create a function to add a Node at the end
void end(Node**head,int var1,string var2){
    Node* newNode = new Node();
    newNode -> age = var1;
    newNode ->name = var2;
    newNode ->next = NULL;
    if(*head==NULL){
        *head = newNode;
        return;
    }
    Node* last = *head;
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = newNode;
}
//function to print out the list
void check(Node*head){
    Node* temp = head;
    while(temp != NULL){
        cout<<"age:" <<temp->age<<" name: "<<temp->name<<" ,";
        temp = temp->next;
    }cout<<endl;
}
//add after specific
void afternode(Node*previous,int var1,string var2){
    if(previous==NULL){
        cout<<"the previous can not be NULL"<<endl;
        return;
    }
    Node* newNode = new Node();
    newNode ->age = var1;
    newNode ->name = var2;
    newNode -> next = previous -> next;
    previous -> next = newNode;
}
int main(){
    Node*head = new Node();
    Node*second = new Node();
    head->age = 12;
    head->name = "ali";
    head->next=second;
    second->age = 20;
    second->name = "erfan";
    second -> next = NULL;
    
    front(&head,15,"alexa");
    end(&head,44,"angelina");
    afternode(second,22,"masha");
    check(head);
    return 0;

}