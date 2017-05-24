
#include <windows.h>
#include <objbase.h>
#include <shellapi.h>

#include "resource.h"

HWND createMessageOnlyWindow(
    const char className[ ]
);

NOTIFYICONDATA createShellIconData(
    const HWND hwnd,
    const UINT callbackMessage,
    const UINT id
);

WNDCLASSEX createWindowClass(
    const char className[ ],
    const WNDPROC windowProc
);
