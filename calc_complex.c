#include<stdio.h>

struct complex{
  double real;
  double imag;
};

typedef struct complex Complex;

Complex scanComplex();
void printComplex(Complex c);
Complex add(Complex c1,Complex c2);/*複素数の加算*/
Complex dif(Complex c1,Complex c2);/*複素数の減算*/
Complex mul(Complex c1,Complex c2);/*複素数の乗算*/
Complex div(Complex c1,Complex c2);/*複素数の除算*/

int main(){
  Complex c1,c2;
  Complex c_ans;
   c1=scanComplex();
   c2=scanComplex();

   c_ans=add(c1,c2);
   printComplex(c1);
   printf("+ ");
   printComplex(c2);
   printf("= ");
   printComplex(c_ans);
   printf("\n");

   c_ans=dif(c1,c2);
   printComplex(c1);
   printf("- ");
   printComplex(c2);
   printf("= ");
   printComplex(c_ans);
   printf("\n");

   c_ans=mul(c1,c2);
   printComplex(c1);
   printf("* ");
   printComplex(c2);
   printf("= ");
   printComplex(c_ans);
   printf("\n");

   c_ans=div(c1,c2);
   printComplex(c1);
   printf("/ ");
   printComplex(c2);
   printf("= ");
   printComplex(c_ans);
   printf("\n");
}

/*複素数を表示する関数*/
void printComplex(Complex c){
  printf("%6.2f +%6.2f(i)", c.real, c.imag);
  return;
}
/*複素数を標準入力より読み込む関数*/
Complex scanComplex(){
  Complex c;
  printf("複素数の実部と虚部を入力\n");
  scanf("%lf%lf",&c.real,&c.imag);
  return c;
}

/*複素数の加算*/
Complex add(Complex c1,Complex c2){
  Complex c;
  c.real=c1.real+c2.real;
  c.imag=c1.imag+c2.imag;
  return c;
}

/*複素数の減算*/
Complex dif(Complex c1,Complex c2){
  Complex c;
  c.real=c1.real-c2.real;
  c.imag=c1.imag-c2.imag;
  return c;
}

/*複素数の乗算*/
Complex mul(Complex c1,Complex c2){
  Complex c;
  c.real=c1.real*c2.real-c1.imag*c2.imag;
  c.imag=c1.real*c2.imag+c1.imag*c2.real;
  return c;
}

/*複素数の除算*/
Complex div(Complex c1,Complex c2){
  Complex c;
  double m;
  m=c2.real*c2.real-c2.imag*c2.imag;
  if(m==0.0){
    c.real=0.0;
    c.imag=0.0;
    return c;
  }else{
    c.real=(c1.real*c2.real+c1.imag+c2.imag)/m;
    c.imag=(-c1.real*c2.imag+c1.imag+c2.real)/m;
    return c;
  }
  
}
