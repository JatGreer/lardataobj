/** ****************************************************************************
 * @file lardataobj/RecoBase/Hit.cxx
 * @brief Definition of signal hit object.
 * @author mitchell.soderberg@yale.edu
 * @see  lardataobj/RecoBase/Hit.h
 * 
 * ****************************************************************************/

// Hit header
#include "lardataobj/RecoBase/Hit.h"

// C/C++ standard library
#include <iomanip>
#include <ostream>
#include <utility> // std::move()


namespace recob {
  
  //----------------------------------------------------------------------
  Hit::Hit()
    : fChannel(raw::InvalidChannelID)
    , fStartTick(0)
    , fEndTick(0)
    , fPeakTime(0.)
    , fSigmaPeakTime(-1.)
    , fRMS(0.)
    , fPeakAmplitude(0.)
    , fSigmaPeakAmplitude(-1.)
    , fSummedADC(0.)
    , fIntegral(0.)
    , fSigmaIntegral(-1.)
    , fMultiplicity(0)
    , fLocalIndex(-1)
    , fGoodnessOfFit(0.)
    , fNDF(-1)
    , fView(geo::kUnknown)
    , fSignalType(geo::kMysteryType)
    , fWireID() // invalid
    , fSummedADC1(0.)
    , fSummedADC2(0.)
    , fSummedADC3(0.)
    , fSummedADC4(0.)
    , fSummedADC5(0.)
    , fSummedADC6(0.)
    , fSummedADC7(0.)
    , fSummedADC8(0.)
    , fContinues(false)
    {}
  
  //----------------------------------------------------------------------
  Hit::Hit(
    raw::ChannelID_t        channel,
    raw::TDCtick_t          start_tick,
    raw::TDCtick_t          end_tick,
    float                   peak_time,
    float                   sigma_peak_time,
    float                   rms,
    float                   peak_amplitude,
    float                   sigma_peak_amplitude,
    float                   summedADC,
    float                   hit_integral,
    float                   hit_sigma_integral,
    short int               multiplicity,
    short int               local_index,
    float                   goodness_of_fit,
    int                     dof,
    geo::View_t             view,
    geo::SigType_t          signal_type,
    geo::WireID             wireID,
    float      	       	    summedADC1,
    float                   summedADC2,
    float      	       	    summedADC3,
    float      	       	    summedADC4,
    float      	       	    summedADC5,
    float      	       	    summedADC6,
    float      	       	    summedADC7,
    float      	       	    summedADC8,
    bool                    continues
    )
    : fChannel(channel)
    , fStartTick(start_tick)
    , fEndTick(end_tick)
    , fPeakTime(peak_time)
    , fSigmaPeakTime(sigma_peak_time)
    , fRMS(rms)
    , fPeakAmplitude(peak_amplitude)
    , fSigmaPeakAmplitude(sigma_peak_amplitude)
    , fSummedADC(summedADC)
    , fIntegral(hit_integral)
    , fSigmaIntegral(hit_sigma_integral)
    , fMultiplicity(multiplicity)
    , fLocalIndex(local_index)
    , fGoodnessOfFit(goodness_of_fit)
    , fNDF(dof)
    , fView(view)
    , fSignalType(signal_type)
    , fWireID(wireID)
    , fSummedADC1(summedADC1)
    , fSummedADC2(summedADC2)
    , fSummedADC3(summedADC3)
    , fSummedADC4(summedADC4)
    , fSummedADC5(summedADC5)
    , fSummedADC6(summedADC6)
    , fSummedADC7(summedADC7)
    , fSummedADC8(summedADC8)
    , fContinues(continues)
  {}
  
  
  //----------------------------------------------------------------------
  // ostream operator.
  //
  std::ostream& operator<< (std::ostream& o, Hit const& hit) {
    o << std::setiosflags(std::ios::fixed) << std::setprecision(2);
    o <<   " Channel "          << std::setw(5) << std::right << hit.Channel()
      <<   " View = "           << std::setw(3) << std::right << hit.View()
      <<   " Signal type = "    << std::setw(3) << std::right << hit.SignalType()
      <<   " Wire = "           << std::setw(3) << std::right << hit.WireID()
      << "\n\tStartTick = "     << std::setw(7) << std::right << hit.StartTick()
        << "\tEndTick = "       << std::setw(7) << std::right << hit.EndTick()
        << "\tPeakTime = "      << std::setw(7) << std::right << hit.PeakTime()
        << " +/- "              << std::setw(7) << std::right << hit.SigmaPeakTime()
        << "\tRMS = "           << std::setw(7) << std::right << hit.RMS()
      << "\n\tAmplitude = "     << std::setw(7) << std::right << hit.PeakAmplitude()
        << " +/- "              << std::setw(7) << std::right << hit.SigmaPeakAmplitude()
        << "\tIntegral = "      << std::setw(7) << std::right << hit.Integral()
        << " +/- "              << std::setw(7) << std::right << hit.SigmaIntegral()
        << "\tADCsum = "        << std::setw(7) << std::right << hit.SummedADC()
        << "\tMultiplicity = "  << std::setw(5) << std::right << hit.LocalIndex() << " of " << hit.Multiplicity()
        << "\tGoodnessOfFit = " << std::setw(7) << std::right << hit.GoodnessOfFit()
        << " DoF = "           << std::setw(7) << std::right << hit.DegreesOfFreedom()
      << std::endl;
    return o;
  } // operator<< (std::ostream, Hit)
  
  
  //----------------------------------------------------------------------
  // < operator.
  //
  bool operator < (const Hit & a, const Hit & b)
  {
    if (a.Channel() != b.Channel())
      return a.Channel() < b.Channel();
    if (a.View() != b.View())
      return a.View() < b.View();
    if (a.StartTick() != b.StartTick())
      return a.StartTick() < b.StartTick();

    return false; //They are equal
  } // operator< (Hit, Hit)
  
  
  //----------------------------------------------------------------------
} // namespace recob

