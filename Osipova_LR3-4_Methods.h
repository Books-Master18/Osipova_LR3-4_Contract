#ifndef SURNAME_LR3_4_METHODS_H // Защита от повторного включения
#define SURNAME_LR3_4_METHODS_H

#include <iostream>
#include <string>
#include <vector>
#include <limits> // Для numeric_limits
#include <iomanip> // Для setprecision

// Предполагается, что у вас есть заголовочный файл с определением класса Polynom (или Contract, как в предыдущем примере)
#include <M:\\Osipova_Program\\Osipova_LR3-4_Contract\\Methods.h> // Замените на фактическое имя файла, если он другой

// Глобальный вектор объектов класса Polynom
std::vector<Polynom> vectorOfallPolynoms;

// === Функции проверки корректности входных данных ===

// Проверка корректности ввода целого числа
bool isValidUnsigned(const std::string& input) {
    // Проверяем, что строка не пустая и содержит только цифры
    if (input.empty() || !std::all_of(input.begin(), input.end(), ::isdigit)) {
        return false;
    }

    try {
        // Преобразуем строку в число
        unsigned long num = std::stoul(input);

        // Проверяем, что число не выходит за пределы допустимых значений для unsigned int
        if (num > std::numeric_limits<unsigned int>::max()) {
            return false;
        }
    }
    catch (const std::invalid_argument& e) {
        // Ошибка преобразования строки в число
        return false;
    }
    catch (const std::out_of_range& e) {
        // Число выходит за пределы допустимых значений
        return false;
    }

    return true;
}

// Проверка корректности ввода double
bool isValidDouble(const std::string& input) {
    try {
        std::stod(input);
    }
    catch (const std::invalid_argument& e) {
        return false;
    }
    catch (const std::out_of_range& e) {
        return false;
    }
    return true;
}

// Проверка корректности ввода текстовых данных (можно добавить дополнительные проверки, если нужно)
bool isValidString(const std::string& input) {
    return !input.empty(); // Просто проверяем, что строка не пустая
}


// === Функции ввода данных с контролем корректности ===

// Ввод целого числа с контролем корректности
unsigned getUnsignedInput(const std::string& prompt) {
    std::string input;
    unsigned value;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (isValidUnsigned(input)) {
            try {
                value = std::stoul(input);
                return value;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Ошибка: Введенное число слишком велико." << std::endl;
            }
        }
        else {
            std::cerr << "Ошибка: Некорректный ввод. Пожалуйста, введите целое положительное число." << std::endl;
        }
    }
}

// Ввод double с контролем корректности
double getDoubleInput(const std::string& prompt) {
    std::string input;
    double value;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (isValidDouble(input)) {
            try {
                value = std::stod(input);
                return value;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Ошибка: Введенное число слишком велико или мало." << std::endl;
            }
        }
        else {
            std::cerr << "Ошибка: Некорректный ввод. Пожалуйста, введите число." << std::endl;
        }
    }
}

// Ввод текстовых данных с контролем корректности
std::string getStringInput(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (isValidString(input)) {
            return input;
        }
        else {
            std::cerr << "Ошибка: Пожалуйста, введите текст." << std::endl;
        }
    }
}

// === Реализация метода отображения всех объектов класса ===

void showArrayPol(const std::vector<Polynom>& arr) {
    std::cout << "--- Список полиномов ---" << std::endl;
    if (arr.empty()) {
        std::cout << "В списке нет полиномов." << std::endl;
    }
    else {
        for (size_t i = 0; i < arr.size(); ++i) {
            std::cout << "Полином #" << i + 1 << ": " << arr[i] << std::endl;
        }
    }
    std::cout << "-------------------------" << std::endl;
}

// === Реализация методов, демонстрирующих функциональность конструкторов ===

void demonstrateConstructors() {
    std::cout << "--- Демонстрация конструкторов ---" << std::endl;

    // 1. Конструктор по умолчанию
    Polynom pol1;
    std::cout << "Конструктор по умолчанию:" << std::endl << pol1 << std::endl;

    // 2. Параметризованный конструктор с заданной степенью
    unsigned k = getUnsignedInput("Введите степень для параметризованного конструктора: ");
    Polynom pol2(k);
    std::cout << "Параметризованный конструктор с заданной степенью:" << std::endl << pol2 << std::endl;

    //3. Параметризованный конструктор с заданной степенью и коэффициентами
    unsigned k3 = getUnsignedInput("Введите степень полинома: ");
    std::vector<double> mas;
    for (unsigned i = 0; i <= k3; ++i) {
        double coeff = getDoubleInput("Введите коэффициент для x^" + std::to_string(i) + ": ");
        mas.push_back(coeff);
    }
    Polynom pol3(k3, mas);
    std::cout << "Параметризованный конструктор с заданной степенью и коэффициентами:" << std::endl << pol3 << std::endl;
    // 4. Конструктор копирования
    Polynom pol4(pol1);
    std::cout << "Конструктор копирования:" << std::endl << pol4 << std::endl;

    std::cout << "-------------------------------" << std::endl;
}

// === Реализация методов, демонстрирующих функциональность методов класса (по заданию) ===

void demonstrateMethods() {
    std::cout << "--- Демонстрация методов ---" << std::endl;

    Polynom pol; // Создаем объект класса

    unsigned newDegree = getUnsignedInput("Введите новую степень для полинома: ");
    std::vector<double> newCoefficients;
    for (unsigned i = 0; i <= newDegree; ++i) {
        double coeff = getDoubleInput("Введите новый коэффициент для x^" + std::to_string(i) + ": ");
        newCoefficients.push_back(coeff);
    }
    pol.setPolynom(newDegree, newCoefficients);
    std::cout << "Полином после setPolynom:" << std::endl << pol << std::endl;
    double xValue = getDoubleInput("Введите значение x для вычисления полинома: ");
    pol.CalculateValue(xValue); // Пример использования метода CalculateValue

    std::cout << "--------------------------" << std::endl;
}

#endif // SURNAME_LR3_4_METHODS_H