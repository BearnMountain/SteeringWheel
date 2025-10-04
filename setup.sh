cmake -B build -DPICO_BOARD=pico2
cmake --build build -j4
picotool load -v -x build/steering_wheel.uf2 -f --force
