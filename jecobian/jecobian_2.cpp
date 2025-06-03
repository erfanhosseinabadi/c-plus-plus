#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "vect_matrix.cpp"

using namespace std;

vector<double> jacobi(const matrix& A, const vector<double>& b, int& out_iter, int max_iter = 10000, double tolerance = 1e-6) {
    int n = A.rows;
    vector<double> x(n);           
    vector<double> x_new(n);

    out_iter = 0;

    for (int iter = 0; iter < max_iter; ++iter) {
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (i != j)
                    sum += A.mat[i][j] * x.v[j];
            }
            if (A.mat[i][i] == 0) {
                cerr << "Error: Zero diagonal element at position " << i << endl;
                exit(1);
            }
            x_new.v[i] = (b.v[i] - sum) / A.mat[i][i];  
        }

        bool converged = true;
        for (int i = 0; i < n; ++i) {
            if (fabs(x_new.v[i] - x.v[i]) > tolerance) {
                converged = false;
                break;
            }
        }
        if (converged) {
            out_iter = iter + 1;
            break;
        }

        x = x_new;
    }

    return x;
}

void gerarMatrizSimples(matrix& A) {
    int n = A.rows;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A.mat[i][j] = rand() % 10 + 1;
        }
        A.mat[i][i] *= 100;  
    }
}

int main() {
    srand(time(0));

    int N;
    cout << "Enter size of system (N): ";
    cin >> N;

    matrix A(N, N);
    gerarMatrizSimples(A);

    vector<double> b(N);
    for (int i = 0; i < N; ++i)
        b.v[i] = rand() % 100 + 1;  

    int iter_count;
    vector<double> x_sol = jacobi(A, b, iter_count);

    cout << endl << "Computed solution after " << iter_count << " iterations:" << endl;
    x_sol.print();

    return 0;
}