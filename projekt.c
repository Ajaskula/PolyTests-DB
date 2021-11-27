#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void output(int wynik[])
/*funkcja przetwarza dane z tablicy int wynik i wypisuje je na ekran w taki sposób, aby był zgodny porządanym*/
{
    int pierwszy=0; //para marametrów pozwalająca ocenić czy dany element będzie wypisany po raz pierwszy.
    int tak=0;
    for(int i=10;i>=0;i--)//pętla wypisuje kolejne elementy wyniku w porządanej postaci.
    {
        if(wynik[i]!=0&&pierwszy==0&&i>=2)
        {
            tak++;
            if(wynik[i]>0&&wynik[i]!=1)
            {
                printf("%dx^%d",wynik[i],i);
            }
            if(wynik[i]<0&&wynik[i]!=-1)
            {
                printf("-%dx^%d",abs(wynik[i]),i);
            }
            if(wynik[i]==1)
            printf("%cx^%d",'\0',i);
            if(wynik[i]==-1)
            printf("-x^%d",i);
            
        }
        if(wynik[i]!=0&&pierwszy!=0&&i>=2)
        {
            tak++;
            if(wynik[i]>0&&wynik[i]!=1)
            {
                printf(" + %dx^%d",wynik[i],i);
            }
            if(wynik[i]<0&&wynik[i]!=-1)
            {
                printf(" - %dx^%d",abs(wynik[i]),i);
            }
            if(wynik[i]==1)
            printf(" + x^%d",i);
            if(wynik[i]==-1)
            printf(" - x^%d",i);
        }
        
        if(wynik[i]!=0&&pierwszy==0&&i==1)
        {
            tak++;
            if(wynik[i]>0&&wynik[i]!=1)
            {
                printf("%dx",wynik[i]);
            }
            if(wynik[i]<0&&wynik[i]!=-1)
            {
                printf("-%dx",abs(wynik[i]));
            }
            if(wynik[i]==1)
            printf("x");
            if(wynik[i]==-1)
            printf("-x");
            
        }
        if(wynik[i]!=0&&pierwszy!=0&&i==1)
        {
            tak++;
            if(wynik[i]>0&&wynik[i]!=1)
            {
                printf(" + %dx",wynik[i]);
            }
            if(wynik[i]<0&&wynik[i]!=-1)
            {
                printf(" - %dx",abs(wynik[i]));
            }
            if(wynik[i]==1)
            printf(" + x");
            if(wynik[i]==-1)
            printf(" - x");
        }
        
        if(wynik[i]!=0&&pierwszy==0&&i==0)
        {
            tak++;
            if(wynik[i]>0)
            {
                printf("%d",wynik[i]);
            }
            else
            {
                printf("-%d",abs(wynik[i]));
            }
            
        }
        if(wynik[i]!=0&&pierwszy!=0&&i==0)
        {
            tak++;
            if(wynik[i]>0)
            {
                printf(" + %d",wynik[i]);
            }
            else
            {
                printf(" - %d",abs(wynik[i]));
            }
        }
        if(wynik[i]==0&&pierwszy==0&&i==0)
            printf("0");
        pierwszy=pierwszy+tak;
    }
}
void wyczysc(char *tablica)
{
    int i=0;
    do
    {
        tablica[i]=' ';
        i++;
    }while(tablica[i]!='\0');
}
void iloczyn(char tablica[], int wynik[])/*funkcja wykonuje operację iloczynu wielomianów*/
{
    int A1[11]={0,0,0,0,0,0,0,0,0,0,0};//tablice pomocnicze, potrzebne do przetwarzania poszczególnych współczynników wielomianu
    int A2[11]={0,0,0,0,0,0,0,0,0,0,0};
    int A3[11]={0,0,0,0,0,0,0,0,0,0,0};
    int A4[11]={0,0,0,0,0,0,0,0,0,0,0};
    int A5[11]={0,0,0,0,0,0,0,0,0,0,0};
    int A6[11]={0,0,0,0,0,0,0,0,0,0,0};
    int A7[11]={0,0,0,0,0,0,0,0,0,0,0};
    int A8[11]={0,0,0,0,0,0,0,0,0,0,0};
    int A9[11]={0,0,0,0,0,0,0,0,0,0,0};
    int A10[11]={0,0,0,0,0,0,0,0,0,0,0};
    int A0[11]={0,0,0,0,0,0,0,0,0,0,0};
    char *pice=strtok(tablica, " ");
    /*przy pomocy funkcji strtok dzielę lablicę na części w taki sposób, że w każdym segmencie otrzymuje tylko jeden jednomian ax^n*/
    while(pice!=NULL)//w pteli dzielę cały wejściowy wielomian na segmenty
    {
        if(strstr(pice,"^10")) //znaleźliśmy wielomian o stopniu 10 przy pomocy funkcji strstr
        { int deg=10;//stopień jednomianu znajdującego się w segmencie
            for(int i=0;i<11;i++)
            {
            A10[i]=wynik[i];
            }
            if(atoi(pice)!=0) //jeśli jego współczynnik jest różny zero, wartość współczynniku określam przy pomocy funkcji atoi
            { 
                for(int i=10-deg; i>=0; i--)//odpowiednio uzupełniamy tablicę pomocniczą A
                {
                A10[i+deg]+=A10[i]*atoi(pice);
                A10[i]=0;
                }
            }
            else if(pice[0]=='-') //jeśli ma on współczynnik -1
            {
             for(int i=10-deg; i>=0; i--)
                {
                A10[i+deg]=A10[i]*(-1);
                A10[i]=0;
                }
            }
            else //jeśli ma współczynnik 1
            {
             for(int i=10-deg; i>=0; i--)
                {
                A10[i+deg]=A10[i]*1;
                A10[i]=0;
                }
            }
        }//następne kroki są analogiczne dla kolejnych stopni wielomianu
        else if(strstr(pice,"^9"))
        { int deg=9;
        for(int i=0;i<11;i++)
            {
            A9[i]=wynik[i];
            }
            if(atoi(pice)!=0)
            {
                for(int i=10-deg; i>=0; i--)
                {
                A9[i+deg]=A9[i]*atoi(pice);
                A9[i]=0;
                }
            }
            else if(pice[0]=='-')
            {
            for(int i=10-deg; i>=0; i--)
                {
                A9[i+deg]=A9[i]*(-1);
                A9[i]=0;
                }
            }
            else
            {
            for(int i=10-deg; i>=0; i--)
                {
                A9[i+deg]=A9[i]*1;
                A9[i]=0;
                }
            }
        }
        else if(strstr(pice,"^8"))
        { int deg=8;
        for(int i=0;i<11;i++)
            {
            A8[i]=wynik[i];
            }
            if(atoi(pice)!=0)
            {
               for(int i=10-deg; i>=0; i--)
                {
                A8[i+deg]=A8[i]*atoi(pice);
                A8[i]=0;
                }
            }
            else if(pice[0]=='-')
            {
             for(int i=10-deg; i>=0; i--)
                {
                A8[i+deg]=A8[i]*(-1);
                A8[i]=0;
                }
            }
            else
            {
            for(int i=10-deg; i>=0; i--)
                {
                A8[i+deg]=A8[i]*1;
                A8[i]=0;
                }
            } 
        }
        else if(strstr(pice,"^7"))
        { int deg=7;
        for(int i=0;i<11;i++)
            {
            A7[i]=wynik[i];
            }
            if(atoi(pice)!=0)
            {
                for(int i=10-deg; i>=0; i--)
                {
                A7[i+deg]=A7[i]*atoi(pice);
                A7[i]=0;
                }
            }
            else if(pice[0]=='-')
            {
             for(int i=10-deg; i>=0; i--)
                {
                A7[i+deg]=A7[i]*(-1);
                A7[i]=0;
                }
            }
            else
            {
             for(int i=10-deg; i>=0; i--)
                {
                A7[i+deg]=A7[i]*1;
                A7[i]=0;
                }
            } 
        }
        else if(strstr(pice,"^6"))
        { int deg=6;
        for(int i=0;i<11;i++)
            {
            A6[i]=wynik[i];
            }
            if(atoi(pice)!=0)
            {
                for(int i=10-deg; i>=0; i--)
                {
                A6[i+deg]=A6[i]*atoi(pice);
                A6[i]=0;
                }
            }
            else if(pice[0]=='-')
            {
             for(int i=10-deg; i>=0; i--)
                {
                A6[i+deg]=A6[i]*(-1);
                A6[i]=0;
                }
            }
            else
            {
            for(int i=10-deg; i>=0; i--)
                {
                A6[i+deg]=A6[i]*1;
                A6[i]=0;
                }
            } 
        }
        else if(strstr(pice,"^5"))
        { int deg=5;
        for(int i=0;i<11;i++)
            {
            A5[i]=wynik[i];
            }
            if(atoi(pice)!=0)
            {
                for(int i=10-deg; i>=0; i--)
                {
                A5[i+deg]=A5[i]*atoi(pice);
                A5[i]=0;
                }
            }
            else if(pice[5]=='-')
            {
             for(int i=10-deg; i>=0; i--)
                {
                A5[i+deg]=A5[i]*(-1);
                A5[i]=0;
                }
            }
            else
            {
             for(int i=10-deg; i>=0; i--)
                {
                A5[i+deg]=A5[i]*1;
                A5[i]=0;
                }
            }
        }
        else if(strstr(pice,"^4"))
        { int deg=4;
        for(int i=0;i<11;i++)
            {
            A4[i]=wynik[i];
            }
            if(atoi(pice)!=0)
            {
                for(int i=10-deg; i>=0; i--)
                {
                A4[i+deg]=A4[i]*atoi(pice);
                A4[i]=0;
                }
            }
            else if(pice[0]=='-')
            {
             for(int i=10-deg; i>=0; i--)
                {
                A4[i+deg]=A4[i]*(-1);
                A4[i]=0;
                }
            }
            else
            {
             for(int i=10-deg; i>=0; i--)
                {
                A4[i+deg]=A4[i]*1;
                A4[i]=0;
                }
            } 
        }
        else if(strstr(pice,"^3"))
        { int deg=3;
        for(int i=0;i<11;i++)
            {
            A3[i]=wynik[i];
            }
            if(atoi(pice)!=0)
            {
                for(int i=10-deg; i>=0; i--)
                {
                A3[i+deg]=A3[i]*atoi(pice);
                A3[i]=0;
                }
            }
            else if(pice[0]=='-')
            {
             for(int i=10-deg; i>=0; i--)
                {
                A3[i+deg]=A3[i]*(-1);
                A3[i]=0;
                }
            }
            else
            {
             for(int i=10-deg; i>=0; i--)
                {
                A3[i+deg]=A3[i]*1;
                A3[i]=0;
                }
            } 
        }
        else if(strstr(pice,"^2"))
        { int deg=2;
        for(int i=0;i<11;i++)
            {
            A2[i]=wynik[i];
            }
            if(atoi(pice)!=0)
            {
                for(int i=10-deg; i>=0; i--)
                {
                A2[i+deg]=A2[i]*atoi(pice);
                A2[i]=0;
                }
            }
            else if(pice[0]=='-')
            {
            for(int i=10-deg; i>=0; i--)
                {
                A2[i+deg]=A2[i]*(-1);
                A2[i]=0;
                }
            }
            else
            {
              for(int i=10-deg; i>=0; i--)
                {
                A2[i+deg]=A2[i]*1;
                A2[i]=0;
                }
            }  
        }
        else if(strstr(pice,"x"))
        { int deg=1;
        for(int i=0;i<11;i++)
            {
            A1[i]=wynik[i];
            }
            if(atoi(pice)!=0)
            {
                for(int i=10-deg; i>=0; i--)
                {
                A1[i+deg]=A1[i]*atoi(pice);
                A1[i]=0;
                }
            }
            else if(pice[0]=='-')
            {
            for(int i=10-deg; i>=0; i--)
                {
                A1[i+deg]=A1[i]*(-1);
                A1[i]=0;
                }
            }
            else
            {
              for(int i=10-deg; i>=0; i--)
                {
                A1[i+deg]=A1[i]*1;
                A1[i]=0;
            }
        }
        }
        else
        { 
        for(int i=0;i<11;i++)
            {
            A0[i]=wynik[i];
            }
         for(int i=10; i>=0; i--)
                {
                A0[i]=A0[i]*atoi(pice);
                } 
     //wyraz wolny dopisujemy do komórki zerowej tablicy wyniku
        }
    
        pice=strtok(NULL, " ");/*dzielimy nasz wielomian na segmenty za każdym razem kiedy trafimy na " "
        to że w ten sposób trafimy na dokładnie jeden jednomian w części zapewnia zefiniowana później funkcja dodajzera*/
    }
    for(int i=0; i<11; i++)//akumulujemy w tablicy wynik współczynniki poszczególnych współczynników z tablic pomocniczych
    {
        wynik[i]=A0[i]+A1[i]+A2[i]+A3[i]+A4[i]+A5[i]+A6[i]+A7[i]+A8[i]+A9[i]+A10[i];
    }
    output(wynik);//wypisujemy otrzymany wielomian
    
}

