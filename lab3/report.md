% Лабораторная работа № 1.2. «Лексический анализатор
  на основе регулярных выражений»
% 26 февраля 2024 г.
% Марченко Андрей, ИУ9-62Б

# Цель работы
Целью данной работы является приобретение навыка разработки простейших лексических анализаторов, 
работающих на основе поиска в тексте по образцу, заданному регулярным выражением.

# Индивидуальный вариант
Идентификаторы: либо последовательности латинских букв, либо непустые последовательности десятичных цифр,
 ограниченные круглыми скобками.\
Числовые литералы: либо последовательности десятичных цифр, не начинающиеся с нуля, либо «0». 
Операции: «()», «:», «:=».

# Реализация

```java
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

    static class Position {
        private int line, pos;

        Position(int line,int pos) {
            this.line = line;
            this.pos = pos;
        }

        void next_line() {
            this.line += 1;
            this.pos = 1;
        }

        void next_pos(int pos) {
            this.pos += pos;
        }

        public String toString() {
            return "(" + this.line + "," + this.pos + ")";
        }
    }

    private static ArrayList<String> text_match(String line, Position pos) {
        String ident = "\\p{L}+|\\(\\d+\\)";
        String num_literal = "[1-9][0-9]*|0";
        String operations = "\\(\\)|:=|:";
        String full_pattern = "(^" + ident + ")|(^" + num_literal + ")|(^" + operations + ")";

        Pattern p = Pattern.compile(full_pattern);
        Matcher m;

        ArrayList<String> tokens = new ArrayList<>();

        while(!line.isEmpty()) {
            m = p.matcher(line);
            if (m.find()) {
                if (m.group(1) != null) {
                    String item = m.group(1);
                    tokens.add("IDENT: " + pos + ": " + item);
                    pos.next_pos(item.length());
                    line = line.substring(line.indexOf(item) + item.length());
                }
                else if (m.group(2) != null) {
                    String item = m.group(2);
                    tokens.add("NUM_LITERAL: " + pos + ": " + item);
                    pos.next_pos(item.length());
                    line = line.substring(line.indexOf(item) + item.length());
                }
                else if (m.group(3) != null){
                    String item = m.group(3);
                    tokens.add("OPERATION: " + pos + ": " + item);
                    pos.next_pos(item.length());
                    line = line.substring(line.indexOf(item) + item.length());
                }
            }
            else {
                if (Character.isWhitespace(line.charAt(0))) {
                    while (Character.isWhitespace(line.charAt(0))) {
                        line = line.substring(1);
                        pos.next_pos(1);
                    }
                }
                else{
                    tokens.add("error : " + pos.toString());
                    while (!m.find() && !line.isEmpty()) {
                        line = line.substring(1);
                        pos.next_pos(1);
                        m = p.matcher(line);
                    }
                }
            }
        }

        return tokens;
    }

    public static void main(String[] args) {
        Position pos = new Position(1, 1);
        List<String> lines;
        ArrayList<String> tokens;

        try {
            lines = Files.readAllLines(Paths.get("src/input.txt"), StandardCharsets.UTF_8);
            for (String line : lines) {
                tokens = text_match(line, pos);
                for (String token : tokens) {
                    System.out.println(token);
                }
                pos.next_line();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }

}
}
```

# Тестирование

Входные данные

```
123 ()
(123324):qwe : :=
95 01
```

Вывод на `stdout` (если необходимо)

```
NUM_LITERAL: (1,1): 123
OPERATION: (1,5): ()
IDENT: (2,1): (123324)
OPERATION: (2,9): :
IDENT: (2,10): qwe
OPERATION: (2,13): :
OPERATION: (2,14): :=
NUM_LITERAL: (3,1): 95
NUM_LITERAL: (3,3): 0
NUM_LITERAL: (3,4): 1
```

# Вывод
В этой лабораторной работе мною был разработан простейший лексический
анализатор на языке Java на основе регулярных выражений. 
Были освоены ключевые навыки для этой лабораторной: я вспомнил синтаксис и констукци языка Java, 
освоил задание на Java регулярных выражений 
и вспомнил навыки работы с ними, полученные на курса ТФЯ в прошлом семестре.