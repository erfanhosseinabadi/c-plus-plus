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
            cout << "matrix destroyed" << endl;  // Fixed message
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

    matrix m1(2,3);
    m1.mat[0][0]=1,m1.mat[0][1]=2,m1.mat[0][2]=3;
    m1.mat[1][0]=4,m1.mat[1][1]=5,m1.mat[1][2]=6;
    matrix m2(2,3);
    m2.mat[0][0]=7,m2.mat[0][1]=8,m2.mat[0][2]=9;
    m2.mat[1][0]=10,m2.mat[1][1]=11,m2.mat[1][2]=12;
    cout<<"m1: "<<endl;
    m1.print();
    cout<<"m2; "<<endl;
    m2.print();
    matrix m3=m1+m2;
    cout<<"m3: "<<endl;
    m3.print();
    matrix m4=m1*m2;
    cout<<"m4: "<<endl;
    m4.print();
    matrix m5=m1*2;
    cout<<"m5: "<<endl;
    m5.print();
    matrix m6 = -m1;
    cout<<"-m1: "<<endl;
    m6.print();

    return 0;


}