#include <stdio.h>
#include <stdlib.h>

// Geld wird ausgegeben
void changeOutput(double change[8], int count[8], double showMoney)
{
    printf("\tEingeworfen: %.2lf EURO\n", showMoney);
    printf("\tRueckgeld: \n");
    for(int j = 0; j < 8; j++)
    {
        change[j] /= 100;
        printf("\t%i --> %.2lf EURO\n", count[j], change[j]);
    }
}

// Rueckgeld wird berechnet
void returnMoney(double money, double change[8])
{
    int count[] = {0,0,0,0,0,0,0,0};
    double showMoney = money;
    int i = 0;
    showMoney /= 100;k
    
    while(money > 0)
    {
        if(money >= change[i])
        {
                money -= change[i];
                count[i]++;
        }
        else
        {
            i++;
        }
    }
    changeOutput(change, count, showMoney);
}

// Main menu
double startMenu()
{
    double money;
    while(1)
    {
        printf("Geben Sie den Geldbetrag ein, den Sie wechseln moechten: ");
        if(scanf("%lf", &money) != 1 || getchar() != '\n')
        {
            while(getchar() != '\n');
            printf("Ungueltige Eingabe!\n");
            system("pause");
            system("cls");
        }
        else
        {
            break;
        }
    }
    money *= 100;
    system("cls");
    return money;
}

int main()
{
    double change[] = {200,100,50,20,10,5,2,1};
    double money = startMenu();
    returnMoney(money, change);
	return 0;
}
