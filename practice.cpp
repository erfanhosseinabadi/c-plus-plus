#include <iostream>
#include <string>
using namespace std;
class Node
{public:
    int age;
    string name;
    Node*next;
    Node(int a,string b): age(a), name(b), next(nullptr) {}
};
void addfront(Node*&head,int var1,string var2){
    Node*newNode = new Node({var1,var2});
    newNode->next=head;
    head=newNode;
}
void addend(Node*&head,int var1,string var2){
    Node*newNode = new Node({var1,var2});
    newNode->next=nullptr;
    if(head==nullptr){
        head=newNode;
        return;
    }
    Node*temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}
void addafter(Node*prevoius,int var1,string var2){
    if(prevoius==nullptr){
        cout<<"your node is not in the list";
        return;
    }
    Node*newNode= new Node({var1,var2});
    newNode->next = prevoius->next;
    prevoius->next=newNode;
}
void deletestart(Node*&head){
    if(head==nullptr){
        cout<<"the list is empty nothing to delete.";
        return;
    }
    Node *temp = head;
    head =head->next;
    delete temp;
    cout<<"the first node is deleted"<<endl;
    return;
}
void deletend(Node*&head){
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    delete temp;
    cout<<"the last node was deleted"<<endl;
    return;
}
void deleteafter(Node*previous){
    Node*temp = previous;
    previous->next= previous->next->next;
    delete temp->next;
    cout<<"the node after was deleted"<<endl;
    return;
}
void print(Node*head){
    Node*temp = head;
    while(temp!=nullptr){
        cout<<"name: "<<temp->name<<" ,age: "<<temp->age<<endl;
        temp=temp->next; 
    }
}
int main(){
    Node*head = new Node({20,"Erfan"});
    Node*second = new Node({22,"ALI"});
    Node*third = new Node({51,"Mahmood"});
    Node*forth = new Node({42,"Zahra"});
    head->next = second;
    second->next=third;
    third->next=forth;
    forth->next=nullptr;
    print(head);
    cout<<endl<<endl;
    addfront(head,21,"Amir");
    addend(head,17,"Armin");
    addafter(forth,16,"jason");
    print(head);
    cout<<endl<<endl;
    deletestart(head);
    deletend(head);
    deleteafter(forth);
    print(head);

    return 0;
}