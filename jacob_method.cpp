#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Vector {
protected:
    vector<double> data;
public:
    Vector(int size = 0) : data(size, 0.0) {}
    int size() const { return data.size(); }
    double& operator[](int i) { return data[i]; }
    const double& operator[](int i) const { return data[i]; }
};

class Matrix {
protected:
    vector<vector<double> > data;
public:
    Matrix(int rows = 0, int cols = 0) : data(rows, vector<double>(cols, 0.0)) {}
    int rows() const { return data.size(); }
    int cols() const { return data.empty() ? 0 : data[0].size(); }
    vector<double>& operator[](int i) { return data[i]; }
    const vector<double>& operator[](int i) const { return data[i]; }
};

Vector multiply(const Matrix& A, const Vector& v) {
    Vector result(A.rows());
    for (int i = 0; i < A.rows(); ++i)
        for (int j = 0; j < A.cols(); ++j)
            result[i] += A[i][j] * v[j];
    return result;
}

Vector jacobi(const Matrix& A, const Vector& B, const Vector& x0, double tol, int max_iter, int& iters) {
    int n = A.rows();
    Vector x = x0, x_new(n);
    for (iters = 0; iters < max_iter; ++iters) {
        for (int i = 0; i < n; ++i) {
            double sum = 0;
            for (int j = 0; j < n; ++j)
                if (j != i) sum += A[i][j] * x[j];
            x_new[i] = (B[i] - sum) / A[i][i];
        }

        double max_diff = 0;
        for (int i = 0; i < n; ++i) {
            double diff = fabs(x_new[i] - x[i]);
            if (diff > max_diff)
                max_diff = diff;
        }
        if (max_diff < tol) break;
        x = x_new;
    }
    
    return x;
}

void generateProblem(Matrix& A, Vector& B, Vector& x_true) {
    static bool seeded = false;
    if (!seeded) { srand((unsigned)time(0)); seeded = true; }

    int n = A.rows();
    for (int i = 0; i < n; ++i)
        x_true[i] = rand() % 10 + 1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            A[i][j] = (i == j) ? rand() % 10 + n * 5 : rand() % 10;

    B = multiply(A, x_true);
}

int main() {
    const double tol = 1e-6;
    const int max_iter = 100000;

    vector<int> sizes;
    sizes.push_back(2);
    sizes.push_back(5);
    sizes.push_back(10);

    for (int k = 0; k < (int)sizes.size(); ++k) {
        int size = sizes[k];

        Matrix A(size, size);
        Vector x_true(size), B(size), x0(size);

        generateProblem(A, B, x_true);
        for (int i = 0; i < size; ++i)
            x0[i] = 0.0;

        int iters;
        Vector x = jacobi(A, B, x0, tol, max_iter, iters);

        double max_error = 0;
        for (int i = 0; i < size; ++i) {
            double error = fabs(x[i] - x_true[i]);
            if (error > max_error)
                max_error = error;
        }

        cout << "Size: " << size << "\nIterations: " << iters << "\nMax Error: " << max_error << "\n\n";
    }

    return 0;
}