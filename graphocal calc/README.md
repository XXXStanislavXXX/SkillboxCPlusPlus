# Калькулятор (Qt + C++)

Небольшое Qt-приложение — простая форма для ввода двух чисел и выполнения операций: сложение, 
вычитание, умножение, деление. Интерфейс генерируется `ui_calc.h` (AutoUic).

## Структура проекта
- `include/calc.h` — объявление класса `MainWindow` (слоты и `Q_OBJECT`).
- `src/calc.cpp` — реализация `MainWindow`.
- `src/main.cpp` — запуск `QApplication` и создание `MainWindow`.
- `ui/calc.ui` — файл интерфейса (если используется).
- `CMakeLists.txt` — настройки сборки с AutoUic.

## Требования
- Qt 6.x
- CMake с поддержкой AutoUic
- CLion (Windows) или другая среда/командная строка

## Быстрая сборка (Windows, CLion / командная строка)
1. Открыть проект в CLion либо из командной строки:
    - mkdir build && cd build
    - cmake .. -DCMAKE_PREFIX_PATH="путь_к_Qt"
    - cmake --build . --config Debug
2. Запустить получившийся исполняемый файл из `build`.

## Важные настройки CMake
Если AutoUic не находит `*.ui`, добавьте путь поиска UI в `CMakeLists.txt`:
```cmake
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui" "${CMAKE_CURRENT_SOURCE_DIR}/src")
