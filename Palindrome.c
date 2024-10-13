#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// 랜덤 알파벳 행렬을 생성하는 함수
void randomalphabet (char matrix[][100],int rows, int cols){
    //행렬을 순회하며 A,B,C 중 랜덤으로 알파벳 채우기
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int random_value = rand() % 3;  // 0, 1, 2 중 하나의 값 생성
            if (random_value == 0) {
                matrix[i][j] = 'A';
            } else if (random_value == 1) {
                matrix[i][j] = 'B';
            } else {
                matrix[i][j] = 'C';
            }
        }
    }
 }
// 행렬 출력 함수
void printmatrix (char matrix[][100],int rows , int cols){
    for (int i = 0; i<rows ; i++){
        for( int j = 0 ; j < cols ; j++){
            printf( "%c" ,matrix[i][j]);
        }
        printf("\n");
    }
}
// 회문인지 아닌지 확인하기 위한 함수 선언
bool isPalindrome(char *str, int len){
    for (int i = 0 ; i<len/2 ; i++){
        if(str[i] != str[len - i -1]){
            return false;
        }
    }
    return true;
}
// 회문의 개수를 새기 위한 함수
int countPalindrome(char matrix[][100], int N, int K) {
    if (K > 100) {
        // K가 temp 배열의 크기를 초과하면 함수 종료
        return 0;
    }
    
    int count = 0;
    char temp[100];

    // 가로열 회문 찾기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N - K; j++) {
            // 배열 경계 확인
            if (j + K <= N) {
                strncpy(temp, &matrix[i][j], K);
                temp[K] = '\0';  // 문자열 끝에 null 문자 추가
                if (isPalindrome(temp, K)) {
                    count++;  // 회문 발견 시 카운트 증가
                }
            }
        }
    }

    // 세로열 회문 찾기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N - K; j++) {
            // 배열 경계 확인
            if (j + K <= N) {
                for (int k = 0; k < K; k++) {
                    temp[k] = matrix[j + k][i];
                }
                temp[K] = '\0';  // 문자열 끝에 null 문자 추가
                if (isPalindrome(temp, K)) {
                    count++;  // 회문 발견 시 카운트 증가
                }
            }
        }
    }

    return count;
}
int main (){
    int k = 0 ;// 10번 반복하기 위한 변수 k 선언 
    srand(time(0));
    while(k<10)
    {
        int rows = 100;
        int cols = 100;
        char matrix [100][100];
        int num = 0; // 총 회문의 개수 확인을 위한 변수선언
        randomalphabet(matrix,rows,cols); // 랜덤 알파벳 행렬 생성
        printf("#%d ",k+1);
        for(int j=1;j<101;j++){
            num = num +  countPalindrome(matrix,rows,j+1);
        }
        printf("%d\n",num);        
        k++;
    }

}

