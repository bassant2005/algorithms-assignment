#include <iostream>
using namespace std;

// ===== function to print Fibonacci series using any function =====
void PrintFibonacciSeries(int n, int (*f)(int)) {
    for (int i = 0; i < n; i++)
        cout << f(i) << " ";
    cout << endl;
}

// ===== Recursive function =====
int RecursiveFibonacci(int n) {
    if (n <= 1)
        return n;
    return RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
}

// ===== Dynamic Programming function =====
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

int main() {
    int n;
    cout << "Enter a number: " ;
    cin >> n;
    cout << endl;

    cout << "Fibonacci Series (Recursive): ";
    PrintFibonacciSeries(n, RecursiveFibonacci);
    cout << "Fibonacci " << n << " : " << RecursiveFibonacci(n) << endl;

    cout << endl;

    cout << "Fibonacci Series (DP): ";
    PrintFibonacciSeries(n, DynamicProgrammingFibonacci);
    cout << "Fibonacci " << n << " : " << DynamicProgrammingFibonacci(n) << endl;
}
