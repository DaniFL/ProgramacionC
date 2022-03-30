#include <stdio.h>

void funcion1(int u, int v);
void funcion2(int *pu, int *pv);

int main(){

int u = 1; 
int v= 3; 
printf("\nAntes de la llamada a func1: u=%d v=%d", u , v); 
funcion1(u,v);
printf("\nDespués de la llamada a func1: u=%d v=%d", u, v);
printf("\nAntes de la llamada a func2: u=%d v=%d", u, v);
funcion2(&u, &v);
printf("\nDespués de la llamada a func2: u=%d v=%d", u,v); 

}
void funcion1(int u, int v){
u=0;
v=0;
printf("\nDentro de func1: u=%d v=%d", u, v);
return;
}

void funcion2(int *pu, int *pv){
*pu=0;
*pv=0;
printf("\nDentro de func2: *pu=%d *pv=%d", *pu, *pv);
return;
}
