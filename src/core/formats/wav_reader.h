#ifndef SNDCTL_WAV_READER_H
#define SNDCTL_WAV_READER_H

#include "pcm_buffer.h"
#include <cstdint>
#include <string>
#include <unordered_map>

namespace sndctl {
class WavReader {
private:
  struct RIFFHeader {
    char chunk_id[4];
    uint32_t file_size;
    char format[4];
  };

  struct FormatChunk {
    char format_id[4];
    uint32_t chunk_size;
    uint16_t audio_format;
    uint16_t channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
  };

  struct DataChunk {
    char data_id[4];
    uint32_t chunk_size;
  };

public:
  WavReader() = default;
  int read(const std::string &filename);
  std::unordered_map<std::string, std::string> get_file_info();
};
} // namespace sndctl

#endif /* SNDCTL_WAV_READER_H */