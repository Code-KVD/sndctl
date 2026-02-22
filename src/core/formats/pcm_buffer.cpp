#include "pcm_buffer.h"

namespace sndctl {

PcmBuffer::PcmBuffer(uint32_t sample_rate, uint16_t channels,
                     uint16_t bits_per_sample)
    : sample_rate(sample_rate), channels(channels),
      bits_per_sample(bits_per_sample) {}

double PcmBuffer::duration() const {
  if (sample_rate == 0 || channels == 0) {
    return 0.0;
  }
  return static_cast<double>(samples.size()) / (sample_rate * channels);
}

size_t PcmBuffer::frame_count() const {
  if (channels == 0) {
    return 0;
  }
  return samples.size() / channels;
}

} // namespace sndctl