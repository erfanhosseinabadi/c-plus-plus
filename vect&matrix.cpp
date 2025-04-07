#include <iostream>
using namespace std;

template <typename T>
class vector{
public: 
   int dim;
   T* v;
   vector(int d) : dim(d), v(new T[d]){
    cout<<"vector created dim = "<<dim<<endl;
   }
   ~vector(){
    delete [] v;
    cout<<"vector destroyed"<<endl;
   }
   vector operator+(const vector& other)const{
     vector result(dim);
     for(int i=0;i<dim;++i){
        result.v[i]=v[i]+other.v[i];
     }
     return result;
   }
   vector operator*(const vector& other)const{
    vector result(dim);
    for(int i =0;i<dim;++i){
        result.v[i]=v[i]*other.v[i];
    }
    return result;
   }
   vector operator-()const{
    vector result(dim);
    for(int i=0;i<dim;++i){
        result.v[i]=-v[i];
    }
    return result;
   }
   vector operator*(int k)const{
    vector result(dim);
    for(int i=0;i<dim;++i){
        result.v[i]=k*v[i];
    }
    return result;
   }
   vector operator=(const vector& other){
    if(&other == this){
        return this;
    }
    
    delete[] v;
    dim=other.dim;
    v=new T[dim];
    for(int i=0;i<dim;++i){
        v[i]=other.v[i];
    }
    return this;
   }
   void print() const{
    for(int i=0;i<dim;++i){
        cout<<v[i]<<", ";
    }
    cout<<endl;
   }
};

int main(){
    vector<int> v1(3);
    v1.v[0]=1,v1.v[1]=2,v1.v[2]=3;
    vector<int> v2(3);
    v2.v[0]=4,v2.v[1]=5,v2.v[2]=6;
    cout<<"v1: ";
    v1.print();
    cout<<"v2: ";
    v2.print();
    vector<int> v3 = v1+v2;
    cout<<"v3: ";
    v3.print();
    vector<int> v4 = v1*v2;
    cout<<"v4: ";
    v4.print();
    vector<int> v5 =-v1;
    cout<<"-v1: ";
    v5.print();
    vector<int> v6=v1*6;
    cout<<"v6: ";
    v6.print();
    return 0;


}