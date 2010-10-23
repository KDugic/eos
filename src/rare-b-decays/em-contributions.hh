/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#ifndef EOS_GUARD_SRC_RARE_B_DECAYS_EM_CONTRIBUTIONS_HH
#define EOS_GUARD_SRC_RARE_B_DECAYS_EM_CONTRIBUTIONS_HH 1

#include <src/utils/complex.hh>

namespace eos
{
    struct EMContributions
    {
        /*
         * Log-enhanced electro-magnetic contributions according to [HLMW2005].
         *
         * s_hat:       s / m_b_pole^2
         * log_m_l_hat: ln(m_l / m_b_pole)
         * mu:          renormalization scale
         */

        // cf. [HLMW2005], Eq. (104), p. 25
        static double omegaem_22(const double & s_hat, const double & log_m_l_hat, const double & mu);

        // cf. [HLMW2005], Eq. (105), p. 25
        static complex<double> omegaem_27(const double & s_hat, const double & log_m_l_hat, const double & mu);

        // cf. [HLMW2005], Eq. (103), p. 25
        static complex<double> omegaem_29(const double & s_hat, const double & log_m_l_hat, const double & mu);

        // cf. [HLMW2005], Eq. (101), p. 25
        static double omegaem_77(const double & s_hat, const double & log_m_l_hat);

        // cf. [HLMW2005], Eq. (102), p. 25
        static double omegaem_79(const double & s_hat, const double & log_m_l_hat);

        // cf. [HLMW2005], Eq. (94), p. 23
        static double omegaem_99(const double & s_hat, const double & log_m_l_hat);

        // cf. [HLMW2005], Eq. (100), p. 24
        static double omegaem_1010(const double & s_hat, const double & log_m_l_hat);
    };
}

#endif