#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 20
typedef struct cell {

    char dd[SIZE]; // 영화 제목
    int gm; // 금액
    int c;// 남은 좌석 
    int k; //총 좌석 수 
    int gu;// 구입한 티켓 수 
    float oi; // 티켓수 * 영화금액해서 = 영화 하나 총합 금액
    char nn[100]; // 영화 간략한 줄거리
    char pp[SIZE]; // 영화 평점 
    char si[SIZE];// 영화 시간대 
    int ga;// 영화관 몇번 인지
    struct cell* next; //다음연결주소
}MOVIE;

int main() {

    int a = 0;
    MOVIE* head = (MOVIE*)malloc(sizeof(MOVIE));
    head->next = NULL;

    while (1) {
        menu();
        scanf("%d", &a);

        if (a == 10) {    // 프로그램 종료 
            system("cls");
            printf("\n\t프로그램을 종료합니다.\n");
            return;
        }

        switch (a)
        {
        case 1:
            dd(head); // 영화등록 함수
            break;

        case 2:
            sac(head); // 영화 삭제 함수 
            break;

        case 3:
            hm(head); // 영화 리스트를 뽑아내는 함수 
            break;

        case 4:
            gu(head); // 영화 티켓 구매 함수 
            break;

        case 5:
            pa(head); //영화 티켓 판매 함수 
            break;

        case 6:
            gum(head); // 영화 정보 검색 함수 
            break;

        case 7:
            drk(head); // 영수증 출력 함수
            break;

        case 8:
            yq(head); // 영화 리스트 파일 출력 함수 
            break;

        case 9:
            ya(head);  // 영화 영수증 파일 출력 함수 
            break;

        default:  // 잘못된 값 출력 
            system("cls");
            printf("\n\t잘못된 값이니 다시 입력해 주세요.\n");
        }
    }
}

menu() {

    printf("===============================\n");
    printf("해달시네마에 오신걸 환영합니다.\n");
    printf("    마스크를 착용해주세요 !    \n");
    printf("===============================\n");


    printf("-------------------------\n");
    printf("1. 영화 등록\n");
    printf("2. 영화 삭제\n");
    printf("3. 현재 상영하는 영화\n");
    printf("4. 영화 티켓 구매\n");
    printf("5. 영화 티켓 판매\n");
    printf("6. 영화 정보 검색\n");
    printf("7. 영수증 출력\n");
    printf("8. 영화 리스트 파일 출력\n");
    printf("9. 영수증 파일 출력\n");
    printf("10.프로그램 종료\n");
    printf("-------------------------\n");
    printf("번호를 입력해 주세요.\n");
}

dd(MOVIE* head) { // 영화 등록 함수 

    MOVIE* movie = (MOVIE*)malloc(sizeof(MOVIE));
    MOVIE* ptr = (MOVIE*)malloc(sizeof(MOVIE));;

    system("cls");
    printf("영화를 등록해 주세요.\n");
    scanf("\t%s", movie->dd);

    printf("\n영화의 간략한 내용을 입력해 주세요.(최대 100자)\n");
    while (getchar() != '\n');
    scanf("%[^\n]", movie->nn, 100);

    printf("\n영화의 평점을 1~10점 중에 입력해 주세요.(문자)\n");
    scanf("%s", movie->pp);

    printf("\n금액을 얼마로 설정할지 입력해 주세요.(숫자)\n");
    scanf(" %d", &movie->gm);

    printf("\n영화의 총 좌석을 지정해 주세요.(숫자)\n");
    scanf("%d", &movie->k);

    printf("\n영화의 시간대를 입력해 주세요.(문자)(ex : 13:00~15:00)\n");
    scanf("%s", movie->si);

    printf("\n영화관을 몇 관으로 할지 정해주세요.(숫자)\n");
    scanf(" %d", &movie->ga);

    movie->gu = 0;  // 티켓 구입 수 초기화
    movie->c = movie->k;  // 남은 좌석 수 초기화
    movie->oi = 0;  // 영화 하나 총 금액 초기화

    movie->next = NULL;

    if (head->next == NULL) {
        head->next = movie;
        return;
    }

    ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = movie;
    return;

}

