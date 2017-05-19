
#include "utils.h"

#define WIN32_LEAN_AND_MEAN

const char WINDOW_CLASS[ ]   = "Trey manager";
const UINT WM_USER_SHELLICON = WM_USER + 1;

LRESULT CALLBACK WindowProcedure(
    HWND   hwnd,
    UINT   message,
    WPARAM wParam,
    LPARAM lParam
) {
    return DefWindowProc( hwnd, message, wParam, lParam );
}

int WINAPI WinMain (
    HINSTANCE hThisInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpszArgument,
    int       nCmdShow
) {
    MSG  messages;
    HWND hwnd;

    WNDCLASSEX windowClass = createWindowClass( WINDOW_CLASS, WindowProcedure );
    if( ! RegisterClassEx( &windowClass ) ) {
        return 0;
    }

    hwnd = createMessageOnlyWindow( WINDOW_CLASS );

    NOTIFYICONDATA iconData = createShellIconData( hwnd, WM_USER_SHELLICON );
    Shell_NotifyIcon( NIM_ADD, &iconData );

    while( GetMessage( &messages, NULL, 0, 0 ) ) {
        TranslateMessage( &messages );
        DispatchMessage( &messages );
    }

    return messages.wParam;
}
