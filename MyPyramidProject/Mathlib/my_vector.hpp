#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <iostream>

using namespace std;

template <typename T>
class vector {
public: 
    int dim;
    T* v;

    vector(int d) : dim(d), v(new T[d]) {
        cout << "vector created dim = " << dim << endl;
    }

    ~vector(){
        delete [] v;
        cout << "vector destroyed" << endl;
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
        for(int i=0;i<dim;++i){
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
            return *this;
        }
        
        delete[] v;
        dim=other.dim;
        v=new T[dim];
        for(int i=0;i<dim;++i){
            v[i]=other.v[i];
        }
        return *this;
    }

    void print() const{
        for(int i=0;i<dim;++i){
            cout<<v[i]<<", ";
        }
        cout<<endl;
    }
};

#endif