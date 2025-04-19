#include <iostream>
using namespace std;
class matrix{
    public:
    int rows,cols;
    double **mat;
    matrix(int r, int c) : rows(r), cols(c) {
        mat = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = 0; 
            }
        }
    }
    ~matrix(){
        for(int i=0;i<rows;++i){
            delete[] mat[i];
        }
        delete[] mat;
    }
    matrix(const matrix& other): rows(other.rows),cols(other.cols){
        mat = new double*[rows];
        for(int i=0;i<rows;++i){
            mat[i]=new double[cols];
        }
        for(int i= 0;i<rows;++i){
            for(int j=0;j<cols;++j){
                mat[i][j]=other.mat[i][j];
            }
        }
    } 
    matrix& operator=(const matrix& other){
        if(this==&other){
            return *this;
        }
        for(int i=0;i<rows;++i){
            delete[] mat[i];
        }
        delete[] mat;
        rows=other.rows;
        cols=other.cols;
        mat = new double*[rows];
        for(int i=0;i<rows;++i){
            mat[i]=new double[cols];
        }
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                mat[i][j]=other.mat[i][j];
            }
        }
    return *this;
    }
    matrix operator+(const matrix& other){
        if(rows!=other.rows||cols!=other.cols){
        throw invalid_argument("the rows and cols in matrices are diffrent");
        }
        matrix result(rows,cols);
            for(int i=0;i<rows;++i){
                for(int j=0;j<cols;++j){
                    result.mat[i][j]=mat[i][j]+other.mat[i][j];
                }
        }
        return result;
    }
    matrix operator-(const matrix& other){
        if(rows!=other.rows||cols!=other.rows){
            throw invalid_argument("the rows and cols in matrices are diffrent");
        }
        matrix result(rows,cols);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.mat[i][j]=mat[i][j]-other.mat[i][j];
            }
        }
        return result;
    }
    matrix operator-()const{
        matrix result(rows,cols);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.mat[i][j]=mat[i][j];
            }
        }
        return result;
    }
    matrix operator*(matrix& other)const{
        if(rows!=other.rows||cols!=other.cols){
            throw invalid_argument("the rows and cols in matrices are diffrent");
        }
        matrix result(rows,cols);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.mat[i][j]=mat[i][j]*other.mat[i][j];
            }
        }
        return result;
    }
    matrix operator*(int k)const{
        matrix result(rows,cols);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.mat[i][j]=k*mat[i][j];
            }
        }
        return result;
    }
    void print()const{
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                cout<<mat[i][j]<<", ";
            }
        cout<<endl;
        }
    }
};
int main(){
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