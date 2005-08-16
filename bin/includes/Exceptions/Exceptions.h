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
        
        class NoMatch : public std::runtime_error {
                public:
                        NoMatch() : std::runtime_error("Nothing too match") { };
        };
        
        class FaultMatch : public std::runtime_error {
                public:
                        FaultMatch() : std::runtime_error("Match expression badly formatted") { };
        };

        class NestedMatch : public std::runtime_error {
                public:
                        NestedMatch() : std::runtime_error("Match expression contains nested matching -- Not supported") { };
        };

        class TypeTempMatch : public std::runtime_error {
                public:
                        TypeTempMatch() : std::runtime_error("Type_temp was not correctly added to the vector, and or was not set to 0.") { };
        };   
}
#endif
