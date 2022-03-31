#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    float valeur;
    float temps;
}Extrema;


int main()
{

    FILE *fich2,*out;
    float time=-1,val=-1,before=-1,after=-1,timebef=0;
    Extrema extremas[45095];
    char line[256],line2[36]="";
    int i=0,j=1;


    fich2=fopen("final.txt","r+");
    out=fopen("out.txt","w");

    fscanf(fich2,"%f %f",&time,&val);


    while((fscanf(fich2,"%f %f",&time,&after))!=EOF)
    {


      if(2*val-after-before>0 && val>150)
      {
          extremas[i].temps=timebef;
          extremas[i].valeur=val;
          i++;

      }

      before=val;
      val=after;
      timebef=time;

    }

    printf("Le nombre totales des extremas maximale superieur a 150 est =%d\n",i);
    system("pause");
     fclose(fich2);

    for(j=0;j<i;j++)
    {

        fprintf(out,"V=%f|T=%f\n",extremas[j].valeur,extremas[j].temps);

    }
    fclose(out);
    return 0;
}
