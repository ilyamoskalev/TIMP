/*!
 *\file
 *\brief Заголовочный файл с описанием класса
 
 *Данный файл содержит в себе определение
 класса структуры данных - односвязный список
 */

#pragma once

#include <iostream>

/*!
 *\brief Класс - односвязный список
 
 *Данный класс описывает методы структуры данных - односвязный список
 */

class list {
public:
    /*!
     *Конструктор класса по - умолчанию
     */
    
    list();

    /*!
     *Добавляет элемент в список
     *\param[in] index Индекс нового элемента
     *\param[in] data Значение нового элемента
     */
    
    void add(const int, const int);
    /*!
     *Удаляет элемент из списка
     *\param[in] index Индекс удаляемого элемента
     */
    
    void del(const int);
    /*!
     *Получает элемент списка
     *\param[in] index Индекс получаемого элемента
     */
    
    int get(const int);
    /*!
     *Деструктор класса. Очищает список.
     *\return Значение элемента в списке по индексу
     */
    
    ~list();
private:
    /*!
     *\brief Структура - узел
     
     *Данная структура хранит данные и
     указатель на следующий узел списка
     */
    
    struct node {
        node(const int data)
        :_data(data), _pnext(nullptr) {}

        int _data; /*!< Значение элемента */
        node *_pnext; /*!< Указатель на следующщий узел */
    };
    
    node *head_; /*!< Указатель на первый узел списка */
    node *cursor_; /*!< Курсор*/
};