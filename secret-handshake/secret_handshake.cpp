#include "secret_handshake.h"

#include <iostream>
#include <string>
#include <vector>

namespace secret_handshake {
std::vector<std::string> commands(const int c) {
  const uint32_t code = 0x1;
  std::vector<std::string> secrets;
  uint32_t bin;
  int num = c;
  int i;

  i = 0;
  for (bin = 0; num > 0; num >>= 1, ++i) {
    if ((num % 2) == 1) {
      bin |= (code << i);
    }
  }

  if (bin & code) {
    secrets.push_back("wink");
  }

  if (bin & (code << 1)) {
    secrets.push_back("double blink");
  }

  if (bin & (code << 2)) {
    secrets.push_back("close your eyes");
  }

  if (bin & (code << 3)) {
    secrets.push_back("jump");
  }

  if (bin & (code << 4)) {
    secrets = std::vector<std::string>(secrets.rbegin(), secrets.rend());
  }

  return secrets;
}
}  // namespace secret_handshake
