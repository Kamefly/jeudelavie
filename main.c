#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define m 15
#define n 40

void Charger ( char nomfichier [], int Population[n][m]);
void MiseAZero(int Population[m][n]);
void Copier(int Population2[m][n],int Population1[m][n]);
void Sauvegarder(int Population[m][n]);
void ChargerParDefaut (int Population[m][n]);
void ChargerAleatoire (int Population[m][n]) ;
void ProchaineEtat (int Population[m][n]);

typedef struct POPULATION POPULATION;
struct POPULATION
{
    int population [m][n];
};

void MiseAZero(int Population[m][n])
{
    int x,y;

    for (x=0;x<m;x++)
    {
        for (y=0;y<n;y++)
        {
            Population [x][y]=0;
        }

    }
}

void Copier(int Population2[m][n],int Population1[m][n])
{
    int x,y;

    for (x=0;x<m;x++)
    {
        for (y=0;y<n;y++)
        {
            Population2[x][y]= Population1[x][y];

        }

    }
}


void Sauvegarder(int Population[m][n])
{
    int x, y ;

    FILE* fichier;
    fichier = fopen( "sauver.txt","w");

    if ( fichier != NULL)
    {
        for (x=0;x<m;x++)

        {
            for (y=0;y<n;y++)
            {
                fprintf(fichier,"%d",Population[x][y]);
            }
        }
        fclose(fichier);
    }
    else
    {
        printf("Erreur ! ");
    }
}


void Charger ( char nomfichier [], int Population[n][m])
{

    int x, y ;

    FILE* fichier;
    fichier = fopen( " nomfichier","r");

    if ( fichier !=NULL)
    {
        for (x=0;x<m;x++)

        {
            for (y=0;y<n;y++)
            {
                fscanf(fichier,"%d",&Population[x][y]);
            }
            fclose(fichier);
        }
    }
    else
        printf("Erreur ! ");
}



    void ProchaineEtat(int Population[m][n])
    {
        int x,y;
        int Population2[m][n] ;
        int nombreDeVoisinsVivants2;

        Copier (Population2, Population) ;

        for (x=0;x<m;x++)
        {
            for (y=0;y<n;y++)
            {
                nombreDeVoisinsVivants2 = NombreDeVoisinsVivants(Population2, x, y);

                if (Population2[x][y]==1 && nombreDeVoisinsVivants2 !=2 && nombreDeVoisinsVivants2 !=3)
                {
                    Population[x][y]= 0 ;
                }
                if (Population2[x][y]==0 && nombreDeVoisinsVivants2 ==3 )
                {
                    Population[x][y]= 1;
                }

            }

        }
    }






    int NombreDeVoisinsVivants(int Population[m][n], int x, int y)
    {
        int NombreDeVoisinsVivants3 = 0 ;

        if ( x >= 0 && x < m && y >=0 && y < n)
        {
            if (x > 0 && y > 0 && Population [x-1][ y-1] == 1)
                NombreDeVoisinsVivants3 ++ ;

            if (y > 0 && Population [x][ y-1] == 1)
                NombreDeVoisinsVivants3 ++ ;

            if (x + 1 < m && y > 0 && Population [x+1][ y-1] == 1)
                NombreDeVoisinsVivants3 ++ ;

            if (x +1< m && Population [x+1][ y] == 1)
                NombreDeVoisinsVivants3 ++ ;

            if (x+1< m && y+1 < n && Population [x +1][ y +1] == 1)
                NombreDeVoisinsVivants3 ++ ;

            if (y +1 <n && Population [x][ y+1] == 1)
                NombreDeVoisinsVivants3 ++ ;

            if (x>0 && y +1 <n && Population [x-1][ y+1] == 1)
                NombreDeVoisinsVivants3 ++ ;

            if (x >0 && Population [x-1][ y] == 1)
                NombreDeVoisinsVivants3 ++ ;
        }
        return  NombreDeVoisinsVivants3 ;
    }



    void ChargerAleatoire (int Population[m][n])
    {
        int x,y;

        for (x=0;x<m;x++)
        {
            for (y=0;y<n;y++)
            {
                Population[x][y] = rand();
            }
        }

    }


    void ChargerParDefaut (int Population[m][n])
    {
        int x = m / 2;
        int y = n / 2;

        MiseAZero(Population);
        Population [x-1][y-1] = 1 ;
        Population [x][y-1] = 1 ;
        Population [x+1][y-1] = 1 ;
        Population [x+1][y] = 1 ;
        Population [x+1][y+1] = 1 ;
        Population [x-1][y+1] = 1 ;
        Population [x-1][ y] = 1 ;

      }
