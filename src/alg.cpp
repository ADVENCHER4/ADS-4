// Copyright 2021 NNTU-CS
void sort(int* arr, int size) {
    int i = 0, j = size - 1;
    int mid = arr[size / 2];
    do {
        while (arr[i] < mid) i++;
        while (arr[j] > mid) j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) sort(arr, j + 1);
    if (i < size) sort(&arr[i], size - i);
}
int cbinsearch(int* arr, int size, int value) {
    int counter = 0;
    int ind, i = 0, j = size - 1, mid = 0, midVal;
    while (i < j) {
        mid = (j + i) / 2;
        midVal = arr[mid];
        if (value < midVal) {
            j = mid - 1;
        } else if (midVal < value) {
            i = mid + 1;
        } else {
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
    sort(arr, len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (arr[i] + arr[j] == value) count++;
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    sort(arr, len);
    int count = 0, int max = len - 1;
    while (arr[max] > value) max--;
    for (int i = 0; i < max; i++) {
        for (int j = i+1; j < max; j++) {
            if (arr[i] + arr[j] == value) count++;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    sort(arr, len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        int num = value - arr[i], count1;
        count += cbinsearch(&arr[i + 1], len - i - 1, num);
    }
    return count;
}
