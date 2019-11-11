#include <bits/stdc++.h>
#define asp ""
#define aps ''
#define one 1
#define two 2
#define dif !=
using namespace std;
const int maxPess = 22;
// codigo para organizar o resultado antes e depois da falha no contest

struct problema{

	char letra;
	int was = 0;
	int ac = 0; // 0 ou 1
	char hora[7];
};

struct Comp{

	char nome[30];
	int resolvidos = 0;
	int penalidade = 0;
	problema lista[10];
};

vector<Comp> Person(maxPess); // tot

bool func(Comp A,Comp B){

	if(A.resolvidos > B.resolvidos) return true;
	else if(A.resolvidos == B.resolvidos) return (A.penalidade < B.penalidade);
	else return false;
}

void init(){

	for(int i=0;i<maxPess;i++){
		Person[i].resolvidos =0;
		Person[i].penalidade =0;
		for(int j=0;j<10;j++){
			Person[i].lista[j].letra = 'a' + j;
			Person[i].lista[j].was =0;
			Person[i].lista[j].ac =0;
			strcpy(Person[i].lista[j].hora,"NULL");
		}
	}
}

int find_user(char *ptr){


	for(int i=0;i<maxPess;i++){
		if(strcmp(ptr,Person[i].nome) == 0) return i;
	}

	return -1;
}

void tratar_horario(char *ptr){ // o contest comeca agora de 00h

	if(strcmp(ptr,"NULL") == 0) return ;

	int hr;
	hr = (ptr[0] - 48)*10 + (ptr[1] - 48);
	hr -= 8;
	ptr[0] = (hr/10) + 48;
	ptr[1] = (hr%10) + 48;
}

int calc_horario(char *ptr){

	int pen = 0;

	pen = (ptr[1] - 48)*60 + (ptr[3] - 48)*10 + (ptr[4] - 48);

	return pen;
}

void before_failure(){

	FILE *arq = NULL;

	arq = fopen("before.in","r");
	char box[30];
	char prob[30];
	int wa;
	int ac;
	char hora[7];
	char lixo[30];
	int pen;

	while(fscanf(arq,"nome: %s\n",box) dif EOF){
		// leitura da sub
		pen = 0;
		int id = find_user(box);
		fscanf(arq,"problema: %s\n",prob);
		fscanf(arq,"was: %d\n",&wa);
		fscanf(arq,"acs: %d\n",&ac);
		fscanf(arq,"hora: %s\n",hora);
		fscanf(arq,"%s\n",lixo);

		if(id == -1){
			printf("nome nao encontrado: %s\n",box);
			continue;	
		}

		if(ac == 0){
			Person[id].lista[prob[0] - 'a'].was = wa;
		}
		else{
			(Person[id].resolvidos)++;
			pen = calc_horario(hora);
			pen += wa*20;
			(Person[id].penalidade) += pen;
			Person[id].lista[prob[0] - 'a'].was = wa;
			Person[id].lista[prob[0] - 'a'].ac = 1;
			strcpy(Person[id].lista[prob[0] - 'a'].hora,hora);
		}
	}

	fclose(arq);
}

void after_failure(){

	FILE *arq = NULL;

	arq = fopen("dados.in","r");
	char log[40];
	char prob;
	char veredito[4];
	char hora[7];
	char lixo[30];

	while(fscanf(arq,"login: %s\n",log) dif EOF){
		fscanf(arq,"questao: %c\n",&prob);
		fscanf(arq,"veredito: %s\n",veredito);
		fscanf(arq,"tempo: %s\n",hora);
		fscanf(arq,"%s\n",lixo);

		int id = find_user(log);
		if(id == -1){
			printf("login nao encontrado %s\n",log);
			continue;
		}
		int pen = 0;

		tratar_horario(hora);
		if(strcmp(veredito,"ac") == 0){
			pen = calc_horario(hora);
			Person[id].resolvidos++;
			Person[id].lista[prob - 'a'].ac = 1;
			pen += Person[id].lista[prob - 'a'].was * 20;
			Person[id].penalidade += pen;
			strcpy(Person[id].lista[prob - 'a'].hora,hora);
		}
		else{
			Person[id].lista[prob - 'a'].was++;
		}
	}
	fclose(arq);
}

void print(){

	printf("Ranking Atualizado\n\n");

	for(int i=0;i<maxPess;i++){
		printf("#%d: %s -> Prob: %d  -> Penalidade: %d\n",i+1,Person[i].nome,Person[i].resolvidos,Person[i].penalidade);
	}
}

int main(){

	// setando o nome de todo mundo
	strcpy(Person[0].nome,"mll5");
	strcpy(Person[1].nome,"vdcn");
	strcpy(Person[2].nome,"gasm");
	strcpy(Person[3].nome,"alas3");
	strcpy(Person[4].nome,"gcgm");
	strcpy(Person[5].nome,"gffarias");
	strcpy(Person[6].nome,"123499");
	strcpy(Person[7].nome,"gvh");
	strcpy(Person[8].nome,"pnc");
	strcpy(Person[9].nome,"vinidj");
	strcpy(Person[10].nome,"lmg2");
	strcpy(Person[11].nome,"gso");
	strcpy(Person[12].nome,"alpvj");
	strcpy(Person[13].nome,"fmln");
	strcpy(Person[14].nome,"rap2");
	strcpy(Person[15].nome,"arttt");
	strcpy(Person[16].nome,"gbrls");
	strcpy(Person[17].nome,"pedrodamatta");
	strcpy(Person[18].nome,"afcf");
	strcpy(Person[19].nome,"gbc8");
	strcpy(Person[20].nome,"vefg");
	strcpy(Person[21].nome,"ibps");

	init(); 

	before_failure();
	sort(Person.begin(),Person.end(),func);

	// 

	after_failure();
	sort(Person.begin(),Person.end(),func);

	print();
}