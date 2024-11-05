#include <stdio.h>

void mark_row(int arr[][5], int row, int row_sz){
    int i = 0;
    for(i = 0; i < row_sz; i++){
        if(arr[row][i] != 0){
            arr[row][i] = -1;
        }
    }
}

int mark_column(int arr[][5], int column, int col_sz){
    int i = 0;
    for(i = 0; i < col_sz; i++){
        if(arr[i][column] != 0){
            arr[i][column] = -1;
        }
    }
}

int main(){
    int row = 4, column = 5, i = 0, j = 0;
    int arr[][5] = {{1,1,1,1,1},{1,1,0,1,1},{1,1,1,1,0},{1,1,1,1,1}};
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            if(arr[i][j] == 0){
                mark_row(arr, i, 5);
                mark_column(arr, j, 4);
            }
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    
}