#include <stdio.h>
#include <assert.h>

char ASCII(int symbol) {
    if (symbol == 48)
        return '0';
    else if (symbol == 49)
        return '1';
    else if (symbol == 50)
        return '2';
    else if (symbol == 51)
        return '3';
    else if (symbol == 52)
        return '4';
    else if (symbol == 53)
        return '5';
    else if (symbol == 54)
        return '6';
    else if (symbol == 55)
        return '7';
    else if (symbol == 56)
        return '8';
    else if (symbol == 57)
        return '9';
}

void test_ASCII() {
    assert(ASCII(48) == '0');
    assert(ASCII(53) == '5');
    assert(ASCII(49) == '1');
    assert(ASCII(54) == '6');
    assert(ASCII(50) == '2');
}

int main() {
    test_ASCII();

    int state = 1, count = 0;
    int symbol;

    while((symbol = getchar()) != '*') {
        char array[100];
        switch (state) {
            case 1:
                if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t') {
                    state = 1;
                }
                else if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
                    state = 3;
                }
                else if (symbol >= '0' && symbol <= '9') {
                    array[count] = ASCII(symbol);
                    count += 1;
                    state = 2;
                }
            break;
            case 2:
                if (symbol >= '0' && symbol <= '9') {
                    array[count] = ASCII(symbol);
                    count += 1;
                    state = 2;
                }
                else if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
                    state = 3;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t') {
                    printf("%c", '0');
                    for (int x = 0; x < count; x++) {
                        printf("%c", array[x]);
                    }
                    printf("%c", ' ');
                    count = 0;
                    state = 4;
                }
                break;
            case 3:
                if ((symbol >= '0' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
                    count = 0;
                    state = 3;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t') {
                    count = 0;
                    state = 1;
                }
                break;
            case 4:
                if (symbol >= '0' && symbol <= '9') {
                    array[count] = ASCII(symbol);
                    count += 1;
                    state = 2;
                }
                else if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
                    state = 3;
                }
                else if (symbol == ' ' || symbol == ',' || symbol == '\n' || symbol == '\t') {
                    state = 1;
                }
            default:
                break;
        }
    }
    return 0;
}