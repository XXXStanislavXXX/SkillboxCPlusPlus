# Makefile для HTML редактора с Qt6

# Переменные
CXX = C:/Program Files/JetBrains/CLion 2025.2.3/bin/mingw/bin/g++.exe
MOC = D:/Qt/6.10.2/mingw_64/libexec/moc.exe
RM = rm -f

# Флаги компиляции
QT_PATH = D:/Qt/6.10.2/mingw_64
INCLUDE_FLAGS = -I$(QT_PATH)/include \
                -I$(QT_PATH)/include/QtCore \
                -I$(QT_PATH)/include/QtGui \
                -I$(QT_PATH)/include/QtWidgets \
                -I.

LIB_FLAGS = -L$(QT_PATH)/lib \
            -lQt6Core \
            -lQt6Gui \
            -lQt6Widgets

CXXFLAGS = -std=c++17 -fPIC $(INCLUDE_FLAGS)

# Целевой файл
TARGET = HTML_redactor.exe

# Исходные файлы
SOURCES = main.cpp
MOC_SOURCES = main_moc.cpp
OBJECTS = main.o main_moc.o

# Правила
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LIB_FLAGS)

main_moc.cpp: main.cpp
	$(MOC) main.cpp -o main_moc.cpp

main.o: main.cpp main_moc.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

main_moc.o: main_moc.cpp
	$(CXX) $(CXXFLAGS) -c main_moc.cpp -o $@

clean:
	$(RM) $(OBJECTS) $(MOC_SOURCES) $(TARGET)

.PHONY: all clean

