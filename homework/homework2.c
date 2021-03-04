#include <stdio.h>
#include <math.h>
#define numOfBits(x) log10(x)/log10(2)	// MACRO numero de bits que tendran 


void convertArray(int array[], int num){  //convertir a binario
	int bits = numOfBits(array[num-1]);   
	int arr[100]; 
	for(int i=0;i<num;i++){
		int stock = 0;
		int aux = 0;
		for(int j=bits; j>=0; j--){
			if(stock<array[i]){
				if(stock+pow(2,j)>array[i]){
					arr[aux]=0;
				} else{
					arr[aux] = pow(2,j)>array[i] ? 0 : 1;
					if (arr[aux]==1){
						stock+=pow(2,j);
					} else{
					   stock+=0;
					}  
				}
			} else{
				arr[aux] = 0;
			}
			aux++;
		}
		printf("\n");
		for(int i=0;i<aux;i++){			//Imprimir array en binario
			printf("%d",arr[i]);
		}
	}
}

int main(){
	int n, j=1;
	int arr[100];
	printf("How many prime number you want to know?: ");
	scanf("%d",&n);

	while (n<0)	{
		printf("Please try again, use a positive number: ");
		scanf("%d",&n);
	}

	for(int i=0;i<n;){	//Conseguir Numeros Primos
		int k = 1;
		int divisores = 0; 
		
		if (j==1)
			divisores++;
		
		for(int k =1; k<=j; k++) { //busca numeros con 2 divisores (primos)
			if(j%k==0 | j==1)
				divisores++;
		}   

		if(divisores == 2){
			arr[i] = j;
			i++;
		}
		j++;  
	}

	for(int i=0;i<n;i++){    // Imprime los numeros primos DECIMAL
		printf("%d ", arr[i]);
	}

	convertArray(arr, n);   //Funcion convertir a binario 
}
