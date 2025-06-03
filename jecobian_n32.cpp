#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// Vect class definition
class Vect {
public:
    int dim;
    double *v;
    int num;
    static int count;

    Vect();
    Vect(int d);
    Vect(int d, const double *ve);
    Vect(const Vect& ve);
    ~Vect();

    Vect& operator=(const Vect& ve);
    Vect& operator+=(const Vect& ve);
    Vect& operator-=(const Vect& ve);

    Vect operator+(const Vect& ve) const;
    Vect operator-(const Vect& ve) const;
    Vect operator-() const;

    friend Vect operator*(double k, const Vect& ve);
    double operator*(const Vect& ve) const;
    double operator[](int i) const;

    void print() const;
};

int Vect::count = 0;

Vect::Vect() : dim(0), v(NULL), num(++count) {}

Vect::Vect(int d) : dim(d), num(++count) {
    v = new double[dim];
    for (int i = 0; i < dim; ++i) {
        v[i] = 0.0;
    }
}

Vect::Vect(int d, const double *ve) : dim(d), num(++count) {
    v = new double[dim];
    for (int i = 0; i < dim; ++i) {
        v[i] = ve[i];
    }
}

Vect::Vect(const Vect& ve) : dim(ve.dim), num(++count) {
    v = new double[dim];
    for (int i = 0; i < dim; ++i) {
        v[i] = ve.v[i];
    }
}

Vect::~Vect() {
    delete[] v;
}

Vect& Vect::operator=(const Vect& ve) {
    if (this == &ve) return *this;
    delete[] v;
    dim = ve.dim;
    v = new double[dim];
    for (int i = 0; i < dim; ++i) {
        v[i] = ve.v[i];
    }
    return *this;
}

Vect& Vect::operator+=(const Vect& ve) {
    if (dim != ve.dim) {
        cerr << "Error: different vector sizes!" << endl;
        return *this;
    }
    for (int i = 0; i < dim; ++i) {
        v[i] += ve.v[i];
    }
    return *this;
}

Vect& Vect::operator-=(const Vect& ve) {
    if (dim != ve.dim) {
        cerr << "Error: different vector sizes!" << endl;
        return *this;
    }
    for (int i = 0; i < dim; ++i) {
        v[i] -= ve.v[i];
    }
    return *this;
}

Vect Vect::operator+(const Vect& ve) const {
    Vect result(*this);
    result += ve;
    return result;
}

Vect Vect::operator-(const Vect& ve) const {
    Vect result(*this);
    result -= ve;
    return result;
}

Vect Vect::operator-() const {
    Vect result(dim);
    for (int i = 0; i < dim; ++i) {
        result.v[i] = -v[i];
    }
    return result;
}

Vect operator*(double k, const Vect& ve) {
    Vect result(ve.dim);
    for (int i = 0; i < ve.dim; ++i) {
        result.v[i] = k * ve.v[i];
    }
    return result;
}

double Vect::operator*(const Vect& ve) const {
    if (dim != ve.dim) {
        cerr << "Error: different vector sizes!" << endl;
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < dim; ++i) {
        sum += v[i] * ve.v[i];
    }
    return sum;
}

double Vect::operator[](int i) const {
    if (i < 0 || i >= dim) {
        cerr << "Error: out of bounds!" << endl;
        return 0;
    }
    return v[i];
}

void Vect::print() const {
    cout << "{";
    for (int i = 0; i < dim; ++i) {
        cout << v[i];
        if (i < dim - 1) cout << ", ";
    }
    cout << "}" << endl;
}


// Matrix class definition
class Matrix {
public:
    int dim;
    double *a;

    Matrix();
    Matrix(int n);
    Matrix(int n, const double *arr);
    Matrix(const Matrix& x);
    ~Matrix();

    Matrix& operator=(const Matrix& x);
    Matrix operator+(const Matrix& x) const;
    Matrix operator-(const Matrix& x) const;
    Matrix operator-() const;
    Matrix operator*(const Matrix& x) const;

    friend Matrix operator*(double k, const Matrix& x);
    Vect operator*(const Vect& r) const;
    void print() const;
    int ind(int i, int j) const { return dim*(i-1) + (j-1); }
};

Matrix::Matrix() : dim(0), a(NULL) {}

Matrix::Matrix(int n) : dim(n) {
    a = new double[dim * dim];
    for (int i = 0; i < dim * dim; ++i) {
        a[i] = 0.0;
    }
}

Matrix::Matrix(int n, const double *arr) : dim(n) {
    a = new double[dim * dim];
    for (int i = 0; i < dim * dim; ++i) {
        a[i] = arr[i];
    }
}

Matrix::Matrix(const Matrix& x) : dim(x.dim) {
    a = new double[dim * dim];
    for (int i = 0; i < dim * dim; ++i) {
        a[i] = x.a[i];
    }
}

Matrix::~Matrix() {
    delete[] a;
}

