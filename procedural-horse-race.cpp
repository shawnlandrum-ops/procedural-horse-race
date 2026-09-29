#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>



const int TRACKLENGTH=15;
const int HORSES=5;

void turn(int progress[], std::string track[], char horses[]){
    char anyKey[5];
    printf("enter any key to coin flip\n");
    scanf("%s",anyKey);

    srand(time(NULL));
    char coins[HORSES];
    coins[0]=rand()%2;
    coins[1]=rand()%2;
    coins[2]=rand()%2;
    coins[3]=rand()%2;
    coins[4]=rand()%2;

    for (int i=0;i<HORSES;i++){
        
        printf("%d\n",coins[i]);
        if (coins[i]==1){
            progress[i]++;
            track[i][progress[i]]=horses[i];
            track[i][progress[i]-1]='.';
        }
    }

}

void isWinner(int progress[], char horses[], bool &gameActive){
    for (int i=0;i<HORSES;i++){
        if (progress[i] == TRACKLENGTH - 1){
            gameActive=false;
            printf("horse %c won!\n", horses[i]);
        }
    }
}

void printTrack(std::string track){
    std::cout<< track << std::endl;
}

int main(){

    char horses[HORSES]={'0','1','2','3','4'};
    std::string track[HORSES];
    track[0]="..............";
    track[1]="..............";
    track[2]="..............";
    track[3]="..............";
    track[4]="..............";
    int progress[HORSES]={0,0,0,0,0};
    bool gameActive=true;
    
    for (int i=0;i<HORSES;i++){
        track[i][progress[i]]=horses[i];
    }

    while(gameActive){
        
        for(int i=0;i<HORSES;i++){
            printTrack(track[i]);
        }
        
        turn(progress, track, horses);
        isWinner(progress, horses, gameActive);
        
        
        
        //std::cout<< track << std::endl;
        //printTrack(track);
        


    }
}
