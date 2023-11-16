from datetime import datetime
from time import sleep, time

GUMB_1 = "1"
GUMB_2 = "2"
GUMB_12 = "12"

SAT = 0
BLINKAJU_SATI = 1
BLINKAJU_MINUTE = 2
BLINKAJU_SEKUNDE = 3

current_time = datetime.fromtimestamp(time())
sat, min, sek = current_time.hour, current_time.minute, current_time.second

def prikazi_sat():
    print(f'{sat}:{min}:{sek}')
    return 0

def cekaj_na_gumb():
    return input("Cekam gumb: ")

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

def blinkaj_sate():
    print("Blinkaju sati")
    return BLINKAJU_SATI

def blinkaj_minute():
    print("Blinkaju minute")
    return BLINKAJU_MINUTE

def blinkaj_sekunde():
    print("Blinkaju sekunde")
    return BLINKAJU_SEKUNDE

stanje = prikazi_sat()

while True:

    gumb = cekaj_na_gumb()

    match stanje:

        case 0:

            if gumb == GUMB_1:
                stanje = blinkaj_sate()

        case 1:

            match gumb:

                case "1":
                    stanje = blinkaj_minute()

                case "2":
                    povecaj_sate()

                case "12":
                    stanje = prikazi_sat()

        case 2:

            match gumb:

                case "1":
                    stanje = blinkaj_sekunde()

                case "2":
                    povecaj_minute()

                case "12":
                    stanje = prikazi_sat()

        case 3:

            match gumb:

                case "2":
                    povecaj_sekunde()

                case "12":
                    stanje = prikazi_sat()