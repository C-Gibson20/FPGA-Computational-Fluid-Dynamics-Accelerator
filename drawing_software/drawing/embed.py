import win32gui
import win32con

def embed_pygame_into_unity(python_title, unity_title, width=800, height=800, x=2980, y=1020):
    hwnd_python = win32gui.FindWindow(None, python_title)
    hwnd_unity = win32gui.FindWindow(None, unity_title)

    if hwnd_python and hwnd_unity:
        # Modify Unity window style to allow child window
        uw_style = win32gui.GetWindowLong(hwnd_unity, win32con.GWL_STYLE)
        uw_style |= win32con.WS_CLIPCHILDREN
        win32gui.SetWindowLong(hwnd_unity, win32con.GWL_STYLE, uw_style)
        win32gui.SetWindowPos(hwnd_unity, None, 0, 0, 0, 0,
                              win32con.SWP_NOMOVE | win32con.SWP_NOSIZE | win32con.SWP_FRAMECHANGED)

        # Ensure Python window is visible
        win32gui.ShowWindow(hwnd_python, win32con.SW_RESTORE)
        win32gui.UpdateWindow(hwnd_python)

        # Embed Python window into Unity window
        win32gui.SetParent(hwnd_python, hwnd_unity)

        # Set Python window styles for embedding
        child_style = win32gui.GetWindowLong(hwnd_python, win32con.GWL_STYLE)
        child_style &= ~(win32con.WS_CAPTION | win32con.WS_THICKFRAME)
        child_style |= (win32con.WS_CHILD | win32con.WS_VISIBLE |
                        win32con.WS_CLIPSIBLINGS | win32con.WS_CLIPCHILDREN |
                        win32con.WS_TABSTOP)
        win32gui.SetWindowLong(hwnd_python, win32con.GWL_STYLE, child_style)

        # Position the Python window within Unity
        win32gui.SetWindowPos(hwnd_python, win32con.HWND_TOP,
                              x, y, width, height,
                              win32con.SWP_SHOWWINDOW |
                              win32con.SWP_NOACTIVATE |
                              win32con.SWP_FRAMECHANGED)

        win32gui.BringWindowToTop(hwnd_python)
    else:
        print("Could not find one or both windows")