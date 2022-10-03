#include <stdio.h>
#include <stdlib.h>

typedef struct cvor {
	struct cvor *p,*l,*r;
	int kljuc;
} node;

node *dodaj(node *koren, int br);
node *makenode(node *newnode, int br);
node *trazi(node *koren, int br);
void inorder(node *koren);
//void obrisi(node *koren,int br);
void obrisistablo(node *koren);


int main(){
	node *root;
	root = NULL;
	root = dodaj(root, 5);
 	root = dodaj(root,6);
	root = dodaj(root,7);
	root = dodaj(root,3);
	inorder(root);
	obrisistablo(root);
	
	return 0;
}

void obrisistablo(node *koren){
	if(koren->l!=NULL){
		obrisistablo(koren->l);
	}
	if(koren->r!=NULL){
		obrisistablo(koren->r);
	}
	free(koren);
}

void inorder(node *koren){
	if(koren==NULL){
		return;
	}
	inorder(koren->l);
	printf("%d ", koren->kljuc);
	inorder(koren->r);
	return;
}

/*void obrisi(node *koren,int br){
	node *temp,*zameni;
	zameni=NULL;
	temp = trazi(koren, br);
	if(temp==NULL){
		return;
	}
	if(temp->r!=NULL){
		zameni = temp->r;
		zameni
	} else(temp->l!=NULL){
		zameni = temp->l;
	}
	
}*/

node *trazi(node *koren, int br){
	if(koren==NULL){
		printf("Stablo ne sadrzi trazeni broj.");
		return NULL;
	}
	if(koren->kljuc==br){
		return koren;	
	}
	
	if(koren->kljuc<br){
		return trazi(koren->r, br);
	}else{
		return trazi(koren->l, br);
	}
}


node *dodaj(node *koren, int br){
	if(koren==NULL){
		koren = makenode(koren, br);
		return koren;
	}
	if(br>koren->kljuc){
		koren->r = dodaj(koren->r, br);
		koren->r->p = koren;
	} else{
		koren->l = dodaj(koren->l,br);
		koren->l->p = koren;
	}
	
	return koren;
}

node *makenode(node *newnode, int br){
	newnode = calloc(1,sizeof(node));
	newnode->p = NULL;
	newnode->l = NULL;
	newnode->r = NULL;
	newnode->kljuc = br;
	return newnode;
}