Matrix& Matrix::operator=(const Matrix& x) {
    if (this == &x) return *this;
    delete[] a;
    dim = x.dim;
    a = new double[dim * dim];
    for (int i = 0; i < dim * dim; ++i) {
        a[i] = x.a[i];
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& x) const {
    Matrix res(dim);
    for (int i = 0; i < dim * dim; ++i) {
        res.a[i] = a[i] + x.a[i];
    }
    return res;
}

Matrix Matrix::operator-(const Matrix& x) const {
    Matrix res(dim);
    for (int i = 0; i < dim * dim; ++i) {
        res.a[i] = a[i] - x.a[i];
    }
    return res;
}

Matrix Matrix::operator-() const {
    Matrix res(dim);
    for (int i = 0; i < dim * dim; ++i) {
        res.a[i] = -a[i];
    }
    return res;
}

Matrix Matrix::operator*(const Matrix& x) const {
    Matrix res(dim);
    for (int i = 1; i <= dim; ++i) {
        for (int j = 1; j <= dim; ++j) {
            res.a[res.ind(i,j)] = 0;
            for (int k = 1; k <= dim; ++k) {
                res.a[res.ind(i,j)] += a[ind(i,k)] * x.a[ind(k,j)];
            }
        }
    }
    return res;
}

Matrix operator*(double k, const Matrix& x) {
    Matrix res(x.dim);
    for (int i = 0; i < x.dim * x.dim; ++i) {
        res.a[i] = k * x.a[i];
    }
    return res;
}

Vect Matrix::operator*(const Vect& r) const {
    if (dim != r.dim) {
        cerr << "Error: matrix and vector dimensions do not match!" << endl;
        return Vect();
    }
    Vect res(dim);
    for (int i = 1; i <= dim; ++i) {
        res.v[i-1] = 0;
        for (int j = 1; j <= dim; ++j) {
            res.v[i-1] += a[ind(i,j)] * r[j-1];
        }
    }
    return res;
}

void Matrix::print() const {
    for (int i = 1; i <= dim; ++i) {
        for (int j = 1; j <= dim; ++j) {
            cout << a[ind(i,j)] << " ";
        }
        cout << endl;
    }
}


// Helper functions
Matrix diag(const Matrix& A) {
    Matrix D(A.dim);
    for (int i = 1; i <= A.dim; ++i) {
        D.a[D.ind(i, i)] = A.a[A.ind(i, i)];
    }
    return D;
}

Matrix inverse_diagonal(const Matrix& D) {
    Matrix H(D.dim);
    for (int i = 1; i <= H.dim; ++i) {
        double val = D.a[D.ind(i, i)];
        if (fabs(val) < 1e-12) {
            cerr << "Zero diagonal element, can't invert" << endl;
            continue;
        }
        H.a[H.ind(i, i)] = 1.0 / val;
    }
    return H;
}

Matrix identity(int n) {
    Matrix I(n);
    for (int i = 1; i <= n; ++i)
        I.a[I.ind(i, i)] = 1.0;
    return I;
}

Matrix generate_matrix(int n) {
    Matrix A(n);
    for (int i = 1; i <= n; ++i) {
        double row_sum = 0;
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                A.a[A.ind(i,j)] = rand() % 11 - 5;
                row_sum += fabs(A.a[A.ind(i,j)]);
            }
        }
        A.a[A.ind(i,i)] = 100.0 * row_sum + (rand() % 5 + 1);
    }
    return A;
}

Vect jacobi(const Matrix& A, const Vect& B, int maxIter = 1000, double eps = 1e-6) {
    int n = B.dim;
    Vect xOld(n), xNew(n);

    Matrix D = diag(A);
    Matrix H = inverse_diagonal(D);
    Matrix I = identity(n);
    Matrix M = I - H * A;

    for (int iter = 0; iter < maxIter; ++iter) {
        xNew = M * xOld + H * B;

        double norm = 0;
        Vect diff = xNew - xOld;
        for (int i = 0; i < n; ++i)
            norm += diff[i] * diff[i];
        norm = sqrt(norm);

        if (norm < eps) break;
        xOld = xNew;
    }

    return xNew;
}

// Main function
int main() {
    srand((unsigned int)time(NULL));

    for (int n = 3; n <= 10; ++n) {
        cout << "----Dimension " << n << "----" << endl;

        double* x_true_arr = new double[n];
        for (int i = 0; i < n; ++i) {
            x_true_arr[i] = rand() % 10 + 1;
        }

        Vect x_true(n, x_true_arr);
        Matrix A = generate_matrix(n);
        Vect B = A * x_true;
        Vect x_approx = jacobi(A, B);

        cout << "Matrix A:" << endl;
        A.print();

        cout << "Vector B (computed from x_true): ";
        B.print();

        cout << "Expected x (x_true): ";
        x_true.print();

        cout << "Approximated x (Jacobi): ";
        x_approx.print();

        Vect error = x_approx - x_true;
        double max_err = 0;
        for (int i = 0; i < n; ++i)
            max_err = (max_err > fabs(error[i])) ? max_err : fabs(error[i]);

        cout << "Max absolute error: " << max_err << endl;

        delete[] x_true_arr;
    }

    return 0;
}