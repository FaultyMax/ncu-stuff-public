#ifndef _LANG_H_
#define _LANG_H_

#include <string>

class Language{

  private:

    int size;
    char* characters;
    
  public:

    static int tested;
    
    Language();
    Language(const Language &og);
    Language(unsigned int val);
    Language(const char* chars);
    
    bool testuj(std::string word);
    void display_chars();
    
    ~Language();
    
};

#endif
