/*************************************************
    @author o_nishy
    @name   git_object.cpp
    @brief  Defining git command objects.
            Each git command inherits GitObj class.
*************************************************/

#include <string>
#include "config.hpp"

namespace GitEmAll
{

enum class GitCmd {
    commit,
    merge,
    fork,
    rename
};

inline std::string quote(std::string message) {
    return "\"" + message + "\"";
}

// Base class for git command
class GitObj {
public:
    virtual std::string write() = 0;

    unsigned long getId() const {return m_id;}

protected:
    GitObj(GitCmd cmd, unsigned long id, std::string my_branch)
        : m_cmd(cmd), m_id(id), m_my_branch(my_branch) {};

    GitCmd m_cmd;
    unsigned long m_id;
    std::string m_my_branch;
};

// git commit class
class CommitObj : public GitObj {
public:
    CommitObj(unsigned long id, std::string my_branch, std::string message)
        : GitObj(GitCmd::commit, id, my_branch), m_message(message) {};

    std::string write() {
        std::string ret_cmd
            = "git checkout " + m_my_branch + "; "
              "echo " + std::to_string(m_id) + " > " + Config::load().filename + "; "
              "git commit -a -m " + quote(m_message) + "\n";
        return ret_cmd;
    }
private:
    std::string m_message;
};

// git merge class
class MergeObj : public GitObj {
public:
    MergeObj(unsigned long id, std::string my_branch, std::string target_branch, std::string message)
        : GitObj(GitCmd::merge, id, my_branch), m_target_branch(target_branch), m_message(message) {};

    std::string write() {
        std::string ret_cmd
            = "git checkout " + m_my_branch + "; "
              "git merge " + m_target_branch + " -s ours -m " + quote(m_message) + "\n";
        return ret_cmd;
    }

private:
    std::string m_target_branch;
    std::string m_message;
};

// git class for forking a branch from another
class ForkObj : public GitObj {
public:
    ForkObj(unsigned long id, std::string my_branch, std::string new_branch, std::string message)
        : GitObj(GitCmd::fork, id, my_branch), m_new_branch(new_branch), m_message(message) {};

    std::string write() {
        std::string ret_cmd
                    = "git checkout " + m_my_branch + "; "
                      "git checkout -b " + m_new_branch + "; "
                      "echo " + std::to_string(m_id) + " > " + Config::load().filename + "; "
                      "git commit -a -m " + quote(m_message) + "\n";
        return ret_cmd;
    }
private:
    std::string m_new_branch;
    std::string m_message;
};

// git class for renaming a branch
// since the old name will not appear on git tree after renamed, using fork command is always recommended
class RenameObj : public GitObj {
public:
    RenameObj(unsigned long id, std::string my_branch, std::string new_name)
        : GitObj(GitCmd::rename, id, my_branch), m_new_name(new_name) {};

    std::string write() {
        std::string ret_cmd
                    = "git checkout " + m_my_branch + "; "
                      "git branch -m " + m_new_name + "\n";
        return ret_cmd;
    }
private:
    std::string m_new_name;
};

}