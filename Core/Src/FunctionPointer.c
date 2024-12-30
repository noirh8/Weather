#include <stdio.h>
#include <stdlib.h>
#include "FunctionPointer.h"


void initFunctionList(FunctionList *list, int initialCapacity)
{
    list->size = 0;
    list->capacity = initialCapacity;
    list->functions = (FunctionPointer *)malloc(initialCapacity * sizeof(FunctionPointer));
}

// Thêm con trỏ hàm vào cuối

void addFunction(FunctionList *list, FunctionPointer func)
{
    if (list->size == list->capacity)
    {
        list->capacity += 2;  // Tăng dung lượng mảng nếu không đủ chỗ
        list->functions = (FunctionPointer *)realloc(list->functions, list->capacity * sizeof(FunctionPointer));
    }
    list->functions[list->size] = func;
    list->size++;
}

// Bỏ con trỏ hàm cuối

void removeLastFunction(FunctionList *list)
{
    if (list->size > 1)
    {
        list->size--;  // Giảm kích thước danh sách, bỏ con trỏ cuối
    }
    else
    {

    }
}

// Gọi con trỏ hàm cuối

void callLastFunction(FunctionList *list) {
    if (list->size > 0)
    {
        list->functions[list->size - 1]();  // Gọi hàm cuối cùng
    }
    else
    {

    }
}

// Đọc con trỏ hàm đầu tiên

void callFirstFunction(FunctionList *list) {
    if (list->size > 0)
    {
        list->functions[0]();  // Gọi hàm đầu tiên
    }
    else
    {

    }
}


void clearAllFunctions(FunctionList *list)
{
    list->size = 0;  // Đặt lại số lượng phần tử về 0
}
