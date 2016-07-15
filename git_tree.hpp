/*************************************************
    @author o_nishy
    @name   git_tree.cpp
    @brief  Defining git branch objects
            All actions to git repository will be taken through branch objects
*************************************************/

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

// Branch object
class Branch {
public:
    // Only instance you can create directly is a master instance
    // You will get forked branch through fork function
    // @todo Copying of Branch object needs to be prohibited
    Branch()
        : m_created_time(0), m_name("master"), m_chain(GitChain::getInstance()) {};

    // get the branch name
    std::string getName() {return m_name;};

    // merge this branch with another
    void merge(unsigned long time, Branch &g, std::string message) {
        if (time < m_created_time) {
            throw TimeContradictionException(m_created_time, time);
        }
        std::shared_ptr<GitObj> merge_obj = std::make_shared<MergeObj>(time, getName(), g.getName(), message);
        m_chain.push(merge_obj);
    }

    // update this branch by making a new commit
    void update(unsigned long time, std::string message) {
        if (time < m_created_time) {
            throw TimeContradictionException(m_created_time, time);
        }
        std::shared_ptr<GitObj> commit_obj = std::make_shared<CommitObj>(time, getName(), message);
        m_chain.push(commit_obj);
    }

    // fork this branch and create another
    Branch fork(unsigned long time, std::string name, std::string message) {
        if (time < m_created_time) {
            throw TimeContradictionException(m_created_time, time);
        }
        std::shared_ptr<GitObj> fork_obj = std::make_shared<ForkObj>(time, getName(), name, message);
        m_chain.push(fork_obj);
        return Branch(time, name);
    }

    // rename this branch (fork is recommended)
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