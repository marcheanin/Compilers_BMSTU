% Лабораторная работа № 1.4 «Лексический распознаватель»
% 25 марта 2024 г.
% Андрей Марченко, ИУ9-62Б

# Цель работы
Целью данной работы является изучение использования детерминированных конечных автоматов с 
размеченными заключительными состояниями (лексических распознавателей) для решения задачи 
лексического анализа.

# Индивидуальный вариант
eq, neq, +-, -+, строковые литералы ограничены знаками :, для включения двоеточия в строку
оно удваивается, не могут пересекать границы строк текста.

# Реализация

Лексическая структура языка — регулярные выражения для доменов:

* …
* …

Граф детерминированного распознавателя:

```dot
digraph G {
    rankdir="LR";
    0 -> 1 [label="_\\n\\t"];
    1 -> 1 [label="_\\n\\t"];
    
    0 -> 2 [label="n"];
    0 -> 3 [label="e"];
    0 -> 4 [label="Digit"];
    0 -> 6 [label="Letter/{n, e}"];
    0 -> 7 [label="+"];
    0 -> 8 [label="-"];
    7 -> 9 [label="-"];
    8 -> 9 [label="+"];
    3 -> 5 [label="q"];
    2 -> 3 [label="e"];
    4 -> 4 [label="Digit"];
    0 -> 10 [label=":"];
    10 -> 10 [label="Any/{:, endline}"];
    10 -> 11 [label=":"];
    11 -> 10 [label=":"];
    3 -> 6 [label="(Letter|Digit)/{q}"];
    2 -> 6 [label="(Letter|Digit)/{e}"];
    6 -> 6 [label="Letter|Digit"];
    
    
    5 -> 6 [label="Letter|Digit"]
    0 [label="start_state", shape=circle];
    1 [label="whitespace", shape=doublecircle];
    2 [label="ident1", shape=doublecircle];
    3 [label="ident2", shape=doublecircle];
    4 [label="num_liter", shape=doublecircle];
    5 [label="keyword", shape=doublecircle];
    6 [label="ident", shape=doublecircle];
    7 [label="pre_op1", shape=circle];
    8 [label="pre_op2", shape=circle];
    9 [label="op", shape=doublecircle];
    10 [label="str_start", shape=circle];
    11 [label="str_end", shape=doublecircle];
}
```

Реализация распознавателя:

Файл `Position.java`:
```java
…
```

Файл `Token.java`:
```java
…
```

Файл `Scanner.java`:
```java
…
```

…

# Тестирование

Входные данные

```
…
```

Вывод на `stdout`

```
…
```

# Вывод
‹пишете, чему научились›