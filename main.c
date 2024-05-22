#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

unsigned int suma(unsigned int n) {
    static int sumaStat = 0;
    if (n<2) {
        sumaStat += 1;
        return 1;
    }
    sumaStat += suma(n-1);
    return sumaStat;
}

int stale(int const *a, int const *b) {
    return *a + *b;
}

double * allocate(n) {
    return malloc(n*sizeof(double));
}

double pass(double (*fun)(int x), int y) {
    return fun(y);
}
double testowa(int x) {
    return x*x;
}

int doskonala(int x) {
    int suma = 0;
    for(int i = 1; i<=x/2; i++) {
        if(x%i==0) {
            suma += i;
        }
    }
    if(suma == x) {
        return suma;
    }
    return -1;
}

int doskonala_lista() {
    int z = 100000;
    for(int i = 1; i<z; i++) {
        if(doskonala(i) == -1) {
            continue;
        }
        printf("%d\n", doskonala(i));
    }
}

void wypisz(unsigned int n, int* tab)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\n", tab[i]);
    }
}
void zeruj(unsigned int n, int* tab)
{
    for(int i = 0; i<=n; i++)
    {
        tab[i] = 0;
    }
}

int pierwsza(unsigned int n)
{
    int pom,i,j;
    bool sito[n];
    for(i=0;i<n;i++)
    {
        sito[i] = true;
    }
    for(i=2;i<n;i++)
    {
        if(sito[i])
        {
            pom =i;
            for(j=2*i;j<n;j=j+i)
            {
                sito[j]=false;
            }
        }
    }
    return pom;
}

int * wskaznik_listy(unsigned int n)
{
    int* lista = malloc(n* sizeof(int));
    for(int i=0;i<n;i++)
    {
        lista[i] = i;
    }
    return &lista[1];
}

void odwrocenie_tablicy(unsigned int n, int* tab)
{
    int zamiany = n;
    if(n%2!=0)
    {
        zamiany = (n-1)/2;
    }
    for(int i = 0; i<=zamiany-1; i++)
    {
        int pomocnicza = tab[i];
        tab[i] = tab[n-1-i];
        tab[n-1-i] = pomocnicza;
    }
    for(int i = 0; i<n; i++)
    {
        printf("%d", tab[i]);
    }
}

char * wytnij(char *napis, int n, int m)
{
    int dlugosc = 0;
    for(int i = 0; napis[i] != 0; i++)
    {
        dlugosc++;
    }

    char *wyciety = malloc(sizeof(char) * dlugosc);
    int indexDlaWyciety = 0;
    for(int j = 0; j<dlugosc; j++)
    {
        if(j >= n && j <= m)
        {
            continue;
        }
        wyciety[indexDlaWyciety] = napis[j];
        indexDlaWyciety++;
    }
    return wyciety;
}

char * wytnijNapis2(char *napis, char *napis2)
{
    int dlugosc = 0;
    for(int i = 0; napis[i] != 0; i++)
    {
        dlugosc++;
    }

    char *wyciety = malloc(sizeof(char) * dlugosc);
    int indexDlaWyciety = 0;
    int pomin;
    int powtorzenia = 0;
    for(int i = 0; napis[i] != 0; i++)
    {
        pomin = 0;
        for(int j = 0; napis2[j] != 0; j++)
        {
            if(napis[i] == napis2[j])
            {
                pomin = 1;
            }
        }
        if(pomin == 1)
        {
            powtorzenia++;
            continue;
        }
        wyciety[indexDlaWyciety] = napis[i];
        indexDlaWyciety++;
    }
    wyciety[dlugosc-powtorzenia]=0;
    return wyciety;
}

void szyfr(char *napis)
{
    for(int i = 0; napis[i] != 0; i++)
    {
        napis[i] = napis[i]+3;
    }
}

int** macierzAlokuj(unsigned int n, unsigned int m)
{
    int **t=malloc(n*sizeof(int*));
    int i;
    for(i=0;i<n;i++)
    {
        t[i] = malloc(m*sizeof(int));
    }
    return t;
}

struct element
{
    int i;
    struct element *next;
};

struct element *utworz()
{
    return NULL;
};

void wyczysc(struct element *Lista)
{
    struct element *wsk = Lista;
    while(Lista!= NULL)
    {
        Lista = Lista->next;
        free(wsk);
        wsk=Lista;
    }
}

