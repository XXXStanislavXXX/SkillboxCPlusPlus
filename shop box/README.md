Shopping Cart System

Система управления корзиной покупок с учетом складских остатков.

##Описание

Консольное приложение на C++ для управления товарами на складе и корзиной покупок. При добавлении товара в корзину его количество списывается со склада, при удалении — возвращается обратно.

##Функциональность

Добавление товаров на склад
Просмотр остатков на складе
Добавление товаров в корзину
Удаление товаров из корзины
Просмотр содержимого корзины
Автоматическое управление складскими остатками

##Требования

Компилятор с поддержкой C++17 или выше
CMake 3.10+

##Сборка

mkdir build
cd build
cmake ..
cmake --build .

##Использование

Запустите программу и следуйте инструкциям:
Введите количество товаров для добавления на склад
Для каждого товара укажите артикул и количество

##Доступные команды

add — добавить товар в корзину
remove — удалить товар из корзины
show — показать содержимое корзины
stock — показать остатки на складе (введите * для всех товаров или конкретный артикул)
exit — выход из программы

##Пример работы

Enter product quantity: 2
Product article: A001
Quantity: 10
Product added successfully
Product article: A002
Quantity: 5
Product added successfully

Enter command (add/remove/show/stock/exit): add
Article: A001
Quantity: 3
Added 3 pcs. of product A001. Cart now contains: 3 pcs.

Enter command (add/remove/show/stock/exit): show
Cart contents:
Article: A001, Quantity: 3

Enter command (add/remove/show/stock/exit): stock
Enter article or * for all: A001
Product A001 - Stock quantity: 7 pcs.

##Структура проекта

Database.h/cpp — управление складом
ShoppingCart.h/cpp — управление корзиной
main.cpp — главный файл программы