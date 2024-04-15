#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

const string PROGRAM = "PROGRAM";
const string RULE = "RULE";
const string LEFT = "LEFT";
const string LEFT_1 = "LEFT 1";
const string LEFT_2 = "LEFT 2";
const string RIGHT = "RIGHT";
const string ALTERNATIVE = "ALTERNATIVE";
const string PART_RIGHT = "PART_RIGHT";
const string PART_RIGHT1 = "PART_RIGHT1";
const string PART_RIGHT2 = "PART_RIGHT2";
const string SYMB = "SYMB";

const string KEY_WORD_EPS = "KEY_WORD_EPS";
const string KEY_WORD_AXIOM = "KEY_WORD_AXIOM";
const string KEY_WORD_OR = "KEY_WORD_OR";
const string KEY_WORD_END = "KEY_WORD_END";
const string STR_TERM = "STR_TERM";
const string NONTERM = "NONTERM";
const string ARROW = "ARROW";
const string END = "END";

class Token {
public:
    string token_type;
    string value;
    int line;
    int position;

    Token(string token_type, string value, int line, int position) : token_type(token_type), value(value), line(line), position(position) {}

    string str() {
        return token_type + " " + value;
    }
};

class Lexer {
public:
    string text;
    int line;
    int position;
    vector<Token> tokens;
    regex rules[10];

    Lexer(string text) : text(text), line(1), position(1) {
        rules[0] = regex("\\$");
        rules[1] = regex("\\s+");
        rules[2] = regex("'epsilon");
        rules[3] = regex("'axiom");
        rules[4] = regex("'end");
        rules[5] = regex("'or");
        rules[6] = regex("->");
        rules[7] = regex("\"[^\"\\s]+\"");
        rules[8] = regex("[A-Z][A-Z0-9]*");
    }

    vector<Token> tokenize() {
        int line_num = 0;
        vector<string> lines;
        size_t pos;
        lines.emplace_back("");
        for (char c : text) {
            lines[line_num].push_back(c);
            if (c == '\n') {
                line_num++;
                lines.emplace_back("");
            }
        }

        for (line_num = 0; line_num < lines.size(); line_num++) {
            position = 1;
            line = line_num + 1;
            while (position < lines[line_num].size() + 1) {
                for (int i = 0; i < 9; i++) {
                    smatch match;
                    if (regex_search(lines[line_num].begin() + position - 1, lines[line_num].end(), match, rules[i])) {
                        if (i != 1) {
                            string value = match.str();
                            Token token = Token(to_string(i), value, line, position);
                            tokens.push_back(token);
                        }
                        position += match.length();
                        break;
                    }
                }
            }
        }

        return tokens;
    }
};

int main() {
    ifstream file("test.txt");
    string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    Lexer lexer(text + "$");

    try {
        vector<Token> tokens = lexer.tokenize();
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}