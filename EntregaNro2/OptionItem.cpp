#include "OptionItem.h"
#include<iostream>

struct UndavOptionItem::OptionItem{
    string text;
    string value;
    bool isSelected;
};

UndavOptionItem::OptionItem* UndavOptionItem::CreateOptionItem(string text, string value){
    OptionItem* nuevoOptionItem = new OptionItem;
    nuevoOptionItem->text = text;
    nuevoOptionItem->value = value;
    nuevoOptionItem->isSelected = false;
    return nuevoOptionItem;
}


void UndavOptionItem::Select(OptionItem* option){
    option->isSelected = true;
}

void UndavOptionItem::Unselect(OptionItem* option){
    option->isSelected = false;
}

bool UndavOptionItem::IsSelected(OptionItem* option){
    return (option->isSelected);
}

string UndavOptionItem::GetText(OptionItem* option){
    return option->text;
}

void UndavOptionItem::SetText(OptionItem* option, string text){
    option->text = text;
}

string UndavOptionItem::GetValue(OptionItem* option){
    return option->value;
}

void UndavOptionItem::SetValue(OptionItem* option, string value){
    option->value = value;
}

string UndavOptionItem::GetHtmlText(OptionItem* option){
    string html;

    if (option->isSelected)
        html = "<option value="+option->value+" selected>"+option->text+"</option>";
    else
        html = "<option value="+option->value+">"+option->text+"</option>";

    return html;
}

void UndavOptionItem::DestroyOptionItem(OptionItem* item){
    delete item;
}
