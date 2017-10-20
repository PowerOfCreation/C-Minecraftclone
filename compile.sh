g++ -o main Main.cpp FastNoise.cpp shader.cpp texture.cpp libglfw3.a libGLEW.a -Wl,-Bdynamic -lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor 
./main