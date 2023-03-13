// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
    int counter = 0;
    int ind, i = 0, j = size - 1, mid = 0, midVal;
    while (i < j) {
        mid = (j + i) / 2;
        midVal = arr[mid];
        if (value < midVal) {
            j = mid - 1;
        }
        else if (midVal < value) {
            i = mid + 1;
        }
        else {
            break;
        }
    }
    ind = mid;
    int lastind = ind;
    while (arr[ind] == value && ind < size && ind >= 0) {
        counter++;
        ind++;
    }
    ind = lastind - 1;
    while (arr[ind] == value && ind < size && ind >=0) {
        counter++;
        ind--;
    }
    return counter;
}
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (arr[i] + arr[j] == value) count++;
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] == value) count++;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int num = value - arr[i], count1;
        count += cbinsearch(&arr[i + 1], len - i, num);
    }
    return count;
}