void dodaj(char tablica[], int wynik[])
{
    char *pice=strtok(tablica, " ");
    while(pice!=NULL)
    {
      //  printf("%s\n",pice);
       // int x=atoi(pice);
       // printf("atoi=%d\n",x);
      //  printf("pierwszy=%c\n",pice[0]);
        
      //  printf("%s",pice);
        if(strstr(pice,"^10"))
        {
            if(atoi(pice)!=0)
            {
                wynik[10]+=atoi(pice);
        //   printf("%d",wynik[10]);
            }
            else if(pice[0]=='-')
            {
                wynik[10]=wynik[10]-1;
            }
            else
            {
                wynik[10]=wynik[10]+1;
            }
        }
        else if(strstr(pice,"^9"))
        {
            if(atoi(pice)!=0)
            {
                wynik[9]+=atoi(pice);
        //  printf("%d\n",wynik[9]);
            }
            else if(pice[0]=='-')
            {
                wynik[9]=wynik[9]-1;
        //  printf("%d\n",wynik[9]);
            }
            else
            {
                wynik[9]=wynik[9]+1;
        //  printf("%d\n",wynik[9]);
            }
        }
        else if(strstr(pice,"^8"))
        {
            if(atoi(pice)!=0)
            {
                wynik[8]+=atoi(pice);
            }
            else if(pice[0]=='-')
            {
                wynik[8]=wynik[8]-1;
            }
            else
            {
            wynik[8]=wynik[8]+1;
            } 
        }
        else if(strstr(pice,"^7"))
        {
            if(atoi(pice)!=0)
            {
                wynik[7]+=atoi(pice);
            }
            else if(pice[0]=='-')
            {
                wynik[7]=wynik[7]-1;
            }
            else
            {
                wynik[7]=wynik[7]+1;
            } 
        }
        else if(strstr(pice,"^6"))
        {
            if(atoi(pice)!=0)
            {
                wynik[6]+=atoi(pice);
            }
            else if(pice[0]=='-')
            {
                wynik[6]=wynik[6]-1;
            }
            else
            {
                wynik[6]=wynik[6]+1;
            } 
        }
        else if(strstr(pice,"^5"))
        {
            if(atoi(pice)!=0)
            {
                wynik[5]+=atoi(pice);
            }
            else if(pice[0]=='-')
            {
                wynik[5]=wynik[5]-1;
            }
            else
            {
                wynik[5]=wynik[5]+1;
            } 
          //  printf("%d\n", wynik[5]);
        }
        else if(strstr(pice,"^4"))
        {
            if(atoi(pice)!=0)
            {
                wynik[4]+=atoi(pice);
            }
            else if(pice[0]=='-')
            {
                wynik[4]=wynik[4]-1;
            }
            else
            {
                wynik[4]=wynik[4]+1;
            } 
        }
        else if(strstr(pice,"^3"))
        {
            if(atoi(pice)!=0)
            {
                wynik[3]+=atoi(pice);
            }
            else if(pice[0]=='-')
            {
                wynik[3]=wynik[3]-1;
            }
            else
            {
                wynik[3]=wynik[3]+1;
            } 
        }
        else if(strstr(pice,"^2"))
        {
            if(atoi(pice)!=0)
            {
                wynik[2]+=atoi(pice);
       // printf("%d",wynik[2]);
            }
            else if(pice[0]=='-')
            {
                wynik[2]=wynik[2]-1;
            }
            else
            {
                wynik[2]=wynik[2]+1;
            }  
        }
        else if(strstr(pice,"x"))
        {
            if(atoi(pice)!=0)
            {
                wynik[1]+=atoi(pice);
            }
            else if(pice[0]=='-')
            {
                wynik[1]=wynik[1]-1;
            }
            else
            {
                wynik[1]=wynik[1]+1;
            }
        }
        else
        {
            wynik[0]+=atoi(pice); //wyraz wolny dopisujemy do komórki zerowej tablicy wyniku
     //   printf("%d",wynik[0]);
        }
    
        pice=strtok(NULL, " ");
    }
    output(wynik);
}

