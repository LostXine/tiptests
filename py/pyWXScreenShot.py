# coding=utf8
import datetime
import os
import pythoncom
import win32api
import pyHook
from PIL import ImageGrab
import itchat


to_username = u'蒋剑斌'


def save_and_send_img():
    find_username = get_dst_username()
    if find_username is None:
        print(u'找不到用户名:'+to_username)
        return
    image_path = 'img.jpg'
    print("%s send screenshot." % datetime.datetime.now().strftime('[%Y-%m-%d %H:%M:%S.%f]'))
    img = ImageGrab.grab()
    img.save(image_path,  'JPEG', quality=95)
    itchat.send_image(image_path, find_username)
    os.remove(image_path)


def get_dst_username():
    chat_room = itchat.search_chatrooms(name=to_username)
    if len(chat_room) > 0:
        return chat_room[0][u'UserName']
    friends = itchat.search_friends(name=to_username)
    if len(friends) > 0:
        return friends[0][u'UserName']
    return None


def on_keybroad_events(event):
    # print('-' * 20 + 'Keyboard Begin' + '-' * 20)
    # printa("Current Time:%s Key:%s" % (datetime.datetime.now().strftime('[%Y-%m-%d %H:%M:%S.%f] '), str(event.Key)))
    # print("MessageName:%s" % str(event.MessageName))
    # print("Message:%d" % event.Message)
    # print("Time:%d" % event.Time)
    # print("Window:%s" % str(event.Window))
    # print("WindowName:%s" % str(event.WindowName))
    # print("Ascii_code: %d" % event.Ascii)
    # print("Ascii_char:%s" % chr(event.Ascii))
    # print('-' * 20 + 'Keyboard End' + '-' * 20)
    if str(event.Key) == 'F12':  # press F12 to finish
        print(u'检测到F12，准备退出')
        win32api.PostQuitMessage()
    if str(event.Key) == 'Snapshot':
        save_and_send_img()
    return True


if __name__ == "__main__":
    print(u'用法: \n1.扫码登陆微信，等待提示登陆成功\n2.按printScreen可以截图\n3.按F12可以退出\n')
    itchat.auto_login()
    hm = pyHook.HookManager()
    hm.KeyDown = on_keybroad_events
    hm.HookKeyboard()
    pythoncom.PumpMessages()
    itchat.logout()
