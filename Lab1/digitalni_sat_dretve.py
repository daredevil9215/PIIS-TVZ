from datetime import datetime
from time import sleep, time
import threading

GUMB_1 = "1"
GUMB_2 = "2"
GUMB_12 = "12"

BLINKAJU_SATI = 0
BLINKAJU_MINUTE = 1
BLINKAJU_SEKUNDE = 2

stop_flag = threading.Event()
gumb = 0
stanje = 0

current_time = datetime.fromtimestamp(time())
sat, min, sek = current_time.hour, current_time.minute, current_time.second

def prikazi_sat():
    print(f'{sat}:{min}:{sek}')

def cekaj_na_gumb():
    return input("Cekam gumb: ")

def blinkaj_sate():

    a = threading.Thread(target=input_thread_h)
    number_thread = threading.Thread(target=blink_thread_h)

    a.start()
    number_thread.start()

    a.join()
    number_thread.join()

def blinkaj_minute():

    a = threading.Thread(target=input_thread_m)
    number_thread = threading.Thread(target=blink_thread_m)

    a.start()
    number_thread.start()

    a.join()
    number_thread.join()

def blinkaj_sekunde():
    a = threading.Thread(target=input_thread_s)
    number_thread = threading.Thread(target=blink_thread_s)

    a.start()
    number_thread.start()

    a.join()
    number_thread.join()

def povecaj_sate():
    global sat
    if sat == 23:
        sat = 0
    else:
        sat += 1

def povecaj_minute():
    global min, sat
    if min == 59:
        min = 0
        sat += 1
    else:
        min += 1

def povecaj_sekunde():
    global sek, min
    if sek == 59:
        sek = 0
        min += 1
    else:
        sek += 1

def input_thread_h():
    global stop_flag, gumb, stanje
    while True:
        user_input = input("")
        if user_input == GUMB_1:
            stop_flag.set()
            stanje = BLINKAJU_MINUTE
            break
        elif user_input == GUMB_2:
            povecaj_sate()
        elif user_input == GUMB_12:
            stop_flag.set()
            gumb = GUMB_12
            stanje = BLINKAJU_SATI
            break

def input_thread_m():
    global stop_flag, gumb, stanje
    while True:
        user_input = input("")
        if user_input == GUMB_1:
            stop_flag.set()
            stanje = 2
            break
        elif user_input == GUMB_2:
            povecaj_minute()
        elif user_input == GUMB_12:
            stop_flag.set()
            gumb = GUMB_12
            stanje = BLINKAJU_SATI
            break

def input_thread_s():
    global stop_flag, gumb, stanje
    while True:
        user_input = input("")
        if user_input == GUMB_2:
            povecaj_sekunde()
        elif user_input == GUMB_12:
            stop_flag.set()
            gumb = GUMB_12
            stanje = 0
            break

def blink_thread_h():
    global stop_flag
    brojac = 0

    while not stop_flag.is_set():

        if brojac % 2:
            print(sat, min, sek, end="\r")
        else:
            print('  ', min, sek, end="\r")

        threading.Event().wait(1)

        brojac += 1

def blink_thread_m():
    global stop_flag
    brojac = 0

    while not stop_flag.is_set():

        if brojac % 2:
            print(sat, min, sek, end="\r")
        else:
            print(sat, '  ', sek, end="\r")
            
        threading.Event().wait(1)

        brojac += 1

def blink_thread_s():
    global stop_flag
    brojac = 0

    while not stop_flag.is_set():

        if brojac % 2:
            print(sat, min, sek, end="\r")
        else:
            print(sat, min, '   ', end="\r")
            
        threading.Event().wait(1)

        brojac += 1

while True:

    prikazi_sat()
    gumb = cekaj_na_gumb()

    if stanje == BLINKAJU_SATI and gumb == GUMB_1:
            
        stop_flag = threading.Event()
        blinkaj_sate()

    if stanje == BLINKAJU_MINUTE:

        stop_flag = threading.Event()
        blinkaj_minute()
                
    if stanje == BLINKAJU_SEKUNDE:

        stop_flag = threading.Event()
        blinkaj_sekunde()