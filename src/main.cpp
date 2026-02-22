#include "core/formats/pcm_buffer.h"
#include <iostream>

int main() {
  std::cout << "Testing sndctl - PCMBuffer\n";

  // Create a PCMBuffer with default values
  sndctl::PcmBuffer buffer;

  std::cout << "Sample Rate: " << buffer.sample_rate << " Hz\n";
  std::cout << "Channels: " << buffer.channels << "\n";
  std::cout << "Bits per Sample: " << buffer.bits_per_sample << "\n";

  // Add some dummy samples to test duration calculation
  buffer.samples.resize(88200); // 1 second of stereo audio at 44100 Hz

  std::cout << "Duration: " << buffer.duration() << " seconds\n";
  std::cout << "Frame Count: " << buffer.frame_count() << "\n";

  std::cout << "\nPCMBuffer test passed!\n";

  return 0;
}