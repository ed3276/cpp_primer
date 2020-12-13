#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include "Screen.h"
#include <vector>

class Window_mgr
{
private:
    std::vector<Screen> screens{Screen(24,80,' ')};
};


#endif // WINDOW_MGR_H
