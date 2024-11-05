#include <stdio.h>
#include <string.h>

int solution(char grid[][5], int N) {
    int totalChanges = 0;
    for(int i = 0; i < N/2; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] != grid[i][5-1-i]){
                totalChanges++;
            }
            else if(grid[i][j] != grid[N-1-i][j]){
                totalChanges++;
            }
            else if(grid[i][j] != grid[N-1-i][5-1-i]){
                totalChanges++;
            }
        }
    }
    return totalChanges;
}

int main() {
    // Input matrix
    int N = 3;  // Corrected row size
    char matrix[3][5] = {
        "BBWWB",
        "WWWBW",
        "BWWWW"
    };
    
    int totalChanges = solution(matrix, N);
    printf("total_change = %d\n", totalChanges);
    
    return 0;
}