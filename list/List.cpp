// Функции работы с классом списка

#include "List.h"       //Класс List

#include "ilstream.h"   //Функции ввода
#include "olstream.h"   //Функции вывода

List::List()
{
    //Конструктор списка

    //Обнуляем значения
    ListSize = x = 0;

    //Обнуляем указатели
    Last = First = Next = NULL;
}

List::~List()
{
    //Диструктор

    //Удаляем указатели
    delete First, Next, Last;
}

size_t List::Size()
{
    //Функция возвращает размер стека
    return ListSize;
}

List *List::first()
{
    //Вернуть указатель на первый элемент
    return First;
}

List *List::last()
{
    //Вернуть указатель на последний элемент
    return Last;
}

int List::index(size_t N)
{
    //Функция возвращает значение N-ого
    //узла от начала списка

    //Проверяем, находится ли индекс
    //в допустимых приделах перделах
    if (N >= 0 && N < ListSize)
    {
        //Если находится в пределе списка

        //Создаем временный список
        List *it = First;

        //Ищем необходимый элемент
        while (it != NULL && (N > 0))
        {
            it = it->Next;
            --N;
        }

        //Возвращаем найленное значение
        return it->x;
    }
    else
    {
        //Если индекс находился
        //за пределами списка
        //возвращаем нуль
        return 0;
    }
}

List *List::indexIter(size_t N)
{
    //Функция возвращает указатель
    //на N-ый элемент

    //Проверяем, находится ли индекс
    //в допустимых приделах перделах
    if (N >= 0 && N < ListSize)
    {
        //Если находится в пределе списка

        //Создаем временный список
        List *it = First;

        //Ищем необходимый элемент
        while (it != NULL && (N > 0))
        {
            it = it->Next;
            --N;
        }

        //Возвращаем найленное значение
        return it;
    }
    else
    {
        //Если индекс находился
        //за пределами списка
        //возвращаем нуль
        return NULL;
    }
}

void List::Swap(List *a, List *b)
{
    //Обменять значения узлов списка
    int c    = a->x;
        a->x = b->x;
        b->x = c;
}

void List::Sort()
{
    /* Функция сортировки односвязного списка
     *
     * В качесвте алгоритма сортировки используется -
     * сортировка пузырьком
     */


    for(size_t i = 0; i < ListSize; ++i)
    {
        for(size_t j = i + 1; j < ListSize; ++j)
        {
            List *a = indexIter(i);
            List *b = indexIter(j);

            if (a->x > b->x)
            {
                Swap(a, b);
            }
        }
    }
}

void List::RemoveNode(size_t N)
{
    //Удаление из списка элемента с индексом N

    if (N >= 0 && N < ListSize)
    {
        List *it = First;
        size_t s = ListSize;

        for(size_t i = 0 ; i < s; it = it->Next, ++i)
        {
            if (i != N)
            {
                pushBack(it->x);
            }
        }

        First = it;
    }
}

bool List::Emty()
{
    /* Проверка. Пустой ли список?
     * return (List.Empty() ? true:false)
     */
    return First;
}