sac(MOVIE* head) {  // 영화 삭제 함수 

    MOVIE* movie = (MOVIE*)malloc(sizeof(MOVIE));
    movie = head->next;
    MOVIE* ptr = (MOVIE*)malloc(sizeof(MOVIE));;
    ptr = head;

    int n = 0;
    char sc[80];

    system("cls");

    if (movie == NULL) {
        printf("\n현재 등록한 영화가 없습니다.\n\n");
        return;
    }

    if (movie->next == NULL) {
        printf("\n존재했던 1개의 영화를 삭제하였습니다.\n");
        head->next = NULL;
        return;
    }

    printf("삭제할 영화를 입력해 주세요.\n");
    scanf("%s", sc);

    while (ptr != NULL) {
        n = strcmp(sc, ptr->dd);

        if (n == 0) {
            printf("\n삭제 하였습니다.\n");
            movie->next = ptr->next;
            return;
        }
        movie = ptr;
        ptr = ptr->next;
    }
    free(movie);
    free(ptr);
    return;

    if (n != 0) {
        printf("\n잘못 입력하였습니다.\n");
        return;
    }
}

gum(MOVIE* head) {   // 영화 정보 검색 함수 

    MOVIE* movie = (MOVIE*)malloc(sizeof(MOVIE));
    movie = head->next;
    int n = 0;
    char sa[80];

    system("cls");

    if (movie == NULL) {
        printf("\n현재 등록한 영화가 없습니다.\n");
        return;
    }

    printf("검색할 영화를 입력해 주세요.\n");
    scanf("%s", sa);

    while (movie != NULL) {
        n = strcmp(sa, movie->dd);
        if (n == 0) {
            printf("\n\n\t영화명 : %s\n\t금액 : %d원\n\t평점 : %s\n\t내용 : %s\n", movie->dd, movie->gm, movie->pp, movie->nn);
            return;
        }
        movie = movie->next;
    }

    if (n != 0) {
        printf("\n영화 데이터가 존재하지 않습니다.\n");
        return;
    }
}

hm(MOVIE* head) {    // 리스트 함수 

    MOVIE* ss = (MOVIE*)malloc(sizeof(MOVIE));
    ss = head->next;
    int n = 1;

    system("cls");

    if (ss == NULL) {
        printf("\n현재 상영하는 영화가 없습니다.\n");
        return;
    }

    while (ss != NULL) {
        printf("\n\t★%d번째 영화★\n\t이름 : %s\n\t금액 : %d\n\t현재 좌석 수 : %d\n\t영화 시간 : %s\n\n", n, ss->dd, ss->gm, ss->c, ss->si);
        ss = ss->next;
        n++;
    }
    return;
}

