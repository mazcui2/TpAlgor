#include <string>
#include "Select.h"
#include "OptionItem.h"

using namespace std;
using namespace UndavSelect;

const int TopeCadena = 100;

struct Options {
    UndavOptionItem::OptionItem* optionItem;
    Options* siguiente;
};

struct UndavSelect::Select {
    string name;
    Options* options;
    int cantidadOptions;
};

Options* CreateOptions() {
    Options* nuevoOptions = new Options;
    nuevoOptions->siguiente=NULL;
    return nuevoOptions;
}

UndavSelect::Select* UndavSelect::CreateSelect(string name) {
    Select* nuevoSelect = new Select;
    nuevoSelect->name = name;
    nuevoSelect->options = CreateOptions();

    return nuevoSelect;
}

Options* ParsearCadenaOptions(char options[]) {
    Options* nuevoOptions = CreateOptions();
    char separador = ',';
    char finCadena = '\0';
    int indice = 0;
    string value,text;

    while (options[indice] != separador) {
        value = value + options[indice];
        indice++;
    }
    indice++;
    while (options[indice] != finCadena) {
        text = text + options[indice];
        indice++;
    }
    nuevoOptions->optionItem=UndavOptionItem::CreateOptionItem(text,value);
    return nuevoOptions;
}

UndavSelect::Select* UndavSelect::CreateSelectFor(string name, char *options[], int optionsCount) {
    Select* nuevoSelect = CreateSelect(name);
    cout<<1<<endl;
    if (optionsCount > 0) {
        Options* nuevoOptions = ParsearCadenaOptions(options[0]);
        nuevoSelect->cantidadOptions = optionsCount;
        nuevoSelect->name = name;
        nuevoSelect->options = nuevoOptions;
        if (optionsCount > 1) {
            for (int i = 1; i < optionsCount; i++) {
                nuevoOptions = ParsearCadenaOptions(options[i]);
                nuevoOptions->siguiente = nuevoSelect->options;
                nuevoSelect->options = nuevoOptions;
            }
        }
    }
    return nuevoSelect;
}

void UndavSelect::SelectItem(Select* select, int optionIndex) {
    Options* auxiliarOptions = select->options;
    int contadorOptions = 1;
    if (optionIndex < select->cantidadOptions) {
        while (auxiliarOptions->siguiente != NULL) {
            if (contadorOptions != optionIndex) {
                UndavOptionItem::Unselect(auxiliarOptions->optionItem);
            } else {
                UndavOptionItem::Select(auxiliarOptions->optionItem);
            }
            auxiliarOptions = auxiliarOptions->siguiente;
            contadorOptions++;
        }
    }

}

UndavOptionItem::OptionItem* UndavSelect::GetSelectedItem(Select* select) {
    Options* auxiliarOptions = select->options;
    while (auxiliarOptions->siguiente != NULL && !UndavOptionItem::IsSelected(auxiliarOptions->optionItem)) {
        auxiliarOptions = auxiliarOptions->siguiente;
    }
    if (UndavOptionItem::IsSelected(auxiliarOptions->optionItem)) {
        return auxiliarOptions->optionItem;
    } else {
        return NULL;
    }
}

void UndavSelect::AddOption(Select* select, UndavOptionItem::OptionItem* newOption) {
    Options* auxiliarOptions = select->options;
    while (UndavOptionItem::GetText(auxiliarOptions->optionItem) != UndavOptionItem::GetText(newOption) &&
            UndavOptionItem::GetValue(auxiliarOptions->optionItem) != UndavOptionItem::GetValue(newOption) &&
            auxiliarOptions->siguiente != NULL ) {

        auxiliarOptions = auxiliarOptions->siguiente;
    }
    if (auxiliarOptions->siguiente == NULL) {
        Options* nuevoOptions = CreateOptions();
        nuevoOptions->optionItem = newOption;
        nuevoOptions->siguiente = NULL;
        auxiliarOptions->siguiente = nuevoOptions;
        select->cantidadOptions++;
    }
}

void DestroyOptions(Options* options) {
    UndavOptionItem::DestroyOptionItem(options->optionItem);
    delete options;
}

void UndavSelect::RemoveOption(Select* select, int optionIndex) {
    if (optionIndex < select->cantidadOptions) {
        Options* auxiliarOptions = select->options;
        int indiceOptions = 1;
        while (indiceOptions + 1 != optionIndex) {
            auxiliarOptions = auxiliarOptions->siguiente;
            indiceOptions++;
        }
        Options* optionsDestroy = auxiliarOptions->siguiente;
        auxiliarOptions->siguiente = auxiliarOptions->siguiente->siguiente;
        DestroyOptions(optionsDestroy);
        select->cantidadOptions--;
    }

}

void UndavSelect::RemoveOption(Select* select, UndavOptionItem::OptionItem* option) {
    Options* auxiliarOptionsActual = select->options;
    Options* auxiliarOptionsAnterior= select->options;
    while (auxiliarOptionsActual->optionItem != option) {
        auxiliarOptionsAnterior=auxiliarOptionsActual;
        auxiliarOptionsActual = auxiliarOptionsActual->siguiente;
    }
    auxiliarOptionsAnterior=auxiliarOptionsActual->siguiente;
    DestroyOptions(auxiliarOptionsActual);
}

string UndavSelect::GetHtmlText(Select* select) {
    Options* auxiliarOptions = select->options;
    string htmlText;
    htmlText = "<select name=\"" + select->name + "\">\n";
    while (auxiliarOptions != NULL) {
        htmlText = htmlText + UndavOptionItem::GetHtmlText(auxiliarOptions->optionItem) + "\n";
        auxiliarOptions = auxiliarOptions->siguiente;
    }
    htmlText = htmlText + "</select>\n";
    return htmlText;
}

int UndavSelect::CountOptions(Select* select) {
    return select->cantidadOptions;
}

void UndavSelect::DestroySelect(Select* select) {
    Options* auxiliarOptions = select->options;
    Options* destroyOptions;
    while (auxiliarOptions->siguiente != NULL) {
        destroyOptions = auxiliarOptions->siguiente;
        auxiliarOptions->siguiente = auxiliarOptions->siguiente->siguiente;
        DestroyOptions(destroyOptions);
    }
    DestroyOptions(auxiliarOptions);
    delete select;
}
