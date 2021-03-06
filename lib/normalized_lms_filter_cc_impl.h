/* -*- c++ -*- */
/* 
 * Copyright 2015 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_ADAPTIVE_NORMALIZED_LMS_FILTER_CC_IMPL_H
#define INCLUDED_ADAPTIVE_NORMALIZED_LMS_FILTER_CC_IMPL_H

#include <adaptive/normalized_lms_filter_cc.h>
#include <gnuradio/filter/fir_filter.h>

namespace gr {
namespace adaptive {

class normalized_lms_filter_cc_impl : public normalized_lms_filter_cc, filter::kernel::fir_filter_ccc
{
    private:
    std::vector<gr_complex> _new_taps;
    bool _updated;
    gr_complex _error;
    gr_complex _snoi_pwr;
    float _mu;
    uint32_t _print_counter;

    protected:
    gr_complex error(const gr_complex& decision, const gr_complex& estimate);
    void update_tap(gr_complex &tap, const gr_complex &in, const float& snoi_pwr);
    

    public:
    normalized_lms_filter_cc_impl(int num_taps, int sps);
    ~normalized_lms_filter_cc_impl();

    std::vector<gr_complex> get_taps() const;
    void set_taps(const std::vector<gr_complex> &taps);
    void print_taps(const std::vector<gr_complex> &taps);
    float mu() const;
    void set_mu(float mu);

    int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);

};

} // namespace adaptive
} // namespace gr

#endif /* INCLUDED_ADAPTIVE_NORMALIZED_LMS_FILTER_CC_IMPL_H */

