# Задание 1: Использование умного указателя

## Описание

Реализация классов `Dog` и `Toy` с использованием умного указателя `std::shared_ptr` для управления временем жизни игрушки.

## Структура проекта

. ├── include/ │ ├── Dog.h # Объявление класса Dog │ └── Toy.h # Объявление класса Toy ├── src/ │ ├── Dog.cpp # Реализация методов класса Dog │ └── Toy.cpp # Реализация методов класса Toy ├── main.cpp # Точка входа программы ├── CMakeLists.txt └── README.md

## Функциональность

### Класс Toy
- Хранит название игрушки
- При уничтожении выводит сообщение о том, что игрушка была брошена

### Класс Dog
- **`getToy(std::shared_ptr<Toy> toy)`** — собака подбирает игрушку
    - Если у собаки уже есть эта игрушка: выводит `I already have this toy`
    - Если игрушка у другой собаки: выводит `Another dog is playing with this toy`
    - Если игрушка свободна: собака подбирает её

- **`dropToy()`** — собака бросает игрушку
    - Если у собаки нет игрушки: выводит `Nothing to drop`
    - Игрушка становится доступной для других собак

## Пример использования

```cpp
auto toy = std::make_shared<Toy>("Ball");

Dog dog1, dog2;

dog1.getToy(toy);  // Собака подбирает игрушку
dog1.getToy(toy);  // "I already have this toy"
dog2.getToy(toy);  // "Another dog is playing with this toy"

dog1.dropToy();    // Собака бросает игрушку
dog2.getToy(toy);  // Теперь вторая собака может взять игрушку
dog2.dropToy();    // Вторая собака бросает игрушку
dog1.dropToy();    // "Nothing to drop"

## Ожидаемый вывод

I already have this toy
Another dog is playing with this toy
Nothing to drop
Toy Ball was dropped
