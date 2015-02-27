#include "einstein.h"


void init_entidades(){
	int i,j;
	for(i = 0; i<5; i++){
		for(j = 0; j<6; j++){
			tabla[i][j] = UNDEF;
		}
	}

	r_index = 0;

}


void define_reglas(){
	//britanico es 0
	tabla[BRITANICO][CASA] = ROJA | MASCARA_PERSISTENTE;



	//sueco es 1
	tabla[SUECO][MASCOTA] = PERRO | MASCARA_PERSISTENTE;

	//danes es 2
	tabla[DANES][BEBIDA] = TE | MASCARA_PERSISTENTE;


	//noruego es 3

	//aleman es 4
	tabla[ALEMAN][FUMA] = PRINCE | MASCARA_PERSISTENTE;
	
	
	//agregamos las reglas indirectas
	agrega_regla(CASA, VERDE, Y, BEBIDA, CAFE);
	agrega_regla(FUMA, PALL, Y, MASCOTA, PAJARO);
	grega_regla(CASA, AMARILLA, Y, FUMA, DUNHILL);
	agrega_regla(POSICION, ENMEDIO, Y, BEBIDA, LECHE);
	agrega_regla(NACIONALIDAD, NORUEGO, Y, POSICION, PRIMERO);
	agrega_regla(FUMA, BLUEMASTERS, Y, BEBIDA, CERVEZA);

	//reglas mas complejas
	agrega_regla(CASA, VERDE, IZQUIERDA, CASA, BLANCA);
	agrega_regla(FUMA, BRENDS, VECINO, MASCOTA, GATO);
	agrega_regla(MASCOTA, CABALLO, VECINO, FUMA, DUNHILL);
	agrega_regla(NACIONALIDAD, NORUEGO, VECINO, CASA, AZUL);
	agrega_regla(FUMA, BRENDS, VECINO, BEBIDA, AGUA);
}


void agrega_regla(int tipo1, int regla1, int op, int tipo2, int regla2){
	if(r_index < 20){
		reglas[r_index].tipo1 = tipo1;
		reglas[r_index].regla2 = regla1;
		reglas[r_index].tipo2 = tipo2;
		reglas[r_index].regla2 = regla2;
		reglas[r_index++].conector = op;
	}else{
		fprintf(stderr, "La estructura de datos que uso es muy tonta y ya no puedo agregar reglas :(\n");
		exit(EXIT_FAILURE);
	}
}


int esta_izquierda(int casa1, int casa2){
	if(casa1 < 0 || casa2 < 0)
		return ERROR;
	return casa2 - casa1 > 0? TRUE:FALSE;
}

int es_vecino(int c1, int c2){
	if((c1 < 0 || c1 > 4) && (c2 < 0 || c2 > 4))
		return ERROR;
	return (abs(c1 - c2) == 1)?TRUE:FALSE;
}

char * get_nacionalidad(int nac){
	switch(nac){
		case BRITANICO:
			strncpy(p_nacionalidad, "Britanico", 50);
			break;
		case SUECO:
			strncpy(p_nacionalidad, "Sueco", 50);
			break;
		case DANES:
			strncpy(p_nacionalidad, "Danes", 50);
			break;
		case NORUEGO:
			strncpy(p_nacionalidad, "Noruego", 50);
			break;
		case ALEMAN:
			strncpy(p_nacionalidad, "Aleman", 50);
			break;

	}
	return p_nacionalidad;
}


int buscar_owner(int mascota){

	if(bfs(
	return UNDEF;
}


int main(){
	int mascota = PECECITO;
	init_entidades();
	define_reglas();

	printf("%x\n", tabla[BRITANICO][CASA]);
	//printf("El duenio del pececito es %s\n", get_nacionalidad( buscar_owner( PECECITO ) ) );


	return 0;
}


