/*
 * FunctionPointer.h
 *
 *  Created on: Dec 8, 2024
 *      Author: MSI MODERN 14
 */

#ifndef INC_FUNCTIONPOINTER_H_
#define INC_FUNCTIONPOINTER_H_



#include <stdio.h>
#include <stdlib.h>

typedef void (*FunctionPointer)(void);  // Định nghĩa kiểu con trỏ hàm void

typedef struct {
    FunctionPointer *functions;  // Mảng chứa các con trỏ hàm
    int size;   // Số lượng phần tử hiện có
    int capacity;  // Dung lượng tối đa của mảng
} FunctionList;

// Khởi tạo danh sách hàm
void initFunctionList(FunctionList *list, int initialCapacity) ;
// Thêm con trỏ hàm vào cuối
void addFunction(FunctionList *list, FunctionPointer func) ;
// Bỏ con trỏ hàm cuối
void removeLastFunction(FunctionList *list) ;

// Gọi con trỏ hàm cuối
void callLastFunction(FunctionList *list) ;

// Đọc con trỏ hàm đầu tiên
void callFirstFunction(FunctionList *list) ;
void clearAllFunctions(FunctionList *list) ;

#endif /* INC_FUNCTIONPOINTER_H_ */
