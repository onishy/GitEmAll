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

class GitObj {
public:
    virtual std::string write() = 0;

    unsigned long getId() const {return m_id;}
    bool operator<(const GitObj& right) {
        return this->m_id < right.getId();
    }

protected:
    GitObj(GitCmd cmd, unsigned long id, std::string my_branch)
        : m_cmd(cmd), m_id(id), m_my_branch(my_branch) {};

    GitCmd m_cmd;
    unsigned long m_id;
    std::string m_my_branch;
};

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

class MergeObj : public GitObj {
public:
    MergeObj(unsigned long id, std::string my_branch, std::string target_branch, std::string message)
        : GitObj(GitCmd::merge, id, my_branch), m_target_branch(target_branch), m_message(message) {};

    std::string write() {
        std::string ret_cmd
            = "git checkout " + m_my_branch + "; "
              "echo " + std::to_string(m_id) + " > " + Config::load().filename + "; "
              "git merge " + m_target_branch + " -s ours -m " + quote(m_message) + "\n";
        return ret_cmd;
    }

private:
    std::string m_target_branch;
    std::string m_message;
};

class ForkObj : public GitObj {
public:
    ForkObj(unsigned long id, std::string my_branch, std::string new_branch)
        : GitObj(GitCmd::fork, id, my_branch), m_new_branch(new_branch) {};

    std::string write() {
        std::string ret_cmd
                    = "git checkout " + m_my_branch + "; "
                      "git branch " + m_new_branch + "\n";
        return ret_cmd;
    }
private:
    std::string m_new_branch;
};

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