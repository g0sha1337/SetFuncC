# Имя компилятора
CC = gcc

# Опции компиляции, например -Wall для вывода предупреждений
CFLAGS = -Wall

# Имя исполняемого файла
EXECUTABLE = run

# Список .c файлов
SOURCES = $(wildcard *.c)

# Преобразование .c файлов в .o файлы
OBJECTS = $(SOURCES:.c=.o)

# Правило по умолчанию
all: $(EXECUTABLE)

# Как собрать конечное приложение
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

# Компиляция .c файлов в .o файлы
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Задача по очистке проекта от объектных и исполняемых файлов
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Указание фиктивных целей
.PHONY: all clean
