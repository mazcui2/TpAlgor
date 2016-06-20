#ifndef FORM_H_
#define FORM_H_

#include <string.h>
#include "InputText.h"
#include "InputCheckBox.h"
#include "Select.h"
#include "RadioButtonList.h"
#include "InputButton.h"

using std::string;
using UndavInputTextBox::TextBox;
using UndavInputCheckBox::CheckBox;
using UndavSelect::Select;
using UndavRadioButtonList::RadioButtonList;
using UndavInputButton::Button;

namespace UndavForm{
	struct Form;

	typedef void (*OnFormSubmitted)(Form* form);

	/*
	 * Precondicion: Ninguna
	 * Postcondicion: Obtiene una instancia valida de Form, que representa un formulario vacio de elementos.
	 * Parametros:
	 * 		@onSubmitted: Funcion que será invocada al invocar la primitiva Form::Submit si el formulario tiene un elemento Button
	 * 		@return: Instancia valida de Form, que representa  un formulario vacio
	 */
	Form* CreateForm(OnFormSubmitted onSubmitted);

	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Agrega un nuevo campo al formulario de tipo Input con @fieldName como nombre asociado.
	 * Si el input es de tipo SubmitButton no realiza ninguna accion. Para agregar un button submit se debe
	 * usar la primitiva AddSubmitButton.
	 * Parametros:
	 * 		@form: Instancia del formulario a la cual se desea agregar el nuevo campo
	 * 		@fieldName: Nombre del campo asociado al elemento del formulario html @input
	 * 		@input: Elemento de formulario html Input que se desea agregar como campo en @form
	 */
	void AddField(Form* form, string fieldName, Input* input);

	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Agrega un nuevo campo al formulario de tipo Select con @fieldName como nombre asociado
	 * al mismo.
	 * Parametros:
	 * 		@form: Instancia del formulario a la cual se desea agregar el nuevo campo
	 * 		@fieldName: Nombre del campo asociado al elemento del formulario html @checkBox
	 * 		@checkBox: Elemento de formulario html que se desea agregar como campo en @form
	 */
	void AddField(Form* form, string fieldName, Select* select);

	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Agrega un nuevo campo al formulario de tipo Select con @fieldName como nombre asociado
	 * al mismo.
	 * Parametros:
	 * 		@form: Instancia del formulario a la cual se desea agregar el nuevo campo
	 * 		@fieldName: Nombre del campo asociado al elemento del formulario html @radioButtons
	 * 		@radioButtons: Elemento de formulario html que se desea agregar como campo en @form
	 */
	void AddField(Form* form, string fieldName, RadioButtonList* radioButtons);

	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Agrega el elemento de formulario Html que representa el boton que permite confirmar el formulario.
	 * Un formulario solo puede tener un unico submit button por lo tanto si el formulario ya tenia un submit button
	 * lo reemplaza por @submitButton
	 * Parametros:
	 * 		@form: Instancia del formulario a la cual se desea agregar el submit button
	 * 		@submitButton: Button submit que se desea establecer al formulario
	 */
	void SetSubmitButton(Form* form, Button* submitButton);

	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Si el formulario posee un submit button invoca a la funcion indicada en la primitiva CreateForm pasandole
	 * como parametro @form. Si no posee un submit button no realiza accion alguna.
	 * Parametros:
	 * 		@form: Instancia del formulario a la cual se desea realizar la confirmacion (submit) de que fue completado
	 */
	void Submit(Form* form);

	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Obtiene la representacion Html del formulario con todos sus elementos.
	 * El orden de los elementos es el mismo en el cual fueron agregados. Como ultimo elemento debe estar
	 * el button submit del mismo.
	 * Se utiliza el string (etiqueta) <form> como comienzo del formulario y </form> como
	 * fin de formulario.
	 * Se utiliza el string (etiqueta) <label> como comienzo de nombre de campo y <label> como
	 * fin de nombre de campo.
	 * Para separar entre nombre de campo y campo se utiliza el string (etiqueta) </br>
	 * Para separar entre campos se utiliza dos strings (etiquetas) <br>.
	 *
	 * Parametros:
	 * 		@form: Instancia del formulario a la cual se desea obtener la representacion Html
	 * 		@return: La representacion HTML del formulario
	 *
	 * Ejemplos:
	 *  (1) Si al formulario se le agrego unicamente un field con el nombre "Correo electronico" y el input <input type='text' name='mail'>
	 *  se obtiene:
	 *  <form>
	 *  <label>Correo electronico</label>
	 *  </br>
	 *  <input type='text' name='mail'>
	 *  </form>
	 *
	 *  (2) Si se agregaron 2 campos y tiene el boton submit
	 *  <form>
	 *  <label>Nombre campo 1</label>
	 *  </br>
	 *  (Representacion HTML del elemento del campo 1)
	 *  </br>
	 *  </br>
	 *  <label>Nombre campo 1</label>
	 *  </br>
	 *  (Representacion HTML del elemento del campo 2)
	 *  </br>
	 *  </br>
	 *  (Representacion HTML del submit botton)
	 *  </form>
	 *
	 *  Nota para los dos ejemplos: No es necesario que respete las nuevas lineas '\n', pueden estar o pueden no estar.
	 */
	string GetHtmlText(Form* form);

