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

//f(x) = 21 x^4 + 29 x^3 + 11x^2 + 29x -10
double f(double x){
	return 21*(x*x*x*x) + 29*(x*x*x) + 11*(x*x) + 29*x -10;
}

double secantes(double a, double b, double raiz){
	char* filename = calloc(100, sizeof(char));
	sprintf(filename, "secantes_saida[%1.1f_%1.1f].dat\0", a, b);
	FILE *p = fopen(filename, "w+");
	free(filename); 
	
	int k;
	double x, x_2, x_1, erro;

	// Impressão dos valores iniciais, k=0 e k=1
	erro = fabs(a - raiz);
	fprintf(p,"\t%d\t%2.8lf\t%2.8lf\t%2.8lf\n", 0, a, f(a), erro);
	erro = fabs(b - raiz);
	fprintf(p,"\t%d\t%2.8lf\t%2.8lf\t%2.8lf\n", 1, b, f(b), erro);

	x_2 = a;
	x_1 = b;

	for (k = 2; erro > ZERO; k++){

		if(fabs(f(x_1)-f(x_2)) < ZERO){
			fprintf(p,"ERRO! divisão por ZERO, derivada da função assumiu valor zero");
			fclose(p);
			return 0;
		}
		if(a>x || x>b){
			fprintf(p,"ERRO! x convergiu para fora do intervalo");
			fclose(p);
			return 0;
		}


		x = (f(x_1)*x_2-f(x_2)*x_1)/(f(x_1)-f(x_2));
		erro = fabs(x - raiz);
		fprintf(p,"\t%d\t%2.8lf\t%2.8lf\t%2.8lf\n", k, x, f(x), erro);

		if(f(x) == 0)
			break;

		x_2 = x_1;
		x_1 = x;

	}
	fclose(p);
	return x;

}

int main (int argc, char** argv){
	secantes(-2.0f,0.0f,-(5.0f/3.0f));
	secantes(0.0f,2.0f, (2.0f/7.0f));

	return 0;
}