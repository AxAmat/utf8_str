/*
    Функция определяет длину символа UTF-8
*/
size_t u8_char_len(char first_byte) {
    if ((first_byte & 0xC0) == 0xC0) {
        if ((first_byte & 0xF0) == 0xF0) return 4;
        else if ((first_byte & 0xE0) == 0xE0) return 3;
        else return 2;
    } else return 1;
}

/*
    Функция определяет длину строки UTF-8
*/
size_t u8_str_len(char * str, int str_len) {
    int i, count = 0;
    for (i = 0; i < str_len; i += u8_char_len(str[i]), count++);
    return count - 1;
}

/*
    Функция возвращает символ строки UTF-8
*/
char* u8_str_index(char * str, int str_len, int index) {
    int i, j, count, start_index, stop_index;
    char res[6];
    for (i = 0, count = 0; i < str_len; i += u8_char_len(str[i]), count++) {
        if (count == index) {
            start_index = i;
            stop_index = i + u8_char_len(str[i]);
            break;
        }
    }
    for (j = start_index; j < stop_index; j++) {
        res[j - start_index] = str[j];
    }
    res[stop_index] = '\0';
    return res;
}