void dodajzera(char tab[], int n) //funkcja przed każdym plusem lub minusem tworzy puste spacje
{
    int i=0;
    int p=i;
    for(i=0; i<n; i++)
    {
         p=i;
        char c=' ';
        char a;
        char b;
        if(tab[p]=='+'||tab[p]=='-')
        {
            n=n+1;
            for(int j=i; j<n; j++)
            {
                a=tab[j];
                b=tab[j+1];
                tab[j]=c;
                c=a;
                a=b;
            }
            i=p+1;
        }
    }
    
}

void usuwajpuste(char *tablica) ///funkcja która usuwa spacje w inpucie
{
    int i=0; 
    int tak=0;
    int b=0;
    do{
        if(tablica[i]==' '&&tak==0)
        {
            b=i;
            tak=1;
        }
        if(tablica[i]!=' '&&tak==1)
        {
            tablica[b]=tablica[i];
            tak=0;
            tablica[i]=' ';
            i=b-1;
        }
        i++;
    }while(tablica[i]!='\0');
}


int main()
{
    char tablica[1002]; //alokuje tablicę char do której będziemy wprowadzać dane
    int i=0;//iterator wpisywania znaków
    int wynik[11]={0,0,0,0,0,0,0,0,0,0,0};//tablica ze współczynnikami wyniku. Na początku ma 11 zer
    char p;//przy pomocy p będziemy wprowadzać dane z kalwiatury
    char s;// przy pomocy s będziemy decydować, czy chcemy dodawać czy mnożyć
    do{
        s=(char)getchar();//pobiera z klawiatury symbol, który decyduje o tym jakie działanie będziemy wykonywać
        
        if(s=='*')
        {
        do //ta pętla wczytuje mi całą linię znaków i umiszcza ją w tablicy.
            {
                p=(char)getchar(); //wczutujemy kolejne zanki
                tablica[i]=p;
                i++;
            }while(p!='\n');//kończymy wszytywać znaki klikając enter
            i=i-1;
            tablica[i]='\0';//umieszczamy znak końca tablicy na końcu tablicy
            usuwajpuste(tablica);
            dodajzera(tablica,i+1);
            iloczyn(tablica,wynik);
            printf("\n");
            memset(tablica, 0, 1002);//czyści tablicę przed każdym wrpowadzeniem nowych danych
            i = 0;
        }
        if(s=='+')
        {
            do //działania w tej pętli są analogiczne dla pętli poprzedniej
            {
                p=(char)getchar();
                tablica[i]=p;
                i++;
            }while(p!='\n');
            i=i-1;
            tablica[i]='\0';
            usuwajpuste(tablica);
            dodajzera(tablica,i+1);
            dodaj(tablica,wynik);
            printf("\n");
            memset(tablica, 0, 1002);
            i = 0;
        }
    }while(s!='.');//kończymy działanie programu wpisując "."
    
    return 0;
}
