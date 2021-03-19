#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 100010;
struct Student{
    char id[10];    //准考证号为8位整数
    int virtueScore;
    int talentScore;
    int sumScore;
    int flag;   //考生类别
}stu[maxn];

bool cmp(Student a, Student b){
    if(a.sumScore != b.sumScore)
        return a.sumScore > b.sumScore;
    else if(a.virtueScore != b.virtueScore)
        return a.virtueScore > b.virtueScore;
    else
        return strcmp(a.id, b.id) < 0;
}

int main(){
    int N, L, H, num = 0; //N考生总数， L录取最低分数线， H优先录取分数线, num是及格人数
    scanf("%d%d%d", &N, &L, &H);
    for(int i = 0; i < N; i++){
        scanf("%s %d %d", stu[i].id, &stu[i].virtueScore, &stu[i].talentScore);
        stu[i].sumScore = stu[i].virtueScore + stu[i].talentScore;
    }
    for(int i = 0; i < N; i++){
        if(stu[i].virtueScore < L || stu[i].talentScore < L){
            stu[i].flag = 5;
        }else if(stu[i].virtueScore >= H && stu[i].talentScore >= H) {
            stu[i].flag = 1;
            num++;
        }else if(stu[i].virtueScore >= H && stu[i].talentScore < H && stu[i].talentScore >= L){
            stu[i].flag = 2;
            num++;
        }else if(stu[i].virtueScore >= L && stu[i].talentScore >= L &&
        stu[i].virtueScore < H && stu[i].talentScore < H &&
        stu[i].virtueScore >= stu[i].talentScore){
            stu[i].flag = 3;
            num++;
        }else{
            stu[i].flag = 4;
            num++;
        }
    }
    printf("%d\n", num);
    sort(stu, stu + num, cmp);
    for(int i = 0; i <  num ; i++){
        if(stu[i].flag == 1)
            printf("%s %d %d\n", stu[i].id, stu[i].virtueScore, stu[i].talentScore);
    }
    for(int i = 0; i <  num ; i++){
        if(stu[i].flag == 2)
            printf("%s %d %d\n", stu[i].id, stu[i].virtueScore, stu[i].talentScore);
    }
    for(int i = 0; i <  num ; i++){
        if(stu[i].flag == 3)
            printf("%s %d %d\n", stu[i].id, stu[i].virtueScore, stu[i].talentScore);
    }
    for(int i = 0; i <  num ; i++){
        if(stu[i].flag == 4)
            printf("%s %d %d\n", stu[i].id, stu[i].virtueScore, stu[i].talentScore);
    }
    return 0;
}
