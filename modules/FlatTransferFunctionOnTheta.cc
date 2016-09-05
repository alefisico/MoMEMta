/*
 *  MoMEMta: a modular implementation of the Matrix Element Method
 *  Copyright (C) 2016  Universite catholique de Louvain (UCL), Belgium
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <momemta/ParameterSet.h>
#include <momemta/Module.h>
#include <momemta/Types.h>
#include <momemta/Utils.h>

/** \brief Flat transfer function on Theta (mainly for testing purposes). 
 *
 * This modules implements a constant (=1) transfer function on a particle's \f$\theta\f$.
 *
 * The primary purpose of this module is the validation of the phase-space generator, since it allows
 * computing phase-space volumes and cross-sections by integrating over the reconstructed particle's momenta.
 *
 * The module still takes a 4-momentum as input, since it needs an energy, a \f$\phi\f$-angle and a mass.
 *
 * The range of \f$\theta\f$ values considered is \f$[0,\pi]\f$. 
 *
 * ### Integration dimension
 *
 * This module adds **1** dimension to the integration.
 *
 * ### Inputs
 *
 *   | Name | Type | %Description |
 *   |------|------|--------------|
 *   | `ps_point` | double | Phase-space point generated by CUBA. |
 *   | `reco_particle` | LorentzVector | Input LorentzVector (experimentally reconstructed particle). |
 *
 * ### Outputs
 *
 *   | Name | Type | %Description |
 *   |------|------|--------------|
 *   | `output` | LorentzVector | Output *generated* LorentzVector, only differing from *reco_particle* by its \f$\theta\f$. |
 *   | `TF_times_jacobian` | double | Transfer function (ie, 1) times the jacobian (due to the integration range). |
 *
 * \ingroup modules
 */

class FlatTransferFunctionOnTheta: public Module {
    public:

        FlatTransferFunctionOnTheta(PoolPtr pool, const ParameterSet& parameters): Module(pool, parameters.getModuleName()) {
            m_ps_point = parameters.get<InputTag>("ps_point");
            m_ps_point.resolve(pool);
            
            m_input = parameters.get<InputTag>("reco_particle");
            m_input.resolve(pool);
        };

        virtual Status work() override {

            const double& ps_point = m_ps_point.get<double>();
            const LorentzVector& reco_particle = m_input.get<LorentzVector>();

            const double new_theta = M_PI*ps_point;

            // Set the output vector's theta angle using the generated value, keeping the input's |P|, phi and E
            output->SetCoordinates(
                reco_particle.P() * std::sin(new_theta) * std::cos(reco_particle.Phi()),
                reco_particle.P() * std::sin(new_theta) * std::sin(reco_particle.Phi()),
                reco_particle.P() * std::cos(new_theta),
                reco_particle.E());

            // Compute TF*jacobian, ie the jacobian of the transformation of [0,1]->[0,pi]
            *TF_times_jacobian = M_PI;

            return Status::OK;
        }

        virtual size_t dimensions() const override {
            return 1;
        }

    private:

        InputTag m_ps_point;
        InputTag m_input;

        std::shared_ptr<LorentzVector> output = produce<LorentzVector>("output");
        std::shared_ptr<double> TF_times_jacobian = produce<double>("TF_times_jacobian");
};
REGISTER_MODULE(FlatTransferFunctionOnTheta);