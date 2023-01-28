int count_appearances(const char* str,const char* symbols){
    int i = 0;
    int j;
    int result = 0;
    while(str[i] != '\0'){
        j = 0;
        while(symbols[j] != '\0'){
            if (str[i] == symbols[j])
                result++;
            j++;
        }
        i++;
    }
    return result;
}