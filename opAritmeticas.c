#include<stdio.h>
void main(){
    float i, n;
    int op;

    do{
        printf("********* MENU *********\n");
        printf("*1 - Soma              *\n");
        printf("*2 - Subtracao         *\n");
        printf("*3 - Multiplicacao     *\n");
        printf("*4 - Divisao           *\n");
        printf("*5 - Sair              *\n");
        printf("Digite a sua escolha:");
        scanf("%d",&op);

        switch (op)
        {
            case 1:
                printf("Escolha o numero:");
                scanf("%f",&n);
                for(i=1;i<=9;i++)
                {
                    printf("%.0f+%.0f = %.0f\n", n, i, n+i);
                }
                break;

            case 2:
                printf("Escolha o numero:");
                scanf("%f",&n);
                for(i=1;i<=9;i++)
                {
                    printf("%.0f-%.0f = %.0f\n", n, i, n-i);
                }
                break;

            case 3:
                printf("Escolha o numero:");
                scanf("%f",&n);
                for(i=1;i<=9;i++)
                {
                    printf("%.0f*%.0f = %.0f\n", n, i, n*i);
                }
                break;

            case 4:
                printf("Escolha o numero:");
                scanf("%f",&n);
                for(i=1;i<=9;i++)
                {
                    printf("%.0f/%.0f = %.2f\n", n, i, n/i);
                }
                break;
        }

    }while (op != 5);
    
}
