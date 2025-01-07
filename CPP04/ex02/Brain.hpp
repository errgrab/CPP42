#pragma once

#include <string>

class Brain {
private:
    std::string ideas[100];
public:
    Brain();
    ~Brain();
    Brain(const Brain& brain);
    Brain& operator=(const Brain& brain);
    std::string getIdea(int index) const;
    void setIdea(int index, std::string idea);
};
