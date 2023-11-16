#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tekst {

    public:

        string sadrzaj;
        vector<int> vectorSadrzaj;

        Tekst() {}

        Tekst(string opis) {
            sadrzaj = opis;
        }

        string getSadrzaj() {
            return sadrzaj;
        }

        vector<int> getVector() {
            return vectorSadrzaj;
        }

        void ispisSadrzaj() {
            cout << sadrzaj << endl;
        }

        void ispisVector() {

            for(int i : vectorSadrzaj) {
                cout << i << " ";
            }

            cout << endl;

        }

};

class TekstDecorator : public Tekst {

    public:

        Tekst* komponenta;

};

class Ascii : public TekstDecorator {

    public:

        vector<int> pretvoriTekstUAscii() {

            vector<int> rez;

            for(char character : komponenta->getSadrzaj()) {
                int asciiValue = static_cast<int>(character);
                rez.push_back(asciiValue);
            }

            return rez;

        }

        string pretvoriAsciiUTekst() {

            string rezultat = "";

            for(int i : komponenta->getVector()) {
                rezultat += i;
            }

            return rezultat;

        }   

};

class TekstUAscii : public Ascii {

    public:

        TekstUAscii(Tekst* tekst) {
            komponenta = tekst;
            vectorSadrzaj = pretvoriTekstUAscii();
        }

};

class Sifra : public TekstDecorator {

    public:

        int kljuc;

        string sifriraj() {

            string rezultat = "";

            for(int i : komponenta->getVector()) {
                int asciiValue = static_cast<int>(i);
                int novi = asciiValue + kljuc;
                rezultat += novi;
            }

            return rezultat;

        }

        vector<int> desifriraj() {

            vector<int> rez;

            for(char character : komponenta->getSadrzaj()) {
                int asciiValue = static_cast<int>(character);
                rez.push_back(asciiValue - kljuc);
            }

            return rez;

        }

};

class Sifrator : public Sifra {

    public:

        Sifrator(int _kljuc, Tekst *a) {
            komponenta = a;
            kljuc = _kljuc;
            sadrzaj = sifriraj();
        }

};

class Desifrator : public Sifra {

    public:

        Desifrator(int _kljuc, Tekst *a) {
            komponenta = a;
            kljuc = _kljuc;
            vectorSadrzaj = desifriraj();
        }

};

class AsciiUTekst : public Ascii {

    public:

        AsciiUTekst(Tekst* tekst) {
            komponenta = tekst;
            sadrzaj = pretvoriAsciiUTekst();
        }

};

int main() {

    Tekst* t = new Tekst("abcde");
    Ascii* a = new TekstUAscii(t);
    Sifra* s = new Sifrator(3, a);

    Tekst* x = new AsciiUTekst(new Desifrator(3, s));

    x->ispisSadrzaj();

}