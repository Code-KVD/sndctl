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
            uint16_t bits_per_sample = 16);

  double duration() const;
  size_t frame_count() const;
};
} // namespace sndctl

#endif /* SNDCTL_PCM_BUFFER_H */