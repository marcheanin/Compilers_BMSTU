% Лабораторная работа № 1.1. Раскрутка самоприменимого компилятора
% 3 февраля 2023 г.
% Марченко Андрей, ИУ9-62Б

# Цель работы
Целью данной работы является ознакомление с раскруткой самоприменимых 
компиляторов на примере модельного компилятора.

# Индивидуальный вариант
Компилятор P5. Заменить ключевые слова begin и end на {{ и }}         соответственно. 
При этом ключевые слова begin и end остаются допустимыми.


# Реализация

Различие между файлами `pcom.pas` и `pcom2.pas`:

```diff
--- pcom.pas    2024-02-17 12:20:54.009438100 +0300
+++ pcom22.pas  2024-02-17 11:26:19.102547000 +0300
@@ -1481,22 +1481,33 @@
              until iscmte or (ch = ')') or eof(input);
              if not iscmte then nextch; goto 1
            end
-         else if ch = '.' then begin sy := LbRaCk; nextch end
+         else if ch = '.' then begin sy := LbRaCk; nextch; goto 1 end
          else sy := lparent;
          op := noop
        end;
       chlcmt:
        begin nextch;
+         if ch = '{' then begin sy := beginsy; op := noop; nextch end
+         else begin
+
          if ch = '$' then options;
          repeat
             while (ch <> '}') and (ch <> '*') and not eof(input) do nextch;
             iscmte := ch = '}'; nextch
          until iscmte or (ch = ')') or eof(input);
          if not iscmte then nextch; goto 1
+
+         end;
        end;
       special:
-        begin sy := ssy[ch]; op := sop[ch];
-          nextch
+        if ch = '}' then begin
+          nextch;
+          if ch = '}' then begin sy := endsy; op := noop; nextch end
+        end
+        else begin
+          begin sy := ssy[ch]; op := sop[ch];
+            nextch
+          end;
         end;
       chspace: sy := othersy
     end; (*case*)
```

Различие между файлами `pcom2.pas` и `pcom3.pas`:

```diff
--- pcom22.pas  2024-02-17 11:26:19.102547000 +0300
+++ pcom3.pas   2024-02-17 12:22:05.015341200 +0300
@@ -262,15 +262,15 @@

    }

-   intsize     =        4;  {{ size of integer }
-   intal       =        4;  {{ memory alignment of integer }
+   intsize     =        4;  { size of integer }
+   intal       =        4;  { memory alignment of integer }
    realsize    =        8;  { size of real }
-   realal      =        4;  {{ memory alignment of real }
+   realal      =        4;  { memory alignment of real }
    charsize    =        1;  { size of char }
    charal      =        1;  { memory alignment of char }
    charmax     =        1;
-   boolsize    =        1;  {{ size of boolean }
-   boolal      =        1;  {{ alignment of boolean }
+   boolsize    =        1;  { size of boolean }
+   boolal      =        1;  { alignment of boolean }
    ptrsize     =        4;  { size of pointer }
    adrsize     =        4;  { size of address }
    adral       =        4;  { alignment of address }
@@ -342,7 +342,7 @@
    dodmplex   = false; { dump lexical }
    doprtryc   = false; { dump recycling tracker counts }

-   {{ version numbers }
+   { version numbers }

    majorver   = 1; { major version number }
    minorver   = 0; { minor version number }
@@ -688,7 +688,7 @@
      stpcnt := stpcnt-1
   end;

-  {{ initialize and register identifier entry }
+  { initialize and register identifier entry }
   procedure ininam(p: ctp);
   begin
      ctpcnt := ctpcnt+1; { count entry }
```

# Тестирование

Тестовый пример:

```pascal
program hello(output);

var 
  x,y: real;
  v: real; 

begin
{***eorjijf
**wfwmlrg
**erkgkeg**}
   x := 2;
   y := 3;
  if x = 0 then {{ write('lol') end;
  write('Введите x,y: ');
  v := x;
  x := y;
  y := v;
  writeln('Новые значения x,y: ',x,' ',y);
}}.

```

Вывод тестового примера на `stdout`

```
Введите x,y: Новые значения x,y:  3.000000000000000e+00  2.000000000000000e+00
```

Как видим, поддерживается как begin/end конструкции, так и `{{`, `}}`.

# Вывод
В ходе данной лабораторной работы было проведено ознакомление с использованием и доработкой 
самоприменимых компиляторов на примере компилятора P5,
получен опыт программирования на языке Pascal
и выполнена поставленная задача.

Основной сложностью для меня было вспоминание школьной программы
основ программирования на Pascal, а также использование 
архитектуры компилятора, однако разобравшись, где в программе 
происходит лексический анализ и как добавить в него новые правила,
выполнить задание не составило труда.
