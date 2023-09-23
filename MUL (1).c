
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int row;
    int col;
    int data;
    struct NODE *next;
}NODE;

typedef struct matrix
{
    NODE *head;
    int rows;
    int columns;
    NODE *tail;
    int nodecount;
}matrix;




matrix finalmatrix;

void dec(matrix *m,int r,int c)
{
    m->head=NULL;
    m->tail=NULL;
    m->columns=c;
    m->rows=r;
    m->nodecount=r*c;
}

void creatematrix(matrix *m,int d,int r,int c)
{
    NODE *cur=(NODE *)malloc(sizeof(NODE));
    cur->row=r;
    cur->col=c;
    cur->data=d;
    cur->next=m->head;
    m->head=cur;

}
matrix* mulmatrix(matrix *m1,matrix *m2)
{
    if(m1->columns != m2->rows){
    printf("\n matrix multiplication could not be performed.");

                printf("by multiplying the two matrices we get : \n ");
                }
    if(m1->head == NULL || m2->head == NULL)
    {
       // printf("addition not possible as matrix is empty");
        return NULL;
    }



    if(m1->columns == m2->rows ){
    dec(&finalmatrix,m1->rows,m1->columns);
    int i,j,data=0,k=0,m=0;
    for(i=1;i<=m1->rows;i++)
    {
        for(j=1;j<=m2->columns;j++)
        {
           // creatematrice(&finalmatrix,(searchdata(m1,i,j) * searchdata(m2,j,i)),i,j);
           data = 0;
           for(k=1;k<=m1->rows;k++){
           //while(k<=3){
               // m=j;
             //  printf(" (  %d , %d ) * (  %d , %d ) \t + " , i , k , k , j );
           data=(searchdata(m1,i,k) * searchdata(m2,k,j)) + data;
          // m=m+1;
           //k=k+1;
           }
          // printf("\n ");
           creatematrix(&finalmatrix,data,i,j);
          // k=0;
        }
        //k=0;


    }
    return (&finalmatrix);
}

}

int searchdata(matrix *m,int r,int c)
{
    NODE *current=m->head;
    while(current!=NULL)
    {

        if(current->col==c && current->row==r)
            return current->data;
        current=current->next;
    }
}

void display(matrix *m)
{
    if(m->head == NULL){
        printf("Matrix is empty \n");
        return;
    }
    int i,j;
    for(i=1;i<=m->rows;i++)
    {
        for(j=1;j<=m->columns;j++)
        {
            printf("%d ",searchdata(m,i,j));
        }
        printf("\n");
    }
}

int main()
{
    int ch,r1,r2,c1,c2,ch2,p,s,data,i,j;
    matrix m1,m2;

                printf("Enter number of rows\n");
                scanf("%d",&r1);
                printf("Enter number of columns\n");
                scanf("%d",&c1);
                dec(&m1,r1,c1);
                p=r1;
                s=c1;
                for(i=1;i<=p;i++)
                {
                    for(j=1;j<=s;j++)
                    {

                       data=rand()%100;
                        creatematrix(&m1,data,i,j);

                    }
                }
                printf("First matrix is \n \n \n");

                display(&m1);
                printf("\n \n \n \n ");

                printf("Enter number of rows\n ");
                scanf("%d",&r2);
                printf("Enter number of columns\n");
                scanf("%d",&c2);
                dec(&m2,r2,c2);
                p=r2;
                s=c2;
                for(i=1;i<=p;i++)
                {
                    for(j=1;j<=s;j++)
                    {
                       // printf("Enter data in %d row %d column  ",i,j);
                        //scanf("%d",&data);
                         data= rand() % 100;
                        creatematrix(&m2,data,i,j);
                    }
                }
                printf("Second matrix is \n");



                display(&m2);
                printf("\n \n \n \n ");

                printf("by multiplying the two matrices we get : \n ");
                 //matrix *resultmatrix=mulmatrix(&m1,&m2);
                                 //   display(resultmatrix);


                if(r1!=0 && r2!=0 && c1!=0 && c2!=0 && r1==r2 && c1==c2)
                {
                    matrix *resultmatrix=mulmatrix(&m1,&m2);
                    display(resultmatrix);
                }
                else
                    printf("\n");

        }
