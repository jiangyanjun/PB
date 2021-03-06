//
//  stdexcept.h	Standard exceptions
//
//  Copyright by WATCOM International Corp. 1988-1996.  All rights reserved.
//
#ifndef _STDEXCEPT_H_INCLUDED
#define _STDEXCEPT_H_INCLUDED
#if !defined(_ENABLE_AUTODEPEND)
  #pragma read_only_file;
#endif

#ifndef __cplusplus
#error stdexception.h is for use with C++
#endif

#ifndef _COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifndef _WCTHROWS
#ifdef _CPPUNWIND
#define _WCTHROWS( __t )	throw __t
#else
#define _WCTHROWS( __t )
#endif
#endif

// corresponds to Header<stdexcept>

// to be fixed later by enhanced string class
//
//
#include <exstring.h>

typedef __ExcString string;

class _WPRTLINK exception {
    string _what_val;
public:
    exception( void ) _WCTHROWS(()) {
    }
    exception( exception const &src ) _WCTHROWS(())
        : _what_val( src._what_val ) {
    }
    exception( string const & what_val ) _WCTHROWS(())
        : _what_val( what_val ) {
    }
    exception& operator=( exception const & src ) _WCTHROWS(()) {
	_what_val = src._what_val;
	return *this;
    }
    virtual ~exception( void ) _WCTHROWS(()) {
    }
    virtual char const * what( void ) const _WCTHROWS(()) {
	return _what_val;
    }
};

class _WPRTLINK logic_error : public exception {
public:
    logic_error( string const& what_arg ) _WCTHROWS(())
        : exception( what_arg ) {
    }
};

class _WPRTLINK domain_error : public logic_error {
public:
    domain_error( string const& what_arg ) _WCTHROWS(())
        : logic_error( what_arg ) {
    }
};

class _WPRTLINK invalid_argument : public logic_error {
public:
    invalid_argument( string const& what_arg ) _WCTHROWS(())
        : logic_error( what_arg ) {
    }
};

class _WPRTLINK length_error : public logic_error {
public:
    length_error( string const& what_arg ) _WCTHROWS(())
        : logic_error( what_arg ) {
    }
};

class _WPRTLINK out_of_range : public logic_error {
public:
    out_of_range( string const& what_arg ) _WCTHROWS(())
        : logic_error( what_arg ) {
    }
};

class _WPRTLINK runtime_error : public exception {
public:
    runtime_error( string const& what_arg ) _WCTHROWS(())
        : exception( what_arg ) {
    }
};

class _WPRTLINK range_error : public runtime_error {
public:
    range_error( string const& what_arg ) _WCTHROWS(())
        : runtime_error( what_arg ) {
    }
};

class _WPRTLINK overflow_error : public runtime_error {
public:
    overflow_error( string const& what_arg ) _WCTHROWS(())
        : runtime_error( what_arg ) {
    }
};

#endif
