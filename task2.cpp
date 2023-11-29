#include <iostream>

int main() {
    double num1, num2, result;
    char operation;

    // Get user input
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Get the desired arithmetic operation
    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    // Perform the selected operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
            break;
        case '/':
            // Check for division by zero
            if (num2 != 0) {
                result = num1 / num2;
                std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            std::cout << "Error: Invalid operation.\n";
            break;
    }

    return 0;
}
