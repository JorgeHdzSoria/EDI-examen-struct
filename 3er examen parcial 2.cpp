#include <stdio.h>
#define MAX 20

typedef struct empleado{
int Edad, Clave;
float Sueldo, Estatura;
char Nombre[10];
}EMP;

void pideEmpl(EMP e[MAX], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Nombre del empleado numero %d; ", i+1);
        scanf("%s", &e[i].Nombre);
        printf("Edad del empleado numero %d; ", i+1);
        scanf("%d", &e[i].Edad);
        printf("Estatura del empleado numero %d; ", i+1);
        scanf("%f", &e[i].Estatura);
        printf("Sueldo del empleado numero %d; ", i+1);
        scanf("%f", &e[i].Sueldo);
        printf("Clave del empleado numero %d; ", i+1);
        scanf("%d", &e[i].Clave);
    }
}

int emplAlto(EMP e[MAX], int n)
{
    EMP aux = e[0];
    int i, res = 0;;
    for(i = 0 ; i < n ; i++)
    {
        if(aux.Estatura < e[i].Estatura)
        {
        res = i + 1;
        }
    }
    return res;
}

void ordenaSueldo(EMP e[MAX], int n)
{
    EMP aux;
    int i, j;
    for(i = 0;i < n;i++)
    {
        for(j = i; j < n; j++)
        {
            if(e[i].Sueldo < e[j].Sueldo)
            {
            aux = e[i];
            e[i] = e[j];
            e[j] = aux;
            }
        }
    }
}

void imprimeArr(EMP e[MAX], int n)
{
    int i;
    printf("Clave\tNombre\tEst\tsueldo\n");
    for(i = 0; i < n; i++)
    {
    printf("%d \t%s \t%.2f \t%.2f \n", e[i].Clave, e[i].Nombre, e[i].Estatura, e[i].Sueldo);
    }
}

int main()
{
    EMP arr[MAX];
    int n, a;
    printf("cuantos empleados desea ingresar?");
    scanf("%d", &n);
    pideEmpl(arr, n);
    ordenaSueldo(arr, n);
    a = emplAlto(arr, n);
    printf("\nLa posicion en el arreglo ordenado del empleado con mayor estatura es: %d\n", a);
    imprimeArr(arr, n);
}
