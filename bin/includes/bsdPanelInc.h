#ifndef BSDPANEL_INC
#define BSDPANEL_INC

#ifndef EXIT_FAILURE
#define EXIT_FAILURE -1
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0 
#endif

namespace bsdPanel { 
        struct exit_t { 
                explicit exit_t( int n = EXIT_FAILURE ) : code( n ) {} int code; 
        }; 
} 

namespace bsdPanel {
        inline void exit_program(int code = EXIT_FAILURE ) { 
                /*this function never returns*/
                throw bsdPanel::exit_t( code ); 
        }
}

/*
int main() {
        try { // Random stuff here } catch ( exit_exception_detail::exit_t const& e ) { return e.code; } catch (...) { return EXIT_FAILURE; }
}      
*/

#endif
