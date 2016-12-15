/*
    Функция определяет длину строки в байтах
*/
int str_len(char * str) {
    int i = 0, res = 0;
    for (; str[i] != '\0'; i++, res++);
    return res;
}

/*
    Функция определяет длину символа UTF-8
*/
int u8_char_len(char first_byte) {
    unsigned short int bytes = 0;
    if ((first_byte & 0xC0) == 0xC0) {
        if ((first_byte & 0xF0) == 0xF0) bytes = 4;
        else if ((first_byte & 0xE0) == 0xE0) bytes = 3;
        else bytes = 2;
    } else bytes = 1;
    return bytes;
}

/*
    Функция определяет длину строки UTF-8
*/
int u8_str_len(char * str) {
    int i = 0, count = 0;
    int str_l = str_len(str);
    for (; i < str_l; i += u8_char_len(str[i]), count++);
    return count - 1;
}

/*
    Функция возвращает символ строки UTF-8
*/
char* u8_str_index(char * str, int index) {
    int i, j, count, start_index, stop_index;
    int str_l = str_len(str);
    static char res[5];
    for (i = 0, count = 0; i < str_l; i += u8_char_len(str[i]), count++) {
        if (count == index) {
            start_index = i;
            stop_index = i + u8_char_len(str[i]);
            break;
        }
    }
    for (j = start_index; j < stop_index; j++) {
        res[j - start_index] = str[j];
    }
    res[stop_index - start_index] = '\0';
    return res;
}
