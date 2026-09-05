#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#define SIZE
using namespace std;


int cubica (int m[],int n )
{
  
   int max=m[0];
   for (int i=0;i<n;i++)
   {
       for(int j=i;j<n;j++)
       {
           int parcial=0;
           for(int k=i;k<=j;k++)
           {
               parcial+=m[k];
           }
           if(parcial > max){
               max=parcial;
           }
       }
   }
   return max;


}
int cuadratica(int m[],int n){
   int max=m[0];
   for(int i=0;i<n;i++){
       int parcial=0;
       for(int j=i; j<n;j++){
           parcial+=m[j];
           if(parcial >max)
           {
               max=parcial;
           }
       }
   }
   return max;
}
int lineal(int m[], int n){
   int masimo=m[0];
   int aqui=m[0];
   for(int i=1;i<n;i++){
       if(m[i]< aqui+m[i])
       {
           aqui=aqui+m[i];
       }else{
           aqui=m[i];
       }
       if(aqui> masimo)
       {
           masimo=aqui;
       }


   }
   return masimo;
}

double medirTiempo(int (*algoritmo)(int[], int), int arr[], int n)
{
    auto inicio = chrono::high_resolution_clock::now();

    algoritmo(arr, n);

    auto fin = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo = fin - inicio;

    return tiempo.count();
}

double medirTiempo2(int (*algoritmo)(int[], int), int arr[], int n,int repeticion)
{
 

    auto inicio = chrono::high_resolution_clock::now();

    int resultado = 0;

    for (int i = 0; i < repeticion; i++)
    {
        resultado += algoritmo(arr, n);
    }

    auto fin = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> tiempo = fin - inicio;

    return tiempo.count() / repeticion;
}
void medicion()
{
    int size=1000;
    cout <<"n \tCubica\t\tCuadratica\t\tLineal"<< endl;
    for(int i=1;i<5;i++)
    {
        int arr[size];
        for(int j=0;j< size;j ++)
        {
            arr[j] =-100 + rand()%201;
        }
        double t1 =medirTiempo(cubica,arr,size);
        double t2=medirTiempo(cuadratica,arr,size);
        double t3= medirTiempo2(lineal, arr ,size,10000);

        cout<< size <<"\t"<< t1<<"ms" <<"\t\t"<<t2<<"ms"<<"\t\t"<<t3 <<"ms"<<endl;

        size*=2 ;
    }
}


   void medicion2()
{
    int size=100000000;

    cout<< "n\t\tLineal"<<endl;

    int* arr= new int[size];

    for(int j= 0; j < size;j++)
    {
        arr[j]= -100 +rand()% 201;
    }

    double t3= medirTiempo(lineal, arr, size);

    cout<<size<<"\t" << t3 <<" ms"<< endl;
    delete[] arr;

    
}

int main(){
   
   //medicion();//Funcion para mostrar los tiempos de los algoritmos segun el tamaño del arreglo 1000 2000 ...8000
    int M[]={1,2,3,4};
    int M1[]={-1,2,3,-2,4};
    int M2[]={-5,-2, -8};
    int M3[]={4, -1, 2 ,1};
    int M4[]={5, -10, 6 ,7 ,-3 ,2};
    //Arreglos para probar el funcionamiento de las funciones cubicas , cuadraticas y lineal
    /*
    cout<< "Arreglo 1:"<< endl;
    cout<< "Cubica: "<< cubica(M, 4) << endl;
    cout<< "Cuadratica: " << cuadratica(M, 4) << endl;
    cout << "Lineal: " << lineal(M, 4) << endl;

    cout<< "\nArreglo 2:"<< endl;
    cout<< "Cubica: "<< cubica(M1, 5) << endl;
    cout<< "Cuadratica: " << cuadratica(M1, 5) << endl;
    cout << "Lineal: " << lineal(M1, 5) << endl;

    cout<< "\nArreglo 3:"<< endl;
    cout<< "Cubica: "<< cubica(M2, 3) << endl;
    cout<< "Cuadratica: " << cuadratica(M2, 3) << endl;
    cout << "Lineal: " << lineal(M2, 3) << endl;

    cout<< "\nArreglo 4:"<< endl;
    cout<< "Cubica: "<< cubica(M3, 4) << endl;
    cout<< "Cuadratica: " << cuadratica(M3, 4) << endl;
    cout << "Lineal: " << lineal(M3, 4) << endl;

    cout<< "\nArreglo 5:"<< endl;
    cout<< "Cubica: "<< cubica(M4, 6) << endl;
    cout<< "Cuadratica: " << cuadratica(M4, 6) << endl;
    cout << "Lineal: " << lineal(M4, 6) << endl;

*/
medicion2();

 
   return 0;


  
}
