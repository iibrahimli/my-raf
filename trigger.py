import pyautogui as pg
import time

time.sleep(5)

while True:
    im = pg.screenshot()

    oldcolor = (0, 0, 0)

    #center is at 640, 480

    color = im.getpixel((638, 478))

    if color[0]-oldcolor[0] > 5 and color[1]-oldcolor[1] > 5 and color[2]-oldcolor[2] > 5:
        pg.click()

    oldcolor = color


    #if color[0] == 255 and color[1] < 255 and color[2] < 255:
    #    pg.click()