#include <iostream>
#include <string>

using namespace std;

class DigitalClock;

class DigitalClockState {
    public:
        virtual void blink(DigitalClock& clock) = 0;
        virtual void increment(DigitalClock& clock) = 0;
        virtual void next_state(DigitalClock& clock) = 0;
};

class DisplayState : public DigitalClockState {
    public:
        void blink(DigitalClock& clock) override;
        void increment(DigitalClock& clock) override;
        void next_state(DigitalClock& clock) override;
};

class HourState : public DigitalClockState {
    public:
        void blink(DigitalClock& clock) override;
        void increment(DigitalClock& clock) override;
        void next_state(DigitalClock& clock) override;
};

class MinuteState : public DigitalClockState {
    public:
        void blink(DigitalClock& clock) override;
        void increment(DigitalClock& clock) override;
        void next_state(DigitalClock& clock) override;
};

class SecondState : public DigitalClockState {
    public:
        void blink(DigitalClock& clock) override;
        void increment(DigitalClock& clock) override;
        void next_state(DigitalClock& clock) override;
};

class DigitalClockController {};

class DigitalClock {

    public:

        int hours, minutes, seconds;

        DisplayState displayState;
        HourState hourState;
        MinuteState minuteState;
        SecondState secondState;

        DigitalClockController clockController;
        DigitalClockState* state = &displayState;

        DigitalClock() {
            time_t now = time(0);
            string time = ctime(&now);
            hours = stoi(time.substr(11, 2));
            minutes = stoi(time.substr(14, 2));
            seconds = stoi(time.substr(17, 2));
        }

        void show_time() {
            cout << hours << ":" << minutes << ":" << seconds << endl;
        }

        void blink_hours() {
            cout << "Blinkaju sati." << endl;
        }

        void blink_minutes() {
            cout << "Blinkaju minute." << endl;
        }

        void blink_seconds() {
            cout << "Blinkaju sekunde." << endl;
        }

        void increment_hours() {
            hours += 1;
        }

        void increment_minutes() {
            minutes += 1;
        }

        void increment_seconds() {
            seconds += 1;
        }

        void set_state(DigitalClockState *newState) {
            state = newState;
        }

        void button1() {
            state->next_state(*this);
            state->blink(*this);
        }

        void button2() {
            state->increment(*this);
        }

        void button12() {
            set_state(&displayState);
            show_time();
        }

};

void DisplayState::blink(DigitalClock& clock) {}
void DisplayState::increment(DigitalClock& clock) {}
void DisplayState::next_state(DigitalClock& clock) {
    clock.set_state(new HourState());
}

void HourState::blink(DigitalClock& clock) {
    clock.blink_hours();
}
void HourState::increment(DigitalClock& clock) {
    clock.increment_hours();
}
void HourState::next_state(DigitalClock& clock) {
    clock.set_state(new MinuteState());
}

void MinuteState::blink(DigitalClock& clock) {
    clock.blink_minutes();
}
void MinuteState::increment(DigitalClock& clock) {
    clock.increment_minutes();
}
void MinuteState::next_state(DigitalClock& clock) {
    clock.set_state(new SecondState());
}

void SecondState::blink(DigitalClock& clock) {
    clock.blink_seconds();
}
void SecondState::increment(DigitalClock& clock) {
    clock.increment_seconds();
}
void SecondState::next_state(DigitalClock&clock) {}


int main() {

    DigitalClock sat;
    string ulaz;

    sat.show_time();

    while (true) {

        cout << "Cekam ulaz: ";
        cin >> ulaz;

        if(ulaz == "1") {
            sat.button1();
        }

        else if (ulaz == "2") {
            sat.button2();
        }

        else if(ulaz == "12") {
            sat.button12();
        }

    }
}