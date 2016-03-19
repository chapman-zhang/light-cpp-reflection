#pragma pack(1)
#include "refHelper.hpp"

#define r(a, n) class START##n{\
public: START##n(){\
        map.addStart(#n, (size_t)this + sizeof(START##n));\
        }\
} start##n; a;\
class END##n{\
public: END##n(){\
        map.addEnd(#n, (size_t)this);\
        }\
} end##n;

#define REF_DECLARE(className) friend class InitHelper<className>; \
    private: static RMap map; \
    public: \
    template <typename T> \
    static T &getValue(void *b, const std::string& name); \
    template <typename T> \
    static void setValue(void *b, const std::string& name, const T& v);

#define REF_IMPEL(className) \
    RMap className::map; \
    InitHelper<className> temp##className; \
    template <typename T> \
    T &className::getValue(void *b, const std::string& name) \
        { \
            return map.getValue<T>(b, name);\
        }; \
    template <typename T> \
    void className::setValue(void *b, const std::string& name, const T& v) \
        { \
            return map.setValue<T>(b, name, v); \
        };