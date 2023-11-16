#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int player = 0; //player ����
    int com = 0; //computer ����
    int round = 0; //�� ������� ������ �Ǿ����� �˱����� round ����
    int result[3] = {0,}; /*
    save the game result (������ ��� ���� - �÷��̾� ����)
    
    result[0] : draw
    result[1] : player win
    result[2] : player lose */

    srand(time(NULL)); /* ���� �� �ʱ�ȭ(initialisation)
    -> ���� ������ �ݺ��Ǵ� ���� �����ϱ� ���� */

    printf("Let's begin 'rock-paper-scissors game'\n");

    while (player != -1) //player�� -1�� �Է����� ��� ���� ���� 
    {
        com = rand() %3 + 1; //���� 1,2,3 �� �ϳ� ����

        printf("input one of Scissors(1), Rock(2), Paper(3) \n => ");
        scanf("%d", &player);

        if(player == -1) {
            //player�� -1�� �Է����� ��� ���� ���� 
            printf("End games \n");
        }

        else if (player>0 && player<4) {

            //player�� 1,2,3 �� �ϳ��� �Է����� ���
            round++; //���� �� ����

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