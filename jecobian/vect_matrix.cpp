#include <iostream>
using namespace std;

template <typename T>
class vector{
public: 
   int dim;
   T* v;
   vector(int d) : dim(d), v(new T[d]){
    //cout<<"vector created dim = "<<dim<<endl;
   }
   ~vector(){
    delete [] v;
    //cout<<"vector destroyed"<<endl;
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
   vector& operator=(const vector& other){
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
class matrix {
    public:
        int rows, cols;
        int** mat;
    
        matrix(int r, int c): rows(r), cols(c) {
            mat = new int*[rows];
            for(int i = 0; i < rows; ++i) {
                mat[i] = new int[cols];
                for(int j = 0; j < cols; ++j) {
                    mat[i][j] = 0;
                }
            }
            cout << "matrix created" << endl;
        }
    
        ~matrix() {
            for(int i = 0; i < rows; ++i) {
                delete[] mat[i];
            }
            delete[] mat;
            cout << "matrix destroyed" << endl; 
        }
    
        matrix(const matrix& other) : rows(other.rows), cols(other.cols) {
            mat = new int*[rows];
            for(int i = 0; i < rows; ++i) {
                mat[i] = new int[cols];
                for(int j = 0; j < cols; ++j) {
                    mat[i][j] = other.mat[i][j];
                }
            }
        }
    
        matrix& operator=(const matrix& other) {
            if(this == &other) {
                return *this;
            }
    
            for(int i = 0; i < rows; ++i) {
                delete[] mat[i];
            }
            delete[] mat;
    
            rows = other.rows;
            cols = other.cols;
    
            mat = new int*[rows];
            for(int i = 0; i < rows; ++i) {
                mat[i] = new int[cols];
                for(int j = 0; j < cols; ++j) {
                    mat[i][j] = other.mat[i][j];
                }
            }
            return *this;
        }
    
        matrix operator+(const matrix& other) const {
            if(rows != other.rows || cols != other.cols) {
                cout << "Matrices have different dimensions!" << endl;
                return matrix(0, 0);
            }
            matrix result(rows, cols);
            for(int i = 0; i < rows; ++i) {
                for(int j = 0; j < cols; ++j) {
                    result.mat[i][j] = mat[i][j] + other.mat[i][j];
                }
            }
            return result;
        }
    
        matrix operator*(const matrix& other) const {
            if(rows != other.rows || cols != other.cols) {
                cout << "Matrices have different dimensions!" << endl;
                return matrix(0, 0);
            }
            matrix result(rows, cols);
            for(int i = 0; i < rows; ++i) {
                for(int j = 0; j < cols; ++j) {
                    result.mat[i][j] = mat[i][j] * other.mat[i][j];
                }
            }
            return result;
        }
    
        matrix operator*(int k) const {
            matrix result(rows, cols);
            for(int i = 0; i < rows; ++i) {
                for(int j = 0; j < cols; ++j) {
                    result.mat[i][j] = k * mat[i][j];
                }
            }
            return result;
        }
    
        matrix operator-() const {
            matrix result(rows, cols);
            for(int i = 0; i < rows; ++i) {
                for(int j = 0; j < cols; ++j) {
                    result.mat[i][j] = -mat[i][j];
                }
            }
            return result;
        }
    
        void print() const {
            for(int i = 0; i < rows; ++i) {
                for(int j = 0; j < cols; ++j) {
                    cout << mat[i][j] << ", ";
                }
                cout << endl;
            }
        }
    };