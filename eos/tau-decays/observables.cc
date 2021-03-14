/* vim: set sw=4 sts=4 et tw=150 foldmethod=marker : */

/*
 * Copyright (c) 2020 Danny van Dyk
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

#include <eos/observable-impl.hh>
#include <eos/tau-decays/tau-to-psd-gamma-nu.hh>
#include <eos/utils/concrete_observable.hh>

namespace eos
{
    // Radiative tau decays to pseudo scalars
    // {{{
    ObservableGroup
    make_tau_to_psd_gamma_nu_group()
    {
        auto imp = new Implementation<ObservableGroup>(
            R"(Observables in $\tau^-\to P \gamma\bar\nu$ decays)",
            R"()",
            {
               /* make_observable("tau->pigammanu::dBR/dq2", R"(d\mathcal{B}(\tau^- \to \pi^-\gamma\bar\nu)/dq^2)",
                        &TauToPseudoscalarGammaNeutrino::branching_ratio,
                        std::make_tuple("q2")),*/
              make_observable("tau->pigammanu::R(E_gamma,E_pi)", R"(R(\tau^- \to \pi^-\gamma\bar\nu)/dq^2)",
                        &TauToPseudoscalarGammaNeutrino::differential_ratio,
                        std::make_tuple("E_gamma","E_pi")),
            }
        );

        return ObservableGroup(imp);
    }
    // }}}

    ObservableSection
    make_tau_decays_section()
    {
        auto imp = new Implementation<ObservableSection>(
            R"(Observables in $\tau$ decays)",
            "",
            {
                // tau^- -> P gamma nubar
                make_tau_to_psd_gamma_nu_group(),
            }
        );

        return ObservableSection(imp);
    }
}