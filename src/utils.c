
#include "utils.h"

HWND createMessageOnlyWindow(
    const char className[ ]
) {
    return CreateWindowEx(
        0,
        className,
        className,
        0,
        0,
        0,
        0,
        0,
        HWND_MESSAGE,
        NULL,
        NULL,
        NULL
    );
}

NOTIFYICONDATA createShellIconData(
    const HWND hwnd,
    const UINT callbackMessage
) {
    const HINSTANCE instance = GetModuleHandle( NULL );
    return ( NOTIFYICONDATA ) {
        .cbSize           = sizeof( NOTIFYICONDATA ),
        .hIcon            = LoadIcon( instance, MAKEINTRESOURCE(ICO1) ),
        .hWnd             = (HWND) hwnd,
        .uID              = 0,
        .uFlags           = NIF_GUID | NIF_ICON | NIF_MESSAGE | NIF_TIP,
        .uCallbackMessage = callbackMessage
    };
}

WNDCLASSEX createWindowClass(
    const char className[ ],
    const WNDPROC windowProc
) {
    const HINSTANCE instance = GetModuleHandle( NULL );
    return ( WNDCLASSEX ) {
        .cbSize        = sizeof( WNDCLASSEX ),
        .hInstance     = instance,
        .lpszClassName = className,
        .lpfnWndProc   = windowProc,
        .style         = CS_DBLCLKS,
        .hIcon         = LoadIcon( instance, MAKEINTRESOURCE( ICO1 ) ),
        .hIconSm       = LoadIcon( instance, MAKEINTRESOURCE( ICO1 ) ),
        .hCursor       = LoadCursor( NULL, IDC_ARROW ),
        .lpszMenuName  = NULL,
        .cbClsExtra    = 0,
        .cbWndExtra    = 0,
        .hbrBackground = NULL
    };
}

