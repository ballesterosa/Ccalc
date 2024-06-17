/*
 * File:    calc.c
 * Author:  Antonio Ballesteros
 * Date:    2024-06-16
 * Description: A basic terminal calculator written in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros
#define PI 3.14159265

// Function declarations
void get1doub(double* a);
void get2doubs(double* a, double* b);
double add(double a, double b);
double sub(double a, double b);
double mult(double a, double b);
double divi(double a, double b);
double sqrt(double a);

// Main function
int main(int argc, char *argv[]) {
  // start of with the greeting
  printf("Hi, this is a calculator with a decent amount of functionality.\n\n");
  
  int val = 1; 
  while (val) {
    printf("What operation would you like to do?\n");
    printf("Options:\n");
    printf("add : addition\n");
    printf("sub : subtraction\n");
    printf("mult : multiplication\n");
    printf("divi : division\n");
    printf("sqrt : square root\n");
    printf("q : quit\n");
    printf("\n");
    
    char temp[10];
    fgets(temp, sizeof(temp), stdin);
    
    double a, b;

    if (strcmp(temp, "add\n") == 0) {
      printf("a + b\n");
      get2doubs(&a, &b);
      double out = add(a, b);
      printf("result: %lf\n", out);
    } else if (strcmp(temp, "sub\n") == 0) {
      printf("a - b\n");
      get2doubs(&a, &b);
      double out = sub(a, b);
      printf("result: %lf\n", out);
    } else if (strcmp(temp, "mult\n") == 0) {
      printf("a * b\n");
      get2doubs(&a, &b);
      double out = mult(a, b);
      printf("result: %lf\n", out);
    } else if (strcmp(temp, "divi\n") == 0) {
      printf("a / b\n");
      get2doubs(&a, &b);
      double out = divi(a, b);
      printf("result: %lf\n", out);
    } else if (strcmp(temp, "sqrt\n") == 0) {
      printf("√a\n");
      get1doub(&a);
      double out = sqrt(a);
      printf("result: %lf\n", out);
    } else {
      val = 0;
    }
    fflush(stdin);
  }

  return 0;
}

void get1doub(double* a) {
  printf("a : ");
  scanf("%lf", a);
}

void get2doubs(double* a, double* b) {
  printf("a : ");
  scanf("%lf", a);
  printf("b : ");
  scanf("%lf", b);
}

double add(double a, double b) {
  return a + b;
}

double sub(double a, double b) {
  return a - b;
}

double mult(double a, double b) {
  return a * b;
}

double divi(double a, double b) {
  return a / b;
}

double sqrt(double a) {
  double root = a / 3;
  if (a <= 0) {
    return 0;
  }
  for (int i = 0; i < 32; i++) {
    root = (root + a / root) / 2;
  }
  return root;
}
