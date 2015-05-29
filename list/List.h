#ifndef LIST_H
#define LIST_H

// Реализация односвязного списка

#include <iostream>

class List
{
private:
    int x;              //Хранимое значение

    size_t ListSize;    //Размер списка

    List *Last;         //Указатель на последний элемент
    List *Next;         //Указатель на следующий элемент
    List *First;        //Указатель на первый элемент

    void Swap(List *a, List *b); //Функция обмена значений
public:

    List();     //Конструктор
    ~List();    //Диструктор


    /* --- Start Input List stream --- */

    void pushBack(const int _x);    //Добавить в конец

    /* --- End Input List stream --- */

    /* --- Start List function ---*/

    size_t Size();                //Размер списка
    List *first();                //Вернуть указатель на первый элемент
    List *last();                 //Вернуть указатель на последний элемент
    List *indexIter(size_t N);    //Указатель на N-ый элемент
    int index(size_t N);          //Вернуть N элементы от начала списка
    void Sort();                  //Сортировка списка
    void RemoveNode(size_t N);    //Удаление узла с индексом N
    bool Emty();                  //True, если массив пустой

    /* --- End List function ---*/

    /* --- Start Output List Stream --- */

    void write(char space);     //Вывести список без перевода на следующую строку
    void writeln(char space);   //Вывести список с переводом на следующую строку
    void write(List *left, List *right, char space);    //Вывести на экран все элементы списка, от left до right
    void writeln(List *left, List *right, char space);  //Вывести на экран все элементы списка, от left до right
    void writeinfile(char space);   //Вывести все значения списка в файл

    /* --- End Output List Stream --- */
};

#endif // LIST_H
