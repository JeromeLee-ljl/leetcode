// Validate if a given string can be interpreted as a decimal number.

// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// " -90e3   " => true
// " 1e" => false
// "e3" => false
// " 6e-1" => true
// " 99e2.5 " => false
// "53.5e93" => true
// " --6 " => false
// "-+3" => false
// "95a54e53" => false

#include "../include/tools.cpp"

// bool skip_int(char* s, int* i) {
//     if (s[*i] < '0' || s[*i] > '9') return 0;
//     while (s[*i] >= '0' && s[*i] <= '9') {
//         (*i)++;
//     }
//     return 1;
// }

// bool skip_decimal(char* s, int* i) {
//     if (s[*i] == '.') {
//         (*i)++;
//         return skip_int(s, i);
//     }
//     if (skip_int(s, i) == 0) {
//         return 0;
//     }
//     if (s[*i] == '.') {
//         (*i)++;
//         while (s[*i] >= '0' && s[*i] <= '9') {
//             (*i)++;
//         }
//     }
//     return 1;
// }

// void skip_whitespace(char* s, int* i) {
//     while (s[*i] == ' ') (*i)++;
// }

// void skip_signal(char* s, int* i) {
//     if (s[*i] == '-' || s[*i] == '+') (*i)++;
// }

// bool isNumber(char* s) {
//     int i = 0;
//     skip_whitespace(s, &i);
//     skip_signal(s, &i);
//     if (skip_decimal(s, &i) == 0) {
//         return 0;
//     }
//     if (s[i] == 'e') {
//         i++;
//         skip_signal(s, &i);
//         if (skip_int(s, &i) == 0) {
//             return 0;
//         }
//     }
//     skip_whitespace(s, &i);
//     if (s[i] == '\0') {
//         return 1;
//     }
//     return 0;
// }

bool skip_int(char** s) {
    if (**s < '0' || **s > '9') return 0;
    while (**s >= '0' && **s <= '9') {
        (*s)++;
    }
    return 1;
}

bool skip_decimal(char** s) {
    if (**s == '.') {
        (*s)++;
        return skip_int(s);
    }
    if (skip_int(s) == 0) {
        return 0;
    }
    if (**s == '.') {
        (*s)++;
        while (**s >= '0' && **s <= '9') {
            (*s)++;
        }
    }
    return 1;
}

bool isNumber(char* s) {
    char* str = s;
    while (*str == ' ') str++;

    if(*str=='-'|| *str=='+') str++;
    if (skip_decimal(&str) == 0) {
        return 0;
    }
    if (*str == 'e') {
        str++;
        if(*str=='-'|| *str=='+') str++;
        if (skip_int(&str) == 0) {
            return 0;
        }
    }
    while (*str == ' ') str++;
    if (*str == '\0') {
        return 1;
    }
    return 0;
}