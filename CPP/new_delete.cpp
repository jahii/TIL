#include <iostream>

int main() {
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;
    int *list = new int[arr_size];
    for(int i=0; i<arr_size; i++){
        std::cin >> list[i];
    }
    for(int i=0; i<arr_size; i++){
        std::cout << i+1 << "th element is : " << list[i] << std::endl;
    }
    delete list;
}