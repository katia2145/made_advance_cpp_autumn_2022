# Домашнее задание №2: Матричный калькулятор

Вариант #1
Необходимо разработать классы для работы с вещественными числами, векторами (строками размерности 1xN и столбцами размерности Nx1) и матрицами размерности MxN и реализовать операции над ними:
1) обращение по индексам к элементам, извлечение диагонали, строки или столбца - 1б (после модификации исходной матрицы извлечённые элементы меняться не должны);
2) возможность создания матрицы из векторов или чисел, вектора из чисел - 1б;
3) поэлементное сложение/вычитание/умножение объектов одинаковой размерности - 1б;
4) умножение числа на матрицу, вектора на матрицу, матрицы на вектор и матрицы на матрицу - 1б;
5) суммирование/вычитание числа и вектора/матрицы, матрицы и вектора (с возможностью выбора - по строкам/по столбцам) - 1б;
6) получение транспонированной и обратной матриц - 1б;
7) подсчёт определителя матрицы - 1б.

Все основные операции должны быть реализованы через перегрузку операторов (операторы могут быть модифицирующие (+= и др.) и немодифицирующие (+ и др.)).

Доп. баллы:
- поддержка "слайсов, как в питоне" (на уровне методов, т.к. операторы такой синтаксис не поддерживают). В качестве примерного интерфейса можно опираться на то, как это сделано в " аналоге numpy на C++" https://github.com/dpilger26/NumCpp -1б;
- размерность матриц может задаваться с помощью шаблонных параметров -2б;

Для сдачи необходимо развернуть базовый CI, в котором будут осуществляться автоматическая сборка и тестирование проекта (хотя бы один интеграционный тест, показывающий работоспособность всех реализованных пунктов). Без покрытия тестами каждый пункт оценивается в 50% стоимости.