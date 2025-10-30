#include <iostream>
using namespace std;

// ===== Function to print Fibonacci series using any function =====
void PrintFibonacciSeries(int n, int (*f)(int)) {
    for (int i = 0; i < n; i++)
        cout << f(i) << " ";
    cout << endl;
}

// ===== Recursive Fibonacci =====
int RecursiveFibonacci(int n) {
    if (n <= 1)
        return n;
    return RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
}

// ===== Dynamic Programming Fibonacci =====
int DynamicProgrammingFibonacci(int n) {
    if (n <= 1)
        return n;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

// ===== Helper function to multiply two 2x2 matrices =====
void multiply(int A[2][2], int B[2][2]) {
    int x = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    int y = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    int z = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    int w = A[1][0]*B[0][1] + A[1][1]*B[1][1];

    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;
}

// ===== Helper function to raise matrix A to power n using divide & conquer =====
void power(int A[2][2], int n) {
    if (n == 0 || n == 1)
        return;

    int M[2][2] = {{1, 1}, {1, 0}};
    power(A, n / 2);
    multiply(A, A);

    if (n % 2 != 0)
        multiply(A, M);
}

// ===== Divide & Conquer (Matrix Multiplication) Fibonacci =====
int MatrixFibonacci(int n) {
    if (n == 0)
        return 0;

    int A[2][2] = {{1, 1}, {1, 0}};
    power(A, n - 1);
    return A[0][0];
}

// ===== Main Function =====
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << endl;

    cout << "Fibonacci Series (Recursive): ";
    PrintFibonacciSeries(n, RecursiveFibonacci);
    cout << "Fibonacci(" << n << ") = " << RecursiveFibonacci(n) << endl;
    cout << endl;

    cout << "Fibonacci Series (Dynamic Programming): ";
    PrintFibonacciSeries(n, DynamicProgrammingFibonacci);
    cout << "Fibonacci(" << n << ") = " << DynamicProgrammingFibonacci(n) << endl;
    cout << endl;

    cout << "Fibonacci Series (Matrix / Divide & Conquer): ";
    PrintFibonacciSeries(n, MatrixFibonacci);
    cout << "Fibonacci(" << n << ") = " << MatrixFibonacci(n) << endl;
}
