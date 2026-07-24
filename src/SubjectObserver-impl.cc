module subjectobserver;

import <algorithm>;

void Observer::notify(Subject &whoFrom) {
    doNotify(whoFrom);
}

void Subject::setState(State s) {
    state = s;
}

void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

void Subject::detach(Observer *o) {
    if (observers.empty()) return;
    else if (observers.back() == o) observers.pop_back();
    else {
        auto it = std::find(observers.begin(), observers.end(), o);
        if (it != observers.end()) observers.erase(it);
    }
}

void Subject::detachLast() {
    observers.pop_back();
}

void Subject::notifyAll() {
    for (auto &ob : observers) ob->notify(*this);
}

Info Subject::getInfo() const {
    return doGetInfo();
}

State Subject::getState() const {
    return state;
}
