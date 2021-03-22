#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1010;
struct Record{
    char name[25];
    int month, dd, hh, mm;
    bool status;
}rec[maxn], temp;
int toll[25];

bool cmp(Record a, Record b){
    int s = strcmp(a.name, b.name); //用户按字母序排列
    if(s != 0)  return s < 0;
    else if(a.month != b.month) return a.month < b.month;   //按月份排列
    else if(a.dd != b.dd)   return a.dd < b.dd; //按天数排列
    else if(a.hh != b.hh)   return a.hh < b.hh; //按小时
    else return a.mm < b.mm;    //按分钟
}
void get_ans(int on, int off, int &time, int &money){
    temp = rec[on];
    while(temp.dd < rec[off].dd || temp.hh < rec[off].hh || temp.mm < rec[off].mm){
        time++; //这次通话总时间加1min
        money+= toll[temp.hh];  //金额加一分钟的费用
        temp.mm++;
        if(temp.mm >= 60){
            temp.mm = 0;
            temp.hh++;
        }
        if(temp.hh >= 24){
            temp.hh = 0;
            temp.dd++;
        }
    }
}
int main(){
    for(int i = 0; i < 24; i++){
        scanf("%d", &toll[i]);
    }
    int n;
    scanf("%d", &n);
    char line[10];  //临时存放on-line和off-line
    for(int i = 0; i < n; i++){
        scanf("%s", rec[i].name);
        scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].dd, &rec[i].hh, &rec[i].mm);
        scanf("%s", line);
        if(strcmp(line, "on-line") == 0){
            rec[i].status = true;
        }else{
            rec[i].status = false;
        }
    }
    sort(rec, rec + n, cmp);
    int on = 0, off, next;  //on 和 off 是配对的两条记录
    while(on < n){  //每次循环处理单个用户的所有记录
        int needPrint  = 0;
        next = on;  //从当前位置寻找下一个用户
        while(next < n && strcmp(rec[next].name, rec[on].name) == 0){
            if(needPrint == 0 && rec[next].status){
                needPrint = 1;  //找到on， needPrint置为1
            }else if(needPrint == 1 && !rec[next].status){
                needPrint = 2;  //找到off, needPrint置为2
            }
            next++; //next自增直到找到下一个用户
        }
        if(needPrint < 2){  //没有找到配对的on-off
            on = next;
            continue;
        }
        int AllMoney = 0;   //总共花费的钱
        printf("%s %02d\n", rec[on].name, rec[on].month);
        while(on < next){   //寻找该用户的所有配对
            while(on < next - 1 && !(rec[on].status && !rec[on + 1].status)){
                on++;   //直到找到连续的online 和 offline
            }
            off = on + 1;
            if(off == next){    //条件满足时已经输出完毕所有的配对
                on = next;
                break;
            }
            printf("%02d:%02d:%02d ", rec[on].dd, rec[on].hh, rec[on].mm);
            printf("%02d:%02d:%02d ", rec[off].dd, rec[off].hh, rec[off].mm);
            int time = 0, money = 0;
            get_ans(on, off, time, money);
            AllMoney += money;
            printf("%d $%.2f\n", time, money / 100.0);
            on = off + 1;   //完成一个配对，从off+1开始找下一对
        }
        printf("Total amount: $%.2f\n", AllMoney / 100.0);
    }
    return 0;
}