gu(MOVIE* head) { // 티켓 구매 

    int n = 0; // 문자열 비교 
    int k = 0; // 구매할지 말지 변수 
    int i; // 반복문을 위한 변수 
    char as[80];
    int hh = 0; // 할인권 여부 
    int lj = 0; // 구입할 티켓 수 
    MOVIE* find = head->next;

    system("cls");

    if (find == NULL) {
        printf("\n현재 상영하는 영화가 없습니다.\n");
        return;
    }

    while (find != NULL) {
        printf("\n\n\t이름 : %s\n\t금액 : %d\n\t현재 좌석 수 : %d\n\t영화 시간 : %s\n\n", find->dd, find->gm, find->c, find->si);
        find = find->next;
    }
    find = head->next;

    printf("구입할 영화를 입력해 주세요.\n");
    scanf("%s", as);

    while (find != NULL) {
        n = strcmp(as, find->dd);

        if (n == 0) {
            printf("\n금액 : %d원입니다. 구매하시겠습니까? 구매는 1번 취소는 2번을 입력해 주세요.\n", find->gm);
            scanf("%d", &k);
            if (k == 1) {

                printf("\n몇장 구매 하시겠습니까?\n");
                scanf("%d", &lj);

                if (find->gu > find->c) {
                    printf("\n잘못 입력하였습니다.\n");
                    return;
                }

                printf("\n혹시 할인권이 있으십니까? 있으면 1번 없으면 2번을 입력해 주세요.\n");
                scanf("%d", &hh);
                if (hh == 1) {
                    ha(find, lj);
                    return;
                }

                if (hh == 2) {
                    if (find->c >= 0 || find->gu <= find->k) {
                        for (i = 0; i < lj; i++) {
                            --find->c;
                            ++find->gu;
                        }
                        printf("\n티켓 구매가 완료되었습니다.\n");
                        find->oi = find->gm * find->gu;
                        printf("\n%s 영화의 티켓을 %d장 발급해드리겠습니다.\n", find->dd, find->gu);
                        printf("\n영화관은 %d관입니다\n", find->ga);
                        printf("\n감사합니다.\n");
                        return;
                    }
                }
                else { // 할인권 번호 잘못 입력 시 
                    printf("\n잘못 입력하였습니다.\n");
                    return;
                }
            }

            if (k == 2)
            {
                printf("\n취소되었습니다.\n");
                return;
            }
            else { // 영화 구매할지 판매할지 잘못 입력했을 경우 
                printf("\n잘못 입력하였습니다.\n");
                return;
            }
        }
        find = find->next;
    }

    if (n != 0) {
        printf("\n데이터가 없습니다.\n");
        return;
    }
}

pa(MOVIE* head) {  //티켓 판매 함수

    int n = 0; // 문자열 비교 
    int k = 0; // 구매할지 말지 변수 
    int i; // 반복문을 위한 변수 
    char as[80];
    int hh = 0; // 할인권 여부 
    int pa = 0; // 판매할 티켓 변수 
    MOVIE* find = head->next;
    int cs = 0;  // 영화 티켓 여부 확인 변수 

    system("cls");

    if (find == NULL) {
        printf("\n현재 상영하는 영화가 없습니다.\n");
        return;
    }

    while (find != NULL) {

        if (find->gu > 0) {
            printf("\n\t현재 가진 영화 : %s\n\t\t 금액 : %d\n\t\t 티켓 수 : %d\n\n", find->dd, find->gm, find->gu);
            cs += find->gu;
        }
        find = find->next;
    }

    if (cs == 0) {
        printf("\n티켓이 없습니다.\n");
        return;
    }

    find = head->next;
    printf("판매할 영화를 입력해 주세요.\n");
    scanf("%s", as);

    while (find != NULL) {
        n = strcmp(as, find->dd);

        if (n == 0) {
            printf("\n영화명 : %s\n 금액 : %d원입니다 판매하시겠습니까? 판매는 1번 취소는 2번을 입력해 주세요.\n", find->dd, find->gm);
            scanf("%d", &k);

            if (k == 1) {
                printf("\n몇 장 판매하시겠습니까?\n");
                scanf("%d", &pa);

                if (find->gu < pa) {
                    printf("\n잘못 입력하였습니다.\n");
                    return;
                }

                printf("\n혹시 할인권으로 영화를 구매하셨었나요? 그렇다면 1번 아니면 2번을 입력해 주세요.\n");
                scanf("%d", &hh);
                if (hh == 1) {
                    hs(find, pa);
                    return;
                }

                if (hh == 2) {
                    if (find->c >= 0 || find->gu <= find->k || find->gu >= pa) {
                        for (i = 0; i < pa; i++) {
                            ++find->c;
                            --find->gu;
                        }
                        printf("\n티켓 판매가 완료되었습니다.\n");
                        find->oi = find->gm * find->gu;
                        printf("\n현재 가지고 계신 %s의 영화 티켓은 %d장입니다.\n", find->dd, find->gu);
                        printf("\n감사합니다.\n");
                        return;
                    }
                }
                else {
                    printf("\n잘못 입력하였습니다.\n"); // 할인권 잘못 입력 시 
                    return;
                }
            }

            if (k == 2) // 티켓 판매 취소 할 경우 
            {
                printf("\n취소되었습니다.\n");
                return;
            }
            else { //구매 판매 잘못 입력시 
                printf("\n잘못 입력하였습니다.\n");
                return;
            }
        }
        find = find->next;
    }
    if (n != 0) {
        printf("\n데이터가 없습니다.\n");
    }
}

