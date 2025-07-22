#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double sdev(int b[],int tam,double media){
    double suma;
    for(int i=0;i<tam;i++){
        suma+=pow((double)b[i]-media,2);
    }
    return (double)sqrt(suma/tam);
}

double normal(int x,double sdev,double media){
    return (double) (x-media)/sdev;
}

int main(int argc,char* argv[]){
    if(argc>1){
        double media;
        int a=atoi(argv[1]);
        int b[a];
        srand(time(NULL));
        for(int i=0;i<a;i++){
            b[i]=rand()%INT_MAX;
            media+=(double)b[i]/a;
            //printf("%d\n",b[i]);
        }
        FILE *arch;
        arch=fopen("datos.txt","w");
        double stddev=sdev(b,a,media);
        for(int i=0;i<a;i++){
            double c=normal(b[i],stddev,media);
            if(c<0) c=-c;
            fprintf(arch,"%d\n",(int)(100000*c));
            //printf("%.2f\n",200-c*100);
            //printf("%d\n",(int)((c)*100000));
        }
        fclose(arch);
    }
    return 0;
}