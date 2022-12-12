#include <stdio.h>
#include <assert.h>

char ASCII(int s) {
    if (s == 48)
        return '0';
    else if (s == 49)
        return '1';
    else if (s == 50)
        return '2';
    else if (s == 51)
        return '3';
    else if (s == 52)
        return '4';
    else if (s == 53)
        return '5';
    else if (s == 54)
        return '6';
    else if (s == 55)
        return '7';
    else if (s == 56)
        return '8';
    else if (s == 57)
        return '9';
}

void test_ASCII() {
    assert(ASCII(48) == '0');
    assert(ASCII(53) == '5');
    assert(ASCII(49) == '1');
    assert(ASCII(54) == '6');
    assert(ASCII(50) == '2');
}

enum {maxn = 100};

int main() {
    test_ASCII();

    int state = 1, count = 0;
    int s;

    while((s = getchar()) != '!') {
        char array[maxn];
        switch (state) {
            case 1:
                if (s == ' ' || s == ',' || s == '\n' || s == '\t') {
                    state = 1;
                }
                else if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')) {
                    state = 3;
                }
                else if (s >= '0' && s <= '9') {
                    array[count] = ASCII(s);
                    count += 1;
                    state = 2;
                }
                break;
            case 2:
                if (s >= '0' && s <= '9') {
                    array[count] = ASCII(s);
                    count += 1;
                    state = 2;
                }
                else if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')) {
                    state = 3;
                }
                else if (s == ' ' || s == ',' || s == '\n' || s == '\t') {
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
                if ((s >= '0' && s <= '9') || (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')) {
                    count = 0;
                    state = 3;
                }
                else if (s == ' ' || s == ',' || s == '\n' || s == '\t') {
                    count = 0;
                    state = 1;
                }
                break;
            case 4:
                if (s >= '0' && s <= '9') {
                    array[count] = ASCII(s);
                    count += 1;
                    state = 2;
                }
                else if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')) {
                    state = 3;
                }
                else if (s == ' ' || s == ',' || s == '\n' || s == '\t') {
                    state = 1;
                }
            default:
                break;
        }
    }
    return 0;
}