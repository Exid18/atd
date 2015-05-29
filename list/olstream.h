#ifndef OLSTREAM_H_INCLUDED
#define OLSTREAM_H_INCLUDED

// Управление выводои списка на экран

#include <fstream>
#include <string>

void List::write(char space)
{
    //Вывести все элементы списка на экран

    for(List *it = First; it != NULL; it = it->Next)
    {
        //Поочередно выводим все элементы списка
        //через символ 'space'
        std::cout << it->x << space;
    }
}

void List::writeln(char space)
{
    //Вывести все элементы списка на экран

    for(List *it = First; it != NULL; it = it->Next)
    {
        //Поочередно выводим все элементы списка
        //через символ 'space'
        std::cout << it->x << space;
    }

    //Переводим курсор на слудующую строку
    std::cout << std::endl;
}

void List::write(List *left, List *right, char space)
{
    //Вывести на экран все элементы списка
    //от left до right

    for(List *it = left; it != right; it = it->Next)
    {
        std::cout << it->x << space;
    }
}

void List::writeln(List *left, List *right, char space)
{
    //Вывести на экран все элементы списка
    //от left до right
    for(List *it = left; it != right; it = it->Next)
    {
        std::cout << it->x << space;
    }

    //Перевести курсор на следующую строку
    std::cout << std::endl;
}

void List::writeinfile(char space)
{
    //Вывести все значения списка в файл

    //Запрашиваем имя файла
    std::cout << "Name falie: ";

    //Инициализируем переменую имени файла
    std::string namefile;

    //Водим имя файла до Enter
    std::getline(std::cin, namefile);

    //Инициализируем переменую файла
    std::ofstream f;

    //Открываем файл на запись
    f.open(namefile.c_str());

    //Поочередно записываем значения
    for(List *it = First; it != NULL; it = it->Next)
    {
        f << it->x << space;
    }

    //Закрываем файл
    f.close();
}

#endif // OLSTREAM_H_INCLUDED
