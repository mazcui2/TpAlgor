#ifndef OPTIONITEM_H_
#define OPTIONITEM_H_

#include <string>
using std::string;

namespace UndavOptionItem{
	struct OptionItem;

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de OptionItem, que representa una opcion seleccionable de
	 * un elemento Select. El elemento creado se encuentra no seleccionado por defecto.
	 * Parametros:
	 * 		@text: Texto que describe la opcion
	 * 		@value: Valor asociado a la opcion
	 * 		@return: Instancia valida de OptionItem
	 */
	OptionItem* CreateOptionItem(string text, string value);

	/*
	 * Precondicion: @option fue creado por la primitiva CreateOptionItem
	 * Postcondicion: Establece como seleccionada la opcion @option
	 * Parametros:
	 * 		@option: Instancia de OptionItem que se desea seleccionar
	 */
	void Select(OptionItem* option);

	/*
	 * Precondicion: @option fue creado por la primitiva CreateOptionItem
	 * Postcondicion: Establece como no seleccionada la opcion @option.
	 * Parametros:
	 * 		@option: Instancia de OptionItem que se desea establecer como no seleccionada
	 */
	void Unselect(OptionItem* option);

	/*
	 * Precondicion: @option fue creado por la primitiva CreateOptionItem
	 * Postcondicion: Devuelve true si @option se encunetra seleccionada. Caso contrario devuelve false.
	 * Parametros:
	 * 		@option: Instancia de OptionItem que se desea establecer como no seleccionada
	 */
	bool IsSelected(OptionItem* option);

	/*
	 * Precondicion: @option fue creado por la primitiva CreateOptionItem
	 * Postcondicion: Devuelve el texto de la opcion.
	 * Parametros:
	 * 		@option: Instancia de OptionItem de la cual se desea obtener el texto
	 * 		@return: Texto de la opcion
	 */
	string GetText(OptionItem* option);

	/*
	 * Precondicion: @option fue creado por la primitiva CreateOptionItem
	 * Postcondicion: Cambia el valor del texto de la opcion por @text
	 * Parametros:
	 * 		@option: Instancia de OptionItem a la cual se desea modificar su texto
	 * 		@text: Valor que se desea asignar como texto de @option
	 */
	void SetText(OptionItem* option, string text);

	/*
	 * Precondicion: @option fue creado por la primitiva CreateOptionItem
	 * Postcondicion: Devuelve el texto de la opcion.
	 * Parametros:
	 * 		@option: Instancia de OptionItem de la cual se desea obtener el texto
	 * 		@return: Texto de la opcion
	 */
	string GetValue(OptionItem* option);

	/*
	 * Precondicion: @option fue creado por la primitiva CreateOptionItem
	 * Postcondicion: Cambia el valor asociado a la opcion por @value
	 * Parametros:
	 * 		@option: Instancia de OptionItem a la cual se desea modificar su valor asociado
	 * 		@value: Valor que se desea establecer para @option
	 */
	void SetValue(OptionItem* option, string value);

	/*
	 * Precondicion: @OptionItem fue creado por la primitiva CreateOptionItem
	 * Postcondicion: Obtiene la representacion html del elemento @option
	 * Parametros:
	 * 		@option: Instancia de OptionItem de la cual se desea obtener la representacion html
	 * 		@return:
	 * 		para un @option con value "mex" y text "Mexico" que no esta seleccionado se obtiene
	 * 		<option value="mex">Mexico</option>
	 *
	 * 		para un @option con value "mex" y text "Mexico" que esta seleccionado se obtiene
	 * 		<option value="mex" selected>Mexico</option>
	 *
	 */
	string GetHtmlText(OptionItem* option);

	/*
	 * Precondicion: @item fue construido con la primitiva CreateOptionItem
	 * Postcondicion: Libera todos los recursos de @item
	 */
	void DestroyOptionItem(OptionItem* item);
}

#endif
