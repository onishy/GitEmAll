/*************************************************
    @author o_nishy
    @name   git_chain.cpp
    @brief  Defining a singleton for holding all git commands.
            Each git command is expressed in class inheriting GitObj, which is defined in git_object.hpp.
*************************************************/

#include <memory>
#include <deque>
#include <sstream>
#include <iostream>
#include "config.hpp"
#include "git_object.hpp"

namespace GitEmAll
{

// GitChain class is a singleton class
class GitChain {
private:
    // Holds commands
    using Chain = std::deque< std::shared_ptr<GitObj> >;
    Chain m_chain;
    GitChain() {
        m_chain = Chain{};
    }
    // Automatically output all commands to stdout at the end of the program
    ~GitChain() {
        std::cout << write();
    }

    // Comparison function for sorting object chain with id
    static bool comp(const std::shared_ptr<GitObj>& lhs, const std::shared_ptr<GitObj>& rhs) {
        return lhs->getId() < rhs->getId();
    }

public:
    static GitChain& getInstance() {
        static GitChain instance;
        return instance;
    }

    void push(const std::shared_ptr<GitObj> obj) {
        m_chain.push_back(obj);
    }

    std::string write() {
        std::sort(m_chain.begin(), m_chain.end(), comp);
        std::stringstream ss;
        ss << "git init" << std::endl
           << "git config --local user.name Anonymous; "
           << "git config --local user.email anonymous@example.com" << std::endl
           << "touch " << Config::load().filename << std::endl
           << "git add -A; git commit -m \"initial commit\"" << std::endl;
        for (auto &obj : m_chain) {
            ss << obj->write();
        }
        return ss.str();
    }
};

}