drk(MOVIE* head) { // 영수증 출력 할 함수 

    MOVIE* yu = (MOVIE*)malloc(sizeof(MOVIE));
    yu = head->next;
    int chgm = 0;     // 영화 총 금액 변수 
    int cs = 0;      // 영화 티켓 수 변수 
    system("cls");

    if (yu == NULL) {
        printf("\n영화정보가 없습니다.\n");
        return;
    }

    while (yu != NULL) {
        if (yu->gu > 0) {
            printf("\n현재 가지고 계신 %s의 영화티켓은 %d장이며 %d관입니다.\n", yu->dd, yu->gu, yu->ga);
            chgm += yu->oi;
            cs += yu->gu;
        }
        yu = yu->next;
    }

    if (cs == 0) {
        printf("\n구입한 영화가 없습니다.\n");
        return;
    }

    printf("\n총 영화의 금액은 %d원입니다.\n", chgm);
    return;
}

yq(MOVIE* head) {  // 현재 상영영화 파일 출력함수

    MOVIE* kk = (MOVIE*)malloc(sizeof(MOVIE));
    kk = head->next;
    int n = 1;  // 번째 영화

    FILE* fl;

    fl = fopen("리스트.txt", "w");

    if (kk == NULL) {
        printf("\n현재 상영하는 영화가 없습니다.\n");
        return;
    }

    while (kk != NULL) {
        fprintf(fl, "\n\t★%d번째 영화★\n\t이름 : %s\n\t금액 : %d\n\t현재 좌석 수 : %d\n\t영화 시간 : %s\n\n", n, kk->dd, kk->gm, kk->c, kk->si);
        kk = kk->next;
        n++;
    }
    printf("\n리스트.txt로 파일 출력하였습니다.\n");
    fclose(fl);
    free(kk);
    return;
}

ya(MOVIE* head) {  // 영화 영수증 파일 출력 

    MOVIE* bb = (MOVIE*)malloc(sizeof(MOVIE));
    bb = head->next;
    int chgm = 0;
    int cs = 0;

    FILE* fp;

    if (bb == NULL) {
        printf("\n현재 상영하는 영화가 없습니다.\n");
        return;
    }

    fp = fopen("영수증.txt", "w");

    while (bb != NULL) {
        if (bb->gu > 0) {
            fprintf(fp, "\n현재 가지고 계신 %s의 영화 티켓은 %d장이며 %d관입니다.\n", bb->dd, bb->gu, bb->ga);
            chgm += bb->oi;
            cs += bb->gu;
        }
        bb = bb->next;
    }
    if (cs == 0) {
        printf("\n구입한 영화가 없습니다.\n");
        return;
    }

    fprintf(fp, "\n총 영화의 금액은 %d원입니다.\n", chgm);
    printf("\n영수증.txt로 파일 출력하였습니다.\n");
    fclose(fp);
    free(bb);
    return;
}

