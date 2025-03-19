#include <iostream>
#include <string>
using namespace std;
class Node{
    public:
    int age;
    int salary;
    string name;
    Node* next;
};
void addfront(Node**head,int var1,int var2,string var3){
    Node* newNode = new Node();
    newNode->age = var1;
    newNode->name = var3;
    newNode->salary = var2;
    newNode->next = *head;
    *head = newNode;
}
void addend(Node**head,int var1,int var2,string var3){
    Node* newNode = new Node();
    newNode -> age = var1;
    newNode ->name = var3;
    newNode->salary = var2;
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
void afternode(Node*previous,int var1,int var2,string var3){
    if(previous==NULL){
        cout<<"the previous can not be NULL"<<endl;
        return;
    }
    Node* newNode = new Node();
    newNode ->age = var1;
    newNode ->name = var3;
    newNode ->salary =var2;
    newNode -> next = previous -> next;
    previous -> next = newNode;
}
void deletestart(Node**head){
    if(*head==NULL){
        cout<<endl<<"the list is empty nothing to delete."<<endl;
        return;
    }
    Node*temp = *head;
    *head = (*head)->next;
    delete temp;
    cout<<endl<<"the first node is deleted."<<endl;
    return;
}
void deleteend(Node**head){
    if(*head==NULL){
        cout<<endl<<"the list is empy nothing to delete"<<endl;
        return;
    }
    Node*secondlast = *head;
    while(secondlast->next->next!=NULL){
        secondlast = secondlast->next;
    }
    delete secondlast->next;
    secondlast->next = NULL;
    cout<<endl<<"the last node is deleted"<<endl;
    return;
}
void deleteat(Node**head,int position){
    if(*head==NULL){
        cout<<endl<<"the list is empy nothing to delete"<<endl;
        return;
    }
    if(position==1){
        Node*temp=*head;
        *head = (*head)->next;
        delete temp;
        return;
    }
    Node*current = *head;
    for(int i=1;i<position-1&&current!=NULL;i++){
        current = current->next;
    }
    if(current==NULL||current->next==NULL){
        cout<<endl<<"the position is not in the list"<<endl;
        return;
    }
    Node*temp =current->next;
    current->next = current->next->next;
    delete temp;
    cout<<endl<<"the node at"<<position<<" position were deleted"<<endl;
    return;
}
void printlist(Node*head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<"name: "<<temp->name<<" salary: "<<temp->salary<<"age: " << temp->age<<endl;
        temp=temp->next;
    }
}
int main(){
    Node*head = new Node();
    Node*second = new Node();
    head->salary = 70000;
    head->name = "ali";
    head->age = 22;
    head->next=second;
    second->salary = 200000;
    second->name = "erfan";
    second->age = 20;
    second -> next = NULL;
    printlist(head);
    cout<<endl;
    addfront(&head,20,38000,"amir");
    addfront(&head,18,26000,"armin");
    printlist(head);
    cout<<endl;
    addend(&head,41,98000,"zahra");
    addend(&head,52,198000,"mahmood");
    printlist(head);
    cout<<endl;
    afternode(second,28,74000,"jack");
    afternode(second->next,12,0,"liza");
    printlist(head);
    cout<<endl;
    deletestart(&head);
    printlist(head);
    cout<<endl;
    deleteend(&head);
    printlist(head);
    cout<<endl;
    deleteat(&head,5);
    printlist(head);
    cout<<endl;

    return 0;

}