//Graph(FindSameContacts)
//Task: find records that contain same contact information.
//Reference: undirected graph, depth first search.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct contact{
	string c1;
	string c2;
	string c3;
};

void buildGraph(contact C[], int *M[], int n){ //contacts, adjacency matrix, record count.
	//initialization with zeroes.
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			M[i][j] = 0;
	
	//two nodes are linked if they represent same person.
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++)
			if (C[i].c1 == C[j].c1 || C[i].c1 == C[j].c2 || C[i].c1 == C[j].c3 || 
			    C[i].c2 == C[j].c1 || C[i].c2 == C[j].c2 || C[i].c2 == C[j].c3 || 
				C[i].c3 == C[j].c1 || C[i].c3 == C[j].c2 || C[i].c3 == C[j].c3){
				M[i][j] = 1;
				M[j][i] = 1;
				break;
			}
	}
}

//visit all records with depth first search algorithm.
void visit(int *M[], bool V[], vector<int>& S, int i, int n){ //adjacency matrix, visited, solution, record count.
	V[i] = true;
	S.push_back(i);

	for (int j = 0; j < n; j++)
		if (M[i][j] && !V[j])
			visit(M, V, S, j, n);
}

//find same contacts.
void find(contact C[], int n){
	vector<int> S; //solution.
	
	//adjacency matrix.
	int **M = new int*[n];
	for(int i = 0; i < n; i++)
		M[i] = new int[n];
	buildGraph(C, M, n);
	
	//visited records.
	bool V[n];
	memset(V, 0, sizeof(V));


	//total number of connected components and nodes in each component is total number of links.
	for (int i = 0; i < n; i++){
		if (!V[i]){
			visit(M, V, S, i, n);
			S.push_back(-1); //delimiter to seperate nodes.
		}
	}

	//print solution.
	for (int i = 0; i < S.size(); i++)
		if (S[i] == -1) cout << endl;
		else cout << S[i] << " ";
}

int main(){
	contact C[] = { 
		{"Ahmet", "ahmet@gmail.com", "725478"},
		{"Burhan", "cevat@gmail.com", "+864210"},
		{"Cevat", "+123456", "cevat@skype.com"},
		{"Davut", "+123456", "ahmet@gmail.com"},
		{"Ekrem", "+987654", "ekrem@gmail.com"},
		{"Cevat", "+135790", "cevat@gmail.com"}
	};

	int n = sizeof(C)/sizeof(C[0]);
	find(C, n);
	
	return 0;
}