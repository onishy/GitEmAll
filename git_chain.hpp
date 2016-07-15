#include <memory>
#include <deque>
#include <sstream>
#include <iostream>
#include "config.hpp"
#include "git_object.hpp"

namespace GitEmAll
{

class GitChain {
private:
    using Chain = std::deque< std::shared_ptr<GitObj> >;
    Chain m_chain;
    GitChain() {
        m_chain = Chain{};
    }
    ~GitChain() {
        std::cout << write();
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
        std::sort(m_chain.begin(), m_chain.end());
        std::stringstream ss;
        ss << "git init" << std::endl
           << "touch " << Config::load().filename << std::endl
           << "git add -A; git commit -m \"initial commit\"" << std::endl;
        for (auto &obj : m_chain) {
            ss << obj->write();
        }
        return ss.str();
    }
};

}