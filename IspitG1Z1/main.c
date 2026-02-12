#include <stdio.h>
#include <stdlib.h>
void matrixEntry(int *mat,unsigned int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            printf("Unesi %d/%d element: ",i+1,j+1);
            scanf("%d",&mat[i*n+j]);
        }
}
void matrixPrint(int *mat,unsigned int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",mat[i*n+j]);
        }
        printf("\n");
    }

}
int matEvenSum(int *mat,unsigned int n,int row,int col){
    int sum=0;
    //lock row
    for(int i=0;i<n;i++){
        if(i != col && mat[row*n+i]%2 == 0){
            sum+=mat[row*n+i];
        }
    }
    //lock col
    for(int i=0;i<n;i++){
        if(i != row && mat[i*n+col]%2 == 0){
            sum+=mat[i*n+col];
        }
    }
    return sum;
}
int main()
{
    unsigned int n;
    scanf("%d",&n);
    int *matrixA = malloc(n*n*sizeof(int));
    int *matrixB = malloc(n*n*sizeof(int));
    matrixEntry(matrixA,n);
    matrixPrint(matrixA,n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            matrixB[i*n+j] = matEvenSum(matrixA,n,i,j);
    matrixPrint(matrixB,n);
    free(matrixA);
    free(matrixB);
    return 0;
}
/*1. (12p) Napisati program koji uˇcitava prirodan broj N i matricu A dimenzija N ×N. Program treba da formira
novu matricu B istih dimenzija tako ˇsto za svaki element B[i][j] izraˇcunava zbir svih parnih brojeva koji se nalaze
u vrsti i ili u koloni j u originalnoj matrici A, pri ˇcemu se element A[i][j] ne raˇcuna. Nije dozvoljeno koriˇs ́cenje
pomo ́cnih nizova ili matrica. Ispisati matricu B.
Primer:
Ulaz: 4
3 8 5 12
7 4 9 10
2 6 11 8
15 14 3 4
Izlaz:
22 36 20 30
16 38 14 28
14 36 16 34
20 22 18 44*/
