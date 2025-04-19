#include <iostream>
using namespace std;
class matrix{
    public:
    int rows,cols;
    double **mat;
    matrix(int r,int c): rows(r), cols(c){
        mat = new double*[rows];
        for(int i=0;i<rows;++i){
            mat[i]=new double[cols];
        }
    }
    ~matrix(){
        for(int i=0;i<rows;++i){
            delete[] mat[i];
        }
        delete[] mat;
    }
    matrix operator+(const matrix& other)const{
        matrix result(rows,cols);
        if(rows!=other.rows||cols!=other.cols){
            cout<<"the matrices are not equal!"<<<endl;
            return matrix(0,0);
        }
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.mat[i][j]=mat[i][j]+other.mat[i][j];
            }
        }
        return result;
    }
    matrix operator*(const matrix& other)const{
        matrix result(rows,cols);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.mat[i][j]=mat[i][j]+other.mat[i][j];
            }
        }
        return result;
    }
    matrix operator*(int k)const{
        matrix result(rows,cols);
        for(int i=0;i<rows;++i){
            for(int j=0;j<rows;++j){
                result.mat[i][j]=k*mat[i][j];
            }
        }
        return result;
    }
    
};