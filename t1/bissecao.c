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

double bissecao(double a, double b, double raiz){
	char* filename = calloc(100, sizeof(char));
	sprintf(filename, "bissecao_saida[%1.1f_%1.1f].dat\0", a, b);
	FILE *p = fopen(filename, "w+");
	free(filename); 
	double x = (a + b)/2;
	int k;
	double erro = fabs(x - raiz);
	for (k = 0; erro > ZERO; k++){
		fprintf(p,"\t%d\t%2.8lf\t%2.8lf\t%2.8lf\t%2.8lf\t%2.8lf\n", k, a, b, x, f(x), erro);
		
		x = (a + b)/2;
		if(fabs(f(x)) < ZERO){
			//Terminamos
		}else if(f(a) * f(x) < 0){
			b = x;
		}else if(f(b)*f(x) < 0){
			a = x;
		}
		//calculando o erro
		erro = fabs(x - raiz);
	}
	fclose(p);
	return x;

}

int main (int argc, char** argv){
	bissecao(-2.0f,0.0f,-(5.0f/3.0f));
	bissecao(0.0f,2.0f, (2.0f/7.0f));

	return 0;
}