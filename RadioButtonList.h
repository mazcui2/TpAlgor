#ifndef RADIOBUTTONLIST_H_
#define RADIOBUTTONLIST_H_

#include <string>
#include "InputRadioButton.h"

using std::string;
using UndavInputRadio::RadioButton;

namespace UndavRadioButtonList{
	struct RadioButtonList;

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de RadioButtonList, que representa una lista de radio buttons donde
	 * todos los radio buttons tendran el valor de @name en el atributo name
	 * Parametros:
	 * 		@name: Atributo name que tendran todos los atributos que se agreguen a la lista
	 * 		@return: Instancia valida de RadioButtonList
	 */
	RadioButtonList* CreateRadioButtonList(string name);

	/*
	 * Precondicion: @radioButtonsCount contiene la cantidad de elementos de @radioButtons. Cada elemento de @radioButtons
	 * representa el valor de cada radio button
	 * Postcondicion: Obtiene una instancia valida de RadioButtonList,  que representa un lista
	 * de elementos radio buttons.
	 * Parametros:
	 * 		@name: Atributo que define el nombre de todos los radio buttons dentro de la lista
	 * 		@radioButtons: Valores de cada uno de los radio buttons a agregar en la lista
	 * 		@radioButtonsCount: Cantidad de radio buttons que tendra la lista
	 * 		@return: Instancia valida de RadioButtonList con los radio buttons cargados
	 */
	RadioButtonList* CreateRadioButtonListFor(string name, char *radioButtons[], int radioButtonsCount);

	/*
	 * Precondicion: @radioButtons fue creado por la primitiva CreateRadioButtonList o CreateRadioButtonListFor
	 * Postcondicion: Obtiene el radio button que se encuentra en la posicion @radioButtonIndex. Si el indice no es valido
	 * devuelve NULL
	 * Parametros:
	 * 		@radioButtons: Instancia de RadioButtonList de la cual se desea obtener un radio button
	 * 		@radioButtonIndex: Numero de indice del radio button que se desea obtener
	 * 		@return: Radio button que se desea obtener
	 */
	RadioButton* GetRadioButton(RadioButtonList* radioButtons, int radioButtonIndex);

	/*
	 * Precondicion: @radioButtons fue creado por la primitiva CreateRadioButtonList o CreateRadioButtonListFor
	 * Postcondicion: Obtiene el radio button que se encuentra seleccionado. Si no hay ninguna opcion seleccionada
	 * devuelve NULL
	 * Parametros:
	 * 		@radioButtons: Instancia de RadioButtonList de la cual se desea obtener la opcion seleccionada
	 * 		@return: Radio button que se encuentra seleccionado
	 */
	RadioButton* GetSelectedRadioButton(RadioButtonList* radioButtons);

	/*
	 * Precondicion: @radioButtons fue creado por la primitiva CreateRadioButtonList o CreateRadioButtonListFor
	 * Postcondicion: Si no existe en la lista ningun @newRadioButton con  el mismo valor, lo agrega en la lista.
	 * Si ya existe, reemplaza el elemento existente por @newRadioButton.
	 * Parametros:
	 * 		@radioButtons: Instancia de Select de la cual se desea obtener la opcion seleccionada
	 * 		@newRadioButton: Opcion que se encuentra seleccionada
	 */
	void AddRadioButton(RadioButtonList* radioButtons, RadioButton* newRadioButton);

	/*
	 * Precondicion: @radioButtons fue creado por la primitiva CreateRadioButtonList o CreateRadioButtonListFor
	 * Postcondicion: Quita el radio button de la lista que tiene como atributo el valor @value. Si no existe ningun
	 * radio button con ese valor, no realiza ninguna accion
	 * Parametros:
	 * 		@radioButtons: Instancia de RadioButtonList de la cual se desea quitar un radio button
	 * 		@value: Valor que determina el radio button que se desea quitar.
	 */
	void RemoveRadioButton(RadioButtonList* radioButtons, string value);

	/*
	 * Precondicion: @radioButtons fue creado por la primitiva CreateRadioButtonList o CreateRadioButtonListFor
	 * Postcondicion: Obtiene la cantidad de radio buttons que se encuentran en radioButtons
	 * Parametros:
	 * 		@radioButtons: Instancia de RadioButtonList de la cual se desea quitar un radio button
	 * 		@return: Cantidad de radio buttons presentes
	 */
	int Count(RadioButtonList* radioButtons);

	/*
	 * Precondicion: @radioButtons fue creado por la primitiva CreateRadioButtonList o CreateRadioButtonListFor
	 * Postcondicion: Libera todos los recursos de @radioButtons
	 */
	void DestroyRadioButtonList(RadioButtonList* radioButtons);
}

#endif
