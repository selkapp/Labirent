#include<stdio.h>
#include <stdbool.h>
#include <time.h>


int N; //matrisin boyutu

bool labirentCozum(int lab[N][N], int x, int y, int yol[N][N]); //labirent cozumu
void yazdir(int yol[N][N]); // yolu yazdiran fonksiyon , yol[N][N]->cozum matrisi
bool kontrol(int lab[N][N], int x, int y); //koordinatlarin labirentin icinde olmasini kontol eder
bool cozum(int lab[N][N]);//labirentCozum() de cozum varsa cozumu yazdir() fonksiyonuna yollar.koordinat girisini burdan aldik.

int main()
{

    srand(time(NULL));
    int n,i,j;
    printf("\nLabirent boyutunu giriniz:");
devam:
    scanf("%d",&n);
    if(n>50)
    {
        printf("\nDaha kucuk bir boyut giriniz:");
        goto devam;
    }

    int lab[n][n];
    for(i=0; i<n; i++) for(j=0; j<n; j++) lab[i][j]=rand()%2;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf(" %d ",lab[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    N=n;


    /* deneme yapmak icin
     int lab[N][N]  =  {  {1, 0, 0, 0, 1},
          {1, 1, 0, 1, 1},
          {1, 1, 0, 0, 1},
          {0, 1, 1, 1, 0},
          {1, 0, 0, 1, 1}
      };
      int i,j;

      for(i=0; i<N; i++)
      {
          for(j=0; j<N; j++)
          {
              printf(" %d ",lab[i][j]);
          }
          printf("\n");
      }
      printf("\n"); */

    cozum(lab);
    return 0;
}


// x, y'nin N*N labirentinde gecerli olup olmadigini kontrol eden bir fonksiyon.
bool kontrol(int lab[N][N], int x, int y)
{
    // if (x,y labirentin disindaysa) return false
    if(x >= 0 && x < N && y >= 0 && y < N && lab[x][y] == 1)
        return true;

    return false;
}
// Yol varsa eger bu fonksiyonla yazdiriyoruz.
void yazdir(int yol[N][N])
{
    printf("\nBulunan yol:\n");
    int i,j;
    for (i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            printf(" %d ", yol[i][j]);
        }
        printf("\n");
    }
}
bool labirentCozum(int lab[N][N], int x, int y, int yol[N][N])
{
    // if (x,y amaç ise) return true
    if(x == N-1 && y == N-1)
    {
        yol[x][y] = 1;
        return true;
    }

    // Labirent [x][y] 'nin geçerli olup olmadigini kontrol et.
    if(kontrol(lab, x, y) == true)
    {
        // çozum yolunun parcasi:  x, y
        yol[x][y] = 1;

        // X yonunde ilerle
        if (labirentCozum(lab, x+1, y, yol) == true)
            return true;

        /* X yonunde hareket etmek çozumu vermezse,
           Y yonunde asagi in  */
        if (labirentCozum(lab, x, y+1, yol) == true)
            return true;

        /* Yukaridaki hareketlerden hicbiri ise yaramazsa GERI DON:
        Cozum yolunun parcasi olarak x, y yi kaldir */
        yol[x][y] = 0;
        return false;
    }

    return false;
}

/* Bu fonksiyon Geri izleme ile Labirent problemini cozer.
   sorunu çözmek icin labirentCozum() fonksiyonunu kullanir. Yoksa yanlis dondurur, varsa dogru dondurur.
   Birden fazla cozum olabilir,
   uygulanabilir cozumlerden birini yazdirir*/
bool cozum(int lab[N][N])
{
    int i,j,yol[N][N];
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++) yol[i][j]=0;
    }
    int x,y;
    printf("\nBaslangic koordinatlarini giriniz: ");
   devamm: printf("\nx? ");
    scanf("%d",&x);
    printf("\ny? ");
    scanf("%d",&y);
    if(x!=0&&y!=0)
    { printf("\nLabirentin icinden baslayamazsiniz.\nLutfen koordinatlari bastan giriniz..");
      goto devamm;

    }

    if(labirentCozum(lab, x, y, yol) == false)
    {
        printf("Yol Bulunamadi!");
        return false;
    }

    yazdir(yol);
    return true;
}

