#include <stdio.h>
// 구조체 
struct Student {
    char name[50]; 
    double math;    
    double eng;     
    double average; 
};
int main() { 
    struct Student students[3];
    // 파일에서 성적 읽어오기 
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }
    int i;
    for (i = 0; i < 3; i++) {
        fscanf(file, "%s %lf %lf", students[i].name, &students[i].math, &students[i].eng);
        students[i].average = (students[i].math + students[i].eng) / 2.0; // 개인별 평균 계산
    }
    fclose(file);
    // 개인별, 과목별 평균
    double mathAvg = 0.0;
    double engAvg = 0.0;
    for (i = 0; i < 3; i++) {
        mathAvg += students[i].math;
        engAvg += students[i].eng;
    }
    mathAvg /= 3;
    engAvg /= 3;
    printf("수학 평균: %.2lf\n", mathAvg);
    printf("영어 평균: %.2lf\n", engAvg);
    
    for (i = 0; i < 3; i++) {
        printf("%s의 개인별 평균: %.2lf\n", students[i].name, students[i].average);
    }
    // 평균 결과를 파일에 저장
    file = fopen("averages.txt", "w");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }
    fprintf(file, "수학 평균: %.2lf\n", mathAvg);
    fprintf(file, "영어 평균: %.2lf\n", engAvg);
    fclose(file);
    return 0;
}

