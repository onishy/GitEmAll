#pragma once

#include <string>

namespace GitEmAll
{

class Config
{
public:
    const std::string filename = "version.txt";

    static Config& load() {
        static Config config;
        return config;
    }
private:
    Config(){};
};

}