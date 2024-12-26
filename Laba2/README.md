# Лабораторная работа №2

## Задание

Необходимо спроектировать класс, реализующий хранение данных, связанных с экземпляром класса в динамической памяти. Это может быть, например представление целых чисел, для которых помимо значения типа `int` хранится строковое представление числа (22 и «двадцать два»). Пример условен. 

Для данного класса необходимо реализовать все необходимые конструкторы, включая конструкторы копирования и перемещения, деструктор. Все конструкторы и деструктор должны «сообщать» о своём вызове. `std::cout << “Copy constructor” << std::endl;` то же относится и к перегрузке операции присваивания (два варианта: без перемещения и с перемещением). 

Определение класса должно быть помещено в заголовочный файл (.hpp), реализация методов в отдельном файле .cpp.

Написать программу (ещё один модуль cpp) осуществляющую работу с экземплярами разработанного класса, которая должна демонстрировать:

* создание статических и динамических экземпляра класса, стандартного вектора в стиле Си, написать функцию для обработки данного вектора;
* передача экземпляров класса в функцию, и возврат экземпляра из функции; включая вариант с передачей и возвратом значений типа ссылки на класс;
* продемонстрировать работу с разработанным классом, создавая вектора и списки экземпляров класса, используя стандартные классы vector и list длиной от 5 до 10.

Проанализировать процессы создания и удаления экземпляров класса для различных примеров. Необходимо получить вывод от всех конструкторов, деструктора и перегруженных операций присваивания.

## Решение
Решение представлено в файле [main.cpp](main.cpp)

## Пример работы

Результат запуска [main.cpp](main.cpp)

```
Default Constructor
Transform Constructor with 1230000000000
Transform Constructor with 1000000000000000
Default Constructor
Transform Constructor with 330000000000
Transform Constructor with 12321
Move Constructor with 12321
12321
Copy Constructor with 1000000000000000
Plus to 1000000000000000
Move Constructor with 2000000000000000
Destructor
Assign Operator with other
Destructor
Assign Operator with string 555
555
1230000000000
1000000000000000
2000000000000000
Transform Constructor with 333
333
Default Constructor
Default Constructor
Default Constructor
Assign Operator with string 0
Assign Operator with string 1
Assign Operator with string 2
1
Copy Constructor with 1230000000000
Copy Constructor with 555
Default Constructor
Copy Constructor with 555
Plus to 555
Move Constructor with 1230000000555
Destructor
Assign Operator with other
Destructor
Destructor
Destructor
1230000000555
Destructor
Assign Operator with string 5
5
Default Constructor
Default Constructor
Default Constructor
Default Constructor
Default Constructor
Default Constructor
Default Constructor
Default Constructor
Default Constructor
Default Constructor
Copy Constructor with 0
Assign Operator with string 41
41
Destructor
Copy Constructor with 0
Assign Operator with string 467
467
Destructor
Copy Constructor with 0
Assign Operator with string 334
334
Destructor
Copy Constructor with 0
Assign Operator with string 500
500
Destructor
Copy Constructor with 0
Assign Operator with string 169
169
Destructor
Copy Constructor with 0
Assign Operator with string 50224
50224
Destructor
Copy Constructor with 0
Assign Operator with string 50478
50478
Destructor
Copy Constructor with 0
Assign Operator with string 50358
50358
Destructor
Copy Constructor with 0
Assign Operator with string 50462
50462
Destructor
Copy Constructor with 0
Assign Operator with string 50464
50464
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
```

## Выводы

* Стековая аллокация является более эффективной и быстрой, но ограничивает время жизни объектов. Они автоматически освобождаются по выходу из своей области видимости.
* Динамическая аллокация предоставляет более гибкие возможности, так как позволяет создавать объекты, время жизни которых не привязано к области видимости, но требует ручного управления памятью и может привести к утечкам, если не будет освобождена.
* Использование std::vector и std::list требует дополнительных затрат на управление памятью (как по выделению, так и по перемещению при изменении размера). Векторы обеспечивают сравнительно более быстрые операции добавления и доступа, но могут производить дополнительные копии при изменении размера.
