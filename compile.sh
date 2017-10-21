dpkg -l libglfw3-dev > /dev/null 2>&1
INSTALLED=$?

if [ $INSTALLED != '0' ]; then
    sudo apt-get install libglfw3-dev
fi
cmake .
make
#g++ -o main Main.cpp FastNoise.cpp shader.cpp texture.cpp libglfw3.a libGLEW.a -Wl,-Bdynamic -lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor 
./main