#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///DISCLAIMER: as operações de positivos estão funcionando normalmente, mas as com negativos estão com problemas nos 4 primeiros bits.
///exemplo, 2 x -3 é (1111)1010, mas por algum motivo tá dando (0001)1010

int shift(int prod[])
{
    int i;
    for(i = 8; i < 0; i--)
    {
        prod[i] = prod[i-1];
    }
}

add(int prod[], int mcand[])
{
    int i;
    bool vai_1;
    vai_1 = false;
    for(i = 7; i >= 0; i--)
    {
        if(prod[i] == 1 && mcand[i] == 1)
        {
            if(vai_1 == true)
            {
                prod[i] = 1;
                vai_1 = true;
            }
            else
            {
                prod[i] = 0;
                vai_1 = false;
            }
        }

        else if(prod[i] == 0 && mcand[i] == 0)
        {
            if(vai_1 == true)
            {
                prod[i] = 1;
                vai_1 = false;
            }
            else
            {
                prod[i] = 0;
                vai_1 = false;
            }
        }
        else if(prod[i] == 1 || prod[i] == 1)
        {
            if(vai_1 == true)
            {
                prod[i] = 0;
                vai_1 = false;
            }
            else
            {
                prod[i] = 1;
                vai_1 = false;
            }
        }
    }
}

int achar_neg(int multiplicando[])
{
    int i;
    ///invertendo os valores;
    i = 0;
    while(i < 4)
    {
        if(multiplicando[i] == 0)
        {
            multiplicando[i] = 1;
            i++;
        }
        else
        {
            multiplicando[i] = 0;
            i++;
        }
    }
    ///somando o 1;
    i = 3;
    while(i >= 0)
    {
        if(multiplicando[i] == 1)
        {
            multiplicando[i] = 0;
            i--;
        }
        else
        {
            multiplicando[i] = 1;
            i--;
        }
    }
}

int main()
{
    int i, produto, mcand;
    int multiplicando[4];
    int neg_multi[4];
    int prod[9];
    prod[8] = 0;

    ///pegando multiplicador e multiplicando
    for(i = 0; i <= 3; i++)
    {
        prod[i] = 0;
    }
    printf("Digite o Multiplicando (parte de cima): \n");

    for(i = 0; i <= 3; i++)
    {
        scanf("%d", &mcand);
        multiplicando[i] = mcand;
        neg_multi[i] = mcand;
    }
    printf("Digite o Multiplicador (parte de baixo): \n");

    for(i = 4; i <= 7; i++)
    {
        scanf("%d", &produto);
        prod[i] = produto;
    }

    achar_neg(neg_multi);

    for(i = 0; i < 4; i++)
    {
        if(prod[8] < prod[7])
        {
            add(prod, neg_multi);
        }
        else if(prod[8] > prod[7])
        {
            add(prod, multiplicando);
        }
        shift(prod);
    }

    for(i = 0; i < 9; i++)
    {
        printf("%d", prod[i]);
    }



    return 0;
}
