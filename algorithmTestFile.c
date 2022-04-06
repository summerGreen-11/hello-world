#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key) {
    int pl = 0; //�˻����� �� �� �ε���
    int pr = n - 1; //�˻����� �� �� �ε���
    int pc; //�˻����� �Ѱ�� �ε���
    do {
        pc = (pl + pr) / 2; //�߾Ӱ� �ε��� ���

        if (a[pc] == key) {
            while (pc>pl) {
                if (a[pc - 1] < key) 
                    break;
                pc--;
            }
            return pc;
        }
        else if (a[pc] < key) {
            pl = pc + 1;
        }
        else {
            pr = pc - 1;
        }
    } while (pl <= pr);
    return -1; //�˻� ����
}

int main() {
    int* x; //�迭�� ������ Ÿ������ ����
    int nx, i, key, idx;
    puts("=== ���� �˻� ===");
    printf("��� ���� : "); scanf_s("%d", &nx);
    x = (int*)calloc(nx, sizeof(int)); //int ��� ũ�⸦ nx�� �Ҵ�
    //nx�� ��� �Է� �ޱ�
    printf("x[0] : "); scanf_s("%d", &x[0]);
    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i); scanf_s("%d", &x[i]);
        } while (x[i] < x[i - 1]); //���������� �ƴϸ� �ٽ� �Է�
    }
    printf("�˻��� : "); scanf_s("%d", &key);
    idx = bin_search(x, nx, key); //�Լ� ȣ��
    if (idx == -1)
        puts("�˻��� �����߽��ϴ�.");
    else
        printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", key, idx);
    free(x);
    return 0;
}