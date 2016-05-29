#include "Select.h"

struct UndavSelect::Select
{
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
	 */
UndavSelect::Select* UndavSelect::CreateSelectFor(string name, char *options[], int optionsCount){

    Select* nuevoSelect = new Select;

    int iterationOption = 0;
    int iterationCharacter = 0;
    char coma = ',';
    bool firstField = false;
    bool secondField = false;
    OptionItem* auxOption;

    while (iterationOption<=optionsCount){

        iterationCharacter=0;
        bool firstField = true;
        bool secondField = false;
        string value = "";
        string text = "";

        while (options[iterationOption][iterationCharacter] != '\0'){

            if (firstField){
                if (options[iterationOption][iterationCharacter] == coma){
                    firstField = false;
                    secondField = true;
                }
                else{
                    value =  value + options[iterationOption][iterationCharacter];
                }
            }

            if (secondField){
                if (options[iterationOption][iterationCharacter] == '\0'){
                    secondField = false;
                }
                else{
                    text = text + options[iterationOption][iterationCharacter];
                }
            }
        }

        //VER MATI 1
        //EN LA ESTRUCTURA SELECT TENGO UN PUNTERO DE OPCIONES. LA IDEA ES IR ENCOLANDO TODAS LAS OPCIONES
        //CREADAS UNA DE TRAS DE LA OTRA A PARTIR DE ESTE PUNTERO PARA GENERAR LA ESTRUCTURA SELECT.
//        nuevoSelect->option = UndavOptionItem::addOptionToListOption(UndavOptionItem::CreateOptionItem(text,value),nuevoSelect->option);

        if (nuevoSelect->option == NULL)
        {
            nuevoSelect->option = UndavOptionItem::CreateOptionItem(text,value);
        }
        else
        {
            auxOption = nuevoSelect->option;
            while (auxOption -> next != NULL)
            {
                auxOption = auxOption -> next;
            }
            auxOption -> next = UndavOptionItem::CreateOptionItem(text,value);
        }

        iterationOption++;
    }
    nuevoSelect->name = name;
    return nuevoSelect;
}


	/*
	 * Precondicion: @select fue creado por la primitiva CreateSelect o CreateSelectFor
	 * Postcondicion: Establece como seleccionado el numero de opcion del select indicado con @optionIndex. Si se encontraba
	 * otro elemento seleccionado, marca a ese elemento como no seleccionado puesto que solo puede estar seleccionado un elemento.
	 * Si el @optionIndex es superior al indice máximo de opciones, no realiza ninguna acción.
	 * Parametros:
	 * 		@select: Instancia de Select a la cual se desea modificar la opcion seleccionada
	 * 		@optionIndex: Indice que indica el número de opcion (comienza en cero) a seleccionar
	 */
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
