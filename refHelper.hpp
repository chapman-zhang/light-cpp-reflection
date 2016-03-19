#pragma once

#include <string>
#include <map>

struct pro
{
    size_t start;
    size_t size;
};

template <typename T>
class InitHelper
{
public:
    InitHelper<T>()
    {
        T t;
        t.map.setBase((size_t)&t);
    };
};


class RMap
{
public:
    RMap():inited(false){};

    void setBase(size_t base)
    {
        if (inited)
        {
            return;
        }
        inited = true;
        auto itr = map.begin();
        while (itr != map.end())
        {
            itr->second.start -= base;
            itr++;
        }
    }

    void addStart(const std::string name, size_t address)
    {
        if (inited)
        {
            return;
        }
        map[name] = pro();
        map[name].start = address;
    }

    void addEnd(const std::string name, size_t address)
    {
        if (inited)
        {
            return;
        }
        map[name].size = address - map[name].start;
    }

    template <typename T>
    T &getValue(void *b, const std::string name)
    {
        size_t v = map[name].start + size_t(b);
        return *(T*)v;
    }

    template <typename T>
    void setValue(void *b, const std::string name, const T& v)
    {
        size_t add = map[name].start + size_t(b);
        *(T*)add = v;
    }

private:
    std::map<std::string, pro> map;
    bool inited;
};