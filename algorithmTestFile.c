#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key) {
    int pl = 0; //검색범위 맨 앞 인덱스
    int pr = n - 1; //검색범위 맨 뒤 인덱스
    int pc; //검색범위 한가운데 인덱스
    do {
        pc = (pl + pr) / 2; //중앙값 인덱스 계산

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
    return -1; //검색 실패
}

int main() {
    int* x; //배열을 포인터 타입으로 선언
    int nx, i, key, idx;
    puts("=== 이진 검색 ===");
    printf("요소 개수 : "); scanf_s("%d", &nx);
    x = (int*)calloc(nx, sizeof(int)); //int 요소 크기를 nx개 할당
    //nx개 요소 입력 받기
    printf("x[0] : "); scanf_s("%d", &x[0]);
    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i); scanf_s("%d", &x[i]);
        } while (x[i] < x[i - 1]); //오름차순이 아니면 다시 입력
    }
    printf("검색값 : "); scanf_s("%d", &key);
    idx = bin_search(x, nx, key); //함수 호출
    if (idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d는(은) x[%d]에 있습니다.\n", key, idx);
    free(x);
    return 0;
}