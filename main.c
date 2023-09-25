#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clean(){
    system("cls");
}


float calcolapi(int n, int cifre, int output_flag){
    if(output_flag != 0 && output_flag != 1 && output_flag != 2){
        printf("Il flag deve essere 0 o 1\n");
    }
    float pi;
    float sum;
    float flag = 1;

    for(int i = 1; i < n; i+=2){
        sum = sum + 1/(i*flag);
        flag *= -1;
    }
    pi = sum*4;
    if(output_flag == 0){
        return pi;
    }
    if(output_flag == 1){
        printf("Pi e' %.*f", cifre, pi);
        return 0;
    }
    if(output_flag == 2){
        FILE *filepi = fopen("pigreco.txt", "w");
        fprintf(filepi, "Pi e' %.*f", cifre, pi);
        fclose(filepi);
        return 0;
    }

}

int main(int argc, char *argv[]){
    clean();
    if(argc >= 3){
        calcolapi(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    }else if(strcmp(argv[1], "--help") == 0){
        printf("\n==========================================================================================\n\n");
        printf("Il programma usa la somma infinita a segni alterni con denominatore dispari, di Leibniz, ovvero 1 - 1/3 + 1/5 - 1/7 +...\n");
        printf("Per usarlo immetti i numeri nell'ordine <numero di iterazioni> <cifre decimali> <flag>");
        printf("\n\n==========================================================================================\n");
    }else{
        printf("Immetti <numero di iterazioni> <cifre decimali> <flag>\n");
    }
    return 0;
}
