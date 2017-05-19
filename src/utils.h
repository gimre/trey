
#include <windows.h>
#include <shellapi.h>

#include "resource.h"

HWND createMessageOnlyWindow(
    const char className[ ]
);

NOTIFYICONDATA createShellIconData(
    const HWND hwnd,
    const UINT callbackMessage
);

WNDCLASSEX createWindowClass(
    const char className[ ],
    const WNDPROC windowProc
);
