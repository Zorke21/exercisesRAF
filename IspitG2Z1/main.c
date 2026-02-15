#include <stdio.h>
#include <stdlib.h>
void matEntry(int *mat,int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("Unesi %d/%d element: ",i+1,j+1);
            scanf("%d", &mat[i*n+j]);
        }
    }
}
void matPrint(int *mat,int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%d ",mat[i*n+j]);
        }
        printf("\n");
    }
}
int bEntry(int *mat,int i,int j,int n){
    int sum = 0,k,m;
    k = i;
    m = j;
    while(k > 0 && m > 0){
        k--;
        m--;
    }
    while(k<n && m<n){
        if(k == n || m == n) break;
        if(k == i && m == j){
            k++;
            m++;
            continue;
        }
        if(mat[k*n+m] % 2 != 0){
            sum+= mat[k*n+m];
        }
        k++;
        m++;
    }
    for(k = 0;k<n;k++){
        m = i + j - k;
        if(m>= 0 && m < n){
            if(k+m == i + j && mat[k*n+m] % 2 == 1 && !(k == i && m == j)){
            sum+= mat[k*n+m];
            }
        }
    }

    return sum;
}
int main(){
    int n;
    scanf("%d",&n);
    int *A = malloc(n*n*sizeof(int));
    int *B = malloc(n*n*sizeof(int));
    matEntry(A,n);

    matPrint(A,n);
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            B[i*n+j] = bEntry(A,i,j,n);
    printf("\n");
    matPrint(B,n);
    free(A);
    free(B);
    return 0;
}
/*Napisati program koji uˇcitava prirodan broj N i matricu A dimenzija N × N. Program treba da
formira novu matricu B istih dimenzija tako ˇsto za svaki element B[i][j] izraˇcunava zbir svih neparnih brojeva koji
se nalaze na dijagonalama na kojima se nalazi element A[i][j] u originalnoj matrici A, pri ˇcemu se element A[i][j]
ne raˇcuna. Nije dozvoljeno koriˇs ́cenje pomo ́cnih nizova ili matrica. Ispisati matricu B.
Primer:
Ulaz: 4
3 8 5 12
7 4 9 10
2 6 11 8
15 14 3 4
Izlaz:
11 16 0 24
3 19 15 16
5 34 3 12
9 11 7 14*/
