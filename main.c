#include <stdio.h>
#include<string.h>
#include <ctype.h>

int primecheck (int n)
{
    if (n==2) return 1;
    if (n % 2 == 0) return 0;
    for (int i=3; i*i<=n; i+=2)
        if (n % i == 0) return 0;
    return 1;
}

void print_primes(int n)
{
    int i=2;
    while (i<=n)
    {
        if (primecheck(i))
            printf("%d ", i);
        if (i==2) i++;
        else i+=2;
    }
    printf("\n");
}

void read_array(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%2d : ", i);
        scanf("%5d", &arr[i]);
    }
}

void print_array(int arr[], int n)
{
    printf("Tomb : \n");
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int palindrome (char string[])
{
    char *p_string = string;
    unsigned long long i = 0, j = 0, str_len = strlen(p_string);
    char *left;
    char *right;

    left = (string + i);
    right= (string + str_len - 1 - j);

    char left_char = *left; // ONLY FOR DEBUG
    char right_char = *right; // ONLY FOR DEBUG

    while ( ((i <= str_len/2) || (j<= str_len/2)) )
    {
        while (*(left + i) - 'A' < 0)
            i++;

        while (*(right - j) - 'A' < 0)
            j++;

        if ( tolower(*(left + i)) == tolower(*(right - j)) )
        {
            i++;
            j++;
        }
        else
            return 0;
    }

    return 1;
}

int main()
{
    //1. Készíts függvényt, ami a múlt órai prímszámos függvény felhasználásával kiír prímszámokat, a paraméteréül kapott számig!
    //int limit;
    //printf("Felso hatar primszar ellenorzesre: ");
    //scanf("%d", &limit);
    //print_primes(limit);

    //2. Készíts függvényeket, amelyek beolvasnak, illetve kiírnak egy N elemű, egész számokat tartalmazó tömböt!
    int n=5;
    //printf("Tomb merete : ");
    //scanf("%d", &n);
    int arr[64];
    //read_array(arr,n);
    //print_array(arr,n);

    //3. Készíts programot, ami egy tömbbe bekér 5 számot, majd mutató segítségével visszafelé kiírja azokat!
    int *p_arr = arr;
    for (int i=n; i>0; i--)
        printf("%d ", *(p_arr+i-1));

    //4. Készíts függvényt, ami a paraméterül kapott karaktertömbben lévő szövegről mutató segítsével eldönti és eredményül visszaadja, hogy az megegyezik-e a visszafelé olvasott változatával! (Palindrom)
    char string[255] = "Go hang a salami I'm a lasagna hog";
    printf("Palindrom: %s \n", (palindrome(string))?"IGEN":"NEM");

    return 0;
}
