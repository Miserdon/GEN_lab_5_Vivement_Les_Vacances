// Customer.cpp
#include <sstream>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for ( const Rental& r : _rentals) {
        double thisAmount = 0;

        thisAmount = getAmountOfPriceCode(thisAmount, r);

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        if ( ( r.getMovie().getPriceCode() == Movie::NEW_RELEASE )
             && r.getDaysRented() > 1 ) frequentRenterPoints++;

        // show figures for this rental
        result << "\t" << r.getMovie().getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

    double Customer::getAmountOfPriceCode(double thisAmount, const Rental &each) {// determine amounts for each line
    switch ( each.getMovie().getPriceCode() ) {
        case Movie::REGULAR:
            thisAmount += 2;
            if ( each.getDaysRented() > 2 )
                thisAmount += ( each.getDaysRented() - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            thisAmount += each.getDaysRented() * 3;
            break;
        case Movie::CHILDRENS:
            thisAmount += 1.5;
            if ( each.getDaysRented() > 3 )
                thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
            break;
    }
    return thisAmount;
}
