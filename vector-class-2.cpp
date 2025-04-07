#include <iostream>
#include <cmath>
using namespace std;
template <typename T> class vector{
    T* P_vector;
    int capacity;
    int current;
public: 
    vector(){
        P_vector = new T[1];
        capacity = 1;
        current=0;
    }
    ~vector(){delete[] P_vector;}

    void push(T data){
        if(current==capacity){
            T* temp = new T[2*capacity];
            for(int i=0;i<capacity;++i){
                temp[i]=P_vector[i];
            }
            delete[] P_vector;
            capacity *= 2;
            P_vector = temp;
        }
            P_vector[current]=data;
            current++;
    }

    void push(T data,int index){
        if(index ==capacity){
            push(data);
        }else{
            P_vector[index] = data;
        }
    }
    T get(int index){
        if(index<current){
            return P_vector[index];
        }
        else{
            cout<<"the index is not in the range"<<endl;
            return -1;
        }}
        
    void pop(){
        current--;
    }
     int size(){
        return current;
    }
     int getcapacity(){
        return capacity;
    }
    void print(){
        for(int i=0 ; i<current;i++){
            cout<< P_vector[i]<<", ";
        }
        cout<<endl;
    }
};
int main(){
    vector<int> v;
    vector<char> v1;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.print();
    v.push(31,2);
    v.print();
    v.pop();
    v.print();
    return 0;

}