#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Vector {
private:
    vector<double> data;
public:
    Vector(int size = 0) : data(size, 0.0) {}

    int size() const {
        return data.size();
    }

    double& operator[](int i) {
        return data[i];
    }

    const double& operator[](int i) const {
        return data[i];
    }
};

void printVector(const Vector& v) {
    cout << "[ ";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "]" << endl;
}


class Matrix {
private:
    vector<vector<double> > data;
public:
    Matrix(int rows = 0, int cols = 0) : data(rows, vector<double>(cols, 0.0)) {}

    int rows() const {
        return data.size();
    }

    int cols() const {
        if (data.empty()) {
            return 0;
        } else {
            return data[0].size();
        }
    }

    vector<double>& operator[](int index) {
        return data[index];
    }

    const vector<double>& operator[](int index) const {
        return data[index];
    }
};

void printMatrix(const Matrix& m) {
    for (int i = 0; i < m.rows(); ++i) {
        for (int j = 0; j < m.cols(); ++j)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

Vector multiplyMatrixVector(const Matrix& A, const Vector& v) {
    int n = A.rows();
    Vector result(n);

    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < A.cols(); ++j) {
            sum += A[i][j] * v[j];
        }
        result[i] = sum;
    }

    return result;
}

Vector jacobi(const Matrix& A, const Vector& B, const Vector& x0,
              double tolerance, int max_iterations, int& iterations) {
    int n = A.rows();
    Vector x = x0;
    Vector x_new(n);

    for (iterations = 0; iterations < max_iterations; ++iterations) {
        for (int i = 0; i < n; ++i) {
            double sigma = 0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sigma += A[i][j] * x[j];
                }
            }
            x_new[i] = (B[i] - sigma) / A[i][i];
        }

        double diff = 0;
        for (int i = 0; i < n; ++i) {
            double err = abs(x_new[i] - x[i]);
            if (err > diff) {
                diff = err;
            }
        }

        if (diff < tolerance) {
            break;
        }

        x = x_new;
    }

    return x;
}

void generateProblem(Matrix& A, Vector& B, Vector& x_true) {
    static bool seeded = false;
    if (!seeded) {
        srand((unsigned)time(0));
        seeded = true;
    }

    int n = A.rows();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = (rand() % 1000 - 500) / 500.0;
        }
        A[i][i] *= 100; 
    }
    for (int i = 0; i < n; ++i) {
        x_true[i] = (rand() % 1000 - 500) / 500.0;
    }

    B = multiplyMatrixVector(A, x_true);
}

int main() {
    const double tolerance = 1e-6;
    const int max_iterations = 100000;

    vector<int> sizes;
    sizes.push_back(2);
    sizes.push_back(5);
    sizes.push_back(10);

    for (size_t i = 0; i < sizes.size(); ++i) {
        int size = sizes[i];

        Matrix A(size, size);
        Vector x_true(size), B(size), x0(size);

        generateProblem(A, B, x_true);

        for (int i = 0; i < size; ++i) {
            x0[i] = 0.0;
        }

        int iterations;
        Vector solution = jacobi(A, B, x0, tolerance, max_iterations, iterations);

        double max_error = 0.0;
        for (int i = 0; i < size; ++i) {
            double error = abs(solution[i] - x_true[i]);
            if (error > max_error) {
                max_error = error;
            }
        }

        cout << "Size: " << size << endl;
        cout << "Iterations: " << iterations << endl;
        cout << "Max Error: " << max_error << endl << endl;
    }

    return 0;
}