
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
    const UINT callbackMessage,
    const UINT id
) {
    const HINSTANCE instance = GetModuleHandle( NULL );
    return ( NOTIFYICONDATA ) {
        .cbSize           = sizeof( NOTIFYICONDATA ),
        .hIcon            = LoadIcon( instance, MAKEINTRESOURCE( RESI_ICON ) ),
        .hWnd             = (HWND) hwnd,
        .dwInfoFlags      = NIIF_INFO,
        .szInfo           = "14 C, sunny with light showers",
        .szInfoTitle      = "Weather",
        .uFlags           = NIF_ICON | NIF_MESSAGE | NIF_TIP | NIF_INFO,
        .uID              = id,
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
        .hIcon         = LoadIcon( instance, MAKEINTRESOURCE( RESI_ICON ) ),
        .hIconSm       = LoadIcon( instance, MAKEINTRESOURCE( RESI_ICON ) ),
        .hCursor       = LoadCursor( NULL, IDC_ARROW ),
        .lpszMenuName  = NULL,
        .cbClsExtra    = 0,
        .cbWndExtra    = 0,
        .hbrBackground = NULL
    };
}

