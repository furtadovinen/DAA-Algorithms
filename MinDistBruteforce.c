#include <stdio.h>
#include <stdlib.h>
#include<float.h>
#include<math.h>
#include <time.h>



long long findNumLines(FILE *fp);

FILE *srcFP, *destFP;
long long numLines, *dX, *dY, *pts;
float min1 = FLT_MAX, dist1 = 0.0;
float min2 = FLT_MAX, dist2 = 0.0;
float min3 = FLT_MAX, dist3 = 0.0;
float premin = FLT_MAX;
float minfinal = FLT_MAX;
int i, j, n, d, mid, a, b, c, p, q, r;
double elapsed;


struct point
{
	int  x , y;
	//int *temp;
};

int main(int argc, char *argv[]) {
	
	
    clock_t tik = clock();

  //int i, j, n, d, mid, a, b, c, p, q, r;
  struct point *pts;
  struct point *temp;
  char str[100];


  /*if(argc!=3) {
    printf("Usage: progname <input_file> <output_file>");
    exit(0);
  }*/
  
  if((srcFP =fopen(argv[1], "r")) == NULL) {
    perror("Error opening input file");
    exit(0);
  }
  
  numLines = findNumLines(srcFP);
  
  dX = (long long *) malloc(numLines * sizeof(long long));
  dY = (long long *) malloc(numLines * sizeof(long long));
	
	
  pts  = (struct point *) malloc(numLines * sizeof(struct point));
  temp = (struct point *) malloc(numLines * sizeof(struct point));
  
  
  //printf("numlines1 = %d\n",numLines);

  for(i=0; i<=numLines; i++) 
  {
    fgets(str, 100, srcFP);
	sscanf(str, "%lld %lld", &dX[i], &dY[i]);
	pts[i].x=dX[i];
	pts[i].y=dY[i];  
  }
  
  //printf("numlines2 = %d\n",numLines);

  n = numLines+1;
	
	
	
	
	
	for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{	
		//printf("j-ipts[x] = %d\n",pts[j].x-pts[i].x); printf("ipts[x] = %d\n",pts[i].x);

		dist1 = sqrt( ((pts[i].x - pts[j].x)*(pts[i].x - pts[j].x)) + ((pts[i].y - pts[j].y)*(pts[i].y - pts[j].y)) );

		if(dist1 < min1)
		{
			min1 = dist1;
			a = i;
			b = j;
		}
	}
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
  //for(i = 0; i <=numLines; i++)
    fprintf(fp, "%d %d %f\n Clock time : %f\n", a,b,min1,elapsed);
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