struct element * dodajnapoczatek(struct element* Lista, int a)
{
    struct element *wsk = malloc(sizeof(struct element));
    wsk->i=a;
    wsk->next=Lista;
    return wsk;
};

unsigned int ile(struct element* Lista)
{
    unsigned int suma = 0;
    while(Lista!=NULL)
    {
        suma++;
        Lista = Lista->next;
    }

    return suma;
}

int main()
{
    struct element *Lista = malloc(sizeof(struct element));
    Lista->i = 1;
    Lista->next = malloc(sizeof(struct element));
    Lista->next->i = 2;
    Lista->next->next = malloc(sizeof(struct element));
    Lista->next->next->i = 5;
    Lista->next->next->next = malloc(sizeof(struct element));
    Lista->next->next->next->i = 7;
    Lista->next->next->next->next = malloc(sizeof(struct element));
    Lista->next->next->next->next->i = 10;
    Lista->next->next->next->next->next = malloc(sizeof(struct element));
    Lista->next->next->next->next->next->i = 11;
    Lista->next->next->next->next->next->next = NULL;
    printf("%d", ile(Lista));
    //printf("%d", Lista->next->i);

    /*
    int liczby[12] = {1, 2 , 3};
    printf("%d", 0[liczby]);
    //odwrocenie_tablicy(3, tablica);
    char napis[] = "matma";
    char matma[] = "matma";
    szyfr(matma);
    printf(matma);
    */
    //char napis2[] = "io";
    //printf(wytnijNapis2(napis, napis2));
    //printf(wytnij(napis, 5, 8));

    /*
    int *p = wskaznik_listy(4);
    printf("%d\n", *p);
    *p = 5;
    printf("%d", *p);
    printf("Hello world!\n");
    int tab[4];
    for(int i = 0; i<=4; i++)
    {
        tab[i] = i+1;
    }
    zeruj(4, tab);
    wypisz(4, tab);
    printf("%d", pierwsza(29));

    doskonala_lista();
    int licz = 43;
    int* ptr = &licz;
    printf("%p\n", ptr, "\n");
    printf("dziwne znaki \&", "\n");
    int z;
    scanf("%d", &z, "\n");
    printf("%d", z, "\n");
    float dwa;
    scanf("%f", &dwa, "\n");
    printf("%.3f", dwa, "\n");
    printf("%e", dwa, "\n");
    */
    /*
    int one;
    int two;
    int three;
    scanf("%d\n%d\n%d", &one, &two, &three);
    printf("%d\n%d\n%d\n", one, two, three);
    printf("%f", (one+two+three)/3.0);
    if(one > two) {
        printf("\nmax(%d, %d) = %d", one, two, one);
    }
    else {
        printf("max(%d, %d) = %d", one, two, two);
    }
    */
    /*
    float a;
    float b;
    float c;
    printf("podaj a, b, c\n");
    scanf("%f%f%f", &a, &b, &c);
    float delta =b*b -4*a*c;
    if(delta > 0) {
        float x1 = (-b+sqrt(delta))/2*a;
        float x2 = (-b-sqrt(delta))/2*a;
        printf("x1: %f, x2: %f", x1, x2);
        return 0;
    }
    else if(delta == 0) {
        float x = -b/2*a;
        printf("x = %f", x);
        return 0;
    }
    printf("delta ujemna - brak rozwiazan");
    */

    /*
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 1; i < m; i++) {
        if(i*n > m) {
            break;
        }
        printf("%d\n", n*i);
    }
    */

    /*
    int n = 37;
    int dzielniki[90] = {};
    int pierw = 1;
    for(int i = 2; i*i <= n; i++){
        pierw = i;
    }
    printf("%d\n", pierw);
    for(int i=0; i<n; i++) {
        dzielniki[i] = i;
        printf("%d\n", dzielniki[i]);
    }
    char napis[] = "d";
    printf("%", napis[0]);
    */
    /*
    int n;
    printf("%s", "podaj calkowita liczbe\n");
    scanf("%d", &n);
    printf("%d", suma(n));
    */
    /*
    int c =1;
    int d = 2;
    int const *a = &c;
    int const *b = &d;
    printf("%d\n", stale(a, b));
    printf("%d %d", *a, *b);

    double* b = allocate();
    printf("adres: %p\n", b);
    *b = 5.5;
    printf("wartosc: %.1f\n", *b);
    */
    /*
    printf("%0.f", pass(testowa, 5));
    */
    return 0;
}