ha(MOVIE* find, int lm) {  // 할인권 사용 구매함수 

    int i;   // 반복 변수 
    int hh;  // 할인 쿠폰 변수 

    printf("\n1. 무료쿠폰 100%\n 2. 할인쿠폰 70%\n 3. 할인쿠폰 50%\n 4. 할인쿠폰 30%\n 5. 할인쿠폰 10%\n");
    scanf("%d", &hh);

    if (find->c >= 0 || find->gu <= find->k) {
        for (i = 0; i < lm; i++) {
            --find->c;
            ++find->gu;
        }
    }

    if (hh == 1) {

        printf("\n티켓 구매가 완료되었습니다.\n");
        find->oi = (find->gm * find->gu) * 0;
        printf("\n%s 영화의 티켓을 %d장 발급해드리겠습니다.\n", find->dd, find->gu);
        printf("\n영화관은 %d관입니다.\n", find->ga);
        printf("\n감사합니다.\n");
        return;
    }

    if (hh == 2) {

        printf("\n티켓 구매가 완료되었습니다.\n");
        find->oi = (find->gm * find->gu) * 0.3;
        printf("\n%s 영화의 티켓을 %d장 발급해드리겠습니다.\n", find->dd, find->gu);
        printf("\n영화관은 %d관입니다.\n", find->ga);
        printf("\n감사합니다.\n");
        return;
    }


    if (hh == 3) {

        printf("\n티켓 구매가 완료되었습니다.\n");
        find->oi = (find->gm * find->gu) / 2;
        printf("\n%s 영화의 티켓을 %d장 발급해드리겠습니다.\n", find->dd, find->gu);
        printf("\n영화관은 %d관입니다.\n", find->ga);
        printf("\n감사합니다.\n");
        return;
    }

    if (hh == 4) {

        printf("\n티켓 구매가 완료되었습니다.\n");
        find->oi = (find->gm * find->gu) * 0.7;
        printf("\n%s 영화의 티켓을 %d장 발급해드리겠습니다.\n", find->dd, find->gu);
        printf("\n영화관은 %d관입니다.\n", find->ga);
        printf("\n감사합니다.\n");
        return;
    }

    if (hh == 5) {

        printf("\n티켓 구매가 완료되었습니다.\n");
        find->oi = (find->gm * find->gu) * 0.9;
        printf("\n%s 영화의 티켓을 %d장 발급해드리겠습니다.\n", find->dd, find->gu);
        printf("\n영화관은 %d관입니다.\n", find->ga);
        printf("\n감사합니다.\n");
        return;
    }

    else {
        printf("\n잘못 입력하였습니다.\n");
        return;
    }
}

hs(MOVIE* find, int ll) {       //할인권 사용 판매 함수 

    int i;
    int hf;  // 할인 쿠폰 변수 

    printf("\n1. 무료쿠폰 100%\n 2. 할인쿠폰 70%\n 3. 할인쿠폰 50%\n 4. 할인쿠폰 30%\n 5. 할인쿠폰 10%\n");
    printf("\n어떤 쿠폰을 사용하셨었나요?\n");
    scanf("%d", &hf);


    if (find->c >= 0 || find->gu <= find->k || find->gu >= ll) {
        for (i = 0; i < ll; i++) {
            ++find->c;
            --find->gu;
        }
    }

    if (hf == 1) {

        printf("\n티켓 판매가 완료되었습니다.\n");
        find->oi = find->oi - (find->gm * ll * 0);
        printf("\n현재 가지고 계신 %s의 영화 티켓은 %d장입니다.\n", find->dd, find->gu);
        printf("\n감사합니다.\n");
        return;
    }

    if (hf == 2) {

        printf("\n티켓 판매가 완료되었습니다.\n");
        find->oi = find->oi - (find->gm * ll * 0.3);
        printf("\n현재 가지고 계신 %s의 영화 티켓은 %d장입니다.\n", find->dd, find->gu);
        printf("\n감사합니다.\n");
        return;
    }

    if (hf == 3) {

        printf("\n티켓 판매가 완료되었습니다.\n");
        find->oi -= ((find->gm * ll) / 2);
        printf("\n현재 가지고 계신 %s의 영화 티켓은 %d장입니다.\n", find->dd, find->gu);
        printf("\n감사합니다.\n");
        return;
    }

    if (hf == 4) {

        printf("\n티켓 판매가 완료되었습니다.\n");
        find->oi = find->oi - (find->gm * ll * 0.7);
        printf("\n현재 가지고 계신 %s의 영화 티켓은 %d장입니다.\n", find->dd, find->gu);
        printf("\n감사합니다.\n");
        return;
    }

    if (hf == 5) {

        printf("\n티켓 판매가 완료되었습니다.\n");
        find->oi = find->oi - (find->gm * ll * 0.9);
        printf("\n현재 가지고 계신 %s의 영화 티켓은 %d장입니다.\n", find->dd, find->gu);
        printf("\n감사합니다.\n");
        return;
    }
}