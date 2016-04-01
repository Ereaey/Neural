#include "idealnerve.h"

IdealNerve::IdealNerve()
{
}

void IdealNerve::nullcline(state_type x, double t)
{
    double e = FV(x[0]) - GV(x[0]) + Iav + istimp;
    double g = FN(x[0]) - GN(x[0]) + Ian;

    std::ofstream f("datanullcline.csv", std::ofstream::out | std::ofstream::app);
    f << QString::number(x[0],'d', 5).toStdString() << ';' << QString::number(e,'d', 15).toStdString() << ';' << QString::number(g,'d', 15).toStdString() << std::endl;
    f.close();

}

double IdealNerve::ISTP(double t)
{
    if (t > 0.101)
        return 0;
    else
        return ISTEP(t);
}

double IdealNerve::ISTEP(double t)
{
    if (t < 0.100)
        return 0;
    else
        return istimp;
}

double IdealNerve::FV(double v)
{
    return Mv / (1 + exp(-1 * KOUP * (v - DELTAv)));
}
double IdealNerve::GV(double v)
{
    return I0P * sqrt(Rv20 * EV / (1 + Rv21 * EV * exp(-1 * KOUP * v)));
}
double IdealNerve::FN(double v)
{
    return Mn / (1 + exp(-1 * KOUP * (v - DELTAn)));
}

double IdealNerve::GN(double v)
{
    return I0P * sqrt(Rn20 * En / (1 + Rn21 * En * exp(-1 * KOUP * v)));
}

double IdealNerve::RN(double n)
{
    return I0P * sqrt(Rr20 * Er / (1 + Rr21 * Er * exp(-1 * KOUP * n)));
}

double IdealNerve::dvdt(state_type x, double t)
{
    return (FV(x[0]) - GV(x[0]) + Iav - RN(x[1]) + ists + ISTP(t)) / Cv;
}

double IdealNerve::dndt(state_type x, double t)
{
    return (FN(x[0]) - GN(x[0]) + Ian - RN(x[1])) / Cn;
}
