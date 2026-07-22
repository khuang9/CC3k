export module subjectobserver;

import <vector>;
import info;
import state;

export class Subject;

export class Observer {
    virtual void doNotify(Subject &whoFrom) = 0;
  public:
    void notify(Subject &whoFrom); 
    virtual ~Observer() = default;
};

export class Subject {
    State state;
  protected:
    std::vector<Observer*> observers;
    void setState(State s);
    virtual Info doGetInfo() const = 0;
  public:
    void attach(Observer *o);
    void detach(Observer *o);
    void detachLast();
    void notifyAll();
    Info getInfo() const;
    State getState() const;
};
