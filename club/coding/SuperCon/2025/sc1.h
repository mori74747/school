#include<stdio.h>
#include<time.h>

# define SC_L 20
# define SC_SC 100
# define SC_alpha 0.20
# define SC_t 10
# define SC_A 10.0

int SC_Ne;

int SC_Sf[SC_L+1][SC_L+1];
int SC_S0[SC_L+1][SC_L+1];

clock_t SC_starttime,SC_endtime;

void SC_input(){

  scanf("%d",&SC_Ne);
  for(int i=1; i<= SC_L; i++){
    for(int j=1; j<= SC_L; j++){
      scanf("%d",&SC_Sf[i][j]);
    };
  };

  SC_starttime=clock();
  
}

void SC_output(){

  SC_endtime=clock();

  for(int i=1; i<= SC_L; i++){
    for(int j=1; j<= SC_L; j++){
      printf("%d\n",SC_S0[i][j]);
    };
  };

  printf("# elapsed time (sec) = %f \n", (double) (SC_endtime-SC_starttime)/CLOCKS_PER_SEC);
  
}








