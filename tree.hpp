#include <exception>
#include "git_chain.hpp"

namespace GitEmAll
{

struct TimeContradictionException : public std::exception
{
    TimeContradictionException(unsigned long created, unsigned long target)
        : m_created(created), m_target(target) {};
    const char * what () const throw () {
        std::string res = "Time Contradiction: " 
            + std::to_string(m_target) + " < " + std::to_string(m_created);
        return res.c_str();
    }
private:
    unsigned long m_created;
    unsigned long m_target;
};

class Branch {
public:
    Branch()
        : m_created_time(0), m_name("master"), m_chain(GitChain::getInstance()) {};

    std::string getName() {return m_name;};

    void merge(unsigned long time, Branch &g, std::string message) {
        if (time < m_created_time) {
            throw TimeContradictionException(m_created_time, time);
        }
        std::shared_ptr<GitObj> merge_obj = std::make_shared<MergeObj>(time, getName(), g.getName(), message);
        m_chain.push(merge_obj);
    }

    void update(unsigned long time, std::string message) {
        if (time < m_created_time) {
            throw TimeContradictionException(m_created_time, time);
        }
        std::shared_ptr<GitObj> commit_obj = std::make_shared<CommitObj>(time, getName(), message);
        m_chain.push(commit_obj);
    }

    Branch fork(unsigned long time, std::string name, std::string message) {
        if (time < m_created_time) {
            throw TimeContradictionException(m_created_time, time);
        }
        std::shared_ptr<GitObj> fork_obj = std::make_shared<ForkObj>(time, getName(), name, message);
        m_chain.push(fork_obj);
        return Branch(time, name);
    }

    void rename(unsigned long time, std::string newname) {
        if (time < m_created_time) {
            throw TimeContradictionException(m_created_time, time);
        }
        std::shared_ptr<GitObj> rename_obj = std::make_shared<RenameObj>(time, getName(), newname);
        m_name = newname;
        m_chain.push(rename_obj);
    }

private:
    Branch(unsigned long time, std::string name)
        : m_created_time(time), m_name(name), m_chain(GitChain::getInstance()) {};

    unsigned long m_created_time;
    std::string m_name;
    GitChain& m_chain;
};

}