#ifndef IDEALNERVE_H
#define IDEALNERVE_H

#include <QMap>
#include <iostream>
#include <boost/array.hpp>
#include <boost/numeric/odeint.hpp>
#include <fstream>

typedef boost::array< double , 2 > state_type;

class IdealNerve
{
    public:
        IdealNerve();

        void operator() ( const state_type &x , state_type &dxdt , const double t)
        {
            dxdt[0] = dvdt(x, t);
            dxdt[1] = dndt(x, t);
            nullcline(x, t);
        }

    private:
        double dvdt(state_type x, double t);
        double dndt(state_type x, double t);
        void nullcline(state_type x, double t);

        double ISTP(double t);
        double ISTEP(double t);
        double FV(double v);
        double GV(double v);
        double FN(double v);
        double GN(double v);
        double RN(double n);

        static constexpr double ists = 0.0;
        static constexpr double Mv = 0.55;
        static constexpr double DELTAv = 0.43;
        static constexpr double EV = 160000.0;
        static constexpr double Rv21 = 1.0;
        static constexpr double Rv20 = 1.0;
        static constexpr double Iav = 0.093;
        static constexpr double Cv = 0.0005;
        static constexpr double Mn = 1.0;
        static constexpr double DELTAn = 0.52;
        static constexpr double En = 9000.0;
        static constexpr double Rn21 = 2.0;
        static constexpr double Rn20 = 0.5;
        static constexpr double Ian = 0.08;
        static constexpr double Cn = 0.00067;
        static constexpr double Er = 200000.0;
        static constexpr double Rr21 = 1.0;
        static constexpr double Rr20 = 1.0;
        static constexpr double istimp = 0.0;
        static constexpr double KOUP = 27.0;
        static constexpr double I0P = 0.000852;
};

#endif // IDEALNERVE_H
