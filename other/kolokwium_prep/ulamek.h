
#ifndef _ULAMEK_
#define _ULAMEK_

class ulamek{

  public:
    int licznik;
    int mianownik;

    ulamek();
    ulamek(int a, int b);

    ulamek(const ulamek &og);

    ulamek operator+(ulamek inny);
    ulamek operator*(ulamek inny);
    
    int& operator[](int i);

    bool operator<(const ulamek n2);
    
    friend std::ostream &operator<<(std::ostream &stream, const ulamek &og);
};

#endif
