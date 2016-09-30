#include "main.h"



LRESULT CALLBACK WindProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX  WndCls;
    static char szAppName[] = "GDISuite";
    MSG         Msg;

    WndCls.cbSize        = sizeof(WndCls);
    WndCls.style         = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
    WndCls.lpfnWndProc   = WindProcedure;
    WndCls.cbClsExtra    = 0;
    WndCls.cbWndExtra    = 0;
    WndCls.hInstance     = hInstance;
    WndCls.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    WndCls.hCursor       = LoadCursor(NULL, IDC_ARROW);
    WndCls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndCls.lpszMenuName  = NULL;
    WndCls.lpszClassName = szAppName;
    WndCls.hIconSm       = LoadIcon(hInstance, IDI_APPLICATION);
    RegisterClassEx(&WndCls);

    CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
                   szAppName,
                   "GDI",
                   WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                   CW_USEDEFAULT,
                   CW_USEDEFAULT,
                   CW_USEDEFAULT,
                   CW_USEDEFAULT,
                   NULL,
                   NULL,
                   hInstance,
                   NULL);

    while( GetMessage(&Msg, NULL, 0, 0) )
    {
        TranslateMessage(&Msg);
        DispatchMessage( &Msg);
    }

    return static_cast<int>(Msg.wParam);
}

LRESULT CALLBACK WindProcedure(HWND hWnd, UINT Msg,
                               WPARAM wParam, LPARAM lParam)
{
    HDC hDC;
    PAINTSTRUCT Ps;

    switch(Msg)
    {
    case WM_DESTROY:
        PostQuitMessage(WM_QUIT);
        break;
    case WM_PAINT:
    {
        std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        unsigned long long time01 = ms.count();
        hDC = BeginPaint(hWnd, &Ps);
        RECT rect;
        int width = 0;
        int height = 0;
        if(GetWindowRect(hWnd, &rect))
        {
            width = rect.right - rect.left;
            height = rect.bottom - rect.top;
            for(int j = 20; j <height; j++)
            {
                for(int i = 0; i <width; i++)
                {
                    int swagandam = 3;
                    swagandam = rand() % width;
                    if(j % 2 == rand() % 3-0)
                    {
                        SetPixel(hDC, i, j, RGB(rand()%255, rand()%255, rand()%255));
                    }

                }

            }
        }
        ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        unsigned long long time02 = ms.count();
        TextOut(hDC, 0, 0, uint64ToString2((time02-time01)).c_str(), 13);
        Beep(rand()%2000+20,rand()%300);

        //MessageBox(hWnd,floatToString((width*height)/(time02-time01)).c_str(),"", MB_OK);
        EndPaint(hWnd, &Ps);
        break;
    }
    default:
        return DefWindowProc(hWnd, Msg, wParam, lParam);
    }
    return 0;
}
