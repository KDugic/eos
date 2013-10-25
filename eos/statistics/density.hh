/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2013 Danny van Dyk
 * Copyright (c) 2013 Frederik Beaujean
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

#ifndef EOS_GUARD_EOS_STATISTICS_DENSITY_HH
#define EOS_GUARD_EOS_STATISTICS_DENSITY_HH 1

#include <eos/statistics/density-fwd.hh>
#include <eos/utils/mutable-fwd.hh>
#include <eos/utils/parameters.hh>
#include <eos/utils/wrapped_forward_iterator.hh>

namespace eos
{
    class Density
    {
        public:
            virtual ~Density() = 0;

            /// Evaluate the density function at the current parameter point.
            virtual double evaluate() const = 0;

            /// Create an independent copy of this density function.
            virtual DensityPtr clone() const = 0;

            /// Iterate over the parameters relevant to this density function.
            ///@{
            struct IteratorTag;
            typedef WrappedForwardIterator<IteratorTag, ParameterDescription> Iterator;

            virtual Iterator begin() const = 0;
            virtual Iterator end() const = 0;
            ///@}
    };
}

#endif