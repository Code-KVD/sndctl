#ifndef SNDCTL_PCM_BUFFER_H
#define SNDCTL_PCM_BUFFER_H

#include <cstdint>
#include <vector>

namespace sndctl {

struct PcmBuffer {

  std::vector<int16_t> samples;
  uint32_t sample_rate;
  uint16_t channels;
  uint16_t bits_per_sample;

  PcmBuffer(uint32_t sample_rate = 44100, uint16_t channels = 2,
            uint16_t bits_per_sample = 16)
      : sample_rate(sample_rate), channels(channels),
        bits_per_sample(bits_per_sample) {}

  double duration() const {
    if (sample_rate == 0 || channels == 0) {
      return 0.0;
    }
    return (double)samples.size() / ((double)sample_rate * (double)channels);
  }

  size_t frame_count() const {
    if (channels == 0) {
      return 0;
    }
    return samples.size() / channels;
  }
};
} // namespace sndctl

#endif /* SNDCTL_PCM_BUFFER_H */