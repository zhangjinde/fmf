#pragma once
#include <string>
#include <map>

namespace FMF {
    class Context {
    public:
        virtual ~Context() = default;

        std::string get(std::string const &key, std::string const &default_value = std::string()) {
            auto value = do_get(key);
            return value.empty() ? default_value : value;
        }
        void set(std::string const &key, std::string const &value) {
            return do_set(key,value);
        }

    private:
        std::map<std::string,std::string> _values;
        virtual std::string do_get(std::string const &key) {
            return _values[key];
        }
        virtual void do_set(std::string const &key, std::string const &value) {
            _values[key] = value;
        }
};
}