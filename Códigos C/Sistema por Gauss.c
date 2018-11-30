#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inserir(float x[],float y[],float z[],float t[]);
void exibir(float x[],float y[],float z[],float t[],float yy[],float zz[],float tt[],float z1[],float t1[],float X[],float Y[],float Z[]);
void calc(float x[],float y[],float z[],float t[],float yy[],float zz[],float tt[],float z1[],float t1[],float X[],float Y[],float Z[]);
float principal(float p1, float p2);
float secundaria(float p1, float p2);
main(){
	float x[3], y[3], z[3], t[3];
	float yy[2], zz[2], tt[2];
	float z1[1], t1[1];
	float X[1], Y[1], Z[1];
	char resp= 's';
	while(resp == 's'||resp =='S'){
	system("cls");
	inserir(x, y, z, t);
	calc(x, y, z, t, yy, zz, tt, z1, t1, X, Y, Z);
	system("cls");
	exibir(x, y, z, t, yy, zz, tt, z1, t1, X, Y, Z);
	printf("\nDeseja fazer outra matriz?\n");
	fflush(stdin);
	scanf("%c", &resp);
	}
	system("pause");
	
}
//Ler o os dados do sistema 3x3
void inserir(float x[],float y[],float z[],float t[]){
	printf("Programa para resolver matrizes\n(Metodo de Gauss)\n	Digite a matriz:\n");
	for(int i=0; i<3; i++){
		printf("\n|X%d |Y%d |Z%d |Total %d|\n", (i+1), (i+1), (i+1), (i+1));
		scanf("%f %f %f %f", &x[i], &y[i], &z[i], &t[i]);
	}
}
//Exibir a o sistema resolvido passo a passo pelo metodo de gauss
void exibir(float x[],float y[],float z[],float t[],float yy[],float zz[],float tt[],float z1[],float t1[],float X[],float Y[],float Z[]){
	int i;
	for(i=0; i<3; i++){
		printf("|%.0fx\t|%.0fy\t|%.0fz\t|= %.0f\n", x[i], y[i], z[i], t[i]);
	}
	for(i=0; i<2; i++){
		printf("\t|%.0fy\t|%.0fz\t|= %.0f\n", yy[i], zz[i], tt[i]);
	}
	printf("\t\t|%.0fz\t|= %.0f\n", z1[0], t1[0]);
	printf("\nX = %.2f\nY = %.2f\nZ = %.2f\n", X[0], Y[0] , Z[0]);
}
//calculos para resolução das matrizes geradas pelo sistema
void calc(float x[],float y[],float z[],float t[],float yy[],float zz[],float tt[],float z1[],float t1[],float X[],float Y[],float Z[]){
	int j=1;
	for(int i=0; i<2; i++){
		yy[i]= (principal(x[0], y[j])+secundaria(x[j], y[0]));
		zz[i]= (principal(x[0], z[j])+secundaria(x[j], z[0]));
		tt[i]= (principal(x[0], t[j])+secundaria(x[j], t[0]));
		j++;
	}
	z1[0]= (principal(yy[0], zz[1])+secundaria(yy[1], zz[0]));
	t1[0]= (principal(yy[0], tt[1])+secundaria(yy[1], tt[0]));
	Z[0]=(float)(t1[0]/z1[0]);
	Y[0]=(float)((tt[0]-(zz[0]*Z[0]))/yy[0]);
	X[0]=(float)((t[0]-(y[0]*Y[0])-(z[0]*Z[0]))/x[0]);
}
//calculo do diagonal principal
float principal(float p1, float p2){
	return p1*p2;
}
//calculo da diagonal segundaria
float secundaria(float p1, float p2){
	return ((p1*p2)*(-1));
}
