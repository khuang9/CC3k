module subjectobserver;

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
    if (observers.back() == o) {
        observers.pop_back();
        return;
    } else {
        // todo
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
