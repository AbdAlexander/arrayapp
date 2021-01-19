#ifndef ARRAPP__H
#define ARRAPP__H

#include <vector>

class array_appender {
public:
    /* Konstruktor és destruktor */
    array_appender()                        {}
    ~array_appender()                       {}

    /* Apppend művelet */
    void append(int* array, int size) {
        for(int index = 0; index < size; ++index)
            arrapp.push_back(&array[index]);
    }

    /* Lekérdező műveletek */
    int size()                              { return arrapp.size(); }
    int at(int index) const                 { return *arrapp[index]; }
    int &at(int index)                      { return *arrapp[index]; }

    /* Operátorok */
    int operator[](int index) const         { return *arrapp[index]; }
    int &operator[](int index)              { return *arrapp[index]; }

private:
    /* Adatszerkezet belső, privát reprezentációja */
    std::vector<int*> arrapp;
};

#endif