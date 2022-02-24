# Class-Rectangle

1. Разработать класс, реализующий представление производной фигуры, как цельного объекта.
Продумать необходимый набор полей, полностью описывающий объект, т.е. параметров, задающих фигуру в общем виде. При этом учитывать возможность смещения фигуры относительно центра координат, а возможность поворота (наклона) можно игнорировать.
Снабдить класс следующими обязательными функциями-членами:
•	конструктор с полным набором параметров, описывающих объект;
•	функция вывода значений параметров, задающих фигуру;
•	функция, возвращающая 1 (истина), если указанная точка принадлежит границе фигуры, и 0 (ложь) в противном случае (координаты точки передаются как параметры);
•	функция, возвращающая 1, если объект пересекает ось абсцисс, и        0 (ложь) в противном случае;
•	функция, возвращающая 1, если объект пересекает ось ординат, и      0 (ложь) в противном случае.
При необходимости добавить внутренние (приватные) функции.
В функции main организовать ввод конкретных параметров объекта с клавиатуры, создание объекта (экземпляра класса), тестирование всех методов с выдачей соответствующих сообщений.
Организовать исходный текст в виде трех исходных файлов:
•	заголовочный с описанием класса (*.h)
•	с реализацией методов (функций-членов) класса (*.cpp)
•	с функцией main (*.cpp).
Для тестирования необходимо подготовить тестовые данные с заранее известными правильными результатами.
Реализовать меню в текстовом режиме для проверки функций:
•	создания объекта
•	проверки принадлежности точки границе фигуры (с допуском 0.005)
•	проверки факта пересечения оси абсцисс
•	проверки факта пересечения оси ординат
В случае реализации внутренних (приватных) функций в их описании реализовать вывод на экран сообщения о вызове этих функций.

Вариант 7
Прямоугольник, задаваемый длинами своих сторон и координатами центра (стороны параллельны осям). Обязательны функции подсчета его периметра и координат вершин.