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
	

   
    clock_t start = clock();
   
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

if(numLines > 3.0)
{	
  
  
  n = numLines+1;
	
	for(i=0;i<n;i++)
	{
		//scanf("%d\n",&A[i]);
		
		d = i;
 
		while ( d > 0 && pts[d-1].x > pts[d].x) 
		{
			temp[i]  = pts[d];
			pts[d]   = pts[d-1];
			pts[d-1] = temp[i];
 
			d--;
		}
	
	}
	
//for(i=0;i<n;i++){printf("pts[%d].x = %d  pts[%d].y =%d\n",i,pts[i].x, i, pts[i].y);}
	

mid = (numLines+1)/2;
printf("mid = %d\n",mid);

//float min1 = FLT_MAX, dist1 = 0.0;
//float min2 = FLT_MAX, dist2 = 0.0;
//float min3 = FLT_MAX, dist3 = 0.0;
//float premin = FLT_MAX;
//float minfinal = FLT_MAX;

int mina, minb;

//printf("min1 before = %f\n",min1); printf("min2 before = %f\n",min2);

for(i=0;i<=mid;i++)
{
	for(j=i+1;j<=mid;j++)
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


printf("min1 = %f\n",min1); printf("n = %d\n",n);


for(i=mid+1;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{	
		//printf("jpts[x] = %d\n",pts[j].x); printf("ipts[x] = %d\n",pts[i].x);

		dist2 = sqrt( ((pts[i].x - pts[j].x)*(pts[i].x - pts[j].x)) + ((pts[i].y - pts[j].y)*(pts[i].y - pts[j].y)) );

		if(dist2 < min2)
		{
			min2 = dist2;
			c = i;
			p = j;
		}
	}
}

printf("min2 = %f\n",min2);


if(min1<min2)
{
	premin=min1;
	a = a;
	b = b;
}
else
{
	premin=min2;
	a = c;
	a = p;
}

printf("premin = %f\n",premin);


mina = round(mid - premin);
minb = round(mid + premin);


for(i=mina;i<=minb;i++)
{
	for(j=i+1;j<minb;j++)
	{	
		//printf("jpts[x] = %d\n",pts[j].x); printf("ipts[x] = %d\n",pts[i].x);

		dist3 = sqrt( ((pts[i].x - pts[j].x)*(pts[i].x - pts[j].x)) + ((pts[i].y - pts[j].y)*(pts[i].y - pts[j].y)) );

		if(dist3 < min3)
		{
			min3 = dist3;
			q = i;
			r = j;
		}
	}
}

printf("min3 = %f\n",min3);



if(premin<min3)
{
	minfinal=premin;
	a = a;
	b = b;
}
else
{
	minfinal=min3;
	a = q;
	b = r;
}


printf("minfinal = %f\n",minfinal);
printf("a = %d  b = %d\n",a,b);


}



else
{
n = numLines+1;	
	
for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{	
		//printf("j-ipts[x] = %d\n",pts[j].x-pts[i].x); printf("ipts[x] = %d\n",pts[i].x);

		dist1 = sqrt( ((pts[i].x - pts[j].x)*(pts[i].x - pts[j].x)) + ((pts[i].y - pts[j].y)*(pts[i].y - pts[j].y)) );

		if(dist1 < minfinal)
		{
			minfinal = dist1;
			a = i;
			b = j;
		}
	}
}

	
}


clock_t stop = clock();
elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;

	
	
  if((destFP = fopen(argv[2], "w")) == NULL) {
    perror("Error opening output file");
    exit(0);
  }
  
  writeDestFile(destFP);

  fclose(srcFP);
  fclose(destFP);
}

int writeDestFile(FILE *fp) {
  long long i;
  //printf("numlines3 = %d\n",numLines);
  //for(i = 0; i <=numLines; i++)
    fprintf(fp, "%d %d %f\n clock time : %f\n", a,b,minfinal,elapsed);
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
