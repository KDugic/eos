/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2020 Danny van Dyk
 * Copyright (c) 2020 Katarina Dugic
 *
 * This file is part of the EOS project. EOS is free software;
 * you can redistribute it and/or modify it under the terms of the GNU General
 * Public License version 2, as published by the Free Software Foundation.
 *
 * EOS is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <eos/form-factors/mesonic.hh>
#include <eos/tau-decays/tau-to-psd-gamma-nu.hh>
#include <eos/utils/destringify.hh>
#include <eos/utils/model.hh>
#include <eos/utils/power_of.hh>
#include <eos/utils/private_implementation_pattern-impl.hh>
#include <eos/utils/options-impl.hh>

namespace eos
{
    using std::norm;

    /*
     * Decay: tau -> P gamma nu, cf. [DGvD:2020A]
     */
    template <>
    struct Implementation<TauToPseudoscalarGammaNeutrino>
    {
        std::shared_ptr<Model> model;

        UsedParameter hbar;

        UsedParameter g_fermi;

        UsedParameter m_tau;

        UsedParameter tau_tau;

        SwitchOption opt_P;

        UsedParameter f_P;

        UsedParameter m_P;

        std::shared_ptr<FormFactors<VacuumToPGamma>> ff;


        Implementation(const Parameters & p, const Options & o, ParameterUser & u) :
            model(Model::make(o.get("model", "SM"), p, o)),
            hbar(p["hbar"], u),
            g_fermi(p["G_Fermi"], u),
            m_tau(p["mass::tau"], u),
            tau_tau(p["life_time::tau"], u),
            opt_P(o, "P", {"pi", "K"}, "pi^-"),
            f_P(p["decay-constant::" + opt_P.value() + "^-"], u),
            m_P(p["mass::" + opt_P.value() + "^-"], u),
            ff(FormFactorFactory<VacuumToPGamma>::create("0->" + opt_P.value() + "gamma", p, o))
        {
            u.uses(*model);
            u.uses(*ff);
        }

        double decay_width(const double & q2) const
        {
            return 0.0;
        }

        double branching_ratio(const double & q2) const
        {
            return decay_width(q2) * tau_tau / hbar;
        }
    };

    TauToPseudoscalarGammaNeutrino::TauToPseudoscalarGammaNeutrino(const Parameters & parameters, const Options & options) :
        PrivateImplementationPattern<TauToPseudoscalarGammaNeutrino>(new Implementation<TauToPseudoscalarGammaNeutrino>(parameters, options, *this))
    {
    }

    TauToPseudoscalarGammaNeutrino::~TauToPseudoscalarGammaNeutrino()
    {
    }

    double
    TauToPseudoscalarGammaNeutrino::branching_ratio(const double & q2) const
    {
        return _imp->branching_ratio(q2);
    }

    const std::set<ReferenceName>
    TauToPseudoscalarGammaNeutrino::references
    {
        "DGvD:2020A"_rn
    };
}
