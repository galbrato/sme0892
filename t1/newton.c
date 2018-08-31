/*
Gabriel Simmel Nascimento	9050232
Leticia Rina Sakurai		9278010
Michelle Wingter da Silva	10783243
*/


#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<float.h>

#define ZERO 0.000001f

double df(double x){
	return 84*x*x*x + 87*x*x + 22*x + 29;
}
//f(x) = 21 x^4 + 29 x^3 + 11x^2 + 29x -10
double f(double x){
	return 21*(x*x*x*x) + 29*(x*x*x) + 11*(x*x) + 29*x -10;
}

double newton(double a, double b, double raiz){
	char* filename = calloc(100, sizeof(char));
	sprintf(filename, "newton_saida[%1.1f_%1.1f].dat\0", a, b);
	FILE *p = fopen(filename, "w+");
	free(filename); 
	double x = (a + b)/2;

	int k;
	double erro = fabs(x - raiz);
	for (k = 0; erro > ZERO || k<10; k++){
		fprintf(p,"\t%d\t%2.8lf\t%2.8lf\t%2.8lf\t%2.8lf\n", k, x, f(x), df(x), erro);
		if(fabs(df(x)) < ZERO){
			fprintf(p,"ERRO! divisão por ZERO, derivada da função assumiu valor zero");
			fclose(p);
			return 0;
		}
		if(a>x || x>b){
			fprintf(p,"ERRO! x convergiu para fora do intervalo");
			fclose(p);
			return 0;
		}
		x -= (f(x)/df(x));

		//calculando o erro
		erro = fabs(x - raiz);
	}
	fclose(p);
	return x;
}

int main (int argc, char** argv){
	newton(-2.0f,0.0f,-(5.0f/3.0f));
	newton(0.0f,2.0f, (2.0f/7.0f));

	return 0;
}