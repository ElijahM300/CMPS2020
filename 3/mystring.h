#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring{
public:
    char *str;
    int allocated_size;
    Mystring();
    Mystring(const char *word);
    friend ostream &operator << (ostream&, const Mystring&);
};

#endif
