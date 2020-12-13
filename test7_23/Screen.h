#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd,c) {}
    char get() const {return contents[cursor];}
    char get(pos r, pos c) const;
    Screen &moves(pos r, pos c);
    void some_member() const;
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) {do_display(os); return *this;}
    const Screen &display(std::ostream &os) const {do_display(os); return *this;}
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;
    void do_display(std::ostream &os) const {os << contents;}
};

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row+c];
}

inline Screen &Screen::moves(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline void Screen::some_member() const
{
    ++access_ctr;
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r*width + c] = ch;
    return *this;
}

#endif // SCREEN_H
