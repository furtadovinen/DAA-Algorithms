#include<stdio.h>
#include<stdlib.h>

int main(){

float x,y,z,a1,b1,c1,a2,b2,c2,p,q;
float i=0,mini;

z = 0.12*x + 0.15*y;


 60*x + 60*y == 300;
 12*x + 6*y == 36;
 10*x + 30*y == 90;

//to find points of l1
//put y=0 and then x=0

float l1x1 = 300/60;
float l1y1 = 0;

float l1x2 = 0;
float l1y2 = 300/60;

//to find points of l2
//put y=0 and then x=0

float l2x1 = 36/12;
float l2y1 = 0;

float l2x2 = 0;
float l2y2 = 36/6;


//to find points of l3
//put y=0 and then x=0


float l3x1 = 90/10;
float l3y1 = 0;

float l3x2 = 0;
float l3y2 = 90/30;



if (l1x1>=l2x1)
    {
        if(l1x1>=l3x1)
           { x = l1x1;
	//printf("l1x1 = %f\n",l1x1);
	    y = 0;
	    z = 0.12*x + 0.15*y;
	    mini = z;
	    p=x;
	    q=y;
	   
	   }
	 else
            { x = l3x1;
	//printf("l3x1 = %f\n",l3x1);
	    y = 0;
	    z = 0.12*x + 0.15*y;
//printf("z = %f\n",z);
	    mini = z;
	    p=x;
	    q=y;
	  
	   }
    }
    else
    {
        if(l2x1>=l3x1)
	{  x = l2x1;
	//printf("l2x1 = %f\n",l2x1);
	    y = 0;
	    z = 0.12*x + 0.15*y;
	    mini = z;
	    p=x;
	    q=y;
	  
	   }
        else
            { x = l3x1;
	//printf("l3x1 = %f\n",l3x1);
	    y = 0;
	    z = 0.12*x + 0.15*y;
	    mini = z;
	    p=x;
	    q=y;
	  
	   }
    }



if (l1y2>=l2y2)
    {
        if(l1y2>=l3y2)
           { x = 0;
	//printf("l1x1 = %f\n",l1y2);
	    y = l1y2;
	    z = 0.12*x + 0.15*y;
	    if(z<=mini)
	    {mini = z;
	    p=x;
	    q=y;}
	   
	   }
	 else
            { x = 0;
	//printf("l3y2 = %f\n",l3y2);
	    y = l3y2;
	    z = 0.12*x + 0.15*y;
//printf("z = %f\n",z);
	    if(z<=mini)
	   { mini = z;
	    p=x;
	    q=y;}
	  
	   }
    }
    else
    {
        if(l2y2>=l3y2)
	{  x = 0;
	//printf("l2y2 = %f\n",l2y2);
	    y = l2y2;
	    z = 0.12*x + 0.15*y;
	    if(z<=mini)
	   {mini = z;
	    p=x;
	    q=y;}
	  
	   }
        else
            { x = 0;
	//printf("l3y2 = %f\n",l3y2);
	    y = l3y2;
	    z = 0.12*x + 0.15*y;
	    if(z<=mini)
	    {mini = z;
	    p=x;
	    q=y;}
	  
	   }
    }

//printf("z after  = %f\n",z);
//printf("minimum value = %f\n",mini);


//intersection of l1 and l2
//l1: 60x + 60y = 300
//l2: 12x + 6y = 36

a1=60;b1=60;c1=300;a2=12;b2=6;c2=36;

float l12x = abs(((b1*c2)-(b2*c1))/((a1*b2)-(a2*b1)));
float l12y = abs(((a2*c1)-(a1*c2))/((a1*b2)-(a2*b1)));

//printf("l12x = %f\n",l12x);
//printf("l12y = %f\n",l12y);

x=l12x;
y=l12y;
z = 0.12*x + 0.15*y;
 if(z<=mini)
{
mini = z;
p=x;
q=y;
}





//intersection of l1 and l3
//l1: 60x + 60y = 300
//l3: 10x + 30y = 90


a1=60;b1=60;c1=300;a2=10;b2=30;c2=90;

float l13x = abs(((b1*c2)-(b2*c1))/((a1*b2)-(a2*b1)));
float l13y = abs(((a2*c1)-(a1*c2))/((a1*b2)-(a2*b1)));

//printf("l13x = %f\n",l13x);
//printf("l13y = %f\n",l13y);

x=l13x;
y=l13y;
z = 0.12*x + 0.15*y;
//printf("z = %f\n",z);
 if(z<=mini)
{
mini = z;
p=x;
q=y;
}

printf("minimum value = %f\n",mini);
printf("points are: x=%f y=%f\n",x,y);

return 0;

}

