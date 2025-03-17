#include <iostream>
#include <string>
using namespace std;
class Node{
    public:
    string name;
    int salary;
    Node*next;
};
void addfront(Node**head,string var1,int var2){
    Node*newNode = new Node();
    newNode->name = var1;
    newNode->salary = var2;
    newNode->next = *head;
    *head = newNode;
}
void deletestart(Node**head){
    if(*head==NULL){
        cout<<"the list is empty nothing to delete."<<endl;
        return;
    }
    Node*temp = *head;
    *head = (*head)->next;
    delete temp;
    cout<<"the first node is deleted."<<endl;
    return;
}
void deleteend(Node**head){
    if(*head==NULL){
        cout<<"the list is empy nothing to delete"<<endl;
        return;
    }
    Node*secondlast = *head;
    while(secondlast->next->next!=NULL){
        secondlast = secondlast->next;
    }
    delete secondlast->next;
    secondlast->next = NULL;
    cout<<"the last node is deleted"<<endl;
    return;
}
void deleteat(Node**head,int position){
    if(*head==NULL){
        cout<<"the list is empy nothing to delete"<<endl;
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
        cout<<"the position is not in the list"<<endl;
        return;
    }
    Node*temp =current->next;
    current->next = current->next->next;
    delete temp;
    cout<<"the node at"<<position<<" position were deleted"<<endl;
    return;
}
void printlist(Node*head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<"name: "<<temp->name<<" salary: "<<temp->salary<<endl;
        temp=temp->next;
    }
}
int main(){
    Node*head = new Node();
    Node*second = new Node();
    head->salary = 70000;
    head->name = "ali";
    head->next=second;
    second->salary = 200000;
    second->name = "erfan";
    second -> next = NULL;
    addfront(&head,"jackson",45000);
    addfront(&head,"sonya",38000);
    addfront(&head,"daria",90000);
    addfront(&head,"mike",120000);
    addfront(&head,"jack",99000);
    addfront(&head,"jason",145000);
    printlist(head);
    return 0;

}