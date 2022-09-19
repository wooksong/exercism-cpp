#include "raindrops.h"

#include <string>

namespace raindrops {
const static std::string RAINDROP_SOUND_3 = "Pling";
const static std::string RAINDROP_SOUND_5 = "Plang";
const static std::string RAINDROP_SOUND_7 = "Plong";

std::string convert(int number) {
  std::string sound;

  if ((number % 3) == 0) {
    sound.append(RAINDROP_SOUND_3);
  }

  if ((number % 5) == 0) {
    sound.append(RAINDROP_SOUND_5);
  }

  if ((number % 7) == 0) {
    sound.append(RAINDROP_SOUND_7);
  }

  if (sound.empty()) {
    sound.append(std::to_string(number));
  }

  return sound;
}
}  // namespace raindrops
