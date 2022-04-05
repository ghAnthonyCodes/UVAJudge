#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>

int main() {
   int h, m, s;
   float speed;
   int currentSeconds = 0;
   int currentSpeed = 0;
   float distance = 0;
   bool update;
   std::string line;

   while (std::getline(std::cin, line)) {

      // Speed update
      if (line.length() > 8) {
         update = true;
         sscanf(line.c_str(), "%d:%d:%d %f", &h, &m, &s, &speed);
      } else {
         update = false;
         sscanf(line.c_str(), "%d:%d:%d", &h, &m, &s);
      }

      // How much time has passed since last update?
      int newSeconds = h*3600 + 60*m + s;
      distance += (newSeconds - currentSeconds)/3600.0*currentSpeed;

      // Update
      currentSeconds = newSeconds;
      currentSpeed = speed;
      if (!update)
         printf("%02d:%02d:%02d %.2f km\n", currentSeconds / 3600, (currentSeconds % 3600) / 60, currentSeconds % 60, distance);
   }
   return 0;
}
