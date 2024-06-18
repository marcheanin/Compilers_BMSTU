% Лабораторная работа № 1.3 «Объектно-ориентированный
  лексический анализатор»
% 4 марта 2024 г.
% Андрей Марченко, ИУ9-62Б

# Цель работы
Целью данной работы является приобретение навыка реализации лексического анализатора на 
объектно-ориентированном языке 
без применения каких-либо средств автоматизации решения задачи лексического анализа.

# Индивидуальный вариант
Строковые литералы: ограничены обратными кавычками, могут занимать несколько строчек текста, 
для включения обратной 
кавычки она удваивается.
Числовые литералы: десятичные литералы представляют собой последовательности десятичных цифр, двоичные — 
последовательности нулей и единиц, оканчивающиеся буквой «b».
Идентификаторы: последовательности десятичных цифр и знаков «?», «*» и «|», не начинающиеся с цифры.

# Реализация

```cpp
#include <iostream>
#include <map>
#include <istream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <cassert>
#include <valarray>

enum class DomainTag {
    STRING_LITERAL = 0,
    NUM_LITERAL = 1,
    IDENT = 2,
    END_OF_PROGRAM = 3
};

class Position {
private:
    int line;
    int pos;
    int index;
    std::string program;

public:
    explicit Position(std::string program) : line(1), pos(1), index(0), program(std::move(program)) {}

    char get_char() {
        return program[index];
    }

    [[nodiscard]] std::string to_string() const {
        return "(" + std::to_string(line) + ", " + std::to_string(pos) + ")";
    }

    bool is_special_ident_symbol() {
        char c = program[index];
        if (c == '?' || c == '*' || c == '|') return true;
        return false;
    }

    bool is_special_binary_marker() {
        return program[index] == 'b';
    }

    bool is_quotation() {
        return program[index] == '`';
    }

    bool is_inner_quotation() {
        if(index + 1 < program.length() && program[index] == '`' && program[index+1] == '`') {
            return true;
        }
        return false;
    }

    bool is_decimal_only() {
        return is_digit() && program[index] > '1';
    }

    bool is_new_line() {
        if (program[index] == '\r' && index + 1 < program.length()) {
            return program[index + 1] == '\n';
        }
        return program[index] == '\n';
    }

    bool is_end_file() {
        return program[index] == '\0';
    };

    bool is_digit() {
        char c = program[index];
        return std::isdigit(c);
    }

    bool is_space() {
        return std::isspace(program[index]);
    }

    void next() {
        if (index != program.length()) {
            if (is_new_line()) {
                if (program[index] == '\r') {
                    index += 1;
                }
                line += 1;
                pos = 1;
            } else {
                pos += 1;
            }
            index += 1;
        }
    }

    void raise_error(const std::string& message = "Не удалось распознать лексему: ") {
        std::cout << message << to_string() << std::endl;
        while (!is_space() && !is_new_line()) {
            next();
            if (is_new_line()) {
                next();
                break;
            }
        }
        skip_spaces();
    }

    void skip_spaces() {
        while (is_space() || is_new_line()) {
            next();
        }
    }
};

class Fragment {
private:
    Position start;
    Position follow;

public:
    Fragment(Position start, Position follow) : start(std::move(start)), follow(std::move(follow)) {}

    std::string to_string() {
        return start.to_string() + "-" + follow.to_string();
    }
};

class Token {
public:
    DomainTag tag;
    Fragment coords;

    Token(DomainTag tag, Position start, Position follow) : tag(tag), 
    coords(std::move(start), 
           std::move(follow)) {}

    virtual std::string to_string() = 0;
};

class IdentToken : public Token {
public:
    int ident;

    IdentToken(int ident, Position start, Position follow) : Token(DomainTag::IDENT,
                                                                          std::move(start),
                                                                          std::move(follow)),
                                                                          ident(ident) {}

    std::string to_string() override {
        return "IDENT " + coords.to_string() + ": " + std::to_string(ident);
    }
};

class NumLiteralToken : public Token {
public:
    int value;

    NumLiteralToken(int _value, Position start, Position follow) : Token(DomainTag::NUM_LITERAL,
                                                                        std::move(start),
                                                                        std::move(follow)),
                                                                        value(_value) {}

    std::string to_string() override {
        return "NUMBER " + coords.to_string() + ": " + std::to_string(value);
    }
};

class StringLiteralToken : public Token {
public:
    std::string text;

    StringLiteralToken(std::string _text, Position start, Position follow) : Token(DomainTag::STRING_LITERAL,
                                                                                  std::move(start),
                                                                                  std::move(follow)),
                                                                                  text(std::move(_text)) {}

    std::string to_string() override {
        return "STRING_LITERAL " + coords.to_string() + ": \"" + text + "\"";
    }
};

class EndToken : public Token {
public:
    EndToken(Position start, Position follow) : Token(DomainTag::END_OF_PROGRAM,
                                                      std::move(start),
                                                      std::move(follow)) {}

    std::string to_string() override {
        return "END " + coords.to_string();
    }
};


class Lexer {
private:
    std::map<std::string, int> name_codes;
    Position pos;

    int add_name(const std::string& name) {
        if (name_codes.find(name) == name_codes.end()) {
            int code = name_codes.size();
            name_codes[name] = code;
        }
        return name_codes[name];
    }

