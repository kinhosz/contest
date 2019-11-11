#include <bits/stdc++.h>
using namespace std;
#define asp ""
#define aps ''
#define one 1
#define two 2
#define dif !=

// programa para converter email para nome do usuario no vjudge
int main(){

	string news,at;
	cin >> news;
	cin >> at;
	freopen("dados.in","r",stdin);

	string aux;
	int cont = 0;
	cin >> aux;
	while(aux dif "FIM"){
		string nome;
		nome = aux;
		cout << nome; // nome:
		cout << " ";
		cin >> nome; // nome_user
		if(nome == at) cout << news << endl;
		else cout << nome << endl;

		cin >> nome; // questao:
		cout << nome;
		cout << " ";
		cin >> nome; // a,b,c...
		cout << nome << endl;

		cin >> nome; // veredito:
		cout << nome;
		cout << " ";
		cin >> nome; // ac,wa..
		cout << nome << endl;

		cin >> nome; // tempo:
		cout << nome;
		cout << " ";
		cin >> nome; // horario de fato
		cout << nome << endl;
		cin >> nome;
		cout << nome << endl; // -----
		cin >> aux;
	}
	cout << aux << endl;
}