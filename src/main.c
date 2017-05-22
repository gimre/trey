
#include "main.h"

int WINAPI WinMain (
    HINSTANCE hThisInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpszArgument,
    int       nCmdShow
) {
    MSG  messages;

    WNDCLASSEX windowClass = createWindowClass( WINDOW_CLASS, WindowProcedure );
    if( ! RegisterClassEx( &windowClass ) ) {
        return 0;
    }

    createMessageOnlyWindow( WINDOW_CLASS );

    while( GetMessage( &messages, NULL, 0, 0 ) ) {
        TranslateMessage( &messages );
        DispatchMessage( &messages );
    }

    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(
    HWND   hwnd,
    UINT   message,
    WPARAM wParam,
    LPARAM lParam
) {
    handleWindowMessage( hwnd, message, wParam, lParam );
    return DefWindowProc( hwnd, message, wParam, lParam );
}

void createShellIcon( HWND hwnd ) {
    NOTIFYICONDATA iconData = createShellIconData( hwnd, WM_USER_SHELLICON );
    Shell_NotifyIcon( NIM_ADD, &iconData );
}

void handleTrayIconMessage(
    HWND   hwnd,
    UINT   message,
    WPARAM wParam,
    LPARAM lParam
) {
    switch( lParam ) {
        case WM_LBUTTONUP:
            MessageBox( hwnd, "You clicked?", "Yes", MB_OK );
            break;
        case WM_RBUTTONUP:
            PostQuitMessage( 0 );
            break;
        default:
            break;
    }
}

void handleWindowMessage(
    HWND   hwnd,
    UINT   message,
    WPARAM wParam,
    LPARAM lParam
) {
    switch( message ) {
        case WM_CREATE:
            createShellIcon( hwnd );
            break;
        case WM_USER_SHELLICON:
            handleTrayIconMessage( hwnd, message, wParam, lParam );
            break;
        default:
            break;
    }
}