    NumLiteralToken* get_number() {
        std::string number_string;
        Position start = pos;
        Position cur = pos;
        bool isDecimalOnly = false;
        while (!pos.is_space() && !pos.is_new_line() && !pos.is_special_binary_marker()) {
            if (!pos.is_digit()) {
                pos.raise_error("Нарушена структура числовой лексемы: ");
                return nullptr;
            }
            if (pos.is_decimal_only()) isDecimalOnly = true;
            number_string += pos.get_char();
            cur = pos;
            pos.next();
        }
        if (pos.is_special_binary_marker()) {
            if (isDecimalOnly) {
                pos.raise_error("В числе обнаружены не только 0 или 1, оно не может быть двоичным: ");
                cur = pos;
                pos.next();
                return nullptr;
            }
            int value = binaryToInt(number_string);
            cur = pos;
            pos.next();
            return new NumLiteralToken(value, start, cur);
        }
        int value = std::stoi(number_string, nullptr, 10);
        return new NumLiteralToken(value, start, cur);
    }

        StringLiteralToken* get_string() {
            std::string string_string;
            Position start = pos;
            Position cur = pos;
            bool isSkipFlag = true;
            if (pos.is_inner_quotation()) {
                pos.next();
                cur = pos;
                pos.next();
                return new StringLiteralToken(string_string, start, cur);
            }
            while(!(pos.is_quotation() && !pos.is_inner_quotation()) || isSkipFlag) {
                string_string += pos.get_char();
                isSkipFlag = false;
                if (pos.is_inner_quotation()) {
                    pos.next();
                    isSkipFlag = true;
                }
                if (pos.is_end_file()) {
                    pos.raise_error("Не закрыта кавычка строкового литерала: ");
                    return nullptr;
                }
                cur = pos;
                pos.next();
            }
            assert(!string_string.empty());
            string_string.erase(0, 1);
            cur = pos;
            pos.next();
            return new StringLiteralToken(string_string, start, cur);
        }

        IdentToken* get_ident() {
            std::string ident_string;
            Position start = pos;
            Position cur = pos;
            while(!pos.is_space() && !pos.is_new_line()) {
                if (!pos.is_digit() && !pos.is_special_ident_symbol()) {
                    pos.raise_error("Нарушена структура идентификатора: ");
                    return nullptr;
                }
                ident_string += pos.get_char();
                cur = pos;
                pos.next();
            }
            return new IdentToken(add_name(ident_string), start, cur);
        }


public:
    explicit Lexer(const std::string& input_text) : pos(input_text + " " + '\0') {}

    int binaryToInt(const std::string& binary) {
        int decimal = 0;

        for (int i = 0; i < binary.length(); i++) {
            if (binary[i] == '1') {
                decimal += pow(2, binary.length() - 1 - i);
            }
        }

        return decimal;
    }

    Token* next_token() {
        pos.skip_spaces();
        if (pos.get_char() == '\0') {
            return new EndToken(pos, pos);
        }
        if (!(pos.is_digit() || pos.is_special_ident_symbol() || pos.is_quotation())) {
            pos.raise_error("Не существует токена, начинающегося с такого символа: ");
            return next_token();
        }
        if (pos.is_digit()) {
            Token* token = get_number();
            if (token) {
                return token;
            } else {
                return next_token();
            }
        }
        else if (pos.is_quotation()) {
            Token* token = get_string();
            if (token) {
                return token;
            } else {
                return new EndToken(pos, pos);
            }
        }
        else {
            Token* token = get_ident();
            if (token) {
                return token;
            } else {
                return next_token();
            }
        }
    }

    void print_dict() {
        for (const auto& pair : name_codes) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
};

int main() {
    std::string text;
    std::ifstream file("input.txt");
    assert(file.is_open());
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            text += line + "\n";
        }
        text.pop_back();
        file.close();
    }
    Lexer lexer(text);
    Token* token = lexer.next_token();
    while (typeid(*token) != typeid(EndToken)) {
        std::cout << token->to_string() << std::endl;
        token = lexer.next_token();
    }
    std::cout << token->to_string() << std::endl;
    lexer.print_dict();
    return 0;
}

```

В чём был баг: как я и сказал на паре, лексер неправильно восстанавливался 
после обнаружения ошибки, и действительно, 
в методе raise_error() было достаточно добавить break после обнаружения перехода на новую строку, 
и еще в считывании
нового токена я также немного аккуратнее обработал переход на новую строку.

# Тестирование

Входные данные

```
`12 ``go go `` `*123 asd
0101b `` ||21|* *123
` werwer
1231fwrwf `
```

Вывод на `stdout`

```
STRING_LITERAL (1, 1)-(1, 16): "12 `go go ` "
IDENT (1, 17)-(1, 20): 0
Не существует токена, начинающегося с такого символа: (1, 22)
NUMBER (2, 1)-(2, 5): 5
STRING_LITERAL (2, 7)-(2, 8): ""
IDENT (2, 10)-(2, 15): 1
IDENT (2, 17)-(2, 20): 0
STRING_LITERAL (3, 1)-(4, 11): " werwer
1231fwrwf "
END (4, 13)-(4, 13)
*123: 0
||21|*: 1
```

# Вывод
В этой лабораторной работе я разработал лексический анализатор по всем правилам 
разработки такого анализатора, на 
своём любимом языке с++. Мне действительно показалось интересным и полезным построить 
всю структуру классов для токенов
и прочего. Также я рад, что хоть и с небольшим багом, но я успел справиться с работой за две пары.