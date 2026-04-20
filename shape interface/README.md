Task_2 — Интерфейс Shape

##Краткое описание

Проект демонстрирует интерфейс Shape и три реализации: Circle, Rectangle, Triangle.
Заголовки в include, реализации в src.
Компилируется с C++20 через CMake.

##Структура проекта

CMakeLists.txt — сборка
main.cpp — точка входа
include/Shape.h, include/Circle.h, include/Rectangle.h, include/Triangle.h
src/Shape.cpp, src/Circle.cpp, src/Rectangle.cpp, src/Triangle.cpp

##Интерфейс и сигнатуры

// интерфейс в `include/Shape.h`
struct BoundingBoxDimensions { double width; double height; };

class Shape {
public:
virtual double square() = 0;
virtual BoundingBoxDimensions dimensions() = 0;
virtual std::string type() = 0;
virtual ~Shape() = default;
};

// функция, используемая в main
void printParams(Shape *shape); // сигнатура обязана быть именно такая

##Пример использования

Ввод:
Triangle
3 4 5
Ожидаемый вывод:
Type: Triangle
Square: 6
Width: 5
Height: 5

##Примечания
Все описания функций находятся в папке include, реализации в src.
Проект использует C++20 стандарт.
Функция printParams принимает Shape * и печатает type, square, width и height.