	/*
	 * Precondicion: @form fue creado con la primitiva CreateForm
	 * Postcondicion: Obtiene un string que equivale a la concatenacion de la secuencia name=value separados por  el caracter &, donde name
	 * es el valor del atributo name del elemento y value es el valor del atributo value del elemento. Concatena todos los elementos de formulario, excepto
	 * el submit button del formulario.
	 * Parametros:
	 * 		@form: Instancia del formulario de la cual se desea obtener el string que lo representa
	 * 		@return: Representacion del formulario que permite enviarse en peticiones HTTP Post por query string
	 * 	Ejemplos:
	 *
	 * 	(1)Si el formulario solo tiene un input (de cualquier tipo): <input type="noImportaElTipo" name="email" value="ejemplo@gmail.com">
	 * 	Se obtiene: email=ejemplo@gmail
	 *
	 * 	(2)Si el formulario solo tiene un input (de cualquier tipo) el cual no tiene atributo name o esta vacio: <input type="noImportaElTipo" name="" value="ejemplo@gmail.com">
	 * 	Se obtiene un string vacio: email=ejemplo@gmail
	 *
	 * 	(3)Si el formulario solo tiene un input (de cualquier tipo) el cual tiene atributo name pero no tiene value o esta vacio el value: <input type="noImportaElTipo" name="email" value="">
	 * 	Se obtiene el siguiente string: email=
	 *
	 * 	(4)Si el formulairo solo tiene un select: <select name="mascota"><option value="perro">Tengo un perro</option><option value="gato">Tengo un gato</option><option selected value="canario">Tengo un canario</option></select>
	 * 	Se obtiene el siguiente string: mascota=canario
	 * 	Notar que  se obtiene el elemento seleccionado solamente. Si el select no tiene elemento seleccionado se obtiene un string vacio
	 *
	 * 	(5)Si el formulario solo tiene un radio button list: <input type="radio" name="subscripccion" value="diaria"> <input selected type="radio" name="subscripccion" value="semanal"> <input type="radio" name="subscripccion" value="quincenal"> <input type="radio" name="subscripccion" value="mensual">
	 * 	Se obtiene el siguiente string: subscripcion=semanal
	 * 	Notar que se obtiene el elemento seleccionado solamente. Si el radio button list no tiene elemento seleccionado se obtiene un string vacio
	 *
	 * 	(6) Si el formulario tiene  los elementos del ejemplo 1, 4 y 5 se obtiene el siguiente string: email=ejemplo@gmail&mascota=canario&subscripcion=semanal
	 *
	 */
	string Serialize(Form* form);

	/*
	 * Precondicion: @form fue construido con la primitiva CreateForm
	 * Postcondicion: Libera todos los recursos de @form
	 */
	void DestroyForm(Form* form);
}

#endif
