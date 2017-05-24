
#include "utils.h"

#define WIN32_LEAN_AND_MEAN

#define WM_USER_SHELLICON ( WM_USER + 1 )

extern const char WINDOW_CLASS[ ] = "Trey manager";

void createShellIcon(
    HWND hwnd,
    UINT id
);

void handleMenuMessage(
    HWND   hwnd,
    UINT   message,
    WPARAM wParam,
    LPARAM lParam
);

void handleTrayIconMessage(
    HWND   hwnd,
    UINT   message,
    WPARAM wParam,
    LPARAM lParam
);

void handleWindowMessage(
    HWND   hwnd,
    UINT   message,
    WPARAM wParam,
    LPARAM lParam
);

void removeShellIcon(
    HWND hwnd,
    UINT id
);

void showTrayPopup(
    HWND hwnd,
    WORD resourceId
);

LRESULT CALLBACK WindowProcedure(
    HWND   hwnd,
    UINT   message,
    WPARAM wParam,
    LPARAM lParam
);

int WINAPI WinMain (
    HINSTANCE hThisInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpszArgument,
    int       nCmdShow
);
