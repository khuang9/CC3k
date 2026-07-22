export module floor;

import <fstream>;
import <iostream>;
import <string>;
import <unordered_set>;
import <vector>;
import chamber;
import subjectobserver;

export class Floor: public Observer {
    std::vector<std::vector<char>> grid;
    // TextDisplay *td;
    std::vector<Chamber> chambers;
    void updateGrid(const Chamber &c);
    virtual void doNotify(Subject &whoFrom) override;

    inline static const std::unordered_set<char> NON_CHAMBER_CELLS{
        '-', '|', '+', '#', ' '
    };

  public:
    explicit Floor(std::string file);
    // void print() const;
    friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

// std::istream &operator>>(std::istream &in, Floor &f);
export std::ostream &operator<<(std::ostream &out, const Floor &f);
