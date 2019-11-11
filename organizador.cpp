#include <bits/stdc++.h>
#define asp ""
#define aps ''
#define one 1
#define two 2
#define dif !=
using namespace std;
// organizando planilha antes da falha do contest

struct submission{

	char nick[40];
	char prob;
	char was[40];
	char acs[40];
	char hora[40];
};

void trata(char *ptr){

	int i;
	for(i=0;i<strlen(ptr);i++){
		if(ptr[i] == 'q')ptr[i] = '1';
		else if(ptr[i] == 'w') ptr[i] = '2';
	}
}

void print(submission at){

	printf("nome: %s\n",at.nick);
	printf("problema: %c\n",at.prob);
	printf("was: %s\n",at.was);
	printf("acs: %s\n",at.acs);
	printf("hora: %s\n",at.hora);
	printf("-----------\n");
}

void save(FILE *arq, submission at){

	fprintf(arq,"nome: %s\n",at.nick);
	fprintf(arq,"problema: %c\n",at.prob);
	fprintf(arq,"was: %s\n",at.was);
	fprintf(arq,"acs: %s\n",at.acs);
	fprintf(arq,"hora: %s\n",at.hora);
	fprintf(arq,"-----------\n");

}

int main(){


	FILE *arq = NULL;
	arq = fopen("before.in","a");

	char box[40];
	char prob;
	int tent;
	int isAc;

	submission atual;

	printf("nome: "); // le da entrada padrao
	scanf(" %s",box);
	while(strcmp(box,"FIM") dif 0){

		strcpy(atual.nick,box);

		printf("problema: ");
		scanf(" %c",&prob);
		atual.prob = prob;

		printf("was: ");
		scanf(" %s",box); // lendo com string pois teclado ta quebrado
		trata(box);
		strcpy(atual.was,box);

		printf("acs: ");
		scanf(" %s",box);
		trata(box);
		strcpy(atual.acs,box);

		if(box[0] dif 48){
			printf("hora: ");
			scanf(" %s",box);
			trata(box);
			strcpy(atual.hora,box);
		}
		else{
			strcpy(atual.hora,"NULL");
		}
		
		print(atual);

		printf("salvar (S), remover (any) ?\n");
		scanf(" %s",box);

		if(box[0] == 's') save(arq,atual);

		fclose(arq);
		arq = fopen("before.in","a");

		system("clear");
		printf("salvo...\n");
		printf("nome: "); // le da entrada padrao
		scanf(" %s",box);
	}

	fclose(arq);
	return 0;
}