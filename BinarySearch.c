#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main(int argc, char *argv[])
{
    int A[50],B[20],i,j,k,n,x,flag=0,first,last,mid,d,temp,temp1,X=0,count=0;
    //printf("Enter size of array:\n");
    //scanf("%d",&n);
	
	if(argc <= 2)
	{
   	printf("Provide command line arguments...\n");
    	return 0;
    	}

	char *token;
	char abc[1000];
	int num;
	FILE *InputFile;
	InputFile = fopen(argv[1], "r");
	if(InputFile==NULL)
	{
		printf("Error in opening file...");
		exit(1);
	}

	
	while(fscanf(InputFile, "%d" , &num)==1)
	{
		A[i]=num;
		i++;
	}
	
	/*fscanf(InputFile, "%s" , abc);
	token = strtok(abc, ",");
	i = 0;
	while(token != NULL)
	{
		A[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}*/
	
	fclose(InputFile);
	
	printf("value of i:%d\n",i);
	n=i;
	
   for(i=0;i<n;i++)
	{
		//scanf("%d\n",&A[i]);
		
		d = i;
 
		while ( d > 0 && A[d-1] > A[d]) 
		{
			temp   = A[d];
			A[d]   = A[d-1];
			A[d-1] = temp;
 
			d--;
		}
	}
    //printf("\nEnter the element to search:");
    //scanf("%d",&x);
 
  FILE *OutFile;
	OutFile=fopen(argv[2] , "w");  
 
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
	first=0;
    last=n-1;
    
	temp1=A[i]-A[j];
	temp=abs(temp1); 
    printf("\ntemp:%d\n",temp);

    while(first<=last)
    { 
        printf("first:%d\n",first);
        printf("last:%d\n",last);
        mid=(first+last)/2;
 
        if(temp==A[mid]){
        //printf("\nElement found at position %d",mid+1);
	fprintf(OutFile, "%d\n", temp);
       // B[X]=temp;
       // count++;
       // X++;
        break;
        }
        
        if(first>last)
        {
          fprintf(OutFile, "Element not found");
        }
        
        else
            if(temp>A[mid])
                first=mid+1;
            else
                last=mid-1;
    }

}    
}

fclose(OutFile);

/*n = count;

for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; )
        {
            if(B[j] == B[i])
            {
                for(k = j; k < n; k++)
                {
                    B[k] = B[k+1];
                }
                n--;
		
            }
            else
            {
                j++;
            }
        }
    }


	FILE *OutFile;
	OutFile=fopen("Output.txt" , "w");
    for(i=0;i<n;i++)
    {
        fprintf(OutFile, "%d\n", B[i]);
    }
	fclose(OutFile);*/
 
 
 return 0;
}