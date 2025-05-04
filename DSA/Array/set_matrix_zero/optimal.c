#include <stdio.h>

int main(){
    int row = 4, column = 5, col0 = 1, i = 0, j = 0;
    int arr[][5] = {{1,1,1,1,1},{1,1,0,1,1},{1,1,1,1,0},{1,1,1,1,1}};
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0;
                if(j != 0){
                    arr[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }

    for(i = 1; i < row; i++){
        for(j = 1; j < column; j++){
            if(arr[i][j] != 0){
                if(arr[i][0] == 0 || arr[0][j] == 0){
                    arr[i][j] = 0;
                }
            }
        }
    }

    if(arr[0][0] == 0){
        for(j = 0; j < column; j++){
            arr[0][j] = 0;
        }
    }

    if(col0 == 0){
        for(i = 0; i < row; i++){
            arr[i][0] = 0;
        }
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    
}