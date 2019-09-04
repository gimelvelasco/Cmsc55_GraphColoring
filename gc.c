#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define DIM 7

int main(){
	//int DIM;
	int i=0, n=0,j=0;
	int aMatrix[DIM][DIM]; //adjacency matrix
	char cchar;
	char tempString[DIM]; //accepts only 4 digits max
	
	for(i=0;i<DIM;i++){//sets all elements of aMatrix to zero
		for(j=0;j<DIM;j++){ 
			aMatrix[i][j] = 0;
		}
	}

	FILE *strm = NULL;
	
	strm = fopen("aMatrix.csv","r");

	if(strm==NULL){
		printf("File not found.\n");
		usleep(500000);
		printf("Program Terminated.");
		return 0;
	}
	else{
		//////////////PARSING
		for(i=0;i<DIM;i++){
			for(j=0;j<DIM;j++){
				n=0;
				do{
					cchar = fgetc(strm);
					tempString[n] = cchar;
					n++;
					if(cchar == '\n' || cchar == EOF){//prevents uhmmm yeah xD
						break;
					}
				}while(cchar!=',');
				tempString[n-1] = '\0';
				sscanf(tempString,"%d",&aMatrix[i][j]);
			}
		}
		fclose(strm);

		//////////////// testing
		for(i=0;i<DIM;i++){
			for(j=0;j<DIM;j++){
				printf(" %d ",aMatrix[i][j]);
			}
			printf("\n");
		}
	}
	
	
	int one=0, two=0, three=0, four=0;
	int a=0,b=0,c=0,d=0;
	//char color[DIM][DIM];
	char *vertex[DIM];
	char *matrix[DIM][DIM];
	//int colmatrix[DIM][DIM];
	
	
	//Set red as the color of the first vertex
	vertex[0] = "red";
	
	//colors the adjacent vertices of the first vertex
		for(a=0;a<DIM;a++){
			if(aMatrix[0][a]!=0){
				//rowmatrix[0][a]=6;
				matrix[a+1][0]="red";
				//color[i][0]="red";
			}
		}
	//assigning colors to the vertices
		int ctr=0;
		for(b=0;b<DIM;b++){
			for(c=1;c<DIM;c++){
				if (aMatrix[b][c]!=0 ){
					for(d=1;d<DIM;d++){
						if(aMatrix[c][d]!=0){
							if(matrix[b+1][d+1]=="red"){
								two++;three++;four++;
							}
							else if(matrix[b+1][d+1]=="blue"){
								one++;three++;four++;
							}
							else if(matrix[b+1][d+1]=="yellow"){
								one++;two++;four++;
							}
							else if(matrix[b+1][d+1]=="violet"){
								one++;two++;three++;
							}
							else{
								one++;two++;three++,four++;
							}
							ctr++;
						}
					}
					if(one==ctr){
						for(d=1;d<DIM;d++){
							if(aMatrix[c][d]!=0){
								matrix[d+1][c+1]="red";
								vertex[c]="red";
							}
								
						}
					}
					else if(two==ctr){
						for(d=1;d<DIM;d++){
							if(aMatrix[c][d]!=0){
								matrix[d+1][c+1]="blue";
								vertex[c]="blue";
							}
						}
					}
					else if(three==ctr){
						for(d=1;d<DIM;d++){
							if(aMatrix[c][d]!=0){
								matrix[d+1][c+1]="yellow";
								vertex[c]="yellow";
							}
						}
					}
					else if(four==ctr){
						for(d=1;d<DIM;d++){
							if(aMatrix[c][d]!=0){
								matrix[d+1][c+1]="violet";
								vertex[c]="violet";
							}
						}
					}
				}
			}
		}
		
		printf("\nColors of the vertices:\n\n");
		int x=0;
		for(x=0;x<DIM;x++){
		printf("Vertex ");
		int v = 'a' + x;
		printf("%c: %s\n",v, vertex[x]);
	}
	

	return 0;
}