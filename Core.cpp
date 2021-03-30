#include"Core.h"
#include<iostream>

bool is_ok(int arr[9][9] , int i, int j, int k) {
    {
        for (int temp = 0; temp < 9; temp++) {
            if (arr[i][temp] == k || arr[temp][j] == k)
                return false;
        }
        int  boxHor = (i / 3) * 3;
        int boxVer = (j / 3) * 3;
        for (int a = boxHor; a < boxHor + 3; a++) {
            for (int b = boxVer; b < boxVer + 3; b++) {
                if (arr[a][b] == k)
                    return false;
            }
        }
        return true;
    }
}



void solver(int sudoku[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {
                    if (is_ok(sudoku, i, j, k)) {
                        sudoku[i][j] = k;
                        solver(sudoku);
                        sudoku[i][j] = 0;
                    }
                }
                return;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << sudoku[i][j];
        }
    }
}




