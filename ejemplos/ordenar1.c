/* programa que lee 10 n�meros positivos y los muestra ordenados de menor a mayor*/
/* no usa algoritmo de ordenaci�n */
main () {
int v[10],i,j,min,posmin;
  for (i=0; i<10;i++){
    printf ("Dar num %d ",i);
    scanf ("%d",&v[i]);
  }
  for (i=0; i<10;i++){
    min=2147483647;  /* 2^31 - 1*/
    posmin=0;
    for (j=0; j<10;j++) 
      if (min>v[j]){
        min=v[j];
        posmin=j;
      }
    printf ("%d,",min);
    v[posmin]=2147483647;
  }
//system("pause");
}
