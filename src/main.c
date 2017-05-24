
#include "main.h"

int WINAPI WinMain (
    const HINSTANCE hThisInstance,
    const HINSTANCE hPrevInstance,
    const LPSTR     lpszArgument,
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
    const HWND   hwnd,
    const UINT   message,
    const WPARAM wParam,
    const LPARAM lParam
) {
    handleWindowMessage( hwnd, message, wParam, lParam );
    return DefWindowProc( hwnd, message, wParam, lParam );
}

void createShellIcon( HWND hwnd, UINT id ) {
    NOTIFYICONDATA iconData = createShellIconData( hwnd, WM_USER_SHELLICON, 0 );
    Shell_NotifyIcon( NIM_ADD, &iconData );
}

void handleMenuMessage(
    const HWND   hwnd,
    const UINT   message,
    const WPARAM wParam,
    const LPARAM lParam
) {
    // const WORD wmEvent = HIWORD(wParam);
    const WORD wmId    = LOWORD(wParam);
    switch( wmId ) {
        case RESM_MENU_FILE_EXIT:
            PostQuitMessage( 0 );
            break;
        default:
            break;
    }
}

void handleTrayIconMessage(
    const HWND   hwnd,
    const UINT   message,
    const WPARAM wParam,
    const LPARAM lParam
) {
    switch( lParam ) {
        case WM_LBUTTONUP:
            MessageBox( hwnd, "You clicked?", "Yes", MB_OK );
            break;
        case WM_RBUTTONUP: {
            showTrayPopup( hwnd, RESM_MENU );
            break;
        }
        default:
            break;
    }
}

void handleWindowMessage(
    const HWND   hwnd,
    const UINT   message,
    const WPARAM wParam,
    const LPARAM lParam
) {
    switch( message ) {
        case WM_COMMAND:
            handleMenuMessage( hwnd, message, wParam, lParam );
            break;
        case WM_CREATE:
            createShellIcon( hwnd, 0 );
            break;
        case WM_QUIT: {
            removeShellIcon( hwnd, 0 );
            break;
        }
        case WM_USER_SHELLICON:
            handleTrayIconMessage( hwnd, message, wParam, lParam );
            break;
        default:
            break;
    }
}

void removeShellIcon(
    const HWND hwnd,
    const UINT id
) {
    NOTIFYICONDATA iconData = createShellIconData( hwnd, WM_USER_SHELLICON, 0 );
    Shell_NotifyIcon( NIM_DELETE, &iconData );
}

void showTrayPopup(
    const HWND hwnd,
    const WORD resourceId
) {
    const HINSTANCE instance   = GetModuleHandle( NULL );
    const HMENU     menuHandle = LoadMenu(
        instance,
        MAKEINTRESOURCE( resourceId )
    );

    POINT point;
    
    GetCursorPos( &point );
    SetForegroundWindow( hwnd );
    TrackPopupMenu(
        GetSubMenu( menuHandle , 0 ),
        TPM_LEFTALIGN | TPM_BOTTOMALIGN,
        point.x,
        point.y,
        0,
        hwnd,
        0
    );

    DestroyMenu( menuHandle );
}
