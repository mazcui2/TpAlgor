#ifndef INPUT_H_
#define INPUT_H_

#include <string>
using std::string;

namespace UndavInput{
	struct Input;

	enum InputType { TextBox, RadioButton, CheckBox, SubmitButton};

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de Input, que representa el tipo de input especificado en @type.
	 * Esta instancia tiene valores vacios en los atributos: Value y Name
	 * Esta instancia esta lista para ser utilizado por las primitivas del TDA UndavInput.
	 * Parametros:
	 * 		@type: Tipo de input que representa la instancia obtenida
	 * 		@return: Instancia valida de Input
	 */
	Input* CreateInput(InputType type);

	/*
	 * Precondicion: @input fue creado por la primitiva CreateInput
	 * Postcondicion: Devuelve el tipo de input que representa @input
	 * Parametros:
	 * 		@input: Instancia de Input de la cual se desea consultar su tipo
	 * 		@return: Tipo de Input
	 */
	InputType GetType(Input* input);

	/*
	 * Precondicion: @input fue creado por la primitiva CreateInput
	 * Postcondicion: Cambia el valor del atributo "value" de @input por @value
	 * Parametros:
	 * 		@input: Instancia de Input a la cual se desea modificar su atributo valor
	 * 		@value: Valor que se desea asignar al atributo "value" de @input
	 */
	void SetValue(Input* input, string value);

	/*
	 * Precondicion: @input fue creado por la primitiva CreateInput
	 * Postcondicion: Obtiene el valor del atributo "value" de @input
	 * Parametros:
	 * 		@input: Instancia de Input a la cual se desea consultar su atributo valor
	 * 		@return: Valor que tiene el atributo "value" de @input
	 */
	string GetValue(Input* input);

	/*
	 * Precondicion: @input fue creado por la primitiva CreateInput
	 * Postcondicion: Cambia el valor del atributo "name" de @input por @name
	 * Parametros:
	 * 		@input: Instancia de Input a la cual se desea modificar su atributo name
	 * 		@value: Valor que se desea asignar al atributo "name" de @input
	 */
	void SetName(Input* input, string name);

	/*
	 * Precondicion: @input fue creado por la primitiva CreateInput
	 * Postcondicion: Obtiene el valor del atributo "name" de @input
	 * Parametros:
	 * 		@input: Instancia de Input a la cual se desea consultar su atributo name
	 * 		@return: Valor que tiene el atributo "name" de @input
	 */
	string GetName(Input* input);

	/*
	 * Precondicion: @input fue creado por la primitiva CreateTextBox
	 * Postcondicion: Obtiene la representacion html del elemento @input
	 * Parametros:
	 * 		@input: Instancia de Input de la cual se desea obtener la representacion html
	 * 		@return:
	 * 		para un @input de tipo TextBox con nombre vacio y sin un valor por defecto obtiene el siguiente string
	 * 		<input type='text'>
	 * 		para un textbox con nombre "pais" y con un defaultValue "Mexico"
	 * 		<input type='text' name='pais' value='Mexico'>
	 *
	 *		para un input de tipo SubmitButton con un value igual a "Suscribirme!"
	 *		<input type='submit' value='Suscribirme!'>
	 *
	 *		para un input de tipo RadioButton
	 *		<input type='radio'>
	 *
	 *		para un input de tipo CheckBox
	 *		<input type='checkbox'>
	 */
	string GetHtmlText(Input* input);

	/*
	 * Precondicion: @input fue construido con la primitiva CreateInput
	 * Postcondicion: Libera todos los recursos de @input
	 */
	void DestroyInput(Input* input);
}

#endif
