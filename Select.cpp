/*#include "Select.h"

struct UndavSelect::Select{
    string name;
    UndavOptionItem::OptionItem *option;
};

UndavSelect::Select* UndavSelect::CreateSelect(string name){
    Select* nuevoSelect = new Select;
    nuevoSelect->name = name;

    return nuevoSelect;
}

	/*
	 * Precondicion: @optionsCount contiene la cantidad de elementos de @options. Cada elemento de @options
	 * esta en formato CSV (campos separados por coma), donde hay dos campos. El primer campo es el valor y el
	 * segundo campo es el texto.
	 * Postcondicion: Obtiene una instancia valida de Select,  que representa un lista
	 * desplegable de opciones donde cada opcion es un elemento de  @options.
	 * Parametros:
	 * 		@name: Atributo que define el nombre del select
	 * 		@options: Opciones que se desea agregar al Select
	 * 		@optionsCount: Cantidad de opciones que se desea agregar al Select
	 * 		@return: Instancia valida de Select con las opciones cargadas
	 *
UndavSelect::Select* UndavSelect::CreateSelectFor(string name, char *options[], int optionsCount){

    int counterOptionChar = 0;

    Select* nuevoSelect = new Select;
    nuevoSelect->name = name;

    //Ahora vamos a crearle los options
    while(counterOptionChar < options.length) {
        UndavOptionItem::OptionItem option = ParseOptionItem(options, counterOptionChar);

        if (nuevoSelect->option == NULL)
        {
            nuevoSelect->option = option;
        }
        else
        {
            auxOption = nuevoSelect->option;
            while (auxOption ->next != NULL)
            {
                auxOption = auxOption -> next;
            }
            auxOption -> next = option;
        }

    }

    return nuevoSelect;
}

UndavOptionItem::OptionItem ParseOptionItem(char *options[], int &counterOptionChar){
    bool loadedValue;
    string value, text;
    char coma = ',';

    //no tiene que ser fin de cadena ni tiene que ser la segunda coma (se da cuenta que es la segunda coma por que ya cargo el value que es el primer parámetro del csv)
    while((options[counterOptionChar] != '\0') && (!loadedValue || options[counterOptionChar] != coma))
    {
        if(options[counterOptionChar] != coma){
            loadedValue = true;
        }
        else{
            if(!loadedValue){
                value = value + options[counterOptionChar];
            }
            else{
                text = text + options[counterOptionChar];
            }
        }
        counterOptionChar++;
    }

    return UndavOptionItem::CreateOptionItem(text,value);
}


	/*
	 * Precondicion: @select fue creado por la primitiva CreateSelect o CreateSelectFor
	 * Postcondicion: Establece como seleccionado el numero de opcion del select indicado con @optionIndex. Si se encontraba
	 * otro elemento seleccionado, marca a ese elemento como no seleccionado puesto que solo puede estar seleccionado un elemento.
	 * Si el @optionIndex es superior al indice máximo de opciones, no realiza ninguna acción.
	 * Parametros:
	 * 		@select: Instancia de Select a la cual se desea modificar la opcion seleccionada
	 * 		@optionIndex: Indice que indica el número de opcion (comienza en cero) a seleccionar
	 *
void UndavSelect::SelectItem(Select* select, int optionIndex){
    //VER MATI 2
    //LA IDEA ES RECORRER TODA LA LISTA DE OPCIONES PRIMERO. SI EL optionIndex ES MAYOR A LA CANTIDAD DE
    //OPCIONES QUE TENGO CARGADA EN MI LISTA NO TOMO NINGUNA ACCION. CASO CONTRATO SI HAY ACCION
    // SELECCCIONO LA OPCION QUE COINCIDE CON optionIndex Y DESSELECCIONO EL RESTO.
    int iteration = 0;
    OptionItem* auxOption = select->option;
    bool noAction;

    while (auxOption != NULL && iteration<=optionIndex){
        auxOption = auxOption->next;
    }

    if (iteration>optionIndex){
        noAction = true;
    }

    if (!noAction){
        auxOption = select->option;
        while (auxOption != NULL && iteration<=optionIndex){
            if (iteration==optionIndex){
                void UndavSelect::Select(auxOption);
            }
            else{
                void UndavSelect::UnSelect(auxOption);
            }
            auxOption = auxOption->next;
        }
    }
}
*/
