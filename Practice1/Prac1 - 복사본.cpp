#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // strlen

#define SIZE 100
#define BUFFERSIZE 500

using namespace std;

int stringProduct(char* src, int cnt, char* dest, 
                    int bufferSize) {
    //
}

int main() {
    char src[SIZE];
    char dest[BUFFERSIZE];

    int bufferSize = BUFFERSIZE;
    int count = 0;
    int len = 0;
    //////////////////////////////////////////////// #1
    cout << "�ݺ��� ���ڿ��� �Է� �Ͻÿ�: "; // �ݺ� ���ڿ� �Է�
    cin >> src;
    cout << "���ڿ��� �ݺ��� Ƚ���� �Է� �Ͻÿ�: "; // �ݺ� Ƚ�� �Է�
    cin >> count;
    cout << endl;
    ////////////////////////////////////////////////
    //////////////////////////////////////////////// #2
    len = stringProduct(src, count, dest, bufferSize);
    ////////////////////////////////////////////////
    if (len == -2) { // ���� Ȯ��
        cout << "�ݺ� ����� buffer�� �������� " << bufferSize << " ���� ũ�ų� �����ϴ�." << endl;
    }
    else {
        cout << "��� ���ڿ�: " << dest << endl;
        cout << "��� ���ڼ�: " << len << "��" << endl;
    }

}
