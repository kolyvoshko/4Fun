/**
   @file      nrand.h
   @brief     Pseudorandom number generator class header.
   @author    Eugene Kolyvoshko (ekolivoshko@gmail.com)
   @date      September 28 2015
   @version   1.0
   @copyright GNU Public License.
*/

#ifndef NRAND_H
#define NRAND_H
#include <string>

/**< \brief Pseudo random number generator class */
class Nrand
{
    public:
        Nrand();
        virtual ~Nrand();

        /** \brief get probably density of pseudo random number
            \param series number of random number
            \return array from 10 double numbers: probably in 0.1 from limits [low;up] */
        double * getProbablyDensity(int series = 10000);

        /** \brief get series of pseudo random number
            \param series number of random number
            \return array of random number */
        double * getSeries(int series = 10000);

        /** \brief get pseudo random number
            \return random double number */
        double getNumber();

        /** \brief get pseudo random number
            \param method name of method generation
            \return random double number */
        double getNumber(std::string method);

        /** \brief set method generation random numbers
            \param method name of method generation
            \return void */
        void setMethod(std::string method);

        /** TODO: in developing*/
        void setRange(double lower, double upper);

    private:
        std::string m_sMethod; /**< \brief contains name of method */
        double m_lower; /**< \brief lower limit */
        double m_upper; /**< \brief upper limit */

        /** \brief mwc method
            \return unsigned long random number*/
        unsigned long m_mwc();

        /** \brief mwc method
            \return unsigned long random number*/
        unsigned long m_x128();
};

#endif // NRAND_H
