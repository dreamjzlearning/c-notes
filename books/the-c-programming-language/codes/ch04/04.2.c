/*
    Sort input strings.
*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char* lineptr[MAXLINES];

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);

void qsort(char* lineptr[], int left, int right);

int main() {

}

#define MAXLEN 1000

int getline(char*, int);
char* alloc(int);

int readlines(char* lineptr[], int maxlines) {
    int len, nlines;
    char* p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        }
        line[len - 1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
    }

    return nlines;
}

void writelines(char* lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

// getline: read a line into s, return length
int getline(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';  //  end of the string
    return i;
}

void qsort(char* v[], int left, int right) {
    int i, last;
    void swap(char* v[], int i, int j);

    if (left >= right) {
        return;
    }
    swap(v, left, (left + right) >> 1);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char* v[], int i, int j) {
    char* temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}