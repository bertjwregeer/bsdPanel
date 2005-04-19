#ifndef BSDPANEL_EXCEPTIONS
#define BSDPANEL_EXCEPTIONS

#include <stdexcept>

namespace bsdPanel {
        class TooManyArgs : public std::runtime_error {
                public:
                        TooManyArgs() : std::runtime_error("Too many arguments") { };
        };

        class TooManyEnv : public std::runtime_error {
                public:
                        TooManyEnv() : std::runtime_error("Too many enviroment variables") { };
        };

        class NoArgs : public std::runtime_error {
                public:
                        NoArgs() : std::runtime_error("No arguments provided") { };
        };      
}
#endif
