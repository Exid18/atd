#ifndef ILSTREAM_H_INCLUDED
#define ILSTREAM_H_INCLUDED

// Управление вводом списка

void List::pushBack(const int _x)
{
    //Добавить в конец списка

    //Проверяем, пустой ли список
    if (First == NULL)
    {
        //Если пустой

        //Выделяем память под новый элемент
        Last       = new List;

        //Записываем значение
        Last->x    = _x;

        //Обнуляем указатель на следующий элемент
        Last->Next = NULL;

        //Сохраняем адрес первого элемента
        First      = Last;
    }
    else
    {
        //Есди не пустой

        //Выделяем память под новый элемент
        Last->Next = new List;

        //Переходим к следующему элементу
        Last       = Last->Next;

        //Сохраняем значение
        Last->x    = _x;

        //Обнуляем указатель на следующий элемент
        Last->Next = NULL;
    }

    //Увеличиваем размер списка на 1
    ++ListSize;
}

#endif // ILSTREAM_H_INCLUDED
