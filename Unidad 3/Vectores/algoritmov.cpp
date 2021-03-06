#include<iostream>

#define SIZE 10
using namespace std;

class node {
	public:
	int data[SIZE];
	node *next;
	
		node() {
			for(int p=0; p<SIZE; p++) {
				data[p] = 0;
			}
			next = NULL;
		}
		
		node(int v[], int n1) {
			for(int s = 0; s < n1; s++) {
				data[s] = v[s];
			}
			next = NULL;
		}
		
		friend class process;
}*start=NULL;

int main() {
	int n, events, sent, receive, sentE, recE, commLines = 0;
	node *temp;
	node *proc[SIZE];	//array de procesos
	cout<<"Ingresa el número de procesos: ";
	cin>>n;
	int vector[n] = {0};	//vector de datos
	
	/*----------------INITIALIZATION LOOP-------------------------*/
	for(int i = 0; i < n; i++) {	//numero de procesos
		for(int v = 0; v < n; v++) {
			vector[v] = 0;
		}
		
		cout<<"Ingresa el número de eventos en el proceso "<<i+1<<": ";
		cin>>events;
		
		for(int j = 1; j <= events; j++) {
			vector[i] = j;
			node *newnode = new node(vector,n);
			if(start == NULL) {
				start = newnode;
				temp = start;
			} else {
				temp->next = newnode;
				temp = temp->next;
			}	
		}	
		proc[i] = start;
		start = NULL;
	}
	
	/*-------------------Datos de kas relaciones--------------------*/
	cout<<"\nIngresa el numero de relaciones: ";
	cin>>commLines;
	node *tempS, *tempR;
	
	for(int i = 0; i < commLines; i++) {
		cout<<"\nIngresa el proceso que envia: ";
		cin>>sent;
		cout<<"\nIngresa el proceso que recibe: ";
		cin>>receive;
		cout<<"\nIngresa la marca de tiempo del que enviar : ";
		cin>>sentE;
		cout<<"\nIngresa la marca de tiempo del que recive: ";
		cin>>recE;
		
		tempS = proc[sent - 1];
		tempR = proc[receive - 1];
		
		for(int j = 1; j < sentE; j++) 
			tempS = tempS->next;
		
		for(int j = 1; j < recE; j++)
			tempR = tempR->next;
		
		for(int j = 0; j < n; j++) {
			tempR->data[j] = (tempR->data[j] < tempS->data[j]) ? tempS->data[j] : tempR->data[j];	
		} 
	}
	
	/*-------------------En pantalla------------------------*/
	cout<<"\nResultados:\n\n";
	for(int k = 0; k < n; k++) {
		cout<<"Proceso "<<k + 1<<": ";
		
		node *temp1 = proc[k];
		while(temp1) {
			cout<<"(";
			for(int f = 0; f < n - 1; f++)
				cout<<temp1->data[f]<<",";
				
			cout<<temp1->data[n-1];
			cout<<")";
			temp1 = temp1->next;
		}
		cout<<endl;
	}
	
	return 0;
}
