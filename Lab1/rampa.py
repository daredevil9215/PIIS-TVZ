from time import sleep

UNUTRA = "u"
VANI = "v"
KARTICA = "k"

SENZOR = 0
CITANJE_KARTICE = 1
RAMPA_GORE = 2
RAMPA_DOLE = 3

def prikazi_stanje():
    print("Senzor radi.")
    return SENZOR

def podigni_rampu():
    print("Rampa je dignuta.")
    return RAMPA_GORE

def spusti_rampu():
    print("Rampa je spustena.")
    return RAMPA_DOLE

def citaj_karticu():
    return input("Prislonite karticu: ")

def cekaj_na_ulaz():
    return input("S koje strane prilazi auto: ")

def idi_na_karticu():
    return CITANJE_KARTICE

def odbijena_kartica():
    return SENZOR

stanje = prikazi_stanje()

while True:

    ulaz = cekaj_na_ulaz()

    match ulaz:

        case "u":

            if stanje == SENZOR:
                stanje = podigni_rampu()
                sleep(1.5)

            if stanje == RAMPA_GORE:
                stanje = spusti_rampu()
                sleep(1.5)

        case "v":

            stanje = idi_na_karticu()
            kartica = citaj_karticu()

            match kartica:

                case "k":

                    if stanje == CITANJE_KARTICE:
                        stanje = podigni_rampu()
                        sleep(1.5)

                    if stanje == RAMPA_GORE:
                        stanje = spusti_rampu()
                        sleep(1.5)

                case _:
                    print("Kartica nije validna.")
                    stanje = odbijena_kartica()