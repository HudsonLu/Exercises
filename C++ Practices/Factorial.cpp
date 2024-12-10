#include <iostream>

int main()
{
    int x;
    std::cout << "Please input a non-negative integer: ";
    std::cin >> x;
    
    int factorial = 1;
    for (int i = x; i > 0; i--){
        factorial *= i;
    }
    std::cout << "The factorial of " << x << " is " << factorial;
    
    return 0;
}