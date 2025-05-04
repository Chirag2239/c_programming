#include <stdio.h>

int main(){
    int row = 4, column = 5, col0 = 1, i = 0, j = 0;
    int arr[][5] = {{1,1,1,1,1},{1,1,0,1,1},{1,1,1,1,0},{1,1,1,1,1}};

    for(i = 1; i < row; i++){
        for(j = 0; j < i; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}