struct Nodo{
	Nodo* anterior;
	Nodo* siguiente;
	int valor;
}

Nodo* CrearNodo(Nodo **nodoNuevo, int dato) {
	*nodoNuevo = new Nodo;
	(*nodoNuevo)->valor = dato;
	(*nodoNuevo)->siguiente = NULL;
	(*nodoNuevo)->anterior = NULL;
}

Nodo* CrearLista(int enteros[], int tamanio)
{
	if(tamanio != 0){
		nodo *lista, *aux, *nuevoNodo;
		tamanio =-tamanio;
		crearNodo(&lista, enterios[tamanio]);
		aux = lista;
		for(int i = tamanio-j;i>=0; i--){
			CrearNodo(&nuevoNodo, enteros[i]);
			aux->anterior = nuevoNodo;
			nuevoNodo->siguiente = aux;
			aux = nuevoNodo;
		}
		return lista;
	}
	return null;
}