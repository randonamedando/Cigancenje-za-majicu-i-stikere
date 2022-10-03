#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int vrednost;
	int status;
	char *kljuc;
} cvor;

typedef int (*f)(char*, int);

int N = 5;
int popunjenost = 0;

void init(cvor *niz);
int djb2(char *key,int);
int sdbm(char *key,int);
void printniz(cvor *niz);
cvor *insert(cvor *niz, char *key, int vrednost, f funct, int *N, int *popunjenost, int kurac);

f func[2] = {djb2, sdbm};

int main(){
	cvor *niz = calloc(N,sizeof(cvor));
	//void (*func[])(char*) = {djb2,sdbm};
	init(niz);
	niz = insert(niz,"Penis1",69,djb2,&N, &popunjenost,1);
	niz = insert(niz,"Penis2",69,djb2,&N, &popunjenost,1);
	niz = insert(niz,"Penis3",69,djb2,&N, &popunjenost,1);
	niz = insert(niz,"Penis4",69,djb2,&N, &popunjenost,1);
	niz = insert(niz,"Penis5",69,djb2,&N, &popunjenost,1);
		
	printniz(niz);
	free(niz);	
}

cvor *rehasiraj(cvor *niz, int *N, int *popunjenost){
	cvor *temp;
	temp = niz;
	printf("Rehasiranje\n");
	cvor *rehashed = calloc(*N,sizeof(cvor));
	
	for(int i=0;i<*N/2;i++){
		if(niz[i].status==1){
			rehashed = insert(rehashed,niz[i].kljuc,niz[i].vrednost,sdbm,N,popunjenost,0);
		}
	}
	niz = rehashed;
	free(temp);
	return niz;
}

void printniz(cvor *niz){
	for(int i=0;i<N;i++){
		if(niz[i].status==1){
			printf("Kljuc: %s, Vrednost: %d\n",niz[i].kljuc,niz[i].vrednost);
		} else if(niz[i].status==0){
			printf("Prazno mesto\n");
		} else{
			printf("Obrisano mesto\n");
		}
	}

}

void init(cvor *niz){
	for(int i=0;i<N;i++){
		niz[i].status = 0;
	}
}

cvor *insert(cvor *niz, char *key, int vrednost, f funct, int *N, int *popunjenost, int kurac){
	int index;
	index = funct(key,*N);
	cvor new;
	new.vrednost = vrednost;
	new.kljuc = key;
	new.status = 1;
	
	while(niz[index].status!=0){
		if(!strcmp(niz[index].kljuc,key)){
			printf("Vec postoji takav kljuc u hash mapi.\n");
			return niz;
		}
		
		index++;
		index%=*N;
	}
	niz[index] = new;
	if(kurac){	
		*popunjenost = *popunjenost + 1;
		printf("Popunjenost je %d\n",*popunjenost);
	}
	if((float)*popunjenost / *N>0.8){
		*N = 2 * *N;
		niz = rehasiraj(niz,N,popunjenost);
	}
	return niz;
}

int djb2(char *key, int N){
	if(key[0] == 0){
		return 5381%N;
	}
	return (djb2(key+1,N)*33+key[0])%N;
}

int sdbm(char *key, int N){
	if(key[0]==0){
		return 0;
	}
	return ((sdbm(key+1,N)*65599)+key[0])%N;
}

