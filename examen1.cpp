#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

void Crea_matriz (char** matriz);
void llenado (char** matriz);
void impresion(char** matriz);
void gamer1 (char** matriz,int f,int c,int fm,int cm); // fila,columna,fila_mover, columna_mover
void gamer2 (char** matriz ,int f ,int c , int fm , int cm); // fila,columna,fila_mover, columna_mover
void libera_memoria(char** matriz);
bool continuar=true;

int main(int argc, char* argv[]){

	char** matriz = new char*[7];
	
	int pieza_fila=0,pieza_colum=0;
	int fila_mover=0,colum_mover=0;
	int jugador=1;
	Crea_matriz (matriz);
	llenado (matriz);
	impresion(matriz);
	
	while(continuar){

		if( (pieza_fila>=0 && pieza_fila<7) && (pieza_colum>=0 && pieza_colum<7) &&  (fila_mover>=0 && colum_mover<7) ){
			if(jugador==1){
	 			cout<< "Jugador1"<<endl;
	 			jugador=2;
	 			cout<<"Posicion comienza en 0 hasta 6"<<endl;
				cout<<"Fila de la pieza a mover"<<endl;
				cin>>pieza_fila;
				cout<<"Columna de la pieza a mover"<<endl;
				cin>>pieza_colum;
				cout<<"Fila donde va ha mover la pieza"<<endl;
				cin>>fila_mover;
				cout<<"Columna donde va ha mover la pieza"<<endl;
				cin>>colum_mover;

	 			if( (pieza_fila>=0 && pieza_fila<7) && (pieza_colum>=0 && pieza_colum<7) &&  (fila_mover>=0 && colum_mover<7) ){
	 				gamer1(matriz,pieza_fila,pieza_colum,fila_mover,colum_mover);
	 			}else{
	 				cout<< "Coordenada mala"<<endl;
	 		}

	 	}
	 	if(jugador==2){
	 		cout<< "Jugador2"<<endl;
	 		jugador=1;
	 		cout<<"Posicion comienza en 0 hasta 6"<<endl;
			cout<<"Fila de la pieza a mover"<<endl;
			cin>>pieza_fila;
			cout<<"Columna de la pieza a mover"<<endl;
			cin>>pieza_colum;
			cout<<"Fila donde va ha mover la pieza"<<endl;
			cin>>fila_mover;
			cout<<"Columna donde va ha mover la pieza"<<endl;
			cin>>colum_mover;

	 		if( (pieza_fila>=0 && pieza_fila<7) && (pieza_colum>=0 && pieza_colum<7) &&  (fila_mover>=0 && colum_mover<7) ){
	 			gamer2(matriz,pieza_fila,pieza_colum,fila_mover,colum_mover);
	 		}else{
	 			cout<< "Coordenada mala"<<endl;
	 		}
	 	} // fin jugador2
	 } // fin if
	 else{
	 	cout<< "Coordenada mala"<<endl;
	 }

	 impresion(matriz);

	} // fin while
	

	libera_memoria(matriz);

	return 0;
}


void Crea_matriz (char** matriz){
	for (int i =0; i<7;i++){
		matriz[i]=new char[7];
	}
}


void llenado (char** matriz){
	for(int i=0; i<7;i++){
		for(int j=0 ;j<7 ;j++){
			matriz[i][j]='.';
			//cout << matriz[i][j];
		}
	}
	matriz[0][3]='#';
	matriz[6][3]='#';
	matriz[3][0]='&';
	matriz[3][6]='&';

}


void libera_memoria(char** matriz) {
	for(int i =0 ; i <7 ;i++){
		delete [] matriz[i];
	}
	delete matriz;
}

void impresion(char** matriz){
	cout<<"   0  1  2  3  4  5  6"<<endl;
	for(int i=0;i<7;i++){
		cout<<i<<" ";
		for(int j=0;j<7;j++){
			cout<<"["<< matriz[i][j]<<"]";
		} 
		cout<<endl;
	}
}

void gamer1 (char** matriz ,int f ,int c , int fm , int cm){ // fila,columna,fila_mover, columna_mover
	int dis=0,dis2=0;
	dis = abs(f-fm); // valor absoluto
	dis2 = abs(c-cm); // valor absoluto

	if(dis<=2 && dis2<=2){
		if((dis==2 && dis2 ==0)||(dis==0 && dis2 ==2)){
			if (matriz[fm][cm]!='&' && matriz[f][c]=='#'){
				
				if ((c-cm)== 2 && matriz[fm][cm]!='&'){
					matriz[fm][cm+1]='#';
            		matriz[fm][cm]='#';
            	}
            	if((c-cm)==-2){
					matriz[fm][cm-1]='#';
					matriz[fm][cm]='#';
				}
				if ((f-fm)== 2 && matriz[fm][cm]!='&'){
		    		matriz[fm+1][cm]='#';
            		matriz[fm][cm]='#';
		    	}
            	if((f-fm)==-2 && matriz[fm][cm]!='&'){
            		matriz[fm-1][cm]='#';
            		matriz[fm][cm]='#';
            	}
		    	
		    }else{
		    	cout << "Perdio turno"<<endl;
		   		cout <<(c-cm)<<endl;
		   	}
	    }
	    if (matriz[fm][cm]=='&'){
	    	matriz[fm][cm]='#';
		   	cout<< "Comio una pieza enemiga"<<endl;
		}
		matriz[fm][cm]='#';
	}else{
		cout<< "No puede mover ahi"<<endl;
	}
}

void gamer2 (char** matriz ,int f ,int c , int fm , int cm){ // fila,columna,fila_mover, columna_mover
	int dis=0,dis2=0;
	dis = abs(f-fm); // valor absoluto
	dis2 = abs(c-cm); // valor absoluto
    
	if(dis<=2 && dis2<=2){
		if( (dis==2 && dis2 ==0) || (dis==0 && dis2==2) ){
			if (matriz[f][c]=='&'&& matriz[fm][cm]!='#'){
				if((c-cm)==-2){
            		matriz[fm][cm-1]='&';
            		matriz[fm][cm]='&';
            	}
		    	if ((c-cm)== 2 && matriz[fm][cm]!='#'){
		    		matriz[fm][cm+1]='&';
            		matriz[fm][cm]='&';
		    	}
				if((f-fm)==-2 && matriz[fm][cm]!='#'){
            		matriz[fm-1][cm]='&';
            		matriz[fm][cm]='&';
			
		   		}
		    	if ((f-fm)== 2 && matriz[fm][cm]!='&'){
		    		matriz[fm+1][cm]='&';
            		matriz[fm][cm]='&';
		    	}

		    }else{
				cout << "Perdio turno"<<endl;
		   		cout <<(c-cm)<<endl;
		   	}
		   }
		   if (matriz[fm][cm]=='#'){
		   	matriz[fm][cm]='&';
		   	cout<< "Comio una pieza enemiga"<<endl;
	}
	

	matriz[fm][cm]='&';
	}else{//
		cout<< "No puede mover ahi"<<endl;
	}
}

