#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void multiply(vector<int>& result, int x) {
    int carry = 0;
    int size = result.size();

    for (int i = 0; i < size; ++i) {
        int product = result[i] * x + carry;
        result[i] = product % 10;
        carry = product / 10;
    }

    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
}

void factorial(int n) {
    vector<int> result;
    result.push_back(1);

    for (int i = 2; i <= n; ++i) {
        multiply(result, i);
    }

    cout << "Factorial of " << n << " is: ";
    for (int i = result.size() - 1; i >= 0; --i) {
        cout << result[i];
    }
    cout << endl;
}

int main() {
    int num;

    cout << "Enter a number to calculate its factorial: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        factorial(num);
    }

    return 0;
}

