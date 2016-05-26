#ifndef SELECT_H_
#define SELECT_H_

#include <string>
#include "OptionItem.h"

using std::string;
using UndavOptionItem::OptionItem;

namespace UndavSelect{
	struct Select;

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de Select, que representa un lista
	 * desplegable de opciones vacia.
	 * Parametros:
	 * 		@name: Atributo que define el nombre del select
	 * 		@return: Instancia valida de Select
	 */
	Select* CreateSelect(string name);

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
	Select* CreateSelectFor(string name, char *options[], int optionsCount);

	/*
	 * Precondicion: @select fue creado por la primitiva CreateSelect o CreateSelectFor
	 * Postcondicion: Establece como seleccionado el numero de opcion del select indicado con @optionIndex. Si se encontraba
	 * otro elemento seleccionado, marca a ese elemento como no seleccionado puesto que solo puede estar seleccionado un elemento.
	 * Si el @optionIndex es superior al indice máximo de opciones, no realiza ninguna acción.
	 * Parametros:
	 * 		@select: Instancia de Select a la cual se desea modificar la opcion seleccionada
	 * 		@optionIndex: Indice que indica el número de opcion (comienza en cero) a seleccionar
	 */
	void SelectItem(Select* select, int optionIndex);

	/*
	 * Precondicion: @select fue creado por la primitiva CreateSelect o CreateSelectFor
	 * Postcondicion: Obtiene la opcion que se encuentra seleccionada. Si no hay ninguna opcion seleccionada
	 * devuelve NULL
	 * Parametros:
	 * 		@select: Instancia de Select de la cual se desea obtener la opcion seleccionada
	 * 		@return: Opcion que se encuentra seleccionada
	 */
	OptionItem* GetSelectedItem(Select* select);

	/*
	 * Precondicion: @select fue creado por la primitiva CreateSelect o CreateSelectFor
	 * Postcondicion: Si @newOption no se encuentra en @select, agrega @newOption. Si ya se encuentra
	 * en la lista no realiza ninguna acción.
	 * Parametros:
	 * 		@select: Instancia de Select a la cual se desea agregar @newOption
	 * 		@newOption: Opcion que se desea agregar
	 */
	void AddOption(Select* select, OptionItem* newOption);

	/*
	 * Precondicion: @select fue creado por la primitiva CreateSelect o CreateSelectFor
	 * Postcondicion: Quita el numero de opcion indicado en @optionIndex. Si @optionIndex no es valida
	 * no realiza ninguna accion
	 * Parametros:
	 * 		@select: Instancia de Select de la cual se desea quitar una opcion
	 * 		@optionIndex: Indice de la opcion que se dease quitar.
	 */
	void RemoveOption(Select* select, int optionIndex);

	/*
	 * Precondicion: @select fue creado por la primitiva CreateSelect o CreateSelectFor
	 * Postcondicion: Quita la opcion @option del select. Si @option no se encuentra en el select
	 * no realiza ninguna accion
	 * Parametros:
	 * 		@select: Instancia de Select de la cual se desea quitar una opcion
	 * 		@option: Opcion que se desea quitar del @select
	 */
	void RemoveOption(Select* select, OptionItem* option);

	/*
	 * Precondicion: @select fue creado por la primitiva CreateSelect o CreateSelectFor
	 * Postcondicion: Obtiene la representacion html del elemento @select
	 * Parametros:
	 * 		@select: Instancia de Select de la cual se desea obtener la representacion html
	 * 		@return:
	 * 		para un @select vacio con nombre "pais" se obtiene
	 * 		<select name="pais">
	 * 		</select>
	 *
	 * 		para un @select  con nombre "pais", con dos elementos y ninguno seleccionado se obtiene
	 *		<select name="pais">
	 *		<option value="arg">Argentina</option>
	 *		<option value="mex">Mexico</option>
	 *		</select>
	 *
	 *		para un @select  con nombre "pais", con dos elementos y el segundo seleccionado se obtiene
	 * 		<select name="pais">
	 *		<option value="arg">Argentina</option>
	 *		<option value="mex" selected>Mexico</option>
	 *		</select>
	 *
	 */
	string GetHtmlText(Select* select);

	/*
	 * Precondicion: @select fue creado por la primitiva CreateSelect o CreateSelectFor
	 * Postcondicion: Obtiene la cantidad de opciones que posee el @select
	 * Parametros:
	 * 		@select: Instancia de Select de la cual se desea obtener la representacion html
	 */
	int CountOptions(Select* select);

	/*
	 * Precondicion: @select fue creado por la primitiva CreateSelect o CreateSelectFor
	 * Postcondicion: Libera todos los recursos de @select
	 */
	void DestroySelect(Select* select);
}

#endif
