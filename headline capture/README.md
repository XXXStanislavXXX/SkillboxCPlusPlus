HTML Page Fetcher
=================

## Описание

C++ приложение, которое получает HTML-страницу с httpbin.org/html и извлекает содержимое тега <h1> с 
использованием библиотеки CPR для HTTP-запросов.

## Структура проекта

project/
├── include/
│   └── html_parser.h      # Объявления функций
├── src/
│   ├── html_parser.cpp    # Реализация функций
│   └── main.cpp           # Точка входа программы
├── CMakeLists.txt         # Конфигурация сборки
└── README.md              # Этот файл

## Требования

CMake 3.14 или выше
Компилятор с поддержкой C++17
Интернет-соединение для загрузки зависимостей

## Зависимости

CPR - библиотека для HTTP-запросов на C++ 
(автоматически загружается CMake)

## Ожидаемый вывод:

Fetching HTML page from https://httpbin.org/html...
Page heading: Herman Melville - Moby-Dick

## Функциональность

fetch_html_page(const std::string& url)
Выполняет HTTP GET запрос с заголовком accept: text/html
Возвращает HTML-контент в виде строки
extract_tag_content(const std::string& html, const std::string& tag_name)
Извлекает текст между указанными HTML-тегами
Возвращает извлеченное содержимое или пустую строку, если тег не найден