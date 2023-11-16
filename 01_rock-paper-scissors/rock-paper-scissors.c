#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int player = 0; //player 변수
    int com = 0; //computer 변수
    int round = 0; //몇 라운드까지 진행이 되었는지 알기위한 round 변수
    int result[3] = {0,}; /*
    save the game result (게임의 결과 저장 - 플레이어 기준)
    
    result[0] : draw
    result[1] : player win
    result[2] : player lose */

    srand(time(NULL)); /* 랜덤 값 초기화(initialisation)
    -> 같은 랜덤이 반복되는 것을 방지하기 위함 */

    printf("Let's begin 'rock-paper-scissors game'\n");

    while (player != -1) //player가 -1을 입력했을 경우 게임 종료 
    {
        com = rand() %3 + 1; //랜덤 1,2,3 중 하나 추출

        printf("input one of Scissors(1), Rock(2), Paper(3) \n => ");
        scanf("%d", &player);

        if(player == -1) {
            //player가 -1을 입력했을 경우 게임 종료 
            printf("End games \n");
        }

        else if (player>0 && player<4) {

            //player가 1,2,3 중 하나를 입력했을 경우
            round++; //라운드 수 증가

            //Draw
            if(com == player) {
                printf("Draw\n\n");
                result[0]++; //result[0] : draw
            }

            //player win
            else if(((player==1)&&(com==3)) || ((player==2)&&(com==1)) || ((player==3)&&(com==2))) {
                printf("player win\n\n");
                result[1]++;
            }

            //player lose
            else if(((com==1)&&(player==3)) || ((com==2)&&(player==1)) || ((com==3)&&(player==2))) {
                printf("player lose\n\n");
                result[2]++;
            }

            else{
                printf("Exceptional Error\n");
            }
        }

        else {
            printf("False Input. Input other numbers(1~3 or -1)\n\n");
        }
    }
    
    system("cls"); //clear screen
    printf("------Game Result------\n");
    printf("%d Round, Draw: %d, win: %d, lose: %d\n", round, result[0], result[1], result[2]);

    return 0;
}