#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // strlen
#include <cstdlib> // malloc, free 

#define SIZE 100
#define BUFFERSIZE 500

using namespace std;

int stringProduct(char* src, int cnt, char* dest, int bufferSize) {
    int srcStrLen = strlen(src);
    int destStrLen = srcStrLen * cnt; // 버퍼 사이즈와 반복할 길이 

    if (destStrLen > bufferSize - 1) {
        return -2; // destStrLen, 즉 함수의 결과로 내보낼 수 있는 크기보다 크므로, error code를 -2로 설정하여 반환
    }
    else {
        for (int k = 0; k < cnt; k++) {
            strcpy(dest + k * srcStrLen, src);
        }
        return destStrLen;
    }
}

int main() {
    char src[SIZE];
    char dest[BUFFERSIZE];

    int bufferSize = BUFFERSIZE;
    int count = 0;
    int len = 0;

    //src = (char*)malloc(sizeof(char) * SIZE);

    //////////////////////////////////////////////// #1
    cout << "반복할 문자열을 입력 하시오: "; // 반복 문자열 입력
    cin >> src;


    cout << "문자열을 반복할 횟수를 입력 하시오: "; // 반복 횟수 입력
    cin >> count;


    cout << endl;
    ////////////////////////////////////////////////


    //////////////////////////////////////////////// #2
    len = stringProduct(src, count, dest, bufferSize);
    ////////////////////////////////////////////////

    if (len == -2) { // 오류 확인
        cout << "반복 결과가 buffer의 사이즈인 " << bufferSize << " 보다 크거나 같습니다." << endl;
    }
    else {
        cout << "결과 문자열: " << dest << endl;
        cout << "출력 글자수: " << len << "개" << endl;
    }


    return 0;
}
