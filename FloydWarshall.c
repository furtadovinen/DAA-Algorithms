#include <stdio.h>
#include <stdlib.h>
#include<float.h>
#include<math.h>
#include <time.h>



long long findNumLines(FILE *fp);

FILE *srcFP, *destFP;
long long numLines, *dX, *dY, *pts, *ddist;
int i, j, n, d, mid, a, b, c, p, q, r;
int mat[12][12];
int path[12][12];
double elapsed;


struct point
{
	int  x, y, dist;
	//int *temp;
};

int main(int argc, char *argv[]) {
	
	
    clock_t tik = clock();

  //int i, j, n, d, mid, a, b, c, p, q, r;
  struct point *pts;
  struct point *temp;
  char str[100];


 for(a=1;a<12;a++)
  {
	for(b=1;b<12;b++)
	{
		if(a==b)
		{
			mat[a][b]=0;
		}
		else
		{
			mat[a][b] = 100000;
		}
	}
	  
  }
  
  

  
  if((srcFP =fopen(argv[1], "r")) == NULL) {
    perror("Error opening input file");
    exit(0);
  }
  
  numLines = findNumLines(srcFP);
  
  dX = (long long *) malloc(numLines * sizeof(long long));
  dY = (long long *) malloc(numLines * sizeof(long long));
  ddist = (long long *) malloc(numLines * sizeof(long long));
	
	
  pts  = (struct point *) malloc(numLines * sizeof(struct point));
  temp = (struct point *) malloc(numLines * sizeof(struct point));
  
  
  //printf("numlines1 = %d\n",numLines);

  for(i=0; i<=numLines; i++) 
  {
    fgets(str, 100, srcFP);
	sscanf(str, "%lld %lld %lld", &dX[i], &dY[i], &ddist[i]);
	pts[i].x=dX[i];
	pts[i].y=dY[i];
	pts[i].dist=ddist[i];
  }
  
  //printf("numlines2 = %d\n",numLines);

  n = numLines+1;
	
	
	for(a=0;a<numLines;a++)
  {
	
		
		//printf("pts[i].x = %d\n",pts[);
		int t1 = pts[a].x;//(int)dX[i];
		int t2 = pts[a].y;//(int)dY[i];
		int t3 = pts[a].dist;//(int)ddist[i];
		mat[t1][t2] = t3;
		mat[t2][t1] = t3;
		
		//printf("mat[%d][%d] = %d \n",t1,t2,t3);
	
	  
  }

  
	
	for(a=1;a<=11;a++)
  {
	for(b=1;b<=11;b++)
	{
		path[a][b] = (a!=b)?b+1:0;
	}
	  
  }
	
	
	
	for(a=1;a<=11;a++)
	{
		//printf("\n node : %d \n",a);
		for(p=1;p<=11;p++)
		{
			for(q=1;q<=11;q++)
			{
				if(mat[p][q] > mat[p][a] + mat[a][q] && p!=q && (p!=a || q!=a))
				{
					mat[p][q] = abs(mat[p][a] + mat[a][q]);
					path[p][q]=path[p][a];
					
				}
				/*else
				{
					mat[p][q] = abs(mat[p][q]);
				}*/
	
			}
		}	
	}
	
	
for(a=1;a<=11;a++){
		for(b=1;b<=11;b++){

		printf("%d\t",path[a][b]);
		
		}
		printf("\n");
}
		
	
	
	
	


clock_t tok = clock();
elapsed = (double)(tok - tik) * 1000.0 / CLOCKS_PER_SEC;

	
	
  if((destFP = fopen(argv[2], "w")) == NULL) {
    perror("Error opening output file");
    exit(0);
  }
  
  writeDestFile(destFP);

  fclose(srcFP);
  fclose(destFP);
}
//printf("clock : %f\n",elapsed);
int writeDestFile(FILE *fp) {
  long long i;
  //printf("numlines3 = %d\n",numLines);
   
   
   //for(i = 0; i <=numLines; i++){
   //fprintf(fp, "%lld %lld %lld\n", dX[i],dY[i],ddist[i]);}
   
   
   
   for(a=1;a<=11;a++)
		for(b=1;b<=11;b++){
			if(a!=b){
				fprintf(fp,"\nnode%d node%d   %3d   path\tnode%d",a+1,b+1,mat[a][b],a+1);
				int k = a+1;
				do{
					k = path[k-1][b];
					fprintf(fp,"->node%d",k);
				}while(k!=b+1);
			}
		}
   
   
}

//returns file size as number of lines in the file
long long findNumLines(FILE *fp) {

  long long numLines = 0;
  char str[100];

  while(!feof(fp)) {
    fgets(str, 100, fp);
    numLines++;	
  }
  
  numLines--;//the above increments count even when EOF reached
  
  if(fseek(fp, 0L, SEEK_SET) == EOF) {
    perror("Error while seeking to begining of file");
    exit(0);
  }

  return numLines;
}
