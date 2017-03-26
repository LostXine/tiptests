import win32con
import win32api
import win32gui
import datetime
import cv2


def win32_get_screen(window_name):
    print datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S') + 'apiGetScreen() start'
    window_handle = win32gui.FindWindow(0, window_name)
    # print type(window_handle) type;long
    l, t, r, b = win32gui.GetWindowRect(window_handle)
    window_height = b - t
    window_width = r - l
    print 'window height:' + unicode(window_height) + ' width:' + unicode(window_width)
    window_dc = win32gui.GetWindowDC(window_handle)
    window_cdc = win32gui.CreateCompatibleDC(window_dc)
    window_bitmap = win32gui.CreateCompatibleBitmap(window_dc, window_width, window_height)
    win32gui.SelectObject(window_cdc, window_bitmap)
    win32gui.BitBlt(window_cdc, 0, 0, window_width, window_height, window_dc, 0, 0, win32con.SRCCOPY)
    win32gui.PyGetMemory()
    # print type(window_bitmap)
    # cv2.imshow('win', window_bitmap)
    win32gui.DeleteObject(window_bitmap)
    win32gui.DeleteDC(window_dc)
    win32gui.DeleteDC(window_cdc)
    print datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S') + 'apiGetScreen() fin'

if __name__ == '__main__':
    win32_get_screen('poi')
