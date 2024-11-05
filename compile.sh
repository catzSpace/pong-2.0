echo "compilando"

g++ -o pong -I headers main.cpp src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

echo "Terminado con exito"
