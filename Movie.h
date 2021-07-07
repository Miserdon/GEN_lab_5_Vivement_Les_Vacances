// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <utility>

class Movie {
public:
    static const int CHILDRENS   = 2;
    static const int REGULAR     = 0;
    static const int NEW_RELEASE = 1;

    explicit Movie( std::string  title, int priceCode = REGULAR );

    int getPriceCode() const;

    std::string getTitle() const;

private:
    std::string _title;
    int _priceCode;
};

inline Movie::
Movie( std::string  title, int priceCode )
        : _title(std::move( title ))
        , _priceCode( priceCode )
{}

inline int Movie::
getPriceCode() const { return _priceCode; }



inline std::string Movie::
getTitle() const { return _title; }

#endif // MOVIE_H