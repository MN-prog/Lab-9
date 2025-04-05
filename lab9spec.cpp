#include <iostream>
#include <string>
#include <cctype>

template <typename T, typename T1>
T* convertation(const T1* inputArr, size_t size) {
    T* resultArr = new T[size];
    for (size_t i = 0; i < size; ++i) {
        resultArr[i] = static_cast<T>(inputArr[i]);
    }
    return resultArr;
}

template <>
int* convertation<int, std::string>(const std::string* inputArr, size_t size) {
    int* resultArr = new int[size];
    for (size_t i = 0; i < size; ++i) {
        try {
            resultArr[i] = std::stoi(inputArr[i]);
        } catch (const std::exception&) {
            std::cerr << "Ошибка: строка \"" << inputArr[i] << "\" не является числом." << std::endl;
            resultArr[i] = 0;
        }
    }
    return resultArr;
}

template <>
double* convertation<double, std::string>(const std::string* inputArr, size_t size) {
    double* resultArr = new double[size];
    for (size_t i = 0; i < size; ++i) {
        try {
            resultArr[i] = std::stod(inputArr[i]);
        } catch (const std::exception&) {
            std::cerr << "Ошибка: строка \"" << inputArr[i] << "\" не является числом." << std::endl;
            resultArr[i] = 0.0;
        }
    }
    return resultArr;
}

int main() {
    int intarr[] = {78, 128, 10294, 7821};
    size_t intarr_size = sizeof(intarr) / sizeof(intarr[0]);

    std::cout << "1) Исходный массив (int): " << std::endl;
    for (size_t i = 0; i < intarr_size; ++i) {
        std::cout << intarr[i] << " ";
    }
    std::cout << std::endl;

    double* doublearr = convertation<double>(intarr, intarr_size);
    std::cout << "Преобразованный массив (double): " << std::endl;
    for (size_t i = 0; i < intarr_size; ++i) {
        std::cout << doublearr[i] << " ";
    }
    std::cout << std::endl;
    delete[] doublearr;

    std::cout << "2) Исходный массив (string): " << std::endl;
    std::string strarr[] = {"10", "20", "30", "40", "abc"};
    size_t strarr_size = sizeof(strarr) / sizeof(strarr[0]);

    for (size_t i = 0; i < strarr_size; ++i) {
        std::cout << strarr[i] << " ";
    }
    std::cout << std::endl;

    int* int1arr = convertation<int>(strarr, strarr_size);
    std::cout << "Преобразованный массив (int): " << std::endl;
    for (size_t i = 0; i < strarr_size; ++i) {
        std::cout << int1arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] int1arr;

    return 0;
